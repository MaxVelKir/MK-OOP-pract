#ifndef INC_16_04_EXERCISE_1_BANANA_H
#define INC_16_04_EXERCISE_1_BANANA_H

#include "Fruit.h"
#include "Product.h"

class Banana : public Fruit, public Product {
public:
    Banana(const char* = "<unknown", float = 0, unsigned = 0, int = 0, int = 0, int = 0, int = 0, float = 0, float = 0, float = 0, float = 0, Taste = SWEET);

    double getPricePerCalories();
    double getFatWeight();

    void print();
};


#endif //INC_16_04_EXERCISE_1_BANANA_H
