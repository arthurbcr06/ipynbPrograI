#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <string>
#include <vector>
#include <stdexcept>

class TareaException : public std::runtime_error {
public:
    explicit TareaException(const std::string& mensaje)
        : std::runtime_error(mensaje) {}
};

class Tarea {
public:
    enum Estado {
        Pendiente = 0,
        EnProgreso = 1,
        Completada = 2
    };

    Tarea(int id, const std::string& titulo, const std::string& descripcion, int prioridad);

    int getId() const;
    std::string getTitulo() const;
    std::string getDescripcion() const;
    int getPrioridad() const;
    Estado getEstado() const;

    void setEstado(Estado nuevoEstado);

    std::string estadoComoTexto() const;

private:
    int id;
    std::string titulo;
    std::string descripcion;
    int prioridad;
    Estado estado;
};

class GestorTareas {
private:
    std::vector<Tarea> tareas;
    int siguienteId;

    Tarea* encontrarTareaPorId(int id);

public:
    GestorTareas();

    void agregarTarea(const std::string& titulo, const std::string& descripcion, int prioridad);
    void listarTareas() const;
    void actualizarEstado(int id, Tarea::Estado nuevoEstado);
    void eliminarTarea(int id);
    void filtrarPorEstado(Tarea::Estado estado) const;
};

#endif // TASK_MANAGER_H
