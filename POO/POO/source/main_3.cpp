#include "Prerequisites.h"
#include "ProgrammingPatterns/MiSingleton.h"
#include "ProgrammingPatterns/RegistroActividad.h"
#include "ProgrammingPatterns/FactoryMethod.h"
#include "ProgrammingPatterns/Vehiculo.h"
#include "ProgrammingPatterns/AbstractFactory/Mueble.h"
#include "ProgrammingPatterns/AbstractFactory/FactoriaMuebles.h"
#include "ProgrammingPatterns/Builder/ConstructorPizza.h"
#include "ProgrammingPatterns/Builder/BuilderPizzaHawaiiana.h"
#include "ProgrammingPatterns/Builder/Pizza.h"
#include "ProgrammingPatterns/Prototype/Prototype.h"
#include "ProgrammingPatterns/Prototype/PrototypeConcreto.h"
#include "ProgrammingPatterns/Adapter/InterfazVieja.h"
#include "ProgrammingPatterns/Adapter/InterfazNueva.h"
#include "ProgrammingPatterns/Adapter/Adaptador.h"
#include "ProgrammingPatterns/Adapter/Circulo.h"
#include "ProgrammingPatterns/Adapter/Cuadrado.h"
#include "ProgrammingPatterns/Adapter/AdaptadorCirculo.h"
#include "ProgrammingPatterns/Adapter/AdaptadorCuadrado.h"

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
  /* Usamos la estructura de mi singleton
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

  FactoriaMuebles* miFabrica = new FactoriaMueblesRusticos();
  Silla* silla = miFabrica->crearSilla();
  Mesa* mesa = miFabrica->crearMesa();

  std::cout << "=== Muebles creados ===" << std::endl;
  silla->descripcion();
  silla->color();
  std::cout << std::endl;
  mesa->descripcion();
  mesa->color();

  delete silla;
  delete mesa;
  delete miFabrica;

  Builder* builder = new BuilderConcreto();
  Director* director = new Director(builder);

  director->construct();
  //director->show();

  Producto* producto = builder->getProducto();
  producto->show();

  delete producto;
  delete director;
  delete builder; */

  /*ConstructorPizza* constructorHawaiiana = new builderPizzaHawaiiana();
  constructorHawaiiana->addIngrediente(INGREDIENTES::ACEITUNAS);
  constructorHawaiiana->buildIngredientes();

  Pizza* pizzaHawaiiana = constructorHawaiiana->getPizza();
  pizzaHawaiiana->show();

  delete constructorHawaiiana;
  delete pizzaHawaiiana;

  Prototype* original = new PrototypeConcreto();
  original->config("Original");

  Prototype* clone = original->clone();
  clone->config("Clone");
  original->info();
  clone->info();

  delete original;
  delete clone;*/

  InterfazVieja* objetoViejo = new InterfazVieja();
  InterfazNueva* objetoNuevo = new Adaptador(objetoViejo);

  objetoNuevo->metodoNuevo();

  delete objetoViejo;
  delete objetoNuevo;

  Circulo* circulo = new Circulo();
  Cuadrado* cuadrado = new Cuadrado();

  Dibujable* adaptarCirculo = new AdaptadorCirculo(circulo);
  Dibujable* adaptarCuadrado = new AdaptadorCuadrado(cuadrado);

  adaptarCirculo->dibujar();
  adaptarCuadrado->dibujar();

  delete circulo;
  delete cuadrado;
  delete adaptarCirculo;
  delete adaptarCuadrado;

  return 0;
}