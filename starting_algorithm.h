#ifndef PLAYER_H
#include "player.h"
#endif

#ifndef MARKET_H
#include "market_record.h"
#endif

#ifndef IOSTREAM
#include <iostream>
#endif

class StartingAlgorithm : public StockAlgorithm {

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
            // TODO: update metric values for all new information stocks
            // TODO: compile buy and sell orders based on the new metric
            buy_and_sell[0] = buy;
            buy_and_sell[1] = sell;
            return buy_and_sell;
        }
        StartingAlgorithm();

    private:
        std::map<std::string, Market_Record> symbol_records_;
        const double metric_hard_buy_point_;
        const double metric_hard_sell_point_;
        // TODO:
        void update_metric(
            Market_Record record,
            float funds,
            float price_update,
            Share portfolio,
            long time);
        bool consider_sell_share(Market_Record share_record);
        bool consider_buy_share(Market_Record share_record);

};
