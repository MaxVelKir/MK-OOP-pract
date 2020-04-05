#include "WashingMachines.h"

WashingMachines::WashingMachines() {
    strcpy(manufacturer, "\0");
    strcpy(model, "\0");
    mass = 0;
    elCons = 0;
    waterCons = 0;
}

WashingMachines::WashingMachines(const char * manufacturer, const char * model, int mass, double elCons, int waterCons) {
    strcpy(this->manufacturer, manufacturer);
    strcpy(this->model, model);
    this->mass = mass;
    this->elCons = elCons;
    this->waterCons = waterCons;
}

bool WashingMachines::operator>(WashingMachines const &temp) {
    int counter = 0;
    if(this->mass > temp.mass)
        counter++;
    if(this->elCons < temp.elCons)
        counter++;
    if(this->waterCons < temp.waterCons)
        counter++;

    return counter >= 2;
}