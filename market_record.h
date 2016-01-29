/* Market Record
* Record for a symbol over a period of time. For use with algorithm records.
*/

#ifndef MARKET_H
#define MARKET_H

#include <vector>

class Market_Record
{
    private:
        std::vector<float> hour_data_;
        std::vector<float>  week_data_;
        double  last_value_;
        double  current_value_;
        long    previous_time_;

    public:
        Market_Record();
        std::vector<float>  get_hour_data();
        std::vector<float>  get_week_data();
        void    set_hour_data( std::vector<float> h_data );
        void    set_week_data( std::vector<float> w_data );
        double  get_last_value();
        double  get_current_value();
        void    set_last_value( double val );
        void    set_current_value( double val);
        ~Market_Record();
};

#endif
