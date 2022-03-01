#include "behavioral_pattern/strategy.h"
#include "creational_pattern//factory/simple_factory/simple_factory.h"
#include "creational_pattern/factory/abstract_factory/abstract_factory.h"
#include "creational_pattern/factory/factory_method/factory_method.h"
#include <memory>
#include <vector>
using namespace factory;
void test_simple_factory() {
  auto a = simple_factory::SimpleFactory::run_func(1);
  a->func();
  auto b = simple_factory::SimpleFactory::run_func(2);
  b->func();
}

void test_factory_method() {
  // 工厂方法模式使得当需要更改为创建另一个对象时只需要更改下面的工厂类对象即可
  unique_ptr<factory_method::Factory> factory =
      make_unique<factory::factory_method::SubClass1Factory>();
  auto a = factory->CreateInstance();
  a->Func();
}

void test_abstract_method() {
  unique_ptr<abstract_factory::Factory> factory =
      make_unique<factory::abstract_factory::FactorySub1Factory>();
  auto a = factory->CreateInstanceBase1();
  a->Func();
  auto b = factory->CreateInstanceBase2();
  b->Func();
}

void test_strategy_pattern() {
  stratey::Context context(
      {make_shared<stratey::Stratey1>(), make_shared<stratey::Stratey2>()});
  context.RunAlgoirthm();
  context.set_strateys({make_shared<stratey::Stratey2>(), make_shared<stratey::Stratey1>()});
  context.RunAlgoirthm();
}

int main() {
  test_strategy_pattern();
  return 1;
}
