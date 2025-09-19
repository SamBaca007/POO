#include "Prerequisites.h"
#include "inventory.h"
#include "rectangle.h"
#include "Circulo.h"
#include "Estudiante.h"
#include "Banco.h"
#include "UsuarioBancario.h"

//Crear una clase Character
class
Character {
public:
	Character() = default;

	Character(int health) : m_health(health) {}

	void
	rebirth() {
		if (!isCharacterAlive && m_health <= 0) {
			std::cout << "El personaje ha revivido en el Respawn Point" << std::endl;
			isCharacterAlive = true;
		}
	}

	int
	getHealth() const {
		return m_health;
	}

	void
	setHealth(int health) {
		m_health = health;
	}

private:
	bool isCharacterAlive = false;

protected:
	int m_health;
};

int
main() {
	Character pepe(150);
	pepe.getHealth();
	std::cout << pepe.getHealth() << std::endl;
	pepe.setHealth(-50);
	std::cout << pepe.getHealth() << std::endl;

	if (pepe.getHealth() >= 0) {
		std::cout << "Pepe, murio" << std::endl;
		pepe.rebirth();
	}

	Inventory inventory;
	inventory.addItem("Pocion de Vida", 5);
	inventory.addItem("Pocion de Mana", 3);
	inventory.addItem("Diamante", 64);

	inventory.useItem("Pocion de Vida", 2);
	inventory.showInventory();

	Rectangulo rectangle(4, 5);
	std::cout << "Rectangulo - Ancho: " << rectangle.getAncho() << ", Alto: " << rectangle.getAlto() << std::endl;
	std::cout << "Area: " << rectangle.area() << std::endl;
	std::cout << "Perimetro: " << rectangle.perimetro() << std::endl;

	Circulo miCirculo(5);
	std::cout << "Circulo - Radio: " << miCirculo.getRadio() << ", Diametro: " << miCirculo.getDiametro() << std::endl;
	std::cout << "Area: " << miCirculo.area() << std::endl;
	std::cout << "Perimetro: " << miCirculo.perimetro() << std::endl;

	Fecha fecha;
	fecha.getFecha();

	Estudiante estudiantes[5];

	estudiantes[0].setEstudiante("Samuel Baca", 19);
	estudiantes[1].setEstudiante("Jesus Cruz", 18);
	estudiantes[2].setEstudiante("Cristian Cardenas", 20);
	estudiantes[3].setEstudiante("Carlos Sanchez", 20);
	estudiantes[4].setEstudiante("Cristhian Morales", 26);

	for (int i = 0; i < 5; i++) {
		estudiantes[i].informacion();
	}

	Banco Santander;
	UsuarioBancario Alice = Santander.nuevoUsuario(CuentaBancaria("Alice", 1001, 5000.0));
	UsuarioBancario Samuel = Santander.nuevoUsuario(CuentaBancaria("Samuel", 1007, 3000.0));

	//Banco BBVA("Samuel", 1007, 5000.0);

	std::cout << "Antes de la transferencia: " << std::endl;
	//Santander.consultarSaldo();
	//BBVA.consultarSaldo();

	std::cout << "Realizando la transferencia..." << std::endl;
	Santander.realizarTransferencia(Samuel, Alice, 1500.0, 1809);

	std::cout << "Despues de la transferencia: " << std::endl;
	//Santander.consultarSaldo();
	//BBVA.consultarSaldo();

	std::cin.get();
	return 0;
}