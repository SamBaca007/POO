#pragma once
#include "ProgrammingPatterns/Builder/ConstructorPizza.h"
#include "ProgrammingPatterns/Builder/Pizza.h"

class 
builderPizzaHawaiiana : public ConstructorPizza {
public:
  builderPizzaHawaiiana() {
    pizza = new Pizza;
  }
  ~builderPizzaHawaiiana() {
    delete pizza;
  }

  void 
  buildIngredientes() override {
    pizza->addIngrediente(QUESO);
    pizza->addIngrediente(TOMATE);
    pizza->addIngrediente(JAMON);
    pizza->addIngrediente(PINA);
  }

  void
  addIngrediente(INGREDIENTES ingrediente) override {
    pizza->addIngrediente(ingrediente);
  }

  Pizza* 
  getPizza() override {
    return pizza;
  }

private:
  Pizza* pizza;
};