#include "grades.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

// --- Estudiante ---
Estudiante::Estudiante(int id, const std::string& nombre, const std::string& apellido)
    : id(id), nombre(nombre), apellido(apellido) {}


// --- SistemaCalificaciones ---

Estudiante* SistemaCalificaciones::encontrarEstudiante(int id) {
    for (auto& est : estudiantes) {
        if (est.id == id)
            return &est;
    }
    return nullptr;
}

const Estudiante* SistemaCalificaciones::encontrarEstudiante(int id) const {
    for (const auto& est : estudiantes) {
        if (est.id == id)
            return &est;
    }
    return nullptr;
}

void SistemaCalificaciones::agregarEstudiante(const Estudiante& estudiante) {
    if (encontrarEstudiante(estudiante.id))
        throw CalificacionesException("ID de estudiante duplicado.");
    estudiantes.push_back(estudiante);
}

void SistemaCalificaciones::eliminarEstudiante(int id) {
    auto it = std::remove_if(estudiantes.begin(), estudiantes.end(),
        [id](const Estudiante& est) { return est.id == id; });

    if (it == estudiantes.end())
        throw CalificacionesException("Estudiante no encontrado.");
    estudiantes.erase(it, estudiantes.end());
}

void SistemaCalificaciones::agregarAsignatura(int idEstudiante, const std::string& asignatura) {
    Estudiante* est = encontrarEstudiante(idEstudiante);
    if (!est)
        throw CalificacionesException("Estudiante no encontrado.");

    if (est->asignaturas.count(asignatura))
        throw CalificacionesException("Asignatura ya agregada.");

    est->asignaturas[asignatura] = {};
}

void SistemaCalificaciones::agregarCalificacion(int idEstudiante, const std::string& asignatura, double nota) {
    if (nota < 0.0 || nota > 10.0)
        throw CalificacionesException("Nota inválida. Debe estar entre 0 y 10.");

    Estudiante* est = encontrarEstudiante(idEstudiante);
    if (!est)
        throw CalificacionesException("Estudiante no encontrado.");

    if (!est->asignaturas.count(asignatura))
        throw CalificacionesException("Asignatura no encontrada.");

    est->asignaturas[asignatura].push_back(nota);
}

void SistemaCalificaciones::mostrarCalificacionesEstudiante(int idEstudiante) const {
    const Estudiante* est = encontrarEstudiante(idEstudiante);
    if (!est)
        throw CalificacionesException("Estudiante no encontrado.");

    std::cout << est->nombre << " " << est->apellido << ":\n";
    for (const auto& pair : est->asignaturas) {
        std::cout << "  " << pair.first << ": ";
        for (double nota : pair.second) {
            std::cout << std::fixed << std::setprecision(1) << nota << " ";
        }
        std::cout << "\n";
    }
}

void SistemaCalificaciones::mostrarPromedioGeneral(int idEstudiante) const {
    const Estudiante* est = encontrarEstudiante(idEstudiante);
    if (!est)
        throw CalificacionesException("Estudiante no encontrado.");

    int totalNotas = 0;
    double suma = 0.0;

    for (const auto& pair : est->asignaturas) {
        for (double nota : pair.second) {
            suma += nota;
            totalNotas++;
        }
    }

    if (totalNotas == 0) {
        std::cout << est->nombre << " " << est->apellido << ": Sin calificaciones." << std::endl;
    } else {
        double promedio = suma / totalNotas;
        std::cout << est->nombre << " " << est->apellido << ": Promedio = "
                  << std::fixed << std::setprecision(2) << promedio << std::endl;
    }
}

void SistemaCalificaciones::mostrarTodosLosEstudiantes() const {
    for (const auto& est : estudiantes) {
        std::cout << "ID: " << est.id << ", Nombre: " << est.nombre << " " << est.apellido << std::endl;
    }
}

void SistemaCalificaciones::mostrarMejoresEstudiantes() const {
    double mejorPromedio = 0.0;
    std::vector<const Estudiante*> mejores;

    for (const auto& est : estudiantes) {
        int totalNotas = 0;
        double suma = 0.0;

        for (const auto& pair : est.asignaturas) {
            for (double nota : pair.second) {
                suma += nota;
                totalNotas++;
            }
        }

        if (totalNotas == 0) continue;

        double promedio = suma / totalNotas;

        if (promedio > mejorPromedio) {
            mejorPromedio = promedio;
            mejores.clear();
            mejores.push_back(&est);
        } else if (promedio == mejorPromedio) {
            mejores.push_back(&est);
        }
    }

    if (mejores.empty()) {
        std::cout << "No hay calificaciones registradas." << std::endl;
    } else {
        for (const auto* est : mejores) {
            std::cout << est->nombre << " " << est->apellido
                      << " - Promedio: " << std::fixed << std::setprecision(2)
                      << mejorPromedio << std::endl;
        }
    }
}

Estudiante SistemaCalificaciones::buscarEstudiante(int idEstudiante) const {
    const Estudiante* est = encontrarEstudiante(idEstudiante);
    if (!est)
        throw CalificacionesException("Estudiante no encontrado.");
    return *est;
}
