/* Management.cpp
* Manages buying and selling shares, works with
* feed and implements abstract algorithms.
*/

#include <stdio.h>
#include <map>
#include "share.h"

int main(int argc, char *argv[]){
    // Hash map with <Symbol, Share>
    //std::map<std::string, Share> investments;

    float funds;
}

/*
* Buy Shares
* > Symbol of stock
* > Volume of shares
* > Price of shares
* < Integer indicating success (0)
*/
int buyShares( string sym, int vol, float cost ){
    if ( vol * cost > funds ) {
        return 1
    } else{
        // TODO: get time, date, and store share in hash map.
        time=0;
        date=0;
        Share invested_shares(cost,vol,time,date);
        funds = funds - vol*cost;
        return 0
    }
}
