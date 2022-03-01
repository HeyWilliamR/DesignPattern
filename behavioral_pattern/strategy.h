#ifndef DESIGNPATTERN_BEHAVIORALPATTERN_STRATEGY_H_
#define DESIGNPATTERN_BEHAVIORALPATTERN_STRATEGY_H_
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
namespace stratey {
class Stratey {
public:
  virtual ~Stratey() = default;
  virtual void Algoirthm() = 0;
};

class Stratey1 : public Stratey {
public:
  void Algoirthm() override { cout << "start stratey1" << endl; }
};

class Stratey2 : public Stratey {
public:
  void Algoirthm() override { cout << "start stratey2" << endl; }
};

class Context {
public:
  explicit Context(vector<shared_ptr<stratey::Stratey>> strateys)
      : strateys_(std::move(strateys)) {}
  void RunAlgoirthm() {
    for (const auto &item : strateys_) {
      item->Algoirthm();
    }
  }
  void set_strateys(const vector<shared_ptr<stratey::Stratey>> &strateys) {
    strateys_ = std::move(strateys);
  }

private:
  vector<shared_ptr<Stratey>> strateys_;
};
} // namespace stratey
#endif // DESIGNPATTERN_BEHAVIORALPATTERN_STRATEGY_H_
