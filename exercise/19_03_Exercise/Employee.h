#ifndef INC_19_03_EXERCISE_EMPLOYEE_H
#define INC_19_03_EXERCISE_EMPLOYEE_H

#include <cstring>

class Employee {
    char firstName[20];
    char lastName[20];
    char position[20];
public:
    Employee();

    void newFirstName(char* firstName);
    void newLastName(char* lastName);
    void newPosition(char* position);

    void print();
};


#endif //INC_19_03_EXERCISE_EMPLOYEE_H
