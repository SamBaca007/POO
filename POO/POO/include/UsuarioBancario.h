#pragma once
#include "Prerequisites.h"
#include "CuentaBancaria.h"

/**
 * @class UsuarioBancario
 * @brief Representa un usuario del banco, gestionando su información personal y su cuenta bancaria.
 *
 * Esta clase encapsula los datos y el comportamiento de un usuario, incluyendo su cuenta bancaria,
 * nombre de usuario, historial de transacciones, y beneficios como cashback y puntos.
 */
class 
UsuarioBancario {
public:
	/**
	 * @brief Constructor de la clase UsuarioBancario.
	 * @param cuenta El objeto CuentaBancaria que se asociará al nuevo usuario.
	 */
	UsuarioBancario(CuentaBancaria cuenta) {
		m_cuenta = cuenta;
		m_nombreUsuario = m_cuenta.m_propietario;
		m_antiguedad.getFecha();
		m_CashBack = m_cuenta.consultarSaldo() * 0.01;
		m_uniquePoints = 5;
	}
	//Destrcutor por defecto
	~UsuarioBancario() = default;

	/**
	 * @brief Obtiene una referencia a la cuenta bancaria del usuario.
	 * @return Una referencia al objeto CuentaBancaria.
	 */
	CuentaBancaria& 
	getCuenta() {
		return m_cuenta;
	}

	/**
	 * @brief Establece el monto de cashback acumulado para el usuario.
	 * @param monto El valor de cashback a asignar.
	 */
	void setCashBack(double monto) {
		m_CashBack += monto;
	}

private:
	CuentaBancaria m_cuenta; ///< El objeto que contiene los datos de la cuenta bancaria del usuario.
	std::string m_nombreUsuario; ///< El nombre del propietario de la cuenta, utilizado como nombre de usuario.
	std::vector<int> m_historialTransacciones; ///< Historial de transacciones realizadas por el usuario.
	Fecha m_antiguedad; ///< La fecha de creación de la cuenta o antigüedad del usuario.
	int m_idUsuario; ///< Identificador único para el usuario.
	double m_CashBack; ///< El monto total de cashback acumulado por el usuario.
	int m_uniquePoints; ///< Puntos de lealtad únicos que el usuario ha acumulado.
};