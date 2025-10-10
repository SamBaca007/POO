#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/AbstractFactory/FabricaAbstracta.h"
#include "ProgrammingPatterns/AbstractFactory/ProductoA1.h"
#include "ProgrammingPatterns/AbstractFactory/ProductoB1.h"

class 
FabricaConcreta : public FabricaAbstracta {
  ProductoA* crearProductoA() const override {
    return new ProductoA1();
  }
  
  ProductoB* crearProductoB() const override {
    return new ProductoB1();
  }
};