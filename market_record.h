/* Market Record
* Record for a symbol over a period of time. For use with algorithm records.
*/

#ifndef MARKET_H
#define MARKET_H

class Market_Record
{
    private:
        float* hour_data_;
        float* week_data_;
        double  last_value_;
        double  current_value_;

    public:
        Market_Record();
        float*  get_hour_data();
        float*  get_week_data();
        void    set_hour_data( float* h_data_ );
        void    set_week_data( float* w_data_ );
        double  get_last_value();
        double  get_current_value();
        void    set_last_value( double val );
        void    set_current_value( double val);
};

#endif
