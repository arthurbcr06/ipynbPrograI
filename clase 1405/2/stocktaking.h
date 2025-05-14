#ifndef STOCKTAKING_H
#define STOCKTAKING_H

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

// Enum de catégories de produit
enum class Categoria {
    ELECTRONICA,
    ROPA,
    ALIMENTOS,
    HOGAR
};

// Exception personnalisée
class InventarioException : public std::exception {
private:
    std::string mensaje;
public:
    explicit InventarioException(const std::string& msg) : mensaje(msg) {}
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

// Classe produit
class Producto {
public:
    int id;
    std::string nombre;
    double precio;
    int cantidad;
    Categoria categoria;

    Producto(int id, const std::string& nombre, double precio, int cantidad, Categoria categoria);
};

// Classe Inventario
class Inventario {
private:
    std::vector<Producto> productos;

    Producto* encontrarProducto(int id);
public:
    void agregarProducto(const Producto& producto);
    void eliminarProducto(int id);
    void actualizarCantidad(int id, int nuevaCantidad);
    void actualizarPrecio(int id, double nuevoPrecio);
    void mostrarInventario() const;
    void mostrarPorCategoria(Categoria categoria) const;
    double calcularValorTotal() const;
    Producto buscarPorId(int id) const;
};

#endif // STOCKTAKING_H
