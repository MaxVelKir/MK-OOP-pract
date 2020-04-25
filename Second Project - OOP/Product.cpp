#include "Product.h"

Product::Product(const char * _name, Date _expiration, Date _in, const char * _manufacturer, const char* _unit, int _quantity, const char * _note) {
    if(_name) {
         name = new char[strlen(_name) + 1];
         strcpy(name, _name);
    }
    if(_manufacturer) {
        manufacturer = new char[strlen(_manufacturer) + 1];
        strcpy(manufacturer, _manufacturer);
    }
    if(_note) {
        note = new char[strlen(_note) + 1];
        strcpy(note, _note);
    }

    if(strcmp(_unit, "KILOGRAMS") == 0 || strcmp(_unit, "kilograms") == 0)
        unit = KILOGRAMS;
    else if (strcmp(_unit, "LITRES") == 0 || strcmp(_unit, "litres") == 0)
        unit = LITRES;
    else {
        unit = UNKNOWN;
    }

    quantity = _quantity;
    in = _in;
    expiration = _expiration;
}

Product::Product(Product const &temp) :
quantity(temp.quantity), expiration(temp.expiration), in(temp.in), unit(temp.unit)
{
    if(temp.name) {
        name = new char[strlen(temp.name) + 1];
        strcpy(name, temp.name);
    }
    if(temp.manufacturer) {
        manufacturer = new char[strlen(temp.manufacturer) + 1];
        strcpy(manufacturer, temp.manufacturer);
    }
    if(temp.note) {
        note = new char[strlen(temp.note) + 1];
        strcpy(note, temp.note);
    }

    location = temp.location;
}

Product::~Product() {
    delete [] name;
    delete [] manufacturer;
    delete [] note;
}

Product& Product::operator=(Product const &temp) {
    if(this != &temp) {
        delete [] name;
        delete [] manufacturer;
        delete [] note;

        if(temp.name) {
            name = new char[strlen(temp.name) + 1];
            strcpy(name, temp.name);
        }
        if(temp.manufacturer) {
            manufacturer = new char[strlen(temp.manufacturer) + 1];
            strcpy(manufacturer, temp.manufacturer);
        }
        if(temp.note) {
            note = new char[strlen(temp.note) + 1];
            strcpy(note, temp.note);
        }

        location = temp.location;
        unit = temp.unit;
        quantity = temp.quantity;
        expiration = temp.expiration;
        in = temp.in;
    }
    return *this;
}

char* Product::getName() const {
    return name;
}

Date& Product::getExpiration() {
    return expiration;
}

Date& Product::getIn() {
    return in;
}

Vector<Location>& Product::getLocation() {
    return location;
}

char* Product::getUnit() const {
    if(unit == KILOGRAMS)
        return "kilograms";
    else if(unit == LITRES)
        return "litres";
    else
        return "<unknown>";
}

int Product::getQuantity() const {
    return quantity;
}

void Product::addQuantity(int n) {
    quantity += n;
}

void Product::removeQuantity(int n) {
    quantity -= n;
}

void Product::read() {
    char _name[MAX_L];
    char _manufacturer[MAX_L];
    char _note[MAX_L];
    char _unit[MAX_L];
    Date _expiration, _in;
    int _quantity;
    cout << "Please enter name of product: ";
    cin.getline(_name, MAX_L);
    cout << "Please enter manufacturer: ";
    cin.getline(_manufacturer, MAX_L);
    cout << "Please enter note or just press enter: ";
    cin.getline(_note, MAX_L);
    cout << "Please enter unit of measurement (KILOGRAMS/LITRES): ";
    do {
        cin.getline(_unit, MAX_L);
        if(strcmp(_unit, "KILOGRAMS") != 0 && strcmp(_unit, "LITRES") != 0 && strcmp(_unit, "litres") != 0 && strcmp(_unit, "kilograms") != 0 && strcmp(_unit, "\0") != 0)
            cout << "Invalid unit, try again: ";
    } while(strcmp(_unit, "KILOGRAMS") != 0 && strcmp(_unit, "LITRES") != 0 && strcmp(_unit, "litres") != 0 && strcmp(_unit, "kilograms") != 0 && strcmp(_unit, "\0") != 0);
    cout << "Please enter expiration date (years/months/days): ";
    _expiration.read();
    cout << "Please enter date of entry (years/months/days): ";
    _in.read();
    cout << "Please enter quantity: ";
    cin.ignore();
    cin >> _quantity;

    if(strcmp(_name, "\0") == 0)
        strcpy(_name, "<unknown>");
    if(strcmp(_manufacturer, "\0") == 0)
        strcpy(_manufacturer, "<unknown>");


    Product temp(_name, _expiration, _in, _manufacturer, _unit, _quantity, _note);
    *this = temp;
}

bool Product::operator==(Product const &temp) {
    return (strcmp(name, temp.name) == 0) &&
    (strcmp(manufacturer, temp.manufacturer) == 0) &&
    (strcmp(note, temp.note) == 0) &&
    expiration == temp.expiration &&
    in == temp.in &&
    unit == temp.unit;
}

ostream &operator<<(ostream &o, Product &temp) {
    o << "Name: " << temp.name << '\n'
      << "Manufacturer: " << temp.manufacturer << '\n'
      << "Unit: " << temp.getUnit() << '\n';

    if(strcmp(temp.note, "\0") != 0)
        o << "Note: " << temp.note << '\n';

    o << "Date of expiration: " << temp.expiration << '\n'
      << "Date of registration in warehouse: " << temp.in << '\n';

    o << "Quantity: " << temp.quantity << '\n'
      << "Locations: ";
    for (int i = 0; i < temp.location.getCurr(); ++i) {
        if(i == 0)
            o << temp.location[i] << '\n';
        else if(i != temp.location.getCurr() - 1)
            o << "           " << temp.location[i] << '\n';
        else
            o << "           " << temp.location[i];
    }

    o << endl;
    return o;
}
