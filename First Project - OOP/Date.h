#ifndef HOTEL_PROJECT_DATE_H
#define HOTEL_PROJECT_DATE_H
#include <iostream>
#include <cmath>

class Date {
    int years;
    int months;
    int days;
public:
    Date();
    Date(int, int, int);

    void setDate(int, int, int);
    void setDateCheckOut();
    void setDatePlusPlus();

    bool operator==(Date const &);
    bool operator>(Date const &);
    bool operator<(Date const &);

    friend std::ostream& operator<<(std::ostream&, Date const &);
};


#endif //HOTEL_PROJECT_DATE_H
