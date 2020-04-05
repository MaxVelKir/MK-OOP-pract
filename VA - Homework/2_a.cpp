//Максим Велизаров Киряков - 45700 - Информатика 1ви крус 5та група

//1613 2143 4493 5003 9293 


#include <iostream>
#include <cmath>

const int MAX = 10000;

bool Prosto(int p) {
    for (int i = 2; i <= p / 2; ++i) {
        if(p % i == 0)
            return false;
    }
    return true;
}

bool modTen(int p) {
    return p % 10 == 3;
}

bool deliteli(int p) {
    int q = p + 2;
    int masiv[q / 2];
    int counter = 0;
    for (int i = 2; i <= q / 2; ++i) {
        if(q % i == 0) {
            masiv[counter] = i;
            counter++;
        }
    }

    for (int j = 0; j < counter - 1; ++j) {
        for (int i = j + 1; i < counter; ++i) {
            if(abs(masiv[j] - masiv[i]) == 2 && masiv[j] != 5 && masiv[i] != 5 && Prosto(masiv[j]) && Prosto(masiv[i]))
                return true;
        }
    }
    return false;
}

int main() {

    int p = 2;

    for (int i = 0; i < MAX; ++i) {
        if(Prosto(p) && modTen(p) && deliteli(p)) {
            std::cout << p << ' ';
        }
        p++;
    }


    return 0;
}
