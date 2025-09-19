#pragma once
#include "Prerequisites.h"
#include "CuentaBancaria.h"
#include "UsuarioBancario.h"

class 
Banco
{
public:
	Banco() = default;
	~Banco() = default;

	UsuarioBancario 
	nuevoUsuario(CuentaBancaria cuenta) {
		UsuarioBancario usuario(cuenta);
		return usuario;
	}

	void 
	realizarTransferencia(UsuarioBancario& cuentaOrigen, UsuarioBancario& cuentaDestino, double monto, int noRef) {
		if (monto > 0 && monto <= cuentaOrigen.getCuenta().consultarSaldo()) {
			cuentaOrigen.getCuenta().consultarSaldo() -= monto;
			cuentaDestino.getCuenta().consultarSaldo() += monto;
			std::cout << "Transferencia de " << monto << " de la cuenta " 
				<< cuentaOrigen.getCuenta().getNumeroCuenta() << " a la cuenta " << cuentaDestino.getCuenta().getNumeroCuenta()
				<< " realizada con exito." << " Numero de referencia: " << noRef << std::endl;
		}
		else {
			std::cout << "Error en la transferencia: Monto invalido o saldo insuficiente." << std::endl;
		}
	}

private:

};
