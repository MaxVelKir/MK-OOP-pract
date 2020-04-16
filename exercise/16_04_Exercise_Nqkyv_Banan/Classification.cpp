#include "Classification.h"

Classification::Classification(const char * _category, float _price, unsigned _barcode) : price(_price), barcode(_barcode) {
    category = new char[strlen(_category) + 1];
    strcpy(category, _category);
}

Classification::~Classification() {
    delete [] category;
}

void Classification::print() {
    std::cout << "Category: " << category << '\n'
              << "Price: " << price << '\n'
              << "Barcode: " << barcode << std::endl;
}
