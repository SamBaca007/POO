#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Composite/Sistema.h"


class
Archivo : public Sistema {
public:
  Archivo() = default;
  ~Archivo() override = default;

  void
  mostrarInfo() override {
    std::cout << "Soy un archivo." << std::endl;
  }

};