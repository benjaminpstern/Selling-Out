#ifndef STOCK_ALGORITHM_H
#include "stock-algorithm.h"
#endif

#ifndef STRING
#include <string>
#endif

#ifndef VECTOR
#include <vector>
#endif

#ifndef MAP
#include <map>
#endif

#ifndef SHARE_H
#include "share.h"
#endif

#ifndef PLAYER_INT
#define PLAYER_INT

using std::string;
using std::map;
using std::vector;

class PlayerInterface
{
    public:
        virtual void execute_trades(const map<string, float>, long time) = 0;
        virtual float get_current_funds() = 0;
        virtual float get_starting_funds() = 0;
        virtual map<string, Share> get_portfolio() = 0;
        virtual ~PlayerInterface() {}
};

#endif
