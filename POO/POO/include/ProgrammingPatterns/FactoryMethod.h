#pragma once
#include "Prerequisites.h"

// Producto abstracto
class
Producto {
public:
  virtual void operacion() const = 0;
  virtual ~Producto() = default;
};

// Clase para la fábrica
class
Fabrica {
public:
  virtual Producto* crearProducto() const = 0;
  virtual ~Fabrica() = default;
};

//Producto concreto A
class
ProductoA : public Producto {
public:
  void operacion() const override {
    std::cout << std::endl;
    std::cout << "Operacion del Producto A" << std::endl;
  }
};

//Fábrica concreta A
class
FabricaA : public Fabrica {
  Producto* crearProducto() const override {
    return new ProductoA();
  }
};