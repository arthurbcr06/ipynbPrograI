#include <iostream>
#include <iomanip>
#include <stdexcept> // Include for std::exception
#include "TArrayInt.h"

int main() {
    try {
        TArrayInt a(10);
        a.SetElement(0, 4);
        a.SetElement(1, 6);
        a.SetElement(2, 3);
        a.SetElement(3, 0);
        a.SetElement(4, 11);
        a.SetElement(5, 0);
        a.SetElement(6, 2);
        a.SetElement(7, 0);
        a.SetElement(8, 2);
        a.SetElement(9, 9);

        std::cout << "¿Qué longitud tiene el array a?: " << a.GetLength() << std::endl;
        std::cout << "¿Cuánto zeros tiene el array a?: " << a.CountZeros() << std::endl;
        std::cout << "El array a está lleno? : " << a.IsFull() << std::endl;

        if (!a.InsertLast(6)) {
            throw std::runtime_error("Failed to insert element.");
        }

        std::cout << "Después de la inserción de un último elemento ¿Qué longitud tiene el array a?: " << a.GetLength() << std::endl;

        for (int i = 0; i < a.GetLength(); ++i) {
            std::cout << "Elemento " << i + 1 << " del array a: " << a.GetElement(i) << std::endl;
        }

        int suma = a.Sum();
        std::cout << "Suma de los elementos del array a: " << suma << std::endl;

        float c = a.Average();
        std::cout << "Promedio de los elementos del array a: " << std::fixed << std::setprecision(4) << c << std::endl;

        TArrayInt b(0);
        std::cout << "El array b está vacío?: " << b.IsEmpty() << std::endl;

    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error occurred." << std::endl;
    }

    return 0;
}
