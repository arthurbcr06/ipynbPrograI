#include "task_manager.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

// --- Tarea ---

Tarea::Tarea(int id, const std::string& titulo, const std::string& descripcion, int prioridad)
    : id(id), titulo(titulo), descripcion(descripcion), prioridad(prioridad), estado(Pendiente) {
    if (prioridad < 1 || prioridad > 5)
        throw TareaException("Prioridad fuera de rango (1-5).");
}

int Tarea::getId() const { return id; }
std::string Tarea::getTitulo() const { return titulo; }
std::string Tarea::getDescripcion() const { return descripcion; }
int Tarea::getPrioridad() const { return prioridad; }
Tarea::Estado Tarea::getEstado() const { return estado; }

void Tarea::setEstado(Estado nuevoEstado) {
    estado = nuevoEstado;
}

std::string Tarea::estadoComoTexto() const {
    switch (estado) {
        case Pendiente: return "Pendiente";
        case EnProgreso: return "En Progreso";
        case Completada: return "Completada";
        default: return "Desconocido";
    }
}

// --- GestorTareas ---

GestorTareas::GestorTareas() : siguienteId(1) {}

void GestorTareas::agregarTarea(const std::string& titulo, const std::string& descripcion, int prioridad) {
    Tarea nueva(siguienteId++, titulo, descripcion, prioridad);
    tareas.push_back(nueva);
    std::cout << "Tarea agregada con ID " << nueva.getId() << "." << std::endl;
}

void GestorTareas::listarTareas() const {
    if (tareas.empty()) {
        std::cout << "No hay tareas registradas." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(5) << "ID"
              << std::setw(20) << "Título"
              << std::setw(30) << "Descripción"
              << std::setw(10) << "Prioridad"
              << std::setw(15) << "Estado" << std::endl;

    for (const auto& tarea : tareas) {
        std::cout << std::left << std::setw(5) << tarea.getId()
                  << std::setw(20) << tarea.getTitulo()
                  << std::setw(30) << tarea.getDescripcion()
                  << std::setw(10) << tarea.getPrioridad()
                  << std::setw(15) << tarea.estadoComoTexto() << std::endl;
    }
}

Tarea* GestorTareas::encontrarTareaPorId(int id) {
    for (auto& tarea : tareas) {
        if (tarea.getId() == id)
            return &tarea;
    }
    return nullptr;
}

void GestorTareas::actualizarEstado(int id, Tarea::Estado nuevoEstado) {
    Tarea* tarea = encontrarTareaPorId(id);
    if (!tarea)
        throw TareaException("Tarea no encontrada.");
    tarea->setEstado(nuevoEstado);
    std::cout << "Estado actualizado para la tarea ID " << id << "." << std::endl;
}

void GestorTareas::eliminarTarea(int id) {
    auto it = std::remove_if(tareas.begin(), tareas.end(), [id](const Tarea& t) {
        return t.getId() == id;
    });

    if (it == tareas.end())
        throw TareaException("Tarea no encontrada.");

    tareas.erase(it, tareas.end());
    std::cout << "Tarea con ID " << id << " eliminada." << std::endl;
}

void GestorTareas::filtrarPorEstado(Tarea::Estado estado) const {
    bool encontrada = false;
    for (const auto& tarea : tareas) {
        if (tarea.getEstado() == estado) {
            if (!encontrada) {
                std::cout << "\nTareas con estado '" << tarea.estadoComoTexto() << "':\n";
                std::cout << std::left << std::setw(5) << "ID"
                          << std::setw(20) << "Título"
                          << std::setw(30) << "Descripción"
                          << std::setw(10) << "Prioridad"
                          << std::setw(15) << "Estado" << std::endl;
                encontrada = true;
            }
            std::cout << std::left << std::setw(5) << tarea.getId()
                      << std::setw(20) << tarea.getTitulo()
                      << std::setw(30) << tarea.getDescripcion()
                      << std::setw(10) << tarea.getPrioridad()
                      << std::setw(15) << tarea.estadoComoTexto() << std::endl;
        }
    }

    if (!encontrada)
        std::cout << "No se encontraron tareas con ese estado." << std::endl;
}
