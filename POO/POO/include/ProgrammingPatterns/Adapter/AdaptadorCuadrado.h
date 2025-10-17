#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Adapter/Cuadrado.h"
#include "ProgrammingPatterns/Adapter/Dibujable.h"

class
AdaptadorCuadrado : public Dibujable {
public:
  AdaptadorCuadrado(Cuadrado* _cuadrado) : cuadrado(_cuadrado) {}
  ~AdaptadorCuadrado() = default;

  void
    dibujar() override {
    std::cout << "Adaptando metodo dibujar a metodo dibujar cuadrado..." << std::endl;
    cuadrado->dibujarCuadrado();
  }

private:
  Cuadrado* cuadrado;
};