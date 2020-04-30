#ifndef INC_30_04_EXERCISE_1_FIGURES_H
#define INC_30_04_EXERCISE_1_FIGURES_H

#include "Shape.h"
#include "Triangle.h"

class Figures : public Shape {
    Shape **shapes;
    int size;
    int curr;
public:
    Figures();
    ~Figures();

    Shape* operator[](int);
    void addShape(Shape *);
    void resize();
    int biggestArea();
    int biggestPerimeter();
};


#endif //INC_30_04_EXERCISE_1_FIGURES_H
