#include <iostream>
#include <string>
using namespace std;


template <typename T>
class Recipiente {
private:
    T elementos[10];
    int total;

public:
    Recipiente() {
        total = 0;
    }

    void agregarElemento(T valor) {
        if (total < 10) {
            elementos[total++] = valor;
        } else {
            cout << "Recipiente lleno, no se puede agregar mas elementos." << endl;
        }
    }

    void mostrarElementos() {
        cout << "Elementos almacenados (" << total << "):" << endl;
        for (int i = 0; i < total; i++) {
            cout << "- " << elementos[i] << endl;
        }
    }

    int cantidad() {
        return total;
    }

    T* obtenerArreglo() {
        return elementos;
    }
};

int main() {
    int opcion;

    do {
        cout << "1. Ingresar enteros" << endl;
        cout << "2. Ingresar decimales" << endl;
        cout << "3. Ingresar textos" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Recipiente<int> rEnteros;
            int cantidad;
            cout << "Cuantos enteros desea ingresar (max 10): ";
            cin >> cantidad;
            for (int i = 0; i < cantidad && i < 10; i++) {
                int valor;
                cout << "Ingrese entero #" << i + 1 << ": ";
                cin >> valor;
                rEnteros.agregarElemento(valor);
            }
            rEnteros.mostrarElementos();
        }

        else if (opcion == 2) {
            Recipiente<float> rFloats;
            int cantidad;
            cout << "Cuantos decimales desea ingresar (max 10): ";
            cin >> cantidad;
            for (int i = 0; i < cantidad && i < 10; i++) {
                float valor;
                cout << "Ingrese decimal #" << i + 1 << ": ";
                cin >> valor;
                rFloats.agregarElemento(valor);
            }
            rFloats.mostrarElementos();
        }

        else if (opcion == 3) {
            Recipiente<string> rTextos;
            int cantidad;
            cout << "Cuantos textos desea ingresar (max 10): ";
            cin >> cantidad;
            cin.ignore(); // limpiar salto de linea
            for (int i = 0; i < cantidad && i < 10; i++) {
                string texto;
                cout << "Ingrese texto #" << i + 1 << ": ";
                getline(cin, texto);
                rTextos.agregarElemento(texto);
            }
            rTextos.mostrarElementos();
        }

        else if (opcion == 4) {
            cout << "Saliendo del programa..." << endl;
        }

        else {
            cout << "Opcion invalida, intente de nuevo." << endl;
        }

    } while (opcion != 4);

    return 0;
}
