#include <iostream>
#include <fstream>

#include "WashingMachines.h"
#include "ArrayOfWM.h"

using namespace std;

void bestWM(ArrayOfWM &temp) {
    int BestMachine = 0;
    for (int i = 0; i < temp.getCurr() - 1; ++i) {
        if(temp.getWM(i) > temp.getWM(BestMachine)) BestMachine = i;
    }

    ofstream file_out("Out.txt");

    file_out << temp.getWM(BestMachine).getManufacturer() << " " << temp.getWM(BestMachine).getModel();

    file_out.close();

}


int main() {

    ArrayOfWM a;
    a.addWashingMachines();
    bestWM(a);

}
