#include "ProgrammingPatterns/Builder/BuilderConcreto.h"

BuilderConcreto::BuilderConcreto() {
  producto = new Producto();
}

void
BuilderConcreto::buildParteA() {
  if (producto) {
    producto->add("Parte A");
  }
}

void
BuilderConcreto::buildParteB() {
  if (producto) {
    producto->add("Parte B");
  }
}

Producto*
BuilderConcreto::getProducto() {
  if (producto) {
    return producto;
  }
  return nullptr;
}