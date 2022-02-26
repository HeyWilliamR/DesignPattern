#ifndef DESIGNPATTERN_SIMPLE_FACTORY_H
#define DESIGNPATTERN_SIMPLE_FACTORY_H
#include <iostream>
#include <memory>
using namespace std;
namespace factory {
class Base {
public:
  Base() = default;
  virtual ~Base() =default;
  virtual void func() {};
};

class Sub1 : public Base {
public:
  Sub1() = default;
  ~Sub1() = default;
  void func() override;
};

class Sub2 : public Base {
public:
  Sub2() = default;
  ~Sub2() = default;
  void func() override;
};
class SimpleFactory {
public:
  static unique_ptr<Base> run_func(int i);
};
} // namespace factory

#endif // DESIGNPATTERN_SIMPLE_FACTORY_H
