#include <iostream>

#include "Stack.hpp"
#include "Queue.hpp"

using namespace std;

int main() {

  Stack<int> numbers;
  Queue<int> numbers1;
  numbers1.push(1);
  numbers1.push(2);
  numbers1.push(3);
  numbers1.push(4);
  numbers1.push(5);
  numbers1.push(6);
  numbers1.push(7);
  numbers1.push(8);
  numbers1.push(9);
  for (size_t i = 0; i < numbers1.getSize(); i++) {
    cout << numbers1.top() << endl;
    if(i % 2 == 0)
      numbers1.pop();
  }


  return 0;
}
