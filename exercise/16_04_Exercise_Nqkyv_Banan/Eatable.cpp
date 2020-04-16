#include "Eatable.h"

Eatable::Eatable(Taste temp) {
    taste = temp;
}

void Eatable::print() {
    switch(taste) {
        case SWEET: std::cout << "SWEET";
            break;
        case SOUR: std::cout << "SOUR";
            break;
        case SALT: std::cout << "SALT";
            break;
        case BITTER: std::cout << "BITTER";
            break;
        case SAVORY: std::cout << "SAVORY";
            break;
    }
}

