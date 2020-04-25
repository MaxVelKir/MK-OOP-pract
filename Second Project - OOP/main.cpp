#include <iostream>
#include <cstring>
#include <fstream>

#include "Vector.h"
#include "Product.h"
#include "Date.h"
#include "Location.h"

using namespace std;

void print(Vector<Product> &warehouse) {
    int count = warehouse.getCurr();
    Vector<Product> temp;

    for (int k = 0; k < count; ++k) {
        cout << warehouse[k];
    }

    bool isUnique = true;
    int counter = 0;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            if(strcmp(warehouse[i].getName(), temp[j].getName()) == 0) {
                temp[j].addQuantity(warehouse[i].getQuantity());
                isUnique = false;
            }
        }
        if(isUnique) {
            temp[counter++] = warehouse[i];
            isUnique = true;
        }
    }

    for (int j = 0; j < counter; ++j) {
        cout << temp[j].getName() << " - " << temp[j].getQuantity() << " in total" << '\n';
    }
}

Location checkPosition(Vector<Product> &warehouse, int count) {
    Location temp;
    if(count == 0)
        temp.setLocation(1, 1, 0, 0);
    else
        temp = warehouse[count - 1].getLocation()[warehouse[count - 1].getLocation().getCurr() - 1];
    return temp;
}

void add(Vector<Product> &warehouse) {
    Product tempP;
    Location tempL;
    int count = warehouse.getCurr();
    bool successful = true;

    tempL = checkPosition(warehouse, count);

    int _section = tempL.getSection();
    int _shelf = tempL.getShelf();
    int _number = tempL.getNumber();

    tempP.read();

    for (int i = 0; i < count; ++i) {
        if (tempP == warehouse[i]) {
            int tempN = warehouse[i].getLocation()[warehouse[i].getLocation().getCurr() - 1].getNumber();
            int tempSH = warehouse[i].getLocation()[warehouse[i].getLocation().getCurr() - 1].getShelf();
            int tempSE = warehouse[i].getLocation()[warehouse[i].getLocation().getCurr() - 1].getSection();
            int tempV = warehouse[i].getLocation()[warehouse[i].getLocation().getCurr() - 1].getVolume();

            if(tempP.getQuantity() < MAX_V - tempV) {
                warehouse[i].getLocation()[warehouse[i].getLocation().getCurr() - 1].setLocation(tempSE, tempSH, tempN, tempP.getQuantity() + tempV);
                warehouse[i].addQuantity(tempP.getQuantity());
                successful = false;
            }
        }
    }

    if(_number == 10) {
        if (_shelf == 10) {
            if(_section == 10) {
                cerr << "FULL WAREHOUSE!!!" << endl;
                successful = false;
            }
            else {
                _number = 1;
                _shelf = 1;
                _section++;
            }
        }
        else {
            _number = 1;
            _shelf++;
        }
    }
    else {
        _number++;
    }

    if (tempP.getQuantity() <= MAX_V && successful)
        tempP.getLocation()[0].setLocation(_section, _shelf, _number, tempP.getQuantity());
    else if (successful) {
        int stacks = tempP.getQuantity() / 50;

        int counter = 0;

        for (int j = 0; j <= stacks; ++j) {
            if (j != stacks) {
                if ((_number - 1) % 10 == 0 && _number != 1) {
                    _number = 1;
                    _shelf++;
                    if ((_shelf - 1) % 10 == 0 && _shelf != 1) {
                        _shelf = 1;
                        _section++;
                    }
                    if (_section > 10 || _shelf > 10 || _number > 10) {
                        cerr << "FULL HOUSE." << endl;
                        successful = false;
                    }
                }
                tempP.getLocation()[counter++].setLocation(_section, _shelf, _number++, MAX_V);
            }

            else if (_section <= 10) {
                if ((_number - 1) % 10 == 0 && _number != 1) {
                    _number = 1;
                    _shelf++;
                    if ((_shelf - 1) % 10 == 0 && _shelf != 1) {
                        _shelf = 1;
                        _section++;
                    }
                    if (_section > 10 || _shelf > 10 || _number > 10) {
                        cerr << "FULL HOUSE." << endl;
                        successful = false;
                    }
                }
                tempP.getLocation()[counter].setLocation(_section, _shelf, _number, tempP.getQuantity() % 50);
            }

            else {
                cerr << "FULL HOUSE." << endl;
                successful = false;
            }
        }
    }

    if(successful)
        warehouse.push(tempP);
}

