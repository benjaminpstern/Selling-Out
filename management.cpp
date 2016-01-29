/* Management.h
* Manages buying and selling shares, works with
* feed and implements abstract algorithms.
*/

#include "management.h"

Manager::Manager(float rate_of_exchange, float cost_of_exchange) : players_(), prices_(), current_fstream_() {
    rate_of_exchange_ = rate_of_exchange;
    cost_of_exchange_ = cost_of_exchange;
    current_fstream_.open("dataFiles/chunk0.data", std::ifstream::in);
    current_filenum_ = 1;
    current_linenum_ = 0;
    eof_ = false;
}
void Manager::progress_one_timestep(void) {
    string next_line = get_line();
    if (!eof()) {
        parse_line_feed(get_line());
        for (vector<PlayerInterface*>::size_type iter = 0; iter < players_.size(); ++iter) {
            progress_player(*players_[iter]);
        }
    }
}

void Manager::progress_player(PlayerInterface& player) {
    player.execute_trades(prices_, current_time_);
}

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

bool Manager::eof(void) {
    return eof_;
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

void Manager::parse_line_feed(string feed) {
    vector<string> feed_split = split(feed, ',');
    if (!feed_split.size()) {
        eof_ = true;
        return;
    }
    string time_str = feed_split[0];
    stringstream ss(time_str);
    ss >> current_time_;

    for (vector<string>::size_type i = 1; i < feed_split.size(); ++i) {
        vector<string> pair = split(feed_split[i], ':');
       string name = pair[0];
       string value_str = pair[1];
       stringstream floatconverter(value_str);
        float value;
        floatconverter >> value;
        prices_[name] = value;
    }
}
void Manager::set_prices(map<string, float> prices) {
    prices_ = prices;
}
const map<string, float>& Manager::get_prices(void) {
    return prices_;
}
long Manager::get_time(void) {
    return current_time_;
}
float Manager::get_assets(PlayerInterface& player) {
    map<string, Share> player_shares = player.get_portfolio();
    float player_funds = player.get_current_funds();
    float share_values = 0;
    for (map<string, Share>::iterator iter = player_shares.begin(); iter != player_shares.end(); ++iter) {
        Share share = (*iter).second;
        string symbol = share.getSymbol();
        float price = prices_.at(symbol);
        share_values += price * share.getBuyVolume();
    }
    return player_funds + share_values;
}

string Manager::get_line() {
    if (eof()) {
        return "";
    }
    string line;
    if (!(current_fstream_ >> line)) {
        current_fstream_.close();
        string new_filename = "dataFiles/chunk";
        new_filename += std::to_string(current_filenum_);
        new_filename += ".data";
        if(current_filenum_ < 50) {
            current_fstream_.open(new_filename, std::ifstream::in);
            current_filenum_++;
            current_linenum_ = 0;
            if (!(current_fstream_ >> line)) {
                return "";
            }
        }
        else {
            eof_ = true;
            return "";
        }
    }
    current_linenum_++;
    return line;
}

void Manager::add_player(PlayerInterface* player_ptr) {
    players_.push_back(player_ptr);
}

int Manager::file_num() {
    return current_filenum_;
}
