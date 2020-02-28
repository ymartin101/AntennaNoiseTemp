# Antenna Noise Temperature

Finds the antenna noise temperature [K] for a receiver with a specific centre frequency [GHz] between 10 MHz and 100 GHz.

This C++ class is based on the noise temperature curves detailed in Figures 2 and 3 in:

https://www.itu.int/dms_pubrec/itu-r/rec/p/R-REC-P.372-13-201609-S!!PDF-E.pdf

Note that the "main.cpp" file makes use of a 1 GHz centre frequency as an example, with all external noise sources enabled. Users may choose to enable noise temperatures from manmade, galactic, cosmic, quiet sun, and sky sources. Each of the computed noise temperatures are determined using interpolation along the curves specified by several sample points for each noise source.
