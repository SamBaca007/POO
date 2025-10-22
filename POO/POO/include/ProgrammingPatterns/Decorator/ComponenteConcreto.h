#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Decorator/Componente.h"

class 
ComponenteConcreto : public Componente {
public:
  ComponenteConcreto() = default;
  ~ComponenteConcreto() = default;

  void 
  operacion() override {
    std::cout << "Realizando operacion concreta..." << std::endl;
  }
};