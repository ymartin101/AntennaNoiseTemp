#ifndef ANTENNA_TEMP_H
#define ANTENNA_TEMP_H

class antenna_temp
{
    private:
        double ant_temp;

    public:
        antenna_temp();
        antenna_temp(double output);

        // Temperature function
        double get_temp(double carrier, int manmade, int galactic, int cosmic, int sun, int sky);

    protected:

};

#endif // ANTENNA_TEMP_H
