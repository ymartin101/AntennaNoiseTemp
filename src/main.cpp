#include "antenna_temp.h"
#include <iostream>

using namespace std;

int main() {
    antenna_temp *Temp = new antenna_temp(0);
    double output = Temp->get_temp(1, 1, 1, 1, 1, 1);
    cout << output;
    return 0;
}
