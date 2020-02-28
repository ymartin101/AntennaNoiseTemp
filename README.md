# Antenna Noise Temperature

Finds the antenna noise temperature [K] for a receiver with a specific centre frequency [GHz] between 10 MHz and 100 GHz.

This C++ class is based on the noise temperature curves detailed in:

https://www.itu.int/dms_pubrec/itu-r/rec/p/R-REC-P.372-13-201609-S!!PDF-E.pdf

Note that the "main.cpp" file makes use of an example of a 1 GHz centre frequency, with all external noise sources enabled. Users may choose to enable noise temperatures from manmade, galactic, cosmic, quiet sun, and sky sources.
