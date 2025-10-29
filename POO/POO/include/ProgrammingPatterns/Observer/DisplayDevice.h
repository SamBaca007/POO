#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Observer/Observer.h"

class
DisplayDevice : public Observer {
public:
  DisplayDevice() = default;
  ~DisplayDevice() = default;

  void
  onNotify(int _value) override {
    std::cout << "Display Device: Temperature updated to "
    << _value << " degrees." << std::endl;
  }

};