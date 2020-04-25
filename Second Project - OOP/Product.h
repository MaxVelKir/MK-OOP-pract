#ifndef SKLAD_PRODUCT_H
#define SKLAD_PRODUCT_H
#include <iostream>
#include <cstring>

#include "Date.h"
#include "Location.h"
#include "Vector.h"

using namespace std;

const int MAX_L = 100;

enum Unit {KILOGRAMS, LITRES, UNKNOWN};

class Product {
    char* name;
    Date expiration;
    Date in;
    char* manufacturer;
    Unit unit;
    int quantity;
    char* note;
    Vector<Location> location;
public:
    Product(const char* = "unknown", Date = Date(), Date = Date(), const char* = "<unknown", const char* = "UNKNOWN", int = 0, const char* = "\0");
    Product(Product const &);
    ~Product();
    Product& operator=(Product const &);

    char* getName() const;
    Date& getExpiration();
    Date& getIn();
    Vector<Location>& getLocation();
    char* getUnit() const;
    int getQuantity() const;
    void addQuantity(int);
    void removeQuantity(int);

    void read();
    bool operator==(Product const &);
    friend ostream& operator<<(ostream&, Product &);
};


#endif //SKLAD_PRODUCT_H
