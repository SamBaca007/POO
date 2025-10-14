#include "Prerequisites.h"
#include "ProgrammingPatterns/AbstractFactory/FactoriaMuebles.h"
#include "ProgrammingPatterns/AbstractFactory/Mueble.h"

Silla* FactoriaMueblesRusticos::crearSilla() {
  return new Silla("rustico", "marron oscuro");
}

Mesa* FactoriaMueblesRusticos::crearMesa() {
  return new Mesa("rustico", "nogal");
}

Silla* FactoriaMueblesModernos::crearSilla() {
  return new Silla("moderno", "gris claro");
}

Mesa* FactoriaMueblesModernos::crearMesa() {
  return new Mesa("moderno", "negro mate");
}