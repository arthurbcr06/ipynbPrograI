#ifndef GRADES_H
#define GRADES_H

#include <string>
#include <vector>
#include <map>
#include <stdexcept>

class CalificacionesException : public std::runtime_error {
public:
    explicit CalificacionesException(const std::string& mensaje)
        : std::runtime_error(mensaje) {}
};

class Estudiante {
public:
    int id;
    std::string nombre;
    std::string apellido;
    std::map<std::string, std::vector<double>> asignaturas;

    Estudiante(int id, const std::string& nombre, const std::string& apellido);
};

class SistemaCalificaciones {
private:
    std::vector<Estudiante> estudiantes;

    Estudiante* encontrarEstudiante(int id);
    const Estudiante* encontrarEstudiante(int id) const;

public:
    void agregarEstudiante(const Estudiante& estudiante);
    void eliminarEstudiante(int id);
    void agregarAsignatura(int idEstudiante, const std::string& asignatura);
    void agregarCalificacion(int idEstudiante, const std::string& asignatura, double nota);
    void mostrarCalificacionesEstudiante(int idEstudiante) const;
    void mostrarPromedioGeneral(int idEstudiante) const;
    void mostrarTodosLosEstudiantes() const;
    void mostrarMejoresEstudiantes() const;
    Estudiante buscarEstudiante(int idEstudiante) const;
};

#endif // GRADES_H
