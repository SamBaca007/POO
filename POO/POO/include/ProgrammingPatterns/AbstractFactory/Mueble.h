#pragma once
#include "Prerequisites.h"

class
Mueble {
public:
  virtual void descripcion() const = 0;
  virtual void color() const = 0;
  virtual ~Mueble() {}
};

class
Silla : public Mueble {
  std::string tipo;
  std::string tono;
public:
  Silla(std::string t, std::string c);
  void descripcion() const override;
  void color() const override;
};

class
Mesa : public Mueble {
  std::string tipo;
  std::string tono;
public:
  Mesa(std::string t, std::string c);
  void descripcion() const override;
  void color() const override;
};
