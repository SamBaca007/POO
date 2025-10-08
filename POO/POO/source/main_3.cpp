#include "Prerequisites.h"
#include "ProgrammingPatterns/MiSingleton.h"
#include "ProgrammingPatterns/RegistroActividad.h"
#include "ProgrammingPatterns/FactoryMethod.h"
#include "ProgrammingPatterns/Vehiculo.h"

// Inicializamos la instancia estatica
MiSingleton* MiSingleton::instance = nullptr;
RegistroActividad* RegistroActividad::instance = nullptr;

void cliente(FactoriaVehiculos* factoria) {
  // 1. Usa la Factoria para crear el Vehiculo.
  // Se usa el polimorfismo: la llamada a crearVehiculo() se resolverá 
  // en tiempo de ejecución a la fábrica concreta apropiada.
  Vehiculo* vehiculo = factoria->crearVehiculo();

  std::cout << std::endl;
  std::cout << "El objeto creado por la factoria es: ";

  // 2. Llama al método del Vehiculo.
  // De nuevo, polimorfismo: la llamada a descripcion() se resolverá 
  // al método de la clase concreta (Coche o Bicicleta).
  vehiculo->descripcion();

  // 3. ¡Muy importante! Limpiar la memoria.
  delete vehiculo;
}

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

  Fabrica* fabrica = new FabricaA(); // Fabrica -> Genera a Tesla (FabricaA)
  Producto* producto = fabrica->crearProducto(); // Producto -> Tesla (ProductoA)
  producto->operacion();

  delete producto;
  delete fabrica;

  FactoriaVehiculos* factoriaCoche = new FactoriaCoches();
  cliente(factoriaCoche);
  delete factoriaCoche;

  FactoriaVehiculos* factoriaBici = new FactoriaBicicletas();
  cliente(factoriaBici);
  delete factoriaBici;

  return 0;
}