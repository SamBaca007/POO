#pragma once
#include "ProgrammingPatterns/Composite/Archivo.h" 

// Implementamos SistemaArchivo como una especialización de Archivo.
// Si Archivo hereda de Sistema, SistemaArchivo también lo hace.
class
SistemaArchivo : public Archivo {
public:
  SistemaArchivo() = default;
  ~SistemaArchivo() override = default;

  // Hereda mostrarInfo() de Archivo, que ya implementa el requisito.
};