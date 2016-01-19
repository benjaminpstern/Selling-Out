/* Management.h
* Manages buying and selling shares, works with
* feed and implements abstract algorithms.
*/

#ifndef MAP
#include <map>
#endif

#ifndef SHARE_H
#include "share.h"
#endif

#ifndef PLAYER_H
#include "player.h"
#endif

#ifndef IOSTREAM
#include <iostream>
#endif

#ifndef SSTREAM
#include <sstream>
#endif

#ifndef VECTOR
#include <vector>
#endif

class Manager {
    public:
        Manager(float rate_of_exchange, float cost_of_exchange);
        void progress_one_timestep(void);
        void set_prices(std::map<std::string, float> prices);
        float get_assets(PlayerInterface& player);
        const std::map<std::string, float>& get_prices(void);
        long get_time(void);
        void parse_line_feed(string feed);
        

    private:
        Player* players_;
        std::map<std::string, float> prices_;
        float cost_of_exchange_;
        float rate_of_exchange_;
        long current_time_;
        string current_filename_;
        void progress_player(PlayerInterface& player);
};
