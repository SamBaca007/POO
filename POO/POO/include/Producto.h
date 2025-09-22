#pragma once
#include "Prerequisites.h"

// Enumeración para definir la categoría de un producto
enum class Categoria {
    ALIMENTO,
    BEBIDA,
    LIMPIEZA,
    ELECTRONICO,
    ROPA,
    OTRO
};

// Enumeración para definir si es consumible o no
enum class TipoConsumo {
    CONSUMIBLE,
    NO_CONSUMIBLE
};

class Producto {
private:
    // Atributos del producto
    std::string nombre;
    std::string codigo;
    Categoria categoria;
    std::string descripcion;
    TipoConsumo tipoConsumo;
    std::string fechaEmpaquetado;   // Ejemplo: "22/09/2025"
    std::string caducidad;          // Ejemplo: "22/09/2026"
    double peso;               // Peso en kg
    double costo;              // Costo en moneda local
    std::string contenido;          // Ejemplo: "500 ml", "1 pieza"
    std::string marca;
    std::string modelo;

public:
    // Constructor por defecto
    Producto() {}

    // Constructor con parámetros
    Producto(std::string nombre, std::string codigo, Categoria categoria, std::string descripcion,
        TipoConsumo tipoConsumo, std::string fechaEmpaquetado, std::string caducidad,
        double peso, double costo, std::string contenido, std::string marca, std::string modelo)
        : nombre(nombre), codigo(codigo), categoria(categoria), descripcion(descripcion),
        tipoConsumo(tipoConsumo), fechaEmpaquetado(fechaEmpaquetado), caducidad(caducidad),
        peso(peso), costo(costo), contenido(contenido), marca(marca), modelo(modelo) {
    }

    // --- Getters ---
    std::string getNombre() const { return nombre; }
    std::string getCodigo() const { return codigo; }
    Categoria getCategoria() const { return categoria; }
    std::string getDescripcion() const { return descripcion; }
    TipoConsumo getTipoConsumo() const { return tipoConsumo; }
    std::string getFechaEmpaquetado() const { return fechaEmpaquetado; }
    std::string getCaducidad() const { return caducidad; }
    double getPeso() const { return peso; }
    double getCosto() const { return costo; }
    std::string getContenido() const { return contenido; }
    std::string getMarca() const { return marca; }
    std::string getModelo() const { return modelo; }

    // --- Setters ---
    void setNombre(const std::string& n) { nombre = n; }
    void setCodigo(const std::string& c) { codigo = c; }
    void setCategoria(Categoria cat) { categoria = cat; }
    void setDescripcion(const std::string& d) { descripcion = d; }
    void setTipoConsumo(TipoConsumo tc) { tipoConsumo = tc; }
    void setFechaEmpaquetado(const std::string& fe) { fechaEmpaquetado = fe; }
    void setCaducidad(const std::string& ca) { caducidad = ca; }
    void setPeso(double p) { peso = p; }
    void setCosto(double co) { costo = co; }
    void setContenido(const std::string& con) { contenido = con; }
    void setMarca(const std::string& m) { marca = m; }
    void setModelo(const std::string& mo) { modelo = mo; }
};