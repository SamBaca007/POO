#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/AbstractFactory/Mueble.h"

class Silla;
class Mesa;

class FactoriaMuebles {
public:
  virtual Silla* crearSilla() = 0;
  virtual Mesa* crearMesa() = 0;
  virtual ~FactoriaMuebles() {}
};

class FactoriaMueblesRusticos : public FactoriaMuebles {
public:
  Silla* crearSilla() override;
  Mesa* crearMesa() override;
};

class FactoriaMueblesModernos : public FactoriaMuebles {
public:
  Silla* crearSilla() override;
  Mesa* crearMesa() override;
};