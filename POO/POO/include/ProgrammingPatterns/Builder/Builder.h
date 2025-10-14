#pragma once
#include "Prerequisites.h"

class Producto;

class Builder {
public:
  Builder() = default;
  ~Builder() = default;

  virtual void buildParteA() = 0;
  virtual void buildParteB() = 0;
  virtual Producto* getProducto() = 0;
};