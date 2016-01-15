/* Manager Header
*  Header for the manager class.
*/

#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <vector>
#include <map>
#include "share.h"
#include "stock-algorithm.h"
#include "player.h"

class Manager
{
    public:
        void progress_one_timestep();
    private:
        Player[]    players_;
        std::map<std::string,float> prices_;
        float       rate_of_exchange_;
        float       cost_of_exchange_;
        long        current_time_;
        std::string current_filename_;
        void        set_initial_conditions(float rox, float cox, std::string file);
        void        progress_player(Player player);
        void        parse_line_feed(std::string feed);
        void        execute_player_trades(Player player, std::vector* buy, std::vector* sell);
};

#endif
