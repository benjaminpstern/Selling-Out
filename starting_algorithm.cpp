/* starting_algorithm
* Updates a simple metric to consider volatility, growth and curvature
* to decide how to invest.
*/

#include "starting_algorithm.h"

// Constructors, Setting, Getting
StartingAlgorithm::StartingAlgorithm( void ) : symbol_records_() {
    metric_hard_buy_point_ = 10.0;
    metric_hard_sell_point_ = 0.0;
    buy_price_volume_ratio_ = 0.3; 
}


