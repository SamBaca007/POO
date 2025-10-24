#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Decorator/Componente.h"


class
Hoja : public Componente {
public:
  Hoja() = default;
  ~Hoja() = default;

  void
  operacion() override {
    // Implementaci�n espec�fica de la hoja
    std::cout << "Operacion realizada por la hoja" << std::endl;
  }

};