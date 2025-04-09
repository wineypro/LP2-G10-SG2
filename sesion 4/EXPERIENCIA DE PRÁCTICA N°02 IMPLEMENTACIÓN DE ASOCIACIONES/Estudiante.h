#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>
using namespace std;

class Curso;

class Estudiante {
private:
    string nombre, apellido, id, correo;
    Curso* cursos[10];
    int numCursos;
public:
    Estudiante(string _nombre, string _apellido, string _id, string _correo) {
        nombre = _nombre;
        apellido = _apellido;
        id = _id;
        correo = _correo;
        numCursos = 0;
    }
    void agregarCurso(Curso* c) {
        if (numCursos < 10) {
            cursos[numCursos] = c;
            numCursos++;
        }
    }
    void eliminarCurso(Curso* c) {
        for (int i = 0; i < numCursos; i++) {
            if (cursos[i] == c) {
                for (int j = i; j < numCursos - 1; j++) {
                    cursos[j] = cursos[j + 1];
                }
                numCursos--;
                break;
            }
        }
    }
    string getNombre() {
        return nombre;
    }
    void imprimirCursos();
};
#endif
