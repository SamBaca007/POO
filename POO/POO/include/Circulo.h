#pragma once
#include "Prerequisites.h"

class 
Circulo {
public:
	Circulo(double radio) : m_radio(radio) {}
	~Circulo() = default;

	double 
	area() const {
		return 3.14159 * (m_radio * m_radio);
	}

	double 
	perimetro() const {
		return 3.14159 * (2 * m_radio);
	}

	double 
	getRadio() const {
		return m_radio;
	}

	double 
	getDiametro() const {
		return 2 * m_radio;
	}

private:
	double m_radio;
};