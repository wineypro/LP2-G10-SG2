#include <iostream>
#include "Tienda.h"

using namespace std;

void mostrarMenu() {
    cout << "\n--- Menú ---\n";
    cout << "1. Ver productos\n";
    cout << "2. Agregar producto al carrito\n";
    cout << "3. Pagar\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    Tienda tienda;
    tienda.agregarProducto(Producto("Camisa", 20.0));
    tienda.agregarProducto(Producto("Pantalón", 30.0));
    tienda.agregarProducto(Producto("Zapatos", 50.0));

    Cliente cliente("Juan");
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            tienda.mostrarProductos();
        } else if (opcion == 2) {
            string nombre;
            cout << "Ingrese el nombre del producto: ";
            getline(cin, nombre);

            Producto producto = tienda.buscarProducto(nombre);
            if (producto.getNombre() != "") {
                cliente.agregarProducto(producto);
            } else {
                cout << "Producto no encontrado.\n";
            }
        } else if (opcion == 3) {
            cliente.pagarCuenta();
        }
    } while (opcion != 4);

    return 0;
}
