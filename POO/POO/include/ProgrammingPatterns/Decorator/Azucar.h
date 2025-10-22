#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Decorator/Condimento.h"

class 
Azucar : public Condimento {
public:
  Azucar(Cafe* _cafe) : Condimento(_cafe) {}
  virtual ~Azucar() override = default;

  void
  decorar() override {
    cafe->servir();
    std::cout << "Azucar agregada." << std::endl;
  }

  void
  servir() override {
    decorar();
  }
};