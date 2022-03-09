#include "test_behavioral_pattern.h"
#include "behavioral_pattern/strategy.h"
#include "behavioral_pattern/template.h"
void test_strategy_pattern() {
  stratey::Context context(
      {make_shared<stratey::Stratey1>(), make_shared<stratey::Stratey2>()});
  context.RunAlgoirthm();
  context.set_strateys(
      {make_shared<stratey::Stratey2>(), make_shared<stratey::Stratey1>()});
  context.RunAlgoirthm();
}

void test_template() {
  auto test = template_pattern::ConcentrateMethod();
  test.Method();
}