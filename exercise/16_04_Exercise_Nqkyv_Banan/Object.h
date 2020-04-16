#ifndef INC_16_04_EXERCISE_1_OBJECT_H
#define INC_16_04_EXERCISE_1_OBJECT_H

#include <iostream>

class Object {
protected:
    int weight;
    int width;
    int length;
    int height;
public:
    Object(int = 0, int = 0, int = 0, int = 0);
    void print();
};


#endif //INC_16_04_EXERCISE_1_OBJECT_H
