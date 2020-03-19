#include <iostream>
#include "Employee.h"
#include "HomeOffice.h"


int main() {

    HomeOffice a;
    Employee b;
    b.newFirstName("Kiro");
    b.newLastName("Asenov");
    b.newPosition("pedal");

    b.print();
    a.newEmployee(b);
    a.print();

    return 0;
}
