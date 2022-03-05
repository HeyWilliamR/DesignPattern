#ifndef DESIGNPATTERN_CREATIONAL_PATTERN_FACTORY_PROTOTYPE_PATTERN_H_
#define DESIGNPATTERN_CREATIONAL_PATTERN_FACTORY_PROTOTYPE_PATTERN_H_
#include <iostream>
#include <memory>
using namespace std;
namespace creational_pattern {
class Proto {
public:
  virtual ~Proto() = default;
  virtual unique_ptr<Proto> Clone() = 0;
};

class ConcreteProto : public Proto {
public:
  ConcreteProto(const string &name) : name_(std::move(name)) {}
  unique_ptr<Proto> Clone() override {
    return make_unique<ConcreteProto>(this->name_);
  }

private:
  string name_;
};
} // namespace creational_pattern
#endif // DESIGNPATTERN_CREATIONAL_PATTERN_FACTORY_PROTOTYPE_PATTERN_H_
