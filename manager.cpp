/* Manager.cpp
*  Manages market and player data for a set of algorithms.
*/

#include "manager.h"

// Begin internal function definitions.
Manager::Manager( void ){
    
}

void Manager::set_initial_conditions(float rox, float cox, std::string file){
    rate_of_exchange_ = rox;
    cost_of_exchange_ = cox;
    current_filename_ = file;
}
