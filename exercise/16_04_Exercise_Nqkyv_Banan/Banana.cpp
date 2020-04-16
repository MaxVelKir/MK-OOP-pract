#include "Banana.h"

Banana::Banana(const char * _category, float _price, unsigned _barcode, int _weight, int _width, int _length, int _height, float _calories, float _protein, float _carbohydrates, float _fat, Taste taste) :
Product(_category, _price, _barcode, _weight, _width, _length, _height),
Fruit(_calories, _protein, _carbohydrates, _fat, taste)
{}

double Banana::getPricePerCalories() {
    return price / calories;
}

double Banana::getFatWeight() {
    return fat / weight;
}

void Banana::print() {
    Product::print();
    Fruit::print();
}