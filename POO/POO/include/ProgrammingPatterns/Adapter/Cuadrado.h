#pragma once
#include "Prerequisites.h"

class
Cuadrado {
public:
  Cuadrado() = default;
  ~Cuadrado() = default;

  virtual void
    dibujarCuadrado() {
    std::cout << "Dibujar un cuadrado." << std::endl;
  }
};