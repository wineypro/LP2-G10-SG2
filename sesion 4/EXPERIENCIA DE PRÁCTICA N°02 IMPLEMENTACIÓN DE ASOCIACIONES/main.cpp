#include <iostream>
#include "Curso.h"
#include "Estudiante.h"
using namespace std;

int main() {
    Estudiante e1("Luis", "Gomez", "001", "luis@example.com");
    Estudiante e2("Ana", "Pérez", "002", "ana@example.com");
    Estudiante e3("Carlos", "Lopez", "003", "carlos@example.com");

    Curso c1("Matemática", "MAT101", "Básico", "01-04", "30-06");
    Curso c2("Historia", "HIS201", "Intermedio", "01-04", "30-06");

    c1.agregarEstudiante(&e1);
    c1.agregarEstudiante(&e2);
    c2.agregarEstudiante(&e1);
    c2.agregarEstudiante(&e3);

    c1.eliminarEstudiante(&e2);
    e1.eliminarCurso(&c2);

    c1.imprimirEstudiantes();
    c2.imprimirEstudiantes();

    e1.imprimirCursos();
    e2.imprimirCursos();
    e3.imprimirCursos();

    return 0;
}
