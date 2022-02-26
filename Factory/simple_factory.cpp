#include "simple_factory.h"

#include <memory>
namespace factory {
void Sub1::func() { cout << "Sub1 func" << endl; }
void Sub2::func() { cout << "Sub2 func" << endl; }

unique_ptr<Base> SimpleFactory::run_func(int i) {
  if (i == 1) {
    return std::make_unique<Sub1>();
  }
  return std::make_unique<Sub2>();
}
} // namespace factory