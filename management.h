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

class Manager {
    public:
        Manager(float rate_of_exchange, float cost_of_exchange);
        void progress_one_timestep(void);
        void set_prices(std::map<std::string, float> prices);
        float get_assets(Player& player);
        

    private:
        Player* players_;
        std::map<std::string, float> prices_;
        float cost_of_exchange_;
        float rate_of_exchange_;
        long current_time_;
        string current_filename_;
        void progress_player(Player player);
        void parse_line_feed(string feed);
};
