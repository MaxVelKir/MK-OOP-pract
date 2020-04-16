#ifndef INC_16_04_EXERCISE_1_PRODUCT_H
#define INC_16_04_EXERCISE_1_PRODUCT_H

#include <iostream>

#include "Object.h"
#include "Classification.h"

class Product : public Object, public Classification {
public:
    Product(const char* = "<unknown", float = 0, unsigned = 0, int = 0, int = 0, int = 0, int = 0);

    double getVolumetriWeight();
    double getPricePerWeight();
    double getPricePerVolume();

    void print();
};


#endif //INC_16_04_EXERCISE_1_PRODUCT_H
