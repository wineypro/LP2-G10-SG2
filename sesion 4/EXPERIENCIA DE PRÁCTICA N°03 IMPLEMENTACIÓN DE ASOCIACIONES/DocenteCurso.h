#ifndef DOCENTECURSO_H
#define DOCENTECURSO_H
#include <string>
#include <iostream>
#include "Estudiante.h"
using namespace std;

class Docente {
private:
    string nombre;
public:
    Docente(string _nombre) {
        nombre = _nombre;
    }
    string getNombre() {
        return nombre;
    }
};

class Curso {
private:
    string nombre;
public:
    Curso(string _nombre) {
        nombre = _nombre;
    }
    string getNombre() {
        return nombre;
    }
};

class Asociacion {
private:
    Estudiante* estudiante;
    Docente* docente;
    Curso* curso;
public:
    Asociacion(Estudiante* _estudiante, Docente* _docente, Curso* _curso) {
        estudiante = _estudiante;
        docente = _docente;
        curso = _curso;
    }
    void imprimirRelacion() {
        cout << "Estudiante: " << estudiante->getNombre()
             << " - Docente: " << docente->getNombre()
             << " - Curso: " << curso->getNombre() << endl;
    }
};
#endif
