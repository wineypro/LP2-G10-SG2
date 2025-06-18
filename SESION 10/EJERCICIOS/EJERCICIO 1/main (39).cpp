#include <iostream>
#include <string>
using namespace std;

template <typename T>
class SistemaEntrega {
private:
    T entregas[10];
    int total;

public:
    SistemaEntrega() {
        total = 0;
    }

    void agregarEntrega(T entrega) {
        if (total < 10) {
            entregas[total++] = entrega;
        }
    }

    T* obtenerEntregas() {
        return entregas;
    }

    int cantidadEntregas() {
        return total;
    }

    void mostrarEntregas() {
        cout << "Listado de entregas (" << total << "):" << endl;
        for (int i = 0; i < total; i++) {
            cout << "- " << entregas[i] << endl;
        }
    }
};


template <typename T>
void ordenarArreglo(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Arreglo ordenado:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "- " << arr[i] << endl;
    }
}

int main() {
    int opcion;
    cout << "Tipo de datos para ingresar entregas:" << endl;
    cout << "1. Enteros" << endl;
    cout << "2. Decimales" << endl;
    cout << "3. Texto (Zonas)" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    int cantidad;
    cout << "Cuantos elementos desea ingresar (max. 10)? ";
    cin >> cantidad;

    switch (opcion) {
        case 1: {
            SistemaEntrega<int> sistema;
            for (int i = 0; i < cantidad; i++) {
                int valor;
                cout << "Ingrese numero entero #" << i + 1 << ": ";
                cin >> valor;
                sistema.agregarEntrega(valor);
            }
            sistema.mostrarEntregas();
            ordenarArreglo(sistema.obtenerEntregas(), sistema.cantidadEntregas());
            break;
        }

        case 2: {
            SistemaEntrega<float> sistema;
            for (int i = 0; i < cantidad; i++) {
                float valor;
                cout << "Ingrese numero decimal #" << i + 1 << ": ";
                cin >> valor;
                sistema.agregarEntrega(valor);
            }
            sistema.mostrarEntregas();
            ordenarArreglo(sistema.obtenerEntregas(), sistema.cantidadEntregas());
            break;
        }

        case 3: {
            SistemaEntrega<string> sistema;
            cin.ignore(); 
            for (int i = 0; i < cantidad; i++) {
                string texto;
                cout << "Ingrese texto #" << i + 1 << ": ";
                getline(cin, texto);
                sistema.agregarEntrega(texto);
            }
            sistema.mostrarEntregas();
            ordenarArreglo(sistema.obtenerEntregas(), sistema.cantidadEntregas());
            break;
        }

        default:
            cout << "Opcion invalida." << endl;
    }

    return 0;
}
