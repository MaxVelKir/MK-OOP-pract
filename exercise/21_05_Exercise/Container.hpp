#ifndef _Container
#define _Container

template<typename T>
class Container {
public:
  virtual void push(const T) = 0;
  virtual void pop() = 0;
  virtual T top() = 0;
  virtual void erase() = 0;
};

#endif
