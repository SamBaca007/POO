#include "Prerequisites.h"
#include "ProgrammingPatterns/MiSingleton.h"
#include "ProgrammingPatterns/RegistroActividad.h"

// Inicializamos la instancia estatica
MiSingleton* MiSingleton::instance = nullptr;
RegistroActividad* RegistroActividad::instance = nullptr;

int 
main() {
  // Usamos la estructura de mi singleton
  MiSingleton* singleton = MiSingleton::getInstance();
  singleton->setData(42);

  std::cout << "Valor del singleton: " << singleton->getData() << std::endl;

  MiSingleton* singleton2 = MiSingleton::getInstance();
  std::cout << "Valor del singleton 2: " << singleton->getData() << std::endl;

  std::cout << std::endl;

  RegistroActividad* agregarActividad = RegistroActividad::getInstance();
  agregarActividad->agregarActividad("La aplicacion se ha iniciado.");
  agregarActividad->agregarActividad("Se ha procesado el formulario A.");

  RegistroActividad* mostrarActividad = RegistroActividad::getInstance();
  mostrarActividad->mostrarRegistro();
}