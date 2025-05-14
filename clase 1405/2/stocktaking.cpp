#include "stocktaking.h"
#include <iostream>
#include <iomanip> // ✅ Pour std::setprecision et std::fixed


// Constructeur Produit
Producto::Producto(int id, const std::string& nombre, double precio, int cantidad, Categoria categoria)
    : id(id), nombre(nombre), precio(precio), cantidad(cantidad), categoria(categoria) {
    if (precio < 0) {
        throw InventarioException("El precio no puede ser negativo.");
    }
    if (cantidad < 0) {
        throw InventarioException("La cantidad no puede ser negativa.");
    }
}

// Méthode privée pour trouver un produit
Producto* Inventario::encontrarProducto(int id) {
    for (auto& producto : productos) {
        if (producto.id == id) {
            return &producto;
        }
    }
    return nullptr;
}

// Ajouter produit
void Inventario::agregarProducto(const Producto& producto) {
    if (encontrarProducto(producto.id)) {
        throw InventarioException("El ID del producto ya existe.");
    }
    productos.push_back(producto);
}

// Supprimer produit
void Inventario::eliminarProducto(int id) {
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        if (it->id == id) {
            productos.erase(it);
            return;
        }
    }
    throw InventarioException("Producto no encontrado.");
}

// Mettre à jour quantité
void Inventario::actualizarCantidad(int id, int nuevaCantidad) {
    if (nuevaCantidad < 0) {
        throw InventarioException("La cantidad no puede ser negativa.");
    }
    Producto* prod = encontrarProducto(id);
    if (!prod) throw InventarioException("Producto no encontrado.");
    prod->cantidad = nuevaCantidad;
}

// Mettre à jour prix
void Inventario::actualizarPrecio(int id, double nuevoPrecio) {
    if (nuevoPrecio < 0) {
        throw InventarioException("El precio no puede ser negativo.");
    }
    Producto* prod = encontrarProducto(id);
    if (!prod) throw InventarioException("Producto no encontrado.");
    prod->precio = nuevoPrecio;
}

// Afficher tout l'inventaire
void Inventario::mostrarInventario() const {
    for (const auto& p : productos) {
        std::cout << "ID: " << p.id
                  << ", Nombre: " << p.nombre
                  << ", Precio: $" << std::fixed << std::setprecision(2) << p.precio
                  << ", Cantidad: " << p.cantidad
                  << ", Categoria: " << static_cast<int>(p.categoria) << std::endl;
    }
}

// Afficher par catégorie
void Inventario::mostrarPorCategoria(Categoria categoria) const {
    for (const auto& p : productos) {
        if (p.categoria == categoria) {
            std::cout << "ID: " << p.id
                      << ", Nombre: " << p.nombre
                      << ", Precio: $" << std::fixed << std::setprecision(2) << p.precio
                      << ", Cantidad: " << p.cantidad << std::endl;
        }
    }
}

// Calculer valeur totale
double Inventario::calcularValorTotal() const {
    double total = 0;
    for (const auto& p : productos) {
        total += p.precio * p.cantidad;
    }
    return total;
}

// Rechercher par ID
Producto Inventario::buscarPorId(int id) const {
    for (const auto& p : productos) {
        if (p.id == id) return p;
    }
    throw InventarioException("Producto no encontrado.");
}
