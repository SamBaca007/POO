#pragma once
#include "Prerequisites.h"

class ProductoA;
class ProductoB;

// Fábrica abstracta
class 
FabricaAbstracta {
public:
  virtual ProductoA*
  crearProductoA() const = 0;
  virtual ProductoB* 
  crearProductoB()const = 0;
  virtual
  ~FabricaAbstracta() = default;
};
