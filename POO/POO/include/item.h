#pragma once
#include "Prerequisites.h"

class
Item {
public:
	Item(const std::string& name, int quantity) : n_name(name), m_quantity(quantity) {}
	~Item() = default;

	std::string
	getName() const {
		return n_name;
	}

	int
	getQuantity() const {
		return m_quantity;
	}

	void
	add(int quantity) {
		m_quantity += quantity;
	}

	void remove(int quantity) {
		if (quantity <= m_quantity) {
			m_quantity -= quantity;
		} else {
			std::cout << "No hay suficiente cantidad de " << n_name << " para remover." << std::endl;
		}
		//m_quantity = (m_quantity - quantity) ? m_quantity - quantity : 0;
	}

private:
	std::string n_name;
	int m_quantity;
};