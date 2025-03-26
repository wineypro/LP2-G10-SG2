#include <iostream>
#include "Carro.h"

using namespace std;

void mostrarMenu() {
    cout << "\n--- Menú ---\n";
    cout << "1. Mover el carro\n";
    cout << "2. Cambiar ruedas\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    int tamanoInicial;
    cout << "Ingrese el tamaño inicial de las ruedas: ";
    cin >> tamanoInicial;

    Carro carro(tamanoInicial);
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        if (opcion == 1) {
            carro.mover();
        } else if (opcion == 2) {
            int nuevoTamano;
            cout << "Ingrese el nuevo tamaño de las ruedas: ";
            cin >> nuevoTamano;
            carro.cambiarRuedas(nuevoTamano);
        }
    } while (opcion != 3);

    return 0;
}
