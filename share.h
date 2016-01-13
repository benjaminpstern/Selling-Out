/* Share Header
* Header for declaration of the share class.
*/

#ifndef SHARE_H
#define SHARE_H

class Share
{
    private:
        float value;  // Value bought at
        long  time;   // Time (epoch) bought at.
        int   date;   // Date (MMDDYYYY) bought at.
        int   volume; // Number of shares bought.
    public:
        Share(float va, int vo, long ti, int da); // Constructor
        void setValues(float va, int vo, long ti, int da); // Setter
        float getReturn(float va); // Return on investment.
        float getBuyPrice();       // Get for "value".
        long  getBuyTime();        // Get for "time".
        int   getBuyDate();        // Get for "date".
        int   getBuyVolume();      // Get for "volume".
};

#endif
