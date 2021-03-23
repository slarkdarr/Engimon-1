// operator delete[] example
#include <iostream>     // std::cout

struct MyClass {
  MyClass() {std::cout <<"MyClass constructed\n";}
  ~MyClass() {std::cout <<"MyClass destroyed\n";}
};

int main () {
  MyClass * pt;

  pt = new MyClass();
  MyClass* pt2 = pt;
  delete pt;
  std::cout << (pt) << std::endl;
  std::cout << "test\n";

  return 0;
}