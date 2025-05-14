#ifndef LIBRARY_MANAGEMENT_H
#define LIBRARY_MANAGEMENT_H

#include <string>
#include <vector>
#include <stdexcept>

class BibliotecaException : public std::runtime_error {
public:
    explicit BibliotecaException(const std::string& mensaje)
        : std::runtime_error(mensaje) {}
};

class Libro {
public:
    int id;
    std::string titulo;
    std::string autor;
    bool disponible;

    Libro(int id, const std::string& titulo, const std::string& autor, bool disponible);
};

class Biblioteca {
private:
    std::vector<Libro> catalogo;

public:
    void agregarLibro(const Libro& libro);
    void prestarLibro(int id);
    void devolverLibro(int id);
    void mostrarCatalogo() const;
    Libro buscarPorId(int id) const;
    int contarDisponibles() const;
};

#endif // LIBRARY_MANAGEMENT_H
