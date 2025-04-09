#include <iostream>
#include "DocenteCurso.h"
using namespace std;

int main() {
    Estudiante* e1 = new Estudiante("Luis");
    Estudiante* e2 = new Estudiante("Ana");

    Docente* d1 = new Docente("Profesor García");
    Docente* d2 = new Docente("Profesora Díaz");

    Curso* c1 = new Curso("Matemática");
    Curso* c2 = new Curso("Física");

    Asociacion* a1 = new Asociacion(e1, d1, c1);
    Asociacion* a2 = new Asociacion(e2, d1, c1);
    Asociacion* a3 = new Asociacion(e1, d2, c2);

    a1->imprimirRelacion();
    a2->imprimirRelacion();
    a3->imprimirRelacion();

    delete e1;
    delete e2;
    delete d1;
    delete d2;
    delete c1;
    delete c2;
    delete a1;
    delete a2;
    delete a3;

    return 0;
}
