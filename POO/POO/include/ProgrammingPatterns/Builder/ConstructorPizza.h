#pragma once

class Pizza;
enum INGREDIENTES;

class
ConstructorPizza {
public:
  ConstructorPizza() = default;
  ~ConstructorPizza() = default;

  virtual void
  buildIngredientes() = 0;

  virtual void
  addIngrediente(INGREDIENTES ingrediente) = 0;

  virtual Pizza*
  getPizza() = 0;
};