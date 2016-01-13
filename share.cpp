// Share.cpp
// Class that represents a market share.
//

#include <stdio.h>
#include "share.h"

// Member Function Definitions
Share::Share(float va, int vo, long ti, int da){
    setValues(va, vo, ti, da);
}

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
    Share share(0.01,100,1452632425,01112016);
    printf("Old Price: %f\n",share.getBuyPrice());
    printf("New Price: %f\n",.76);
    printf("Selling for a return of: %f\n",share.getReturn(0.76));
}
