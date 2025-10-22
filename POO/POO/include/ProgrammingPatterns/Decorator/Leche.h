#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Decorator/Condimento.h"

class
Leche : public Condimento {
public:
  Leche(Cafe* _cafe) : Condimento(_cafe) {}
  virtual ~Leche() override = default;

  void
  decorar() override {
    cafe->servir();
    std::cout << "Leche agregada." << std::endl;
  }

  void
  servir() override {
    decorar();
  }
};