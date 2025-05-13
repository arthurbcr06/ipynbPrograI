/*Declara la clase LibraryCollection, que tiene:

Un nombre (collectionName)

El total de libros (totalBooks)

Libros por categoría (booksByCategory, de tamaño fijo 3)*/

//g++ -std=c++11 main.cpp library_management.cpp -o programme 

#ifndef LIBRARY_MANAGEMENT_H
#define LIBRARY_MANAGEMENT_H

#include <string>
#include <vector>

// Clase que representa una colección de biblioteca.
// Maneja el nombre de la biblioteca, el número total de libros declarados,
// y la distribución de libros por categoría (por ejemplo: Ciencia, Literatura, Historia)

class LibraryCollection { 
private:
    std::string collectionName;       // Nombre de la biblioteca
    int totalBooks;                   // Número total de libros (valor informativo)
    std::vector<int> booksByCategory; // Lista de libros por categoría (máximo 3 categorías)

public:
    // Constructor: inicializa el nombre de la biblioteca y la cantidad total de libros
    LibraryCollection(const std::string& name, int totalBooks);

    // Añade un número de libros a la siguiente categoría disponible.
    // El orden esperado es: 0 = Ciencia, 1 = Literatura, 2 = Historia
    void addBooksByCategory(int count);

    // Devuelve el nombre de la colección
    std::string getCollectionName() const;

    // Calcula el índice de diversidad de categorías basado en la distribución de libros
    double calculateCategoryDiversityRatio() const;

    // Verifica si la colección cumple un umbral mínimo de diversidad (por defecto: 60%)
    bool meetsDiversityThreshold(double threshold = 0.6) const;

    // Encuentra el índice de la categoría con más libros (0 = Ciencia, etc.)
    int findMostPopularCategoryIndex() const;
};

#endif
