#include <iostream>
#include "GestorInventario.h"
#include "GeneradorReportes.h"

using namespace std;

void mostrarMenu() {
    cout << "\n--- Menu ---\n";
    cout << "1. Registrar producto\n";
    cout << "2. Crear y procesar pedido\n";
    cout << "3. Generar reportes\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    GestorInventario gestor;
    GeneradorReportes reportes(&gestor);
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string nombre;
            double precio;
            int stock;
            cout << "Nombre del producto: ";
            getline(cin, nombre);
            cout << "Precio: ";
            cin >> precio;
            cout << "Stock: ";
            cin >> stock;
            gestor.agregarProducto(Producto(nombre, precio, stock));
        }
        else if (opcion == 2) {
            vector<Producto> productosPedido;
            vector<int> cantidades;
            string nombre;
            int cantidad;
            char continuar;

            do {
                cout << "Ingrese el nombre del producto: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Cantidad: ";
                cin >> cantidad;

                Producto p = gestor.buscarProducto(nombre);
                if (p.getNombre() != "") {
                    productosPedido.push_back(p);
                    cantidades.push_back(cantidad);
                } else {
                    cout << "Producto no encontrado.\n";
                }

                cout << "¿Agregar otro producto? (s/n): ";
                cin >> continuar;
            } while (continuar == 's' || continuar == 'S');

            Pedido pedido(productosPedido, cantidades, "En proceso");
            gestor.actualizarInventario(pedido);
            reportes.registrarPedido(pedido);
        }
        else if (opcion == 3) {
            cout << "1. Reporte general\n";
            cout << "2. Reporte de inventario bajo\n";
            cout << "Seleccione una opcion: ";
            int subOpcion;
            cin >> subOpcion;

            if (subOpcion == 1) {
                reportes.reporteGeneral();
            } else if (subOpcion == 2) {
                int umbral;
                cout << "Ingrese el umbral de stock bajo: ";
                cin >> umbral;
                reportes.reporteInventarioBajo(umbral);
            }
        }
    } while (opcion != 4);

    return 0;
}
