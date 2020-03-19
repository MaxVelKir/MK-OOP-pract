#ifndef INC_19_03_EXERCISE_HOMEOFFICE_H
#define INC_19_03_EXERCISE_HOMEOFFICE_H
#include "Employee.h"

class HomeOffice {
    int size;
    int curr = 0;
    Employee *employees;
public:
    HomeOffice();

    void newEmployee(Employee NEW);
    void resize();

    void print();
};


#endif //INC_19_03_EXERCISE_HOMEOFFICE_H
