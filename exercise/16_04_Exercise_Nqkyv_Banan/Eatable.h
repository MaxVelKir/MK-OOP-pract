#ifndef INC_16_04_EXERCISE_1_EATABLE_H
#define INC_16_04_EXERCISE_1_EATABLE_H

#include <iostream>

enum Taste { SWEET, SOUR, SALT, BITTER, SAVORY };

class Eatable {
protected:
    Taste taste;
public:
    Eatable(Taste = SWEET);
    void print();
};


#endif //INC_16_04_EXERCISE_1_EATABLE_H
