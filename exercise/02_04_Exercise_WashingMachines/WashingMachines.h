#ifndef INC_02_04_EXERCISE_1_0_WASHINGMACHINES_H
#define INC_02_04_EXERCISE_1_0_WASHINGMACHINES_H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const int MAX_L = 32;

class WashingMachines {

    char manufacturer[MAX_L];
    char model[MAX_L];
    int mass;
    double elCons;
    int waterCons;

public:

    WashingMachines();
    ~WashingMachines() = default;

    WashingMachines(const char*, const char*, int, double, int);

    char* getManufacturer() { return manufacturer; }
    char* getModel()        { return model;        }
    int getMass()           { return mass;         }
    double getElCons()      { return elCons;       }
    int getWaterCons()      { return waterCons;    }

    bool operator>(const WashingMachines &);
};


#endif //INC_02_04_EXERCISE_1_0_WASHINGMACHINES_H
