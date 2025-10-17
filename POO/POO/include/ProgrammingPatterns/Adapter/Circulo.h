#pragma once
#include "Prerequisites.h"

class 
Circulo {
public:
  Circulo() = default;
  ~Circulo() = default;

  virtual void 
  dibujarCirculo() {
    std::cout << "Dibujar un circulo." << std::endl;
  }
};