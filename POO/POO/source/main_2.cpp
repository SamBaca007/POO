#include "Prerequisites.h"
#include "inventory.h"
#include "rectangle.h"

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

	Fecha fecha;
	fecha.getFecha();
	std::cin.get();
	return 0;
}