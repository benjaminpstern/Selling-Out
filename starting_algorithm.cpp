/* starting_algorithm
* Updates a simple metric to consider volatility, growth and curvature
* to decide how to invest.
*/

#include "starting_algorithm.h"

// Constructors, Setting, Getting

StartingAlgorithm::StartingAlgorithm( double buy_point, double sell_point, double volume_ratio ) : symbol_records_() {
    metric_hard_buy_point_ = buy_point;
    metric_hard_sell_point_ = sell_point;
    buy_price_volume_ratio_ = volume_ratio;
}

StartingAlgorithm::StartingAlgorithm( void ) {
    StartingAlgorithm( 10.0, 0.0, 0.3);
}

// Metric Math
void StartingAlgorithm::update_metric( 
    Market_Record record,
    float funds,
    float price_update,
    std::map<std::string, Share> portfolio,
    long time)
{
    // Update Record, shift appropriate datasets
    week_data = record.get_week_data();
    hour_data = record.get_hour_data();
    if( time - record.previous_time_ > 900 ) {
        week_data.erase(week_data.begin());
        week_data.push_back(price_update);
    }
    hour_data.erase(hour_data.begin());
    hour_data.push_back(price_update);
}
