#pragma once
#include "Prerequisites.h"

class 
RegistroActividad {
private:
  RegistroActividad() {}

  ~RegistroActividad() = default;

public:
  static 
  RegistroActividad* getInstance() {
    if (instance == nullptr) {
      instance = new RegistroActividad();
    }
    return instance;
  }

  void agregarActividad(const std::string& actividad) {
    registro.push_back(actividad);
  }

  void mostrarRegistro() const {
    std::cout << "Registro de Actividad" << std::endl;
    std::cout << std::endl;
    if (registro.empty()) {
      std::cout << "El registro est� vac�o." << std::endl;
    }
    else {
      for (const std::string& act : registro) {
        std::cout << "-> " << act << std::endl;
      }
    }
  }

private:
  // Instancia est�tica �nica de la clase
  static RegistroActividad* instance;

  // Contenedor para las actividades (lista de cadenas de texto)
  std::vector<std::string> registro;
};