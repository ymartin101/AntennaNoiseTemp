/// Find the antenna noise temperature for a receiver with centre frequency "carrier" [GHz]

#include "antenna_temp.h"

antenna_temp::antenna_temp()
{
}

antenna_temp::antenna_temp(double output)
{
    ant_temp = output;
}

double antenna_temp::get_temp(double carrier, int manmade, int galactic, int cosmic, int sun, int sky)
{
    // If any external noise is included, find the frequency limits
    int i1, i2 = 0;
    double fc_range [] = {0.01,0.02,0.05,0.08,0.1,0.2,0.5,0.9,1,1.4,2,2.8,5,6.2,10,16,20,24,30,40,50,60,70,80,90,100}; // Carrier frequency range (10 MHz to 100 GHz)

    if (manmade == 1 || galactic == 1 || cosmic == 1 || sky == 1 || sun == 1){

        // Find Fc within range
        for (int i = 0; i < (int(sizeof(fc_range)/sizeof(fc_range[0])) - 1); i++){
            if (fc_range[i] <= carrier && fc_range[i+1] >= carrier){   // Find the array entry range within which the carrier resides
                i1 = i;
                i2 = i + 1;
            }
        }
    }

    // Find the temperature for each noise source using linear interpolation; only apply if both top and bottom of range is non-zero

    // Add manmade noise
    if (manmade == 1){
        double noise_manmade [] = {29000000, 5786260.713, 578626.0713, 145344.2978, 45961.90258, 10289.58829, 3253.853517, 1829.776299,
                                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        if (noise_manmade[i1] != 0 && noise_manmade[i2] != 0){
            ant_temp += ((carrier - fc_range[i1])/(fc_range[i2] - fc_range[i1]))*(noise_manmade[i2] - noise_manmade[i1]) + noise_manmade[i1];       // Manmade
        }
    }

    // Add galactic noise for worst-case
    if (galactic == 1){
        double noise_galcentre [] = {365088.3694, 72844.70651, 11545.10795, 3650.883694, 3253.853517, 728.4470651, 91.70605214,
                                        23.03551881, 18.29776299, 10.28958829, 5.786260713, 4.596190258,
                                        0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        if (noise_galcentre[i1] != 0 && noise_galcentre[i2] != 0){
            ant_temp += ((carrier - fc_range[i1])/(fc_range[i2] - fc_range[i1]))*(noise_galcentre[i2] - noise_galcentre[i1]) + noise_galcentre[i1]; // Galactic centre
        }
    }

    // Add quiet sun noise
    if (sun == 1){
        double noise_quiet_sun [] = {0,0,0,0, 728447.0651, 515701.0289, 230355.1881, 163078.9843, 129538.2417, 91706.05214,
                                    64922.91302, 45961.90258, 20530.42775, 16307.89843, 11545.10795, 8173.310501,
                                    7284.470651, 6492.291302, 5786.260713, 5157.010289, 4596.190258, 4596.190258,
                                    4596.190258, 4596.190258, 4596.190258, 4596.190258};
        if (noise_quiet_sun[i1] != 0 && noise_quiet_sun[i2] != 0){
            ant_temp += ((carrier - fc_range[i1])/(fc_range[i2] - fc_range[i1]))*(noise_quiet_sun[i2] - noise_quiet_sun[i1]) + noise_quiet_sun[i1]; // Quiet sun
        }
    }

    // Add atmospheric noise for worst-case (i.e. horizontal)
    if (sky == 1){
        double noise_sky_hor [] = {4596190.258, 18297.76299, 0,0,0,0,0, 57.86260713, 64.92291302, 72.84470651, 81.73310501, 102.8958829, 115.4510795,
                                129.5382417, 145.3442978, 182.9776299, 230.3551881, 290, 290, 290, 290, 290, 290, 290, 290, 290};
        if (noise_sky_hor[i1] != 0 && noise_sky_hor[i2] != 0){
            ant_temp += ((carrier - fc_range[i1])/(fc_range[i2] - fc_range[i1]))*(noise_sky_hor[i2] - noise_sky_hor[i1]) + noise_sky_hor[i1];       // Sky horizontal
        }
    }

    // Add cosmic noise
    if (sky == 1){
        double noise_cosmic [] = {0,0,0,0,0,0,0,0,0, 2.7,2.7,2.7,2.7,2.7,2.7,2.7,
                                    0,0,0,0,0,0,0,0,0,0};
        if (noise_cosmic[i1] != 0 && noise_cosmic[i2] != 0){
            ant_temp += ((carrier - fc_range[i1])/(fc_range[i2] - fc_range[i1]))*(noise_cosmic[i2] - noise_cosmic[i1]) + noise_cosmic[i1];          // Cosmic
        }
    }

    return ant_temp;
}
