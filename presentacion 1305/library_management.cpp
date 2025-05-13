/*El índice de diversidad calcula qué tan equilibradas están las 3 categorías:

Si todas tienen casi la misma cantidad de libros → cercano a 1

Si una domina mucho → índice más bajo

La función meetsDiversityThreshold() verifica si ese índice es mayor o igual a 0.6 (60%).*/
#include "library_management.h"
#include <stdexcept>
#include <numeric>   // Para std::accumulate
#include <algorithm> // Para std::max_element

// Constructor: inicializa los atributos con los valores dados
LibraryCollection::LibraryCollection(const std::string& name, int totalBooks)
    : collectionName(name), totalBooks(totalBooks) {
    booksByCategory.reserve(3); // Reservamos espacio para 3 categorías
}

// Añade una cantidad de libros a la siguiente categoría disponible
void LibraryCollection::addBooksByCategory(int count) {
    // Verifica que no se superen las 3 categorías esperadas
    if (booksByCategory.size() >= 3) {
        throw std::runtime_error("Ya se han añadido todas las categorías permitidas.");
    }
    booksByCategory.push_back(count);
}

// Devuelve el nombre de la colección
std::string LibraryCollection::getCollectionName() const {
    return collectionName;
}

// Calcula el ratio de diversidad entre categorías
// Una distribución más equilibrada da un ratio más alto
double LibraryCollection::calculateCategoryDiversityRatio() const {
    if (booksByCategory.empty()) return 0.0;

    double total = std::accumulate(booksByCategory.begin(), booksByCategory.end(), 0);
    if (total == 0) return 0.0;

    // Distribución ideal: libros equitativos entre categorías
    double esperado = total / booksByCategory.size();
    double sumaDeRelaciones = 0.0;

    for (int count : booksByCategory) {
        double relacion = static_cast<double>(count) / esperado;
        // Se usa una métrica simétrica que penaliza grandes desequilibrios
        sumaDeRelaciones += (relacion < 1 ? relacion : 1 / relacion);
    }

    // Promedio normalizado entre 0 y 1
    return sumaDeRelaciones / booksByCategory.size();
}

// Verifica si la colección cumple con un nivel mínimo de diversidad
bool LibraryCollection::meetsDiversityThreshold(double threshold) const {
    return calculateCategoryDiversityRatio() >= threshold;
}

// Retorna el índice de la categoría con mayor número de libros
int LibraryCollection::findMostPopularCategoryIndex() const {
    if (booksByCategory.empty()) {
        throw std::runtime_error("No hay categorías definidas.");
    }

    // Retorna el índice del elemento con valor máximo
    return std::distance(booksByCategory.begin(),
                         std::max_element(booksByCategory.begin(), booksByCategory.end()));
}
