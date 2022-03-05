#include "template.h"
namespace template_pattern {

void Template::Method() {
  CommonMethod();
  SpecialMethod();
}
void Template::CommonMethod() { cout << "Run Common Method" << endl; }
void ConcentrateMethod::SpecialMethod() { cout << "Special Method" << endl; }
} // namespace template_pattern
