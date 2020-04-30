#include "Figures.h"

Figures::Figures() {
    size = 1;
    curr = 0;
    shapes = new Shape*[size];
}

Figures::~Figures() {
    delete [] shapes;
}

Shape* Figures::operator[](int n) {
    return shapes[n];
}

void Figures::addShape(Shape* temp) {
    resize();
    shapes[curr++] = temp;
}

void Figures::resize() {
    if(curr == size) {
        Shape **arr = new Shape*[size + 1];
        for (int i = 0; i < curr; ++i) {
            arr[i] = shapes[i];
        }
        delete [] shapes;
        size++;
        shapes = arr;
    }
}

int Figures::biggestArea() {
    int counter = 0;
    for (int i = 1; i < curr; ++i) {
        if(shapes[i]->getArea() > shapes[counter]->getArea())
            counter = i;
    }
    return counter;
}

int Figures::biggestPerimeter() {
    int counter = 0;
    for (int i = 1; i < curr; ++i) {
        if(shapes[i]->getPerimeter() > shapes[counter]->getPerimeter())
            counter = i;
    }
    return counter;
}