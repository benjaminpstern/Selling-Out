/* Management.h
* Manages buying and selling shares, works with
* feed and implements abstract algorithms.
*/

#include "management.h"

Manager::Manager(float rate_of_exchange, float cost_of_exchange) {
    rate_of_exchange_ = rate_of_exchange;
    cost_of_exchange_ = cost_of_exchange;
}
void Manager::progress_one_timestep(void) {
}
void Manager::progress_player(PlayerInterface& player) {
}
void Manager::parse_line_feed(string feed) {
}
void Manager::set_prices(std::map<std::string, float> prices) {
    prices_ = prices;
}
float Manager::get_assets(PlayerInterface& player) {
    std::map<string, Share> player_shares = player.get_portfolio();
    float player_funds = player.get_current_funds();
    float share_values = 0;
    for (std::map<string, Share>::iterator iter = player_shares.begin(); iter != player_shares.end(); ++iter) {
        Share share = (*iter).second;
        string symbol = share.getSymbol();
        float price = prices_.at(symbol);
        share_values += price * share.getBuyVolume();
    }
    return player_funds + share_values;
}
