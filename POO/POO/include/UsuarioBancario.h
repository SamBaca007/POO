#pragma once
#include "Prerequisites.h"
#include "CuentaBancaria.h"

class 
UsuarioBancario {
public:
	UsuarioBancario(CuentaBancaria cuenta) {
		m_cuenta = cuenta;
		m_nombreUsuario = m_cuenta.m_propietario;
		m_antiguedad.getFecha();
		m_CashBack = m_cuenta.consultarSaldo() * 0.01;
		m_uniquePoints = 5;
	}
	~UsuarioBancario() = default;

	CuentaBancaria& 
	getCuenta() {
		return m_cuenta;
	}

private:
	CuentaBancaria m_cuenta;
	std::string m_nombreUsuario;
	std::vector<int> m_historialTransacciones;
	Fecha m_antiguedad;
	int m_idUsuario;
	int m_CashBack;
	int m_uniquePoints;
};