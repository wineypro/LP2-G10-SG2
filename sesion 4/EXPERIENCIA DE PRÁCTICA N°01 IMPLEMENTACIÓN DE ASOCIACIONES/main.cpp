#include <iostream>
#include "Padre.h"
#include "Hijo.h"
using namespace std;

int main() {
    Padre p("Carlos");

    Hijo h1("Luis");
    Hijo h2("Ana");
    Hijo h3("Pedro");

    p.agregarHijo(&h1);
    p.agregarHijo(&h2);
    p.agregarHijo(&h3);

    p.imprimirInfo();

    return 0;
}
