#pragma once
#include "Prerequisites.h"
#include "CuentaBancaria.h"
#include "UsuarioBancario.h"

/**
 * @class Banco
 * @brief Gestiona las operaciones bancarias principales, como la creación de usuarios,
 * transferencias, compras y cálculo de cashback.
 */
class 
Banco
{
public:

	//Constructor por defecto
	Banco() = default;
	//Destructor por defecto
	~Banco() = default;

	/**
	 * @brief Crea una nueva instancia de un UsuarioBancario a partir de una CuentaBancaria.
	 * @param cuenta El objeto CuentaBancaria que se asociará al nuevo usuario.
	 * @return Una instancia de UsuarioBancario.
	 */
	UsuarioBancario 
	nuevoUsuario(CuentaBancaria cuenta) {
		UsuarioBancario usuario(cuenta);
		return usuario;
	}

	// Calcula y devuelve un porcentaje de cashback con base en el tipo de comercio y el monto de la compra.
	double cashBack(TRADE comercio, double _monto) {

		double retorno = 0.0;
		switch (comercio) {
		case TELECOMUNICAIONES:
			retorno = _monto * 0.01;
			break;
		case RESTAURANTES:
			retorno = _monto * 0.02;
			break;
		case FARMACIAS:
			retorno = _monto * 0.03;
			break;
		case SUPERMERCADOS:
			retorno = _monto * 0.01;
			break;
		default:
			retorno = 0.0;
			break;
		}
		return retorno;
	}

	/**
	 * @brief Realiza una transferencia de saldo entre dos cuentas de usuario.
	 * @param cuentaOrigen La cuenta de donde se retirará el monto.
	 * @param cuentaDestino La cuenta a la que se le depositará el monto.
	 * @param monto La cantidad de dinero a transferir.
	 * @param noRef El número de referencia de la transferencia.
	 */
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

	/**
	 * @brief Procesa una compra para un usuario, restando el monto y aplicando cashback.
	 * @param cuentaOrigen La cuenta del usuario que realiza la compra.
	 * @param producto El nombre del artículo comprado.
	 * @param monto El costo total de la compra.
	 * @param noRef El número de referencia de la compra.
	 */
	void realizarCompra(UsuarioBancario& cuentaOrigen, const std::string& producto, double monto, int noRef) {
		if (monto > 0 && monto <= cuentaOrigen.getCuenta().consultarSaldo()) {
			cuentaOrigen.getCuenta().consultarSaldo() -= monto;
			std::cout << "Compra del articulo: " << producto << " Costo: $" << monto 
			<< "Numero de Referencia: " << noRef << std::endl;

			cuentaOrigen.setCashBack(cashBack(SUPERMERCADOS, monto));
			std::cout << "Ganaste CashBack por tu compra aplicado: $" << cashBack(SUPERMERCADOS, monto) << std::endl;
		}
		else {
			std::cout << "Error en la transferencia: Monto invalido o saldo insuficiente." << std::endl;
		}
	}

private:

};
