#include <iostream>
#include <stdexcept> // Include for std::exception
#include "TSanSilvestre.h"

int main() {
    try {
        TDDate fecha;
        fecha.Day = 10;
        fecha.Mounth = 2; // Corrected from 02 to 2
        fecha.Year = 1990;

        TSanSilvestre* deportista = new TSanSilvestre("Juan", "Atletismo");
        if (!deportista) {
            throw std::runtime_error("Memory allocation failed.");
        }

        deportista->SetBirth(fecha);
        std::cout << "La fecha de nacimiento del deportista es: "
                  << deportista->GetBirth().Day << ", "
                  << deportista->GetBirth().Mounth << ", "
                  << deportista->GetBirth().Year << std::endl;

        std::cout << "El nombre del deportista es: " << deportista->GetName() << std::endl;
        std::cout << "El deporte es: " << deportista->GetDeporte() << std::endl;

        deportista->SetRecord(0, 10.0);
        deportista->SetRecord(1, 11.0);
        deportista->SetRecord(2, 12.0);
        deportista->SetRecord(3, 13.0);
        deportista->SetRecord(4, 14.0);

        for (int i = 0; i < 5; ++i) {
            std::cout << "El record " << i + 1 << " es: " << deportista->GetRecord(i) << std::endl;
        }

        std::cout << "El promedio es: " << deportista->Compare(30.5) << std::endl;

        delete deportista;

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
