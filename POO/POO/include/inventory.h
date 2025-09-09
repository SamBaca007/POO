#pragma once
#include "Prerequisites.h"
#include"Item.h"

class
	Inventory {
public:
	Inventory() = default;
	~Inventory() = default;

	void
		addItem(const std::string& name, int quantity) {
		//Se busca si existe el elemento a agregar para incrementar su cantidad
		for (auto& item : m_items) {
			if (item.getName() == name) {
				item.add(quantity);
				return;
			}
		}
		//Si no existe, agrega un nuevo objeto
		m_items.emplace_back(name, quantity);
	}

	void
		showInventory() const {
		//Verificar que el inventario NO esté vacío
		if (m_items.empty()) {
			std::cout << "Inventario vacio" << std::endl;
			return;
		}

		//Mostrar objetos del inventario
		std::cout << "Inventario: " << std::endl;
		for (auto& item : m_items) {
			std::cout << "- " << item.getName() << ": " << item.getQuantity() << std::endl;
		}
	}

	void
		useItem(const std::string& name, int quantity) {
		for (auto& item : m_items) {
			if (item.getName() == name) {
				item.remove(quantity);
				//Si la cantidad del objeto es 0, se quita del inventario
				if (item.getQuantity() == 0) {
					//m_items.erase(std::remove(m_items.begin(), m_items.end(), item), m_items.end());
				}
				std::cout << "Usaste " << quantity << " de " << name << "(s)." << std::endl;
				return;
			}
		}

		std::cout << "No tienes " << name << " en el inventario." << std::endl;
	}

private:
	std::vector<Item> m_items;
};