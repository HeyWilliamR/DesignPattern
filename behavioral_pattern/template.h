#ifndef DESIGNPATTERN_BEHAVIORAL_PATTERN_TEMPLATE_H_
#define DESIGNPATTERN_BEHAVIORAL_PATTERN_TEMPLATE_H_
#include <iostream>
using namespace std;
namespace template_pattern {
class Template {
public:
  void Method();
  void CommonMethod();
  virtual void SpecialMethod() = 0;
  virtual ~Template() = default;
};

class ConcentrateMethod : public Template {
public:
  virtual ~ConcentrateMethod() = default;
  void SpecialMethod() override;
};
} // namespace template_pattern
#endif // DESIGNPATTERN_BEHAVIORAL_PATTERN_TEMPLATE_H_
