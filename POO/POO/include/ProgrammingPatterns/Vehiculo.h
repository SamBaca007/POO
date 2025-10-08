#pragma once
#include "Prerequisites.h"

// Clase base vehículo
class
Vehiculo {
public:
  virtual void descripcion() const = 0;
  virtual ~Vehiculo() = default;
};

// Clase base fábrica
class
FactoriaVehiculos {
public:
  virtual Vehiculo* crearVehiculo() const = 0;
  virtual ~FactoriaVehiculos() = default;
};

// Producto Concreto Coche
class
Coche : public Vehiculo {
public:
  void descripcion() const override {
    std::cout << "Soy un coche" << std::endl;
  }
};

// Producto Concreto Bicicleta
class
Bicicleta : public Vehiculo {
public:
  void descripcion() const override {
    std::cout << "Soy una bicicleta" << std::endl;
  }
};

// Fábrica Concreta Coches
class 
FactoriaCoches : public FactoriaVehiculos {
public:
  Vehiculo* crearVehiculo() const override {
    return new Coche();
  }
};

// Fábrica Concreta Bicicletas
class 
FactoriaBicicletas : public FactoriaVehiculos {
public:
  Vehiculo* crearVehiculo() const override {
    return new Bicicleta();
  }
};
