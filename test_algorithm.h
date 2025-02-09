#ifndef PLAYER_H
#include "player.h"
#endif

#ifndef IOSTREAM
#include <iostream>
#endif

class TestAlgorithm : public StockAlgorithm {
    public:
        std::vector<Share>* actions(
            const std::map<std::string, float> prices,
            float current_funds,
            const std::map<std::string, Share> portfolio,
            long time) 
        {
            float threshold = 1.15;
            std::vector<Share>* buy_and_sell = new std::vector<Share>[2];
            std::vector<Share> buy;
            std::vector<Share> sell;
            float lowest_price = 1000000;
            std::string lowest_price_symbol = "";
            for (std::map<std::string, float>::const_iterator iter = prices.begin(); iter != prices.end(); ++iter) {
                std::string symbol = iter->first;
                float price = prices.at(symbol);
                if (price < lowest_price) {
                    lowest_price = price;
                    lowest_price_symbol = symbol;
                }
            }
            Share buy_share(lowest_price_symbol, lowest_price, current_funds/lowest_price, time);
            for (std::map<std::string, Share>::const_iterator iter = portfolio.begin(); iter != portfolio.end(); ++iter) {
                std::string symbol = iter->first;
                Share share = portfolio.at(symbol);
                float old_price = share.getBuyPrice();
                float current_price = prices.at(symbol);
                if (current_price / old_price > threshold) {
                    sell.push_back(share);
                }
            }
            buy.push_back(buy_share);
            buy_and_sell[0] = buy;
            buy_and_sell[1] = sell;
            return buy_and_sell;
        }
};
