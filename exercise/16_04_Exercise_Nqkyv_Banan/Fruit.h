#ifndef INC_16_04_EXERCISE_1_FRUIT_H
#define INC_16_04_EXERCISE_1_FRUIT_H

#include <iostream>

#include "Eatable.h"

class Fruit : public Eatable {
protected:
    float calories;
    float protein;
    float carbohydrates;
    float fat;
public:
    Fruit(float = 0, float = 0, float = 0, float = 0, Taste = SWEET);
    void print();
};


#endif //INC_16_04_EXERCISE_1_FRUIT_H
