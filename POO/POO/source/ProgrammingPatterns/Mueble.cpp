#include "Prerequisites.h"
#include "ProgrammingPatterns/AbstractFactory/Mueble.h"

Silla::Silla(std::string t, std::string c) : tipo(t), tono(c) {}
void Silla::descripcion() const {
  std::cout << "Silla de estilo " << tipo << "." << std::endl;
}
void Silla::color() const {
  std::cout << "Color de la silla: " << tono << "." << std::endl;
}

Mesa::Mesa(std::string t, std::string c) : tipo(t), tono(c) {}
void Mesa::descripcion() const {
  std::cout << "Mesa de estilo " << tipo << "." << std::endl;
}
void Mesa::color() const {
  std::cout << "Color de la mesa: " << tono << "." << std::endl;
}
