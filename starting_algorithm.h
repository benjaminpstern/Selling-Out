#ifndef PLAYER_H
#include "player.h"
#endif

#ifndef MARKET_H
#include "market_record.h"
#endif

#ifndef IOSTREAM
#include <iostream>
#endif

using std::string;
using std::map;
using std::vector;
class StartingAlgorithm : public StockAlgorithm {

    public:
        vector<Share>* actions(
            const map<string, float> prices,
            float current_funds,
            const map<string, Share> portfolio,
            long time)
        {

            vector<Share>* buy_and_sell = new vector<Share>[2];
            vector<Share> buy;
            vector<Share> sell;
            for (map<string, float>::const_iterator iter = prices.begin(); iter != prices.end(); ++iter) {
                string symbol = iter->first;
                float price = prices.at(symbol);
                this->update_metric( symbol_records_.at(symbol), current_funds, price, portfolio, time);
                if( this->consider_sell_share( symbol_records_.at(symbol) ) ) {
                    Share sellable_share = portfolio.at(symbol);
                    sell.push_back( sellable_share );
                } else if( this->consider_buy_share( symbol_records_.at(symbol) ) ) {
                    int recommended_volume = this->recommend_buy_volume( symbol_records_.at(symbol), current_funds );
                    Share buy_share( symbol, price, recommended_volume, time);
                    buy.push_back( buy_share );
                }
            }
            buy_and_sell[0] = buy;
            buy_and_sell[1] = sell;
            return buy_and_sell;
        }
        StartingAlgorithm();
        StartingAlgorithm( double buy_point, double sell_point, double volume_ratio );

    private:
        map<string, Market_Record> symbol_records_;
        double metric_hard_buy_point_;
        double metric_hard_sell_point_;
        double buy_price_volume_ratio_;
        
        // TODO:
        void update_metric(
            Market_Record record,
            float funds,
            float price_update,
            map<string, Share> portfolio,
            long time);
        float calculate_volatility(Market_Record record);
        float calculate_growth(Market_Record record);
        int   recommend_buy_volume( Market_Record record, float current_funds );

        bool  consider_sell_share(Market_Record share_record){
            if( share_record.get_current_value() > metric_hard_buy_point_ ) return true;
            else return false;
        }
        bool  consider_buy_share(Market_Record share_record){
            if( share_record.get_current_value() < metric_hard_sell_point_ ) return true;
            else return false;
        }

};
