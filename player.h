#ifndef STOCK_ALGORITHM_H
#include "stock-algorithm.h"
#endif

#ifndef STRING
#include <string>
#endif

#ifndef VECTOR
#include <vector>
#endif

#ifndef MAP
#include <map>
#endif

#ifndef SHARE_H
#include "share.h"
#endif

#ifndef PLAYER_H
#define PLAYER_H
class Player
{
    public:
        Player(StockAlgorithm pa, float starting_funds);
        void execute_trades(const std::map<std::string, float>, long time);

    private:
        StockAlgorithm player_algorithm_;
        float starting_funds_;
        float current_funds_;
        std::map<std::string, Share> portfolio_;

        void buy(std::string symbol, int num_shares, float cost_per_share, long time);
        void buy(Share buy_share);
        void sell(std::string symbol, int num_shares, float cost_per_share, long time);
        void sell(Share sell_share, float price);
};

#endif
