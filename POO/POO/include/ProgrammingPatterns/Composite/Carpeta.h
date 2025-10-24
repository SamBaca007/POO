#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Composite/Sistema.h" // Hereda del componente base (Punto 5)
// Necesitamos saber qué son Archivo o Carpeta para los punteros, 
// aunque solo necesitamos punteros a 'Sistema'
#include <vector> 

class 
SistemaCarpeta : public Sistema { // Hereda de 'Sistema' (Punto 5)
public:
  SistemaCarpeta() = default;
  ~SistemaCarpeta() override {
    // Buena práctica: liberar la memoria de los hijos
    for (Sistema* hijo : elementos) {
      delete hijo;
    }
    elementos.clear();
  }

  // Método requerido en el punto 2 de la práctica
  void 
  mostrarInfo() override {
    std::cout << "Soy una carpeta" << std::endl; // Muestra su propia información
    // Recorre y delega la operación a todos los hijos
    for (Sistema* hijo : elementos) {
      hijo->mostrarInfo();
    }
  }

  // Método para agregar un hijo (equivalente a 'add' en tu ejemplo)
  void agregarSistema(Sistema* componente) {
    elementos.push_back(componente);
  }

private:
  // Almacena punteros al tipo base (Sistema), 
  // lo que permite almacenar Archivos o CarpetaSistemas
  std::vector<Sistema*> elementos;
};