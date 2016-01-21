// Share.cpp
// Class that represents a market share.
//

#include <stdio.h>
#include "share.h"

// Member Function Definitions
Share::Share(std::string sym, float va, int vo, long ti){
    setValues(sym, va, vo, ti);
}

void Share::setValues(std::string sym, float va, int vo, long ti){
    symbol_ = sym;
    value_bought_ = va;
    volume_bought_ = vo;
    time_bought_ = ti;
}

void Share::add_shares(float va, int vo, long ti){
    value_bought_ = va;
    volume_bought_ += vo;
    time_bought_ = ti;
}

float Share::sub_shares(float va, int vo, long ti){
    volume_bought_ -= vo;
    time_bought_ = ti;
    return va*vo;
}

// Getter Functions
float Share::getBuyPrice( void ){
    return value_bought_;
}
long Share::getBuyTime( void ){
    return time_bought_;
}
int Share::getBuyVolume( void ){
    return volume_bought_;
}
std::string Share::getSymbol( void ){
    return symbol_;
}

/*
int main(){
    Share share("LOL",0.01,100,1452632425);
    printf("Old Price: %f\n",share.getBuyPrice());
    printf("New Price: %f\n",.76);
    printf("Selling for a return of: %f\n",share.sub_shares(.76,100,1452632466));
}*/
