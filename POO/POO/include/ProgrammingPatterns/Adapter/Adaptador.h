#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Adapter/InterfazVieja.h"
#include "ProgrammingPatterns/Adapter/InterfazNueva.h"

class 
Adaptador : public InterfazNueva {
public:
  Adaptador(InterfazVieja* _interfazVieja) : interfazVieja(_interfazVieja) {}
  ~Adaptador() = default;

  void 
  metodoNuevo() override {
    std::cout << "Adaptando metodo nuevo a metodo viejo..." << std::endl;
    interfazVieja->metodoViejo();
  }

private:
  InterfazVieja* interfazVieja;
};