#include <iostream>
#include <cstring>

using namespace std;


const int MAX_L = 30;

class Human {
    char firstName[MAX_L]{};
    char familyName[MAX_L]{};
    int age;

protected:
    Human() {
        strcpy(firstName, "\0");
        strcpy(familyName, "\0");
        age = 0;
    }

    Human(char* _firstName, char* _familyName, int _age) {
        strcpy(firstName, _firstName);
        strcpy(familyName, _familyName);
        age = _age;
    }

    void setFirst(char* _firstName) {
        strcpy(firstName, _firstName);
    }
    void setFamily(char* _familyName) {
        strcpy(firstName, _familyName);
    }
    void setAge(int _age) {
        age = _age;
    }

    void print() {
        cout << firstName << ' ' << familyName << " - " << age;
    }

};

class Student : public Human {
    int fn;
    char spec[MAX_L];
public:
    Student() : Human() {
        fn = 0;
        strcpy(spec, "\0");
    }
    Student(char* _firstName, char* _familyName, int _age, int _fn, char* _spec) : Human(_firstName, _familyName, _age) {
        fn = _fn;
        strcpy(spec, _spec);
    }
    void print() {
        Human::print();
        cout << " - " << fn << ' ' << spec << endl;
    }

};

class Shape {
    char type[MAX_L];
protected:
    Shape() {
        strcpy(type, "\0");
    }

    Shape(const char* _type) {
        strcpy(type, _type);
    }

    ~Shape() = default;

    void print() {
        cout << type;
    }

};

class Rectangular : public Shape {
    int width;
    int height;
public:
    Rectangular() : Shape() {
        width = 0;
        height = 0;
    }

    Rectangular(const char* _type, int _width, int _height) : Shape(_type) {
        width = _width;
        height = _height;
    }

    ~Rectangular() = default;

    void print() {
        Shape::print();
        cout << " - width: " << width << ", height: " << height;
    }
};

class ColoredRectangular : public Rectangular {
    char color[MAX_L];
public:
    ColoredRectangular() : Rectangular() {
        strcpy(color, "\0");
    }

    ColoredRectangular(const char* _type, int _width, int _height, const char* _color) : Rectangular(_type, _width, _height) {
        strcpy(color, _color);
    }

    ~ColoredRectangular() = default;

    void print() {
        Rectangular::print();
        cout << ", color: " << color << endl;
    }
};

class Square : public Shape {
    int side;
public:
    Square() : Shape() {
        side = 0;
    }

    Square(const char* _type, int _side) : Shape(_type) {
        side = _side;
    }

    ~Square() = default;

    void print() {
        Shape::print();
        cout << ' ' << side << endl;
    }
};

class Triangle : public Shape {
    int side1;
    int side2;
    int side3;
public:
    Triangle() : Shape() {
        side1 = 0;
        side2 = 0;
        side3 = 0;
    }

    Triangle(const char* _type, int _side1, int _side2, int _side3) : Shape(_type) {
        side1 = _side1;
        side2 = _side2;
        side3 = _side3;
    }

    ~Triangle() = default;

    void print() {
        Shape::print();
        cout << " - side1: " << side1 << ", side2: " << side2 << ", side3: " << side3 << endl;
    }
};

int main() {
    Student a("Charles", "Xavier", 19, 45700, "Informatics");
    a.print();

    ColoredRectangular b("CRect", 10, 10, "red");
    b.print();

    Triangle c("Pyramid wanna be", 3, 4, 5);
    c.print();

    return 0;
}
