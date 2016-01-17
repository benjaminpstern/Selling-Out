/* Share Header
* Header for declaration of the share class.
*/

#ifndef IOSTREAM
#include <iostream>
#endif

#ifndef SHARE_H
#define SHARE_H

#include <string>
using namespace std;

class Share
{
    private:
        float  value_bought_;  // Value bought at
        long   time_bought_;   // Time (epoch) bought at.
        int    volume_bought_; // Number of shares bought.
        string symbol_;        // Symbol of the stock.
    public:
        Share(string sym, float va, int vo, long ti); // Constructor
        void setValues(string sym, float va, int vo, long ti); // Setter
        float getBuyPrice();       // Get for "value".
        long  getBuyTime();        // Get for "time".
        string getSymbol();        // Get for "symbol".
        int   getBuyVolume();      // Get for "volume".
        void  add_shares(float va, int vo, long ti);
        float sub_shares(float va, int vo, long ti);
};

/*
 * for printing Shares.
 */

inline std::ostream& operator<<(std::ostream &strm, Share s) {
      return strm << s.getBuyVolume() << " Shares of " << s.getSymbol() << " bought for " << s.getBuyPrice() << " each";
}
#endif
