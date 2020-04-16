#ifndef INC_16_04_EXERCISE_1_CLASSIFICATION_H
#define INC_16_04_EXERCISE_1_CLASSIFICATION_H

#include <iostream>
#include <cstring>

class Classification {
protected:
    float price;
    unsigned barcode;
    char* category;
public:
    Classification(const char* = "<unknown", float = 0, unsigned = 0);
    ~Classification();
    void print();
};


#endif //INC_16_04_EXERCISE_1_CLASSIFICATION_H
