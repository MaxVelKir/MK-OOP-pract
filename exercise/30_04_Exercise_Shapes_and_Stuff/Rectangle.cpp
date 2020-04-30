#include "Rectangle.h"

Rectangle::Rectangle(int a, int b) {
    this->a = a;
    this->b = b;
}

float Rectangle::getArea() {
    return a * b;
}

int Rectangle::getPerimeter() {
    return 2 * a + 2 * b;
}