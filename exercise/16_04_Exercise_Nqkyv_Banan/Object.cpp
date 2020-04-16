#include "Object.h"

Object::Object(int _weight, int _width, int _length, int _height) {
    weight = _weight;
    width = _width;
    length = _length;
    height = _height;
}

void Object::print() {
    std::cout << "Weight: " << weight << '\n'
              << "Width: " << width << '\n'
              << "Length: " << length << '\n'
              << "Height: " << height << std::endl;
}