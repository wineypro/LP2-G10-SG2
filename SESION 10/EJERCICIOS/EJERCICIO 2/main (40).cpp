#include <iostream>
#include <string>
using namespace std;

class SistemaOrdenamiento {
public:
    template <typename T>
    void ordenarYMostrar(T arr[], int n) {
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
};

template <typename T>
class SistemaEntrega {
private:
    T entregas[10];
    int total;

public:
    SistemaEntrega() : total(0) {}

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
        cout << "Listado original de entregas:" << endl;
        for (int i = 0; i < total; i++) {
            cout << "- " << entregas[i] << endl;
        }
    }
};

int main() {
    SistemaOrdenamiento orden;
    int opcion;

    do {
        cout << "1. Ingresar numeros enteros" << endl;
        cout << "2. Ingresar numeros decimales" << endl;
        cout << "3. Ingresar textos" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            SistemaEntrega<int> sistemaInt;
            int cantidad;
            cout << "Cuantos numeros enteros desea ingresar (max 10): ";
            cin >> cantidad;
            for (int i = 0; i < cantidad; i++) {
                int valor;
                cout << "Ingrese entero #" << i + 1 << ": ";
                cin >> valor;
                sistemaInt.agregarEntrega(valor);
            }
            sistemaInt.mostrarEntregas();
            orden.ordenarYMostrar(sistemaInt.obtenerEntregas(), sistemaInt.cantidadEntregas());
        }

        else if (opcion == 2) {
            SistemaEntrega<float> sistemaFloat;
            int cantidad;
            cout << "Cuantos numeros decimales desea ingresar (max 10): ";
            cin >> cantidad;
            for (int i = 0; i < cantidad; i++) {
                float valor;
                cout << "Ingrese decimal #" << i + 1 << ": ";
                cin >> valor;
                sistemaFloat.agregarEntrega(valor);
            }
            sistemaFloat.mostrarEntregas();
            orden.ordenarYMostrar(sistemaFloat.obtenerEntregas(), sistemaFloat.cantidadEntregas());
        }

        else if (opcion == 3) {
            SistemaEntrega<string> sistemaTexto;
            int cantidad;
            cout << "Cuantos textos desea ingresar (max 10): ";
            cin >> cantidad;
            cin.ignore(); 
            for (int i = 0; i < cantidad; i++) {
                string texto;
                cout << "Ingrese texto #" << i + 1 << ": ";
                getline(cin, texto);
                sistemaTexto.agregarEntrega(texto);
            }
            sistemaTexto.mostrarEntregas();
            orden.ordenarYMostrar(sistemaTexto.obtenerEntregas(), sistemaTexto.cantidadEntregas());
        }

        else if (opcion == 4) {
            cout << "Saliendo del programa..." << endl;
        }

        else {
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }

    } while (opcion != 4);

    return 0;
}
