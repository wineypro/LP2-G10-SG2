#include <iostream>
using namespace std;

class Cliente {
protected:
    string nombre;
    string apellido;

public:
    Cliente(string n, string a)
        : nombre(n), apellido(a) {}

    void mostrarNombre() {
        cout << "Nombre completo: " << nombre << " " << apellido << endl;
    }
};

// Herencia publica

class ClientePublico : public Cliente {
public:
    ClientePublico(string n, string a)
        : Cliente(n, a) {}

    void mostrar() {
        mostrarNombre();
    }
};

// Herencia protegida
class ClienteProtegido : protected Cliente {
public:
    ClienteProtegido(string n, string a)
        : Cliente(n, a) {}

    void mostrar() {
        mostrarNombre();
    }
};

// Herencia privada
class ClientePrivado : private Cliente {
public:
    ClientePrivado(string n, string a)
        : Cliente(n, a) {}

    void mostrar() {
        mostrarNombre();
    }
};

int main() {
    ClientePublico cliente1("Ana", "Torres");
    ClienteProtegido cliente2("Luis", "Perez");
    ClientePrivado cliente3("Carlos", "Gomez");

    cout << "--- Herencia Publica ---" << endl;
    cliente1.mostrar();

    cout << "\n--- Herencia Protegida ---" << endl;
    cliente2.mostrar();

    cout << "\n--- Herencia Privada ---" << endl;
    cliente3.mostrar();

    return 0;
}