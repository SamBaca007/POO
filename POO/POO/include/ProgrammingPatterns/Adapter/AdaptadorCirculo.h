#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Adapter/Circulo.h"
#include "ProgrammingPatterns/Adapter/Dibujable.h"

class
AdaptadorCirculo : public Dibujable {
public:
  AdaptadorCirculo(Circulo* _circulo) : circulo(_circulo) {}
  ~AdaptadorCirculo() = default;

  void
  dibujar() override {
    std::cout << "Adaptando metodo dibujar a metodo dibujar circulo..." << std::endl;
    circulo->dibujarCirculo();
  }

private:
  Circulo* circulo;
};