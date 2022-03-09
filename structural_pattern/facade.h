#ifndef DESIGNPATTERN_STRUCTURAL_PATTERN_FACADE_H_
#define DESIGNPATTERN_STRUCTURAL_PATTERN_FACADE_H_
#include <iostream>
using namespace std;
namespace facade {
class SubSystemOne {
public:
  void Method() { cout << "Method1 is running" << endl; }
};
class SubSystemTwo {
public:
  void Method() { cout << "Method2 is running" << endl; }
};
class SubSystemThree {
public:
  void Method() { cout << "Method3 is running" << endl; }
};
class Facade {
public:
  void MethodA() {
    sys_one_.Method();
    sys_two_.Method();
  }
  void MethodB() {
    sys_one_.Method();
    sys_three.Method();
  }

private:
  SubSystemOne sys_one_ = SubSystemOne();
  SubSystemTwo sys_two_ = SubSystemTwo();
  SubSystemThree sys_three = SubSystemThree();
};
} // namespace facade
#endif // DESIGNPATTERN_STRUCTURAL_PATTERN_FACADE_H_
