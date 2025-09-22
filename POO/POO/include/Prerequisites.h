#pragma once
// STD Library Includes
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

struct 
Fecha {
	int dia;
	int mes;
	int anio;

	void 
	getFecha () {
		//Obtener fecha actual del sistema
		time_t t = time(0);
		tm* now = localtime(&t);

		//Crear instancia de Fecha
		dia = now->tm_mday;
		mes = now->tm_mon + 1;
		anio = now->tm_year + 1900;

		//Usar la función de la estructura
		std::cout << "Fecha actual: " << toString() << std::endl;
	}

	std::string toString() const {
		return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
	}
};

// Enumera los diferentes tipos de industrias o giros comerciales para la clase Banco.
enum
	TRADE {
	TELECOMUNICAIONES = 1,
	RESTAURANTES = 2,
	FARMACIAS = 3,
	SUPERMERCADOS = 4
};