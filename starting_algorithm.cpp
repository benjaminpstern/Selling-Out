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
    vector<float> week_data = record.get_week_data();
    vector<float> hour_data = record.get_hour_data();
    if( time - record.previous_time_ > 900 ) {
        week_data.erase(week_data.begin());
        week_data.push_back(price_update);
    }
    hour_data.erase(hour_data.begin());
    hour_data.push_back(price_update);

    // Calculate growth ratio
    double week_growth_metric = this->assess_growth_metric( week_data );
    double hour_growth_metric = this->assess_growth_metric( hour_data );
    double volatility = this->assess_volatility_metric( week_data );
    
    // Set Metric Value
    // TODO: Update this to refine algorithm or contribute to complexity.
    double last_metric_value = record.get_last_value();
    record.set_current_value( last_metric_value*0.1 + week_growth_metric + hour_growth_metric - volatility );
    record.set_last_value( last_metric_value );
}

double StartingAlgorithm::assess_volatility_metric( vector<float> volatile_data )
{
    // Currently this will be very simple/stupid/awful, count of local minima/maxima
    // TODO: when/if we implement industry affiliation, compare to industry

    float previous_value = 0.0;
    int number_of_changes = 0;
    for(unsigned i=0; i < volatile_data.size()-1; i++){
        if( volatile_data.at(i) < previous_value && volatile_data.at(i) <= volatile_data.at(i+1) ){
            number_of_changes++;
        }else if ( volatile_data.at(i) > previous_value && volatile_data.at(i) >= volatile_data.at(i+1) ){
            number_of_changes++;
        }
        previous_value = volatile_data.at(i);
    }
    return 0.15*number_of_changes;
}




