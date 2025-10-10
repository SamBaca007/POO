#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/AbstractFactory/ProductoB.h"

// Producto A1 concreto
class
  ProductoB1 : public ProductoB {
public:
  void operacionB() const override;

};
