#ifndef SKLAD_DATE_H
#define SKLAD_DATE_H

#include <iostream>

using namespace std;

class Date {
    int years;
    int months;
    int days;
public:
    Date(int = 0, int = 0, int = 0);

    void read();
    friend ostream& operator<<(ostream&, Date const &);
    bool operator>(Date const &);
    bool operator>=(Date const &);
    bool operator<(Date const &);
    bool operator<=(Date const &);
    bool operator==(Date const &);
};


#endif //SKLAD_DATE_H
