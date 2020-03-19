#include "HomeOffice.h"
#include <iostream>

HomeOffice::HomeOffice() {
    size = 5;
    employees = new Employee[size];
}

void HomeOffice::resize() {
        Employee *arr1 = new Employee[size + 5];
        for (int i = 0; i < size; ++i) {
            arr1[i] = employees[i];
        }
        delete []employees;

        size =+ 5;
        employees = arr1;
}

void HomeOffice::newEmployee(Employee NEW) {
    if (curr == size)
        resize();

    employees[curr] = NEW;
    curr++;
}

void HomeOffice::print() {
    for (int i = 0; i < size; ++i) {
        employees[i].print();
    }
}