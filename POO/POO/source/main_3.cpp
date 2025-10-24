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
#include "ProgrammingPatterns/Decorator/ComponenteConcreto.h"
#include "ProgrammingPatterns/Decorator/DecoratorConcretoA.h"
#include "ProgrammingPatterns/Decorator/DecoratorConcretoB.h"
#include "ProgrammingPatterns/Decorator/Cafeteria.h"
#include "ProgrammingPatterns/Decorator/Leche.h"
#include "ProgrammingPatterns/Decorator/Azucar.h"
#include "ProgrammingPatterns/Composite/Hoja.h"
#include "ProgrammingPatterns/Composite/Composite.h"
#include "ProgrammingPatterns/Composite/SistemaArchivo.h"
#include "ProgrammingPatterns/Composite/Carpeta.h"

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
  delete clone;

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

ComponenteConcreto* objeto = new ComponenteConcreto();
DecoratorConcretoA* decoradorA = new DecoratorConcretoA(objeto);
DecoratorConcretoB* decoradorB = new DecoratorConcretoB(decoradorA);

objeto->operacion();
decoradorA->operacion();
decoradorB->operacion();

delete objeto;
delete decoradorA;
delete decoradorB;

Cafeteria* cafeteria = new Cafeteria();
Leche* cafeConLeche = new Leche(cafeteria);
Azucar* cafeConAzucar = new Azucar(cafeConLeche);

std::cout << "--- Preparacion 1: Solo Base ---" << std::endl;
cafeteria->servir();

std::cout << "\n--- Preparacion 2: Con Leche ---" << std::endl;
cafeConLeche->decorar();

std::cout << "\n--- Preparacion 3: Con Leche y Azucar ---" << std::endl;
cafeConAzucar->decorar();

delete cafeConAzucar;
delete cafeConLeche;
delete cafeteria;*/

Hoja* hoja1 = new Hoja();
Hoja* hoja2 = new Hoja();
Composite* composite = new Composite();

composite->add(hoja1);
composite->add(hoja2);
composite->operacion();

delete hoja1;
delete hoja2;
delete composite;

// 1. Crear instancias de SistemaArchivo (los "archivos individuales" o Hojas)
    // Se usan punteros al tipo base 'Sistema' para poder añadirlos a la carpeta
    // y usar polimorfismo, aunque se inicializan como SistemaArchivo.
Sistema* archivo1 = new SistemaArchivo();
Sistema* archivo2 = new SistemaArchivo();
Sistema* archivo3 = new SistemaArchivo();

// 2. Crear instancias de SistemaCarpeta (el "contenedor" o Composite)
SistemaCarpeta* carpetaPrincipal = new SistemaCarpeta();
SistemaCarpeta* subCarpeta = new SistemaCarpeta();

// 3. Organizar la estructura (Patrón Composite)
// Agregamos archivos a la subcarpeta
std::cout << "--- Agregando elementos a la SubCarpeta ---" << std::endl;
subCarpeta->agregarSistema(archivo3);

// Agregamos archivos y la subcarpeta a la carpeta principal
std::cout << "--- Agregando elementos a la Carpeta Principal ---" << std::endl;
carpetaPrincipal->agregarSistema(archivo1);
carpetaPrincipal->agregarSistema(subCarpeta); // ¡Una carpeta dentro de otra!
carpetaPrincipal->agregarSistema(archivo2);

// 4. Mostrar la información de todo el sistema (Punto 6)
// Al llamar a mostrarInfo() en el componente raíz (la carpeta), 
// la llamada se propaga a todos los hijos (Patrón Composite).
std::cout << "\n==========================================" << std::endl;
std::cout << "MOSTRANDO LA INFORMACION DE TODO EL SISTEMA" << std::endl;
std::cout << "==========================================" << std::endl;

carpetaPrincipal->mostrarInfo();

// 5. Limpieza de memoria (IMPORTANTE: liberar solo el elemento raíz)
// El destructor virtual de SistemaCarpeta se encarga de liberar 
// recursivamente a todos sus hijos (archivo1, subCarpeta, archivo2, etc.).
std::cout << "\n--- Limpieza de memoria ---" << std::endl;
delete carpetaPrincipal;

// Los destructores de SistemaCarpeta (si están bien implementados) 
// se encargan de borrar subCarpeta, archivo1, archivo2 y archivo3.

  return 0;
}