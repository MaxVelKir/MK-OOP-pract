#ifndef _Queue
#define _Queue

#include "Container.hpp"

template<typename T>
class Queue : public Container<T> {
  T *array;
  int size;
  int curr;
public:
  Queue();
  Queue(Queue<T> const &);
  ~Queue();
  Queue<T>& operator=(Queue<T> const &);

  void push(const T);
  void pop();
  T top();
  void erase();
  int getSize();
};

template<typename T>
Queue<T>::Queue() {
  size = 3;
  curr = 0;
  array = new T[size];
}

template<typename T>
Queue<T>::Queue(Queue<T> const &temp) {
  size = temp.size;
  curr = temp.curr;
  array = new T[size];
  for (size_t i = 0; i < curr; i++) {
    array[i] = temp.array[i];
  }
}

template<typename T>
Queue<T>::~Queue() {
  delete [] array;
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue<T> const &temp) {
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
void Queue<T>::push(T const temp) {
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
void Queue<T>::pop() {
  T* arr = new T[size];
  int counter = 0;
  for (size_t i = 1; i < curr; i++)
    arr[counter++] = array[i];

  delete [] array;
  curr--;
  array = arr;
}

template<typename T>
T Queue<T>::top() {
  return array[curr - 1];
}

template<typename T>
void Queue<T>::erase() {
  delete [] array;
  size = 3;
  curr = 0;
  array = new T[size];
}

template<typename T>
int Queue<T>::getSize() {
  return curr;
}

#endif
