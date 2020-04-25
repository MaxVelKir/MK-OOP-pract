#include "Date.h"

Date::Date() {
    years = -1;
    months = -1;
    days = -1;
}

Date::Date(int _years, int _months, int _days) : years(_years), months(_months), days(_days) {
    if(years < 0 || months < 1 || months > 12|| days < 1 || days > 31)
        std::cerr << "Invalid date!";
}

void Date::setDate(int _years, int _months, int _days) {
    years = _years;
    months = _months;
    days = _days;
    if(years < 0 || months < 1 || months > 12|| days < 1 || days > 31)
        std::cerr << "Invalid date!";
}

void Date::setDateCheckOut() {
    years = -1;
    months = -1;
    days = -1;
}

void Date::setDatePlusPlus() {
    if(days < 31) {
        days++;
    }
    else {
        days = 1;
        if(months < 12)
            months++;
        else {
            months = 1;
            years++;
        }
    }
}

bool Date::operator==(Date const &dt) {
    return years == dt.years && months == dt.months && days == dt.days;
}

bool Date::operator>(Date const &dt) {
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

bool Date::operator<(Date const &dt) {
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

std::ostream& operator<<(std::ostream& o, Date const &temp) {
    return o << '(' << temp.years << '/' << temp.months << '/' << temp.days << ')' << '\n';
}