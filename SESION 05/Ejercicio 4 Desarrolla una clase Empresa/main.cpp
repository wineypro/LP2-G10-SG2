#include <iostream>
using namespace std;

class Gerente {
private:
    string nombre;
public:
    Gerente(string _nombre) {
        nombre = _nombre;
        cout << "Constructor de Gerente: " << nombre << endl;
    }
    ~Gerente() {
        cout << "Destructor de Gerente: " << nombre << endl;
    }
};

class Direccion {
private:
    string ciudad;
public:
    Direccion(string _ciudad) {
        ciudad = _ciudad;
        cout << "Constructor de Direccion: " << ciudad << endl;
    }
    ~Direccion() {
        cout << "Destructor de Direccion: " << ciudad << endl;
    }
};

class Empresa {
private:
    Gerente gerente;
    Direccion direccion;

public:
    Empresa(string nomGerente, string ciudadDireccion)
        : gerente(nomGerente), direccion(ciudadDireccion) {
        cout << "Constructor de Empresa" << endl;
    }

    ~Empresa() {
        cout << "Destructor de Empresa" << endl;
    }
};

string leerTexto(string mensaje) {
    string entrada;
    do {
        cout << mensaje;
        getline(cin, entrada);
        if (entrada.empty()) {
            cout << "Entrada no puede estar vacía. Intente nuevamente." << endl;
        }
    } while (entrada.empty());
    return entrada;
}

int main() {
    int opcion;
    string nombreGerente, ciudadEmpresa;

    while (true) {
        cout << "=== MENU ===" << endl;
        cout << "1. Crear Empresa" << endl;
        cout << "2. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                nombreGerente = leerTexto("Ingrese el nombre del gerente: ");
                ciudadEmpresa = leerTexto("Ingrese la ciudad de la empresa: ");
                cout << "Constructor de Empresa" << endl;
                {
                    Empresa miEmpresa(nombreGerente, ciudadEmpresa);
                }
                break;
            case 2:
                cout << "Programa finalizado." << endl;
                return 0;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}
