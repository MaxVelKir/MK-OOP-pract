#include "Fruit.h"

Fruit::Fruit(float _calories, float _protein, float _carbohydrates, float _fat, Taste taste) : Eatable(taste) {
    calories = _calories;
    protein = _protein;
    carbohydrates = _carbohydrates;
    fat = _fat;
}

void Fruit::print() {
    std::cout << "Calories: " << calories << '\n'
              << "Protein: " << protein << '\n'
              << "Carbohydrates: " << carbohydrates << '\n'
              << "Fat: " << fat << '\n'
              << "Taste: ";
    Eatable::print();
}