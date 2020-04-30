#ifndef INC_30_04_EXERCISE_1_RECTANGLE_H
#define INC_30_04_EXERCISE_1_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
int a;
int b;
public:
    Rectangle(int, int);
    float getArea();
    int getPerimeter();
};


#endif //INC_30_04_EXERCISE_1_RECTANGLE_H
