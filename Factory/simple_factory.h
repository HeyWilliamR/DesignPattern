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
  virtual void func() = 0;
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
  // 这里不能使用对象，因为C++的多态针对的是指针而不是对象
  // 所以当使用返回值为对象是会报编译错误。
  static unique_ptr<Base> run_func(int i);
};
} // namespace factory

#endif // DESIGNPATTERN_SIMPLE_FACTORY_H
