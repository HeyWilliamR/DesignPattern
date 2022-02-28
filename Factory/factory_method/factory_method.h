#ifndef DESIGNPATTERN_FACTORY_FACTORY_METHOD_H_
#define DESIGNPATTERN_FACTORY_FACTORY_METHOD_H_
#include <iostream>
#include <memory>
using namespace std;
namespace factory {
namespace factory_method {
class Base {
public:
  virtual ~Base() = default;
  virtual void Func() = 0;
  Base() = default;
};

class SubClass1 : public Base {
public:
  void Func() { cout << "SubClass1"; }
};

class SubClass2 : public Base {
public:
  void Func() { cout << "SubClass2"; }
};

class Factory {
public:
  virtual ~Factory() = default;
  Factory() = default;
  virtual unique_ptr<Base> CreateInstance() = 0;
};

class SubClass1Factory : public Factory {
public:
  virtual unique_ptr<Base> CreateInstance() { return make_unique<SubClass1>(); }
};

class SubClass2Factory : public Factory {
public:
  virtual unique_ptr<Base> CreateInstance() { return make_unique<SubClass2>(); }
};
} // namespace factory_method
} // namespace factory
#endif // DESIGNPATTERN_FACTORY_FACTORY_METHOD_H_
