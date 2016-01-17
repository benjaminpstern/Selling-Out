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

class StockAlgorithm
{
    public:
        virtual std::vector<Share>* actions(
                const std::map<std::string, float> prices,
                float current_funds,
                const std::map<std::string, Share> portfolio,
                long time) = 0;
        ~StockAlgorithm() {
        }
};

#endif
