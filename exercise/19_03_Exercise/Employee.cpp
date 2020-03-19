#include "Employee.h"
#include <cstring>
#include <iostream>

Employee::Employee() {
    strcpy(this->firstName, "\0");
    strcpy(this->lastName, "\0");
    strcpy(this->position, "\0");
}

void Employee::newFirstName(char *firstName) {
    strcpy(this->firstName, firstName);
}

void Employee::newLastName(char *lastName) {
    strcpy(this->lastName, lastName);
}

void Employee::newPosition(char *position) {
    strcpy(this->position, position);
}

void Employee::print() {
    std::cout << firstName << " " << lastName << " - " << position << std::endl;
}