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

#ifndef STOCK_ALGORITHM_H
#define STOCK_ALGORITHM_H

using std::string;
using std::map;
using std::vector;
class StockAlgorithm
{
    public:
        virtual vector<Share>* actions(
                const map<string, float> prices,
                float current_funds,
                const map<string, Share> portfolio,
                long time) = 0;
        ~StockAlgorithm() {
        }
};

#endif
