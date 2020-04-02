#include "ArrayOfWM.h"

void ArrayOfWM::resize() {

    if(curr == size) {
        WashingMachines *arr2 = new WashingMachines[size * 2];
        for (int i = 0; i < curr; ++i) {
            arr2[i] = arr[i];
        }

        delete [] arr;

        size *= 2;
        arr = arr2;
    }
}

ArrayOfWM::ArrayOfWM() {
    size = 5;
    arr = new WashingMachines[size];
}

ArrayOfWM::~ArrayOfWM() {
   delete [] arr;
};

void ArrayOfWM::addWashingMachines() {
    int n;
    char manufacturer[MAX_L];
    char model[MAX_L];
    int mass;
    double elCons;
    int waterCons;

    ifstream file_in("In.txt");

    file_in >> n;

    for (int i = 0; i < n; ++i) {
        file_in.ignore();

        file_in.getline(manufacturer, MAX_L);
        file_in.getline(model, MAX_L);
        file_in >> mass;
        file_in >> elCons;
        file_in >> waterCons;

        WashingMachines a(manufacturer, model, mass, elCons, waterCons);
        resize();
        arr[curr] = a;
        curr++;
    }
}