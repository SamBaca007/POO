#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Composite/Sistema.h" // Hereda del componente base (Punto 5)
// Necesitamos saber qu� son Archivo o Carpeta para los punteros, 
// aunque solo necesitamos punteros a 'Sistema'
#include <vector> 

class 
SistemaCarpeta : public Sistema { // Hereda de 'Sistema' (Punto 5)
public:
  SistemaCarpeta() = default;
  ~SistemaCarpeta() override {
    // Buena pr�ctica: liberar la memoria de los hijos
    for (Sistema* hijo : elementos) {
      delete hijo;
    }
    elementos.clear();
  }

  // M�todo requerido en el punto 2 de la pr�ctica
  void 
  mostrarInfo() override {
    std::cout << "Soy una carpeta" << std::endl; // Muestra su propia informaci�n
    // Recorre y delega la operaci�n a todos los hijos
    for (Sistema* hijo : elementos) {
      hijo->mostrarInfo();
    }
  }

  // M�todo para agregar un hijo (equivalente a 'add' en tu ejemplo)
  void agregarSistema(Sistema* componente) {
    elementos.push_back(componente);
  }

private:
  // Almacena punteros al tipo base (Sistema), 
  // lo que permite almacenar Archivos o CarpetaSistemas
  std::vector<Sistema*> elementos;
};