#ifndef PLAYER_H
#include "player.h"
#endif

#ifndef IOSTREAM
#include <iostream>
#endif

using std::string;
using std::map;
using std::vector;

class TestAlgorithm : public StockAlgorithm {
    public:
        vector<Share>* actions(
                const map<string, float> prices,
                float current_funds,
                const map<string, Share> portfolio,
                long time)
        {
            float threshold = 1.15;
            vector<Share>* buy_and_sell = new vector<Share>[2];
            vector<Share> buy;
            vector<Share> sell;
            float lowest_price = 1000000;
            string lowest_price_symbol = "";
            for (map<string, float>::const_iterator iter = prices.begin(); iter != prices.end(); ++iter) {
                string symbol = iter->first;
                float price = prices.at(symbol);
                if (price < lowest_price) {
                    lowest_price = price;
                    lowest_price_symbol = symbol;
                }
            }
            Share buy_share(lowest_price_symbol, lowest_price, current_funds/lowest_price, time);
            for (map<string, Share>::const_iterator iter = portfolio.begin(); iter != portfolio.end(); ++iter) {
                string symbol = iter->first;
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
