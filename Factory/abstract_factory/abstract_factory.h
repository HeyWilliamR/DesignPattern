#ifndef DESIGNPATTERN_FACTORY_ABSTRACT_FACTORY_ABSTRACT_FACTORY_H_
#define DESIGNPATTERN_FACTORY_ABSTRACT_FACTORY_ABSTRACT_FACTORY_H_
#include <iostream>
#include <memory>
using namespace std;
namespace factory {
namespace abstract_factory {
class Base1 {
public:
  virtual ~Base1() = default;
  virtual void Func() = 0;
};

class Base2 {
public:
  virtual ~Base2() = default;
  virtual void Func() = 0;
};

class Sub1Base1 : public Base1 {
public:
  void Func() override { cout << "Sub1Base1" << endl; }
};

class Sub2Base1 : public Base1 {
public:
  void Func() override { cout << "Sub2Base1" << endl; }
};

class Sub1Base2 : public Base2 {
public:
  void Func() override { cout << "Sub1Base2" << endl; }
};

class Sub2Base2 : public Base2 {
public:
  void Func() override { cout << "Sub2Base2" << endl; }
};

class Factory {
public:
  virtual unique_ptr<Base1> CreateInstanceBase1() = 0;
  virtual unique_ptr<Base2> CreateInstanceBase2() = 0;
};

class FactorySub1Factory : public Factory {
public:
  unique_ptr<Base1> CreateInstanceBase1() { return make_unique<Sub1Base1>(); }
  unique_ptr<Base2> CreateInstanceBase2() { return make_unique<Sub1Base2>(); }
};

class FactorySub2Factory : public Factory {
public:
  unique_ptr<Base1> CreateInstanceBase1() { return make_unique<Sub2Base1>(); }
  unique_ptr<Base2> CreateInstanceBase2() { return make_unique<Sub2Base2>(); }
};
} // namespace abstract_factory
} // namespace factory
#endif // DESIGNPATTERN_FACTORY_ABSTRACT_FACTORY_ABSTRACT_FACTORY_H_
