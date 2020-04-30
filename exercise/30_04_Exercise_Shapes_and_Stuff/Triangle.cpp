#include "Triangle.h"

Triangle::Triangle(int a, int b, int c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

float Triangle::getArea() {
    float p = (float)(a + b + c) / 2;
    return sqrt(p * (p - (float)a) * (p - (float)b) * (p - (float)c));
}

int Triangle::getPerimeter() {
    return a + b + c;
}