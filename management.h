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

#ifndef FSTREAM
#include <fstream>
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
        void parse_line_feed(std::string feed);
        bool eof(void);
        void add_player(PlayerInterface* player_ptr);
        int file_num();

    private:
        std::vector<PlayerInterface*> players_;
        std::map<std::string, float> prices_;
        float cost_of_exchange_;
        float rate_of_exchange_;
        long current_time_;
        int current_filenum_;
        int current_linenum_;
        std::ifstream current_fstream_;
        void progress_player(PlayerInterface& player);
        std::string get_line();
        bool eof_;
};
