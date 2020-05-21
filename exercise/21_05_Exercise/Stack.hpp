#ifndef _Stack
#define _Stack

#include "Container.hpp"

template<typename T>
class Stack : public Container<T> {
  T *array;
  int size;
  int curr;
public:
  Stack();
  Stack(Stack<T> const &);
  ~Stack();
  Stack<T>& operator=(Stack<T> const &);

  void push(const T);
  void pop();
  T top();
  void erase();
  int getSize();
};

template<typename T>
Stack<T>::Stack() {
  size = 3;
  curr = 0;
  array = new T[size];
}

template<typename T>
Stack<T>::Stack(Stack<T> const &temp) {
  size = temp.size;
  curr = temp.curr;
  array = new T[size];
  for (size_t i = 0; i < curr; i++) {
    array[i] = temp.array[i];
  }
}

template<typename T>
Stack<T>::~Stack() {
  delete [] array;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T> const &temp) {
  if(this != &temp) {
    delete [] array;
    size = temp.size;
    curr = temp.curr;
    array = new T[size];
    for (size_t i = 0; i < curr; i++) {
      array[i] = temp.array[i];
    }
    return *this;
  }
}

template<typename T>
void Stack<T>::push(T const temp) {
  if(curr == size) {
    T* arr = new T[size * 2];
    for (size_t i = 0; i < curr; i++)
      arr[i] = array[i];

    delete [] array;
    size *= 2;
    array = arr;
  }
  array[curr++] = temp;
}

template<typename T>
void Stack<T>::pop() {
  T* arr = new T[size];
  for (size_t i = 0; i < curr - 1; i++)
    arr[i] = array[i];

  delete [] array;
  curr--;
  array = arr;
}

template<typename T>
T Stack<T>::top() {
  return array[curr - 1];
}

template<typename T>
void Stack<T>::erase() {
  delete [] array;
  size = 3;
  curr = 0;
  array = new T[size];
}

template<typename T>
int Stack<T>::getSize() {
  return curr;
}

#endif
