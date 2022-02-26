#include "Factory/simple_factory.h"
void test_simple_factory(){
  auto a = factory::SimpleFactory::run_func(1);
  a->func();
  auto b = factory::SimpleFactory::run_func(2);
  b->func();
}

int main(){
  test_simple_factory();
  return 1;
}
