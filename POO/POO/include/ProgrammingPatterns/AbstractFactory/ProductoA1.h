#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/AbstractFactory/ProductoA.h"

// Producto A1 concreto
class 
ProductoA1 : public ProductoA {
public:
  void operacionA() const override;

};