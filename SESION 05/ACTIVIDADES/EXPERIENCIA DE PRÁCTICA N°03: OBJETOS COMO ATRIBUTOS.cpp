#include <iostream>
using namespace std;

class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha(int d = 1, int m = 1, int a = 2000) : dia(d), mes(m), anio(a) {}
    void mostrar() const {
        cout << dia << "/" << mes << "/" << anio;
    }
};

class Contrato {
private:
    string codigo;
    string descripcion;
    Fecha fechaInicio;
public:
    Contrato(string c, string d, const Fecha& f)
        : codigo(c), descripcion(d), fechaInicio(f) {}

    void mostrar() const {
        cout << "Codigo: " << codigo << endl;
        cout << "Descripción: " << descripcion << endl;
        cout << "Fecha de inicio: ";
        fechaInicio.mostrar();
        cout << endl;
    }
};

class Empleado {
private:
    string nombre;
    Contrato contrato;
public:
    Empleado(string nom, const Contrato& c)
        : nombre(nom), contrato(c) {}

    void mostrar() const {
        cout << "Empleado: " << nombre << endl;
        cout << "Contrato:" << endl;
        contrato.mostrar();
    }
};


int main() {
    Fecha f(29, 4, 2025);
    Contrato c("CT-001", "Contrato indefinido", f);
    Empleado e("Carlos Gomez", c);

    e.mostrar();

    return 0;
}
