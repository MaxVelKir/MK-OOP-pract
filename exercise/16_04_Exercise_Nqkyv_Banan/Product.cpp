#include "Product.h"

Product::Product(const char * _category, float _price, unsigned _barcode, int _weight, int _width, int _length, int _height) :
Classification(_category, _price, _barcode),
Object(_weight, _width, _length, _height) {}

double Product::getVolumetriWeight() {
    return width * height * length;
}

double Product::getPricePerWeight() {
    return price / weight;
}

double Product::getPricePerVolume() {
    return price / getVolumetriWeight();
}

void Product::print() {
    Classification::print();
    Object::print();
}