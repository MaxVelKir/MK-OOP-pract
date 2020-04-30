#include <iostream>

#include "Triangle.h"
#include "Square.h"
#include "Figures.h"

using namespace std;

int main() {
    Triangle tr(4, 5, 6);
    Square sq(5);

    Figures f;
    f.addShape(&sq);
    f.addShape(&tr);
    cout << f[f.biggestArea()]->getArea() << ' ' << f[f.biggestPerimeter()]->getPerimeter() << endl;
    return 0;
}
