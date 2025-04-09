#ifndef CURSO_H
#define CURSO_H
#include <iostream>
#include "Estudiante.h"
using namespace std;

class Curso {
private:
    string nombre, codigo, descripcion, fechaInicio, fechaFin;
    Estudiante* estudiantes[10];
    int numEstudiantes;
public:
    Curso(string _nombre, string _codigo, string _descripcion, string _fechaInicio, string _fechaFin) {
        nombre = _nombre;
        codigo = _codigo;
        descripcion = _descripcion;
        fechaInicio = _fechaInicio;
        fechaFin = _fechaFin;
        numEstudiantes = 0;
    }
    void agregarEstudiante(Estudiante* e) {
        if (numEstudiantes < 10) {
            estudiantes[numEstudiantes] = e;
            numEstudiantes++;
            e->agregarCurso(this);
        }
    }
    void eliminarEstudiante(Estudiante* e) {
        for (int i = 0; i < numEstudiantes; i++) {
            if (estudiantes[i] == e) {
                for (int j = i; j < numEstudiantes - 1; j++) {
                    estudiantes[j] = estudiantes[j + 1];
                }
                numEstudiantes--;
                break;
            }
        }
        e->eliminarCurso(this);
    }
    string getNombre() {
        return nombre;
    }
    void imprimirEstudiantes() {
        cout << "Curso: " << nombre << endl;
        for (int i = 0; i < numEstudiantes; i++) {
            cout << "- " << estudiantes[i]->getNombre() << endl;
        }
    }
};

void Estudiante::imprimirCursos() {
    cout << "Estudiante: " << nombre << " " << apellido << endl;
    for (int i = 0; i < numCursos; i++) {
        cout << "- " << cursos[i]->getNombre() << endl;
    }
}
#endif
