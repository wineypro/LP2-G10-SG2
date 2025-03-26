#include <iostream>
#include "Factura.h"

using namespace std;

void mostrarMenu() {
    cout << "\n--- Menú ---\n";
    cout << "1. Agregar producto a la factura\n";
    cout << "2. Mostrar factura\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    Factura factura;
    Producto producto1("Laptop", 1200, 10);
    Producto producto2("Mouse", 25, 50);

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string nombre;
            int cantidad;

            cout << "Ingrese el nombre del producto (Laptop o Mouse): ";
            getline(cin, nombre);
            cout << "Cantidad: ";
            cin >> cantidad;

            if (nombre == "Laptop") {
                factura.agregarProducto(producto1, cantidad);
            } else if (nombre == "Mouse") {
                factura.agregarProducto(producto2, cantidad);
            } else {
                cout << "Producto no encontrado.\n";
            }
        } else if (opcion == 2) {
            double descuento, impuesto;
            cout << "Ingrese descuento (%): ";
            cin >> descuento;
            cout << "Ingrese impuesto (%): ";
            cin >> impuesto;
            factura.calcularTotal(descuento, impuesto);
        }
    } while (opcion != 3);

    return 0;
}
