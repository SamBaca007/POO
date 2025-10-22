#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Decorator/Decorator.h"

class
DecoratorConcretoA : public Decorator {
public:
  DecoratorConcretoA(Componente* _componente) : Decorator(_componente) {}
  ~DecoratorConcretoA() = default;

  void operacion() override {
    Decorator::operacion();
    std::cout << "Agregando funcionalidad A..." << std::endl;
  }
};