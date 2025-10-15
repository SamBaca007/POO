#pragma once
#include "Prerequisites.h"

enum
INGREDIENTES {
  QUESO = 1,
  TOMATE = 2,
  ACEITUNAS = 3,
  JAMON = 4,
  CHAMPINONES = 5,
  PINA = 6
};

class
Pizza {
public:

  Pizza() = default;
  ~Pizza() = default;

  void
  addIngrediente(INGREDIENTES ingrediente) {
    ingrediente = ingrediente;
    ingredientes.push_back(ingrediente);
  }

  void show() {
    std::cout << "Pizza con los siguientes ingredientes: " << std::endl;
    for (const auto& ingrediente : ingredientes) {
      switch (ingrediente) {
      case QUESO:
        std::cout << "- Queso" << std::endl;
        break;
      case TOMATE:
        std::cout << "- Tomate" << std::endl;
        break;
      case ACEITUNAS:
        std::cout << "- Aceitunas" << std::endl;
        break;
      case JAMON:
        std::cout << "- Jamon" << std::endl;
        break;
      case CHAMPINONES:
        std::cout << "- Champinones" << std::endl;
        break;
      case PINA:
        std::cout << "- Pina" << std::endl;
        break;
      default:
        std::cout << "- Ingrediente desconocido" << std::endl;
        break;
      }
    }
  }

private:
  INGREDIENTES ingrediente;
  std::vector<INGREDIENTES> ingredientes;
};