void remove(Vector<Product> &warehouse) {
    char _name[MAX_L];
    int _quantity;

    cout << "Please enter name of product you want to remove: ";
    cin.getline(_name, MAX_L);
    cout << "Please enter the quantity: ";
    cin >> _quantity;

    int order[warehouse.getCurr()];
    int counter = 0;

    for (int i = 0; i < warehouse.getCurr(); ++i) {
        if(strcmp(warehouse[i].getName(), _name) == 0) {
            order[counter++] = i;
        }
    }

    Vector<Product> sorted;
    int curr = 0;

    for (int k = 0; k < counter; ++k) {
        sorted[curr++] = warehouse[order[k]];
    }

    if(counter > 1) {
        bool isSorted = false;
        do {
            isSorted = true;

            for (int i = counter - 1; i > 0; --i) {
                if (sorted[i].getExpiration() < sorted[i - 1].getExpiration()) {
                    Product temp(sorted[i - 1]);
                    sorted[i - 1] = sorted[i];
                    sorted[i] = temp;

                    isSorted = false;
                }
            }
        }
        while (!isSorted);
    }

    int stacks = _quantity / 50;

    for (int i = 0; i < counter; ++i) {
        if(sorted[i].getQuantity() > 50) {
            int counter2 = (sorted[i].getLocation()[sorted[i].getLocation().getCurr() - 1].getVolume() < 50 ? sorted[i].getLocation().getCurr() - 1 : sorted[i].getLocation().getCurr());
            for (int j = 0; j < counter2; ++j) {
                if(stacks == 0)
                    break;

                sorted[i].getLocation().pop("first");
                sorted[i].removeQuantity(50);
                stacks--;
            }

            if(stacks == 0 && sorted[i].getQuantity() >= _quantity % 50) {
                for (int j = sorted[i].getLocation().getCurr() - 1; j >= 0; --j) {
                    if(sorted[i].getLocation()[j].getVolume() >= _quantity % 50) {
                        sorted[i].getLocation()[j].removeVolume(_quantity % 50);
                        sorted[i].removeQuantity(_quantity % 50);
                        _quantity = 0;
                        if(sorted[i].getLocation()[j].getVolume() == 0)
                            sorted[i].getLocation().pop("last");
                        break;
                    }
                }
            }
        }
        else if(stacks == 0 && sorted[i].getQuantity() >= _quantity % 50) {
            for (int j = sorted[i].getLocation().getCurr() - 1; j >= 0; --j) {
                if(sorted[i].getLocation()[j].getVolume() >= _quantity % 50) {
                    sorted[i].getLocation()[j].removeVolume(_quantity % 50);
                    _quantity = 0;
                    if(sorted[i].getLocation()[j].getVolume() == 0)
                        sorted[i].getLocation().pop("last");
                    break;
                }
            }
        }
        else if(_quantity == 0)
            break;
    }

    if(_quantity == 0) {
        for (int i = 0; i < warehouse.getCurr(); ++i) {
            for (int j = 0; j < counter; ++j) {
                if(warehouse[i] == sorted[j]) {
                    warehouse[i] = sorted[j];
                }
            }
        }
        for (int l = 0; l < counter; ++l) {
            cout << sorted[l];
        }
    }
    else
        cout << "Can't remove such an amount." << endl;

}

void save(Vector<Product> &warehouse) {
    ofstream file_out("warehouse.txt", std::ios::out);
    for (int i = 0; i < warehouse.getCurr(); ++i) {
        file_out << warehouse[i];
    }
    file_out.close();
}

void log(Vector<Product> &warehouse) {
    Date In, Out;
    cout << "Please enter <from> date (years/months/days): ";
    In.read();
    cout << "Please enter <to> date (years/months/days): ";
    Out.read();
    cout << "The following items were added:" << endl;
    for (int i = 0; i < warehouse.getCurr(); ++i) {
        if(In <= warehouse[i].getIn() && Out >= warehouse[i].getIn())
            cout << " - " << warehouse[i].getName() << " : " << warehouse[i].getQuantity() << '\n';
    }
}

void clean(Vector<Product> &warehouse) {
    Date today(2020, 04, 25);
    int counter = warehouse.getCurr();
    for (int i = 0; i < counter; ++i) {
        if(warehouse[i].getExpiration() <= today) {
            warehouse.pop(i);
            i--;
            counter--;
        }
    }
}

int main() {
    Vector<Product> warehouse;

    while(true) {
        char input[MAX_L];
        cin.getline(input, MAX_L);

        if(strcmp(input, "print") == 0)
            print(warehouse);
        else if(strcmp(input, "add") == 0)
            add(warehouse);
        else if(strcmp(input, "remove") == 0)
            remove(warehouse);
        else if (strcmp(input, "log") == 0)
            log(warehouse);
        else if(strcmp(input, "clean") == 0)
            clean(warehouse);
        else if(strcmp(input, "save") == 0)
            save(warehouse);
        else if(strcmp(input, "exit") == 0)
            break;
    }

    return 0;
}
