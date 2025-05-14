#include "library_management.h"
#include <iostream>

// --- Libro ---

Libro::Libro(int id, const std::string& titulo, const std::string& autor, bool disponible)
    : id(id), titulo(titulo), autor(autor), disponible(disponible) {}

// --- Biblioteca ---

void Biblioteca::agregarLibro(const Libro& libro) {
    for (const auto& l : catalogo) {
        if (l.id == libro.id) {
            throw BibliotecaException("El libro con ID " + std::to_string(libro.id) + " ya existe.");
        }
    }
    catalogo.push_back(libro);
}

void Biblioteca::prestarLibro(int id) {
    for (auto& l : catalogo) {
        if (l.id == id) {
            if (!l.disponible) {
                throw BibliotecaException("El libro con ID " + std::to_string(id) + " ya está prestado.");
            }
            l.disponible = false;
            return;
        }
    }
    throw BibliotecaException("Libro con ID " + std::to_string(id) + " no encontrado.");
}

void Biblioteca::devolverLibro(int id) {
    for (auto& l : catalogo) {
        if (l.id == id) {
            if (l.disponible) {
                throw BibliotecaException("El libro con ID " + std::to_string(id) + " no estaba prestado.");
            }
            l.disponible = true;
            return;
        }
    }
    throw BibliotecaException("Libro con ID " + std::to_string(id) + " no encontrado.");
}

void Biblioteca::mostrarCatalogo() const {
    for (const auto& l : catalogo) {
        std::cout << "ID: " << l.id
                  << ", Titulo: " << l.titulo
                  << ", Autor: " << l.autor
                  << ", Disponible: " << (l.disponible ? "Sí" : "No") << std::endl;
    }
}

Libro Biblioteca::buscarPorId(int id) const {
    for (const auto& l : catalogo) {
        if (l.id == id) {
            return l;
        }
    }
    throw BibliotecaException("Libro con ID " + std::to_string(id) + " no encontrado.");
}

int Biblioteca::contarDisponibles() const {
    int contador = 0;
    for (const auto& l : catalogo) {
        if (l.disponible) {
            ++contador;
        }
    }
    return contador;
}
