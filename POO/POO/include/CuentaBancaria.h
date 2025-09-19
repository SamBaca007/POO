#pragma once
#include "Prerequisites.h"

class 
CuentaBancaria {
public:
	CuentaBancaria() = default;
	CuentaBancaria(std::string propietario, int numCuenta, double saldoInicial) : 
		m_propietario(propietario), m_numeroCuenta(numCuenta), m_saldo(saldoInicial) {}
	~CuentaBancaria() = default;

	double& 
	consultarSaldo() {
		std::cout << "Saldo actual de " << m_propietario 
		<< " (Cuenta " << m_numeroCuenta << "): " << m_saldo << std::endl;
		return m_saldo;
	}

	void 
	mostrarInteresCalculado() {
		double tasaInteres = 5.0;
		double interes = calcularInteres(tasaInteres);
		std::cout << "Interes calculado al " << tasaInteres << "% sobre el saldo de " 
		<< m_saldo << " es: " << interes << std::endl;
	}
	int 
	getNumeroCuenta() const {
		return m_numeroCuenta;
	}

protected:
	void 
	transferir(CuentaBancaria& cuentaOrigen, CuentaBancaria& cuentaDestino, double monto, int noRef) {
		if (monto > 0 && monto <= cuentaOrigen.m_saldo) {
			cuentaOrigen.m_saldo -= monto;
			cuentaDestino.m_saldo += monto;
			std::cout << "Transferencia de " << monto << " de la cuenta " 
			<< cuentaOrigen.m_numeroCuenta << " a la cuenta " << cuentaDestino.m_numeroCuenta 
				<< " realizada con exito." << " Numero de referencia: " << noRef << std::endl;
		} else {
			std::cout << "Error en la transferencia: Monto invalido o saldo insuficiente." << std::endl;
		}
	}

private:
	double 
	calcularInteres(double tasaInteres) {
		return m_saldo * tasaInteres / 100.0;
	}

public:
	std::string m_propietario;
protected:
	int m_numeroCuenta;
private:
	double m_saldo;
};