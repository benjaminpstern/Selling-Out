// Market Record.cpp
// Object to hold market record data
//

#include "market_record.h"

// Member Function Definitions
Market_Record::Market_Record() : hour_data_(60,0), week_data_(130,0) {
    last_value_ = 0;
    current_value_ = 0;
}

std::vector<float> Market_Record::get_hour_data( void ){
    return hour_data_;
}
std::vector<float> Market_Record::get_week_data( void ){
    return week_data_;
}

double Market_Record::get_last_value(){
    return last_value_;
}

double Market_Record::get_current_value(){
    return current_value_;
}

void Market_Record::set_hour_data( std::vector<float> h_data ){
    hour_data_ = h_data;
}

void Market_Record::set_week_data (std::vector<float> w_data){
    week_data_ = w_data;
}

void Market_Record::set_last_value(double val){
    last_value_ = val;
}

void Market_Record::set_current_value(double val){
    current_value_ = val;
}

Market_Record::~Market_Record() {
    delete[] hour_data_;
    delete[] week_data_;
}
