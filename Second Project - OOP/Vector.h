#ifndef SKLAD_VECTOR_H
#define SKLAD_VECTOR_H

#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class Vector {
    T *vector;
    int size;
    int curr;
public:
    Vector();
    Vector(Vector<T> const &);
    ~Vector();
    Vector& operator=(Vector<T> const &);

    int getCurr();

    void resize(int);
    void push(T const &);
    void pop(const char*);
    void pop(int);
    T& operator[](int);
};

template <typename T>
Vector<T>::Vector() {
    curr = 0;
    size = 1;
    vector = new T[size];
}

template <typename T>
Vector<T>::Vector(const Vector<T> &temp) {
    size = temp.size;
    curr = temp.curr;
    vector = new T[size];
    for (int i = 0; i < curr; ++i) {
        vector[i] = temp.vector[i];
    }
}

template <typename T>
Vector<T>::~Vector() {
    delete [] vector;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &temp) {
    if (this != &temp) {
        delete[] vector;

        size = temp.size;
        curr = temp.curr;

        vector = new T[size];

        for (int i = 0; i < curr; ++i) {
            vector[i] = temp.vector[i];
        }
    }
    return *this;
}

template <typename T>
int Vector<T>::getCurr() {
    return curr;
}

template<typename T>
void Vector<T>::push(const T &temp) {
    if(curr == size) {
        T *arr = new T[size + 1];
        for (int i = 0; i < curr; ++i) {
            arr[i] = vector[i];
        }
        delete [] vector;
        size++;
        vector = arr;
    }
    vector[curr++] = temp;
}

template<typename T>
void Vector<T>::pop(const char* position) {
    if(strcmp(position, "first") == 0) {
        T *arr = new T[size - 1];

        for (int i = 1; i < curr; ++i)
            arr[i - 1] = vector[i];

        delete[] vector;
        size--;
        curr--;
        vector = arr;
    }

    else if(strcmp(position, "last") == 0) {
        T *arr = new T[size - 1];

        for (int i = 0; i < curr - 1; ++i)
            arr[i] = vector[i];

        delete[] vector;
        size--;
        curr--;
        vector = arr;
    }
}

template<typename T>
void Vector<T>::pop(int n) {
    T *arr = new T[size - 1];
    int counter = 0;

    for (int i = 0; i < curr; ++i) {
        if(i != n)
            arr[counter++] = vector[i];
    }

    delete[] vector;
    if(counter < curr) {
        size--;
        curr--;
    }
    vector = arr;
}

template <typename T>
T & Vector<T>::operator[](int i) {
    if (curr <= i) {
        resize(i + 1);
        curr = i + 1;
    }
    return vector[i];
}

template <typename T>
void Vector<T>::resize(int _size) {
    T * arr = new T[_size];
    if (_size < curr)
        curr = _size;

    for (int i = 0; i < curr; ++i)
        arr[i] = vector[i];

    delete[] vector;
    size = _size;
    vector = arr;
}


#endif //SKLAD_VECTOR_H
