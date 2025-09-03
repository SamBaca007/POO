#include "Prerequisites.h"

//Crear una clase Character
class
Character {
public:
	Character() = default;

	Character(int health) : m_health(health){}

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

class Inventory {
public:
	//Adds an item
	void
	addItem(const std::string& item) {
		items.push_back(item);
	}

	//Shows item list
	void
	showItems() const {
		if (items.empty()) {
			std::cout << "El inventario esta vacio" << std::endl;
		}
		else {
			std::cout << "Inventario: " << std::endl;
			for (size_t i = 0; i < items.size(); i++) {
				std::cout << i + 1 << " " << items[i] << std::endl;
			}
		}
	}

	//Uses an item
	void
	useItem(int index) {
		if (index >= 0 && index < (int)items.size()) {
			std::cout << "Has usado: " << items[index] << std::endl;
			items.erase(items.begin() + index);
		}
		else {
			std::cout << "Inválido" << std::endl;
		}
	}

private:
	std::vector<std::string> items;
};

//This function is in charge of being the entry point of the app.
int 
main () {
	Character pepe(150);
	pepe.getHealth();
	std::cout << pepe.getHealth() << std::endl;
	pepe.setHealth(-50);
	std::cout << pepe.getHealth() << std::endl;

	if (pepe.getHealth() >= 0) {
		std::cout << "Pepe, murio" << std::endl;
		pepe.rebirth();
	}

	Inventory bag;

	// Adds items
	for (int i = 0; i < 3; i++) {
		bag.addItem("Pocion " + std::to_string(i + 1));
	}
	bag.addItem("Espada");
	bag.addItem("Escudo");

	bag.showItems();

	// Switch control
	int opcion = 1; // Player uses first item
	switch (opcion) {
	case 1:
		bag.useItem(0);
		break;
	case 2:
		bag.showItems();
		break;
	default:
		std::cout << "Accion invalida." << std::endl;
		break;
	}

	std::cout << "Inventario final:" << std::endl;
	bag.showItems();

	std::cout << std::endl;

	std::cout << "Hello World" << std::endl;
	return 0;
}