#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Proxy/Sujeto.h"

class
SujetoReal : public Sujeto {
public:
  SujetoReal() = default;
  ~SujetoReal() = default;

  void
  Request() override {
    std::cout << "SujetoReal: Handling Request." << std::endl;
  }
};