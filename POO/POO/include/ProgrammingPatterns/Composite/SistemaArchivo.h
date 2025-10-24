#pragma once
#include "ProgrammingPatterns/Composite/Archivo.h" 

// Implementamos SistemaArchivo como una especializaci�n de Archivo.
// Si Archivo hereda de Sistema, SistemaArchivo tambi�n lo hace.
class
SistemaArchivo : public Archivo {
public:
  SistemaArchivo() = default;
  ~SistemaArchivo() override = default;

  // Hereda mostrarInfo() de Archivo, que ya implementa el requisito.
};