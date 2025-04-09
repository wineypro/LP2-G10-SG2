#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Cliente.h"
#include "Producto.h"
#include "Venta.h"
using namespace std;

bool validarTelefono(string telefono) {
    if (telefono.length() != 9) return false;
    for (char c : telefono) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool validarFecha(string fecha) {
    if (fecha.length() != 10 || fecha[2] != '/' || fecha[5] != '/') return false;
    string diaStr = fecha.substr(0, 2);
    string mesStr = fecha.substr(3, 2);
    string anioStr = fecha.substr(6, 4);

    for (char c : diaStr + mesStr + anioStr) {
        if (!isdigit(c)) return false;
    }

    int dia = stoi(diaStr);
    int mes = stoi(mesStr);

    if (dia < 1 || dia > 31 || mes < 1 || mes > 12) return false;

    return true;
}

int main() {
    vector<Cliente> clientes;
    vector<Producto> productos;
    vector<Venta> ventas;

    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Registrar cliente\n";
        cout << "2. Registrar producto\n";
        cout << "3. Realizar venta\n";
        cout << "4. Mostrar pagos\n";
        cout << "5. Mostrar clientes\n";
        cout << "6. Mostrar productos\n";
        cout << "7. Mostrar ventas\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string nombre, direccion, telefono;
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Direccion: ";
            getline(cin, direccion);
            do {
                cout << "Telefono (9 digitos): ";
                getline(cin, telefono);
                if (!validarTelefono(telefono)) {
                    cout << "Telefono invalido. Debe tener 9 digitos.\n";
                }
            } while (!validarTelefono(telefono));

            clientes.push_back(Cliente(nombre, direccion, telefono));
        } else if (opcion == 2) {
            string codigo, descripcion, proveedor;
            float precio;
            cout << "Codigo: ";
            getline(cin, codigo);
            cout << "Descripcion: ";
            getline(cin, descripcion);
            cout << "Precio: ";
            cin >> precio;
            cin.ignore();
            cout << "Proveedor: ";
            getline(cin, proveedor);
            productos.push_back(Producto(codigo, descripcion, precio, proveedor));
        } else if (opcion == 3) {
            if (clientes.empty() || productos.empty()) {
                cout << "Debe haber al menos un cliente y un producto registrado.\n";
                continue;
            }
            string factura, fecha;
            int idxCliente;
            cout << "Numero de factura: ";
            getline(cin, factura);
            do {
                cout << "Fecha (dd/mm/aaaa): ";
                getline(cin, fecha);
                if (!validarFecha(fecha)) {
                    cout << "Fecha invalida. Use el formato dd/mm/aaaa.\n";
                }
            } while (!validarFecha(fecha));

            cout << "Seleccione cliente:\n";
            for (int i = 0; i < clientes.size(); i++) {
                cout << i << ". " << clientes[i].nombre << endl;
            }
            cin >> idxCliente;
            cin.ignore();
            Venta venta(factura, fecha, &clientes[idxCliente]);

            char mas;
            do {
                int idxProd, cantidad;
                cout << "Seleccione producto:\n";
                for (int i = 0; i < productos.size(); i++) {
                    cout << i << ". " << productos[i].descripcion << " ($" << productos[i].precio << ")\n";
                }
                cin >> idxProd;
                cout << "Cantidad: ";
                cin >> cantidad;
                cin.ignore();
                for (int j = 0; j < cantidad; j++) {
                    venta.agregarProducto(productos[idxProd]);
                }
                cout << "Agregar otro producto? (s/n): ";
                cin >> mas;
                cin.ignore();
            } while (mas == 's');
            ventas.push_back(venta);
        } else if (opcion == 4) {
            if (clientes.empty()) {
                cout << "No hay clientes registrados.\n";
                continue;
            }
            for (Cliente& c : clientes) {
                cout << "Cliente: " << c.nombre << "\nPagos: ";
                if (c.pagos.empty()) {
                    cout << "Sin pagos registrados.";
                } else {
                    for (float pago : c.pagos) cout << "$" << pago << " ";
                }
                cout << "\n";
            }
        } else if (opcion == 5) {
            for (Cliente& c : clientes) {
                cout << "Nombre: " << c.nombre << ", Direccion: " << c.direccion << ", Telefono: " << c.telefono << endl;
                cout << "Compras: ";
                for (string& compra : c.compras) cout << compra << ", ";
                cout << "\nPagos: ";
                for (float pago : c.pagos) cout << "$" << pago << ", ";
                cout << "\n";
            }
        } else if (opcion == 6) {
            for (Producto& p : productos) {
                cout << "Codigo: " << p.codigo << ", Descripcion: " << p.descripcion
                     << ", Precio: $" << p.precio << ", Proveedor: " << p.proveedor << endl;
            }
        } else if (opcion == 7) {
            for (Venta& v : ventas) {
                cout << "Factura: " << v.numeroFactura << ", Fecha: " << v.fecha
                     << ", Cliente: " << v.cliente->nombre << "\nProductos:\n";
                for (Producto& p : v.productos) {
                    cout << "- " << p.descripcion << " ($" << p.precio << ")\n";
                }
                cout << "\n";
            }
        }
    } while (opcion != 0);

    return 0;
}
