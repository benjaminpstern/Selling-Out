// Market Record.cpp
// Object to hold market record data
//

#include "market_record.h"

// Member Function Definitions
Market_Record::Market_Record(){
    hour_data_[60];
    week_data_[130];
    last_value_ = 0;
    current_value_ = 0;
}

float[] get_hour_data( void ){
    return hour_data_;
}
float[] get_week_data( void ){
    return week_data_;
}

double get_last_value(){
    return last_value_;
}

double get_current_value(){
    return current_value();
}

void set_hour_data( float[] h_data_ ){
    hour_data_ = h_data_;
}

void set_week_data (float[] w_data_){
    week_data_ = w_data_;
}

void set_last_value(double val){
    last_value_ = val;
}

void set_current_value(double val){
    current_value_ = val;
}