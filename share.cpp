// Share.cpp
// Class that represents a market share.
//

#include <stdio.h>

class Share {
    public:
        float value;  // Value bought at
        long  time;   // Time (epoch) bought at.
        int   date;   // Date (MMDDYYYY) bought at.
        int   volume; // Number of shares bought.
        void setValues(float va, int vo, long ti, int da);  // Constructor.
        float getReturn(float va); // Return on investment.
        float getBuyPrice();    // Get for "value".
        long  getBuyTime();     // Get for "time'.
        int   getBuyDate();     // Get for "date".
        int   getBuyVolume();   // Get for "volume".
};

// Member Function Definitions

void Share::setValues(float va, int vo, long ti, int da){
    value = va;
    volume = vo;
    time = ti;
    date = da;
}

// Getter Functions
float Share::getBuyPrice( void ){
    return value;
}
long Share::getBuyTime( void ){
    return time;
}
int Share::getBuyVolume( void ){
    return volume;
}
int Share::getBuyDate( void ){
    return date;
}

// Return on investment
float Share::getReturn( float va ){
    return volume * (va - value);
}

int main(){
    Share share;
    share.setValues(0.01,100,1452632425,01112016);
    printf("Old Price: %f\n",share.getBuyPrice());
    printf("New Price: %f\n",.76);
    printf("Selling for a return of: %f\n",share.getReturn(0.76));
}
