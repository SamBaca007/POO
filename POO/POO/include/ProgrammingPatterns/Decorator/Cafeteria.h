#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Decorator/Cafe.h"

class
Cafeteria : public Cafe {
public:
  Cafeteria() = default;
  virtual ~Cafeteria() override = default;

  void
  servir() override {
    std::cout << "Cafe preparado." << std::endl;
  }

  void
  prepararCafe() {
    servir();
  }
};