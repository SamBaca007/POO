#pragma once
#include "Prerequisites.h"

// Clase base para productos A
class 
ProductoA {
public:
  virtual void 
  operacionA() const = 0;

  virtual 
  ~ProductoA() = default;
};