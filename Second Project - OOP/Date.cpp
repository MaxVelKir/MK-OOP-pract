#include "Date.h"
Date::Date(int _years, int _months, int _days) : years(_years), months(_months), days(_days) {}

void Date::read() {
    char c;
    cin >> years >> c >> months >> c >> days;
    if(years < 0 || months > 12 || months < 1 || days < 1 || days > 31) {
        cout << "Invalid date, try again: ";
        read();
    }
}

ostream &operator<<(ostream &o, const Date &temp) {
    return o << temp.years << '/' << temp.months << '/' << temp.days;
}

bool Date::operator>(const Date &dt) {
    if (years > dt.years)
        return true;

    else if (years == dt.years) {
        if (months > dt.months) {
            return true;
        }

        else if (months == dt.months) {
            return days > dt.days;
        }
    }
    else return false;
}

bool Date::operator>=(const Date &dt) {
    if (years > dt.years)
        return true;

    else if (years == dt.years) {
        if (months > dt.months) {
            return true;
        }

        else if (months == dt.months) {
            return days >= dt.days;
        }
    }
    else return false;
}

bool Date::operator<(const Date &dt) {
    if (years < dt.years)
        return true;

    else if (years == dt.years) {
        if (months < dt.months) {
            return true;
        }

        else if (months == dt.months) {
            return days < dt.days;
        }
    }
    else return false;
}

bool Date::operator<=(const Date &dt) {
    if (years < dt.years)
        return true;

    else if (years == dt.years) {
        if (months < dt.months) {
            return true;
        }

        else if (months == dt.months) {
            return days <= dt.days;
        }
    }
    else return false;
}

bool Date::operator==(const Date &dt) {
    return years == dt.years && months == dt.months && days == dt.days;
}