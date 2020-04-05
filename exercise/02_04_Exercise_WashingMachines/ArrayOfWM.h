#ifndef INC_02_04_EXERCISE_1_0_ARRAYOFWM_H
#define INC_02_04_EXERCISE_1_0_ARRAYOFWM_H

#include "WashingMachines.h"
#include <fstream>

class ArrayOfWM {

    WashingMachines *arr;
    int curr = 0;
    int size;

public:

    ArrayOfWM();
    ~ArrayOfWM();

    int getCurr()                 { return curr; }
    int getSize()                 { return size; }
    WashingMachines getWM(int n) { return arr[n]; }

    void addWashingMachines();

    void resize();
};


#endif //INC_02_04_EXERCISE_1_0_ARRAYOFWM_H
