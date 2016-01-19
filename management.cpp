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

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

void Manager::parse_line_feed(string feed) {
    std::vector<std::string> feed_split = split(feed, ',');
    string time_str = feed_split[0];
    stringstream ss(time_str);
    ss >> current_time_;

    for (std::vector<std::string>::size_type i = 1; i < feed_split.size(); ++i) {
        std::vector<std::string> pair = split(feed_split[i], ':');
        string name = pair[0];
        string value_str = pair[1];
        stringstream floatconverter(value_str);
        float value;
        floatconverter >> value;
        prices_[name] = value;
    }
}
void Manager::set_prices(std::map<std::string, float> prices) {
    prices_ = prices;
}
const std::map<std::string, float>& Manager::get_prices(void) {
    return prices_;
}
long Manager::get_time(void) {
    return current_time_;
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
