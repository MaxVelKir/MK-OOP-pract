#ifndef INC_30_04_EXERCISE_1_TRIANGLE_H
#define INC_30_04_EXERCISE_1_TRIANGLE_H

#include "Shape.h"
#include <cmath>

class Triangle : public Shape {
int a;
int b;
int c;
public:
    Triangle(int, int, int);
    float getArea();
    int getPerimeter();
};


#endif //INC_30_04_EXERCISE_1_TRIANGLE_H
