#ifndef PLAYER_H
#include "player.h"
#endif

Player::Player(StockAlgorithm* pa, float starting_funds) : portfolio_() {
    player_algorithm_ = pa;
    starting_funds_ = starting_funds;
    current_funds_ = starting_funds_;
}

void Player::execute_trades(const std::map<std::string, float> prices, long time) {
    std::vector<Share>* trades = player_algorithm_->actions(prices, current_funds_, portfolio_, time);
    std::vector<Share> buys = trades[0];
    std::vector<Share> sells = trades[1];
    for (std::vector<Share>::size_type i = 0; i < buys.size(); ++i) {
        Share buy_share = buys[i];
        buy(buy_share);
    }
    for (std::vector<Share>::size_type i = 0; i < sells.size(); ++i) {
        Share sell_share = sells[i];
        float price = prices.find(sell_share.getSymbol())->second;
        sell(sell_share, price);
    }
    delete[] trades;
}

void Player::buy(std::string symbol, int num_shares, float cost_per_share, long time) {
    float cost = num_shares * cost_per_share;
    current_funds_ -= cost;
    std::map<string, Share>::iterator cur_share_iter = portfolio_.find(symbol);
    if (cur_share_iter != portfolio_.end()) {
        Share cur_share = cur_share_iter->second;
        cur_share.add_shares(cost_per_share, num_shares, time);
    }
    else {
        Share shares(symbol, cost_per_share, num_shares, time);
        portfolio_.insert(std::pair<std::string, Share>(symbol, shares));
    }
}

void Player::buy(Share buy_share) {
    buy(buy_share.getSymbol(), buy_share.getBuyVolume(), buy_share.getBuyPrice(), buy_share.getBuyTime());
}

void Player::sell(std::string symbol, int num_shares, float cost_per_share, long time) {
    std::map<string, Share>::iterator cur_share_iter = portfolio_.find(symbol);
    if (cur_share_iter != portfolio_.end()) {
        Share cur_share = cur_share_iter->second;
        cur_share.sub_shares(cost_per_share, num_shares, time);
        current_funds_ += num_shares * cost_per_share;
    }
}

void Player::sell(Share sell_share, float price) {
    sell(sell_share.getSymbol(), sell_share.getBuyVolume(), price, sell_share.getBuyTime());
}
