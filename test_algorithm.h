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
        std::vector<Share>* buy_and_sell = new std::vector<Share>[2];
        std::vector<Share> buy;
        std::vector<Share> sell;
        float lowest_price = 1000000;
        string lowest_price_symbol = "";
        for (std::map<std::string, float>::const_iterator iter = prices.begin(); iter != prices.end(); ++iter) {
            string symbol = iter->first;
            float price = prices.at(symbol);
            if (price < lowest_price) {
                lowest_price = price;
                lowest_price_symbol = symbol;
            }
        }
        Share share(lowest_price_symbol, lowest_price, current_funds/lowest_price, time);
        buy.push_back(share);
        buy_and_sell[0] = buy;
        buy_and_sell[1] = sell;
        return buy_and_sell;
    }
};
