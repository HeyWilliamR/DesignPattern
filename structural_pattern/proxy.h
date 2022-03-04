#ifndef DESIGNPATTERN_STRUCTURAL_PATTERN_PROXY_H_
#define DESIGNPATTERN_STRUCTURAL_PATTERN_PROXY_H_
#include <iostream>
#include <memory>
using namespace std;
namespace structure {
class SubObject {
public:
  virtual void operator1() = 0;
  virtual ~SubObject() = default;
  virtual void operator2() = 0;
  SubObject() = default;
};

class RealObject final : public SubObject {
public:
  RealObject() = default;
  void operator2() override { cout << "RealObject2" << endl; }
  void operator1() override { cout << "RealObject1" << endl; }
  void operator3() { cout << "operator3"; }
};

class Proxy : public SubObject {
private:
  shared_ptr<RealObject> real_obj_ = nullptr;

public:
  Proxy(shared_ptr<RealObject> real_obj) : real_obj_(real_obj) {}
  virtual ~Proxy() = default;
  void operator2() override { real_obj_->operator1(); }
  void operator1() override { real_obj_->operator2(); }
};
} // namespace structure
#endif // DESIGNPATTERN_STRUCTURAL_PATTERN_PROXY_H_
