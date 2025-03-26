#include <iostream>
#include "Tienda.h"

using namespace std;

void mostrarMenu() {
    cout << "\n--- MENÚ ---\n";
    cout << "1. Ver productos en la tienda\n";
    cout << "2. Agregar producto\n";
    cout << "3. Eliminar producto\n";
    cout << "4. Actualizar precio de producto\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    Tienda tienda;
    tienda.agregarProducto(Producto("Camisa", 20.0, 10));
    tienda.agregarProducto(Producto("Pantalón", 30.0, 5));
    tienda.agregarProducto(Producto("Zapatos", 50.0, 3));

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            tienda.mostrarProductos();
        } 
        else if (opcion == 2) {
            string nombre;
            double precio;
            int stock;

            cout << "Nombre del producto: ";
            getline(cin, nombre);
            cout << "Precio: ";
            cin >> precio;
            cout << "Stock: ";
            cin >> stock;

            tienda.agregarProducto(Producto(nombre, precio, stock));
            cout << "Producto agregado correctamente.\n";
        } 
        else if (opcion == 3) {
            string nombre;
            cout << "Ingrese el nombre del producto a eliminar: ";
            getline(cin, nombre);

            cout << "\nLista antes de eliminar:\n";
            tienda.mostrarProductos();

            if (tienda.eliminarProducto(nombre)) {
                cout << "Producto eliminado correctamente.\n";
            } else {
                cout << "Producto no encontrado.\n";
            }

            cout << "\nLista después de eliminar:\n";
            tienda.mostrarProductos();
        } 
        else if (opcion == 4) {
            string nombre;
            double nuevoPrecio;
            cout << "Ingrese el nombre del producto a actualizar: ";
            getline(cin, nombre);
            cout << "Ingrese el nuevo precio: ";
            cin >> nuevoPrecio;

            cout << "\nLista antes de actualizar precio:\n";
            tienda.mostrarProductos();

            if (tienda.actualizarPrecio(nombre, nuevoPrecio)) {
                cout << "Precio actualizado correctamente.\n";
            } else {
                cout << "Producto no encontrado.\n";
            }

            cout << "\nLista después de actualizar precio:\n";
            tienda.mostrarProductos();
        }

    } while (opcion != 5);

    return 0;
}
