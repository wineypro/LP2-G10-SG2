#include <iostream>

using namespace std;

const int MAX_PRODUCTOS = 100;
const int MAX_FACTURAS = 100;

class Inventario {
private:
    int id_productos[MAX_PRODUCTOS];
    string productos_disponibles[MAX_PRODUCTOS];
    int cantidades[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS];
    int total_productos;

public:
    Inventario() : total_productos(0) {}

    void agregarProducto() {
        if (total_productos >= MAX_PRODUCTOS) {
            cout << "Inventario lleno.\n";
            return;
        }

        int id;
        string nombre;
        int cantidad;
        float precio;

        cout << "Ingrese el ID del producto: ";
        cin >> id;
        cout << "Ingrese el nombre del producto: ";
        cin >> nombre;
        cout << "Ingrese la cantidad: ";
        cin >> cantidad;
        cout << "Ingrese el precio: ";
        cin >> precio;

        if (cantidad > 0 && precio > 0) {
            for (int i = 0; i < total_productos; i++) {
                if (id_productos[i] == id) {
                    cout << "El ID ya existe. \n";
                    return;
                }
            }

            id_productos[total_productos] = id;
            productos_disponibles[total_productos] = nombre;
            cantidades[total_productos] = cantidad;
            precios[total_productos] = precio;
            total_productos++;

            cout << "Producto agregado .\n";
        } else {
            cout << "La cantidad y el precio deben ser mayores a 0.\n";
        }
    }

    void mostrarInventario() {
        cout << "\nInventario Disponible:\n";
        for (int i = 0; i < total_productos; i++) {
            cout << "ID: " << id_productos[i] 
                 << ", Producto: " << productos_disponibles[i] 
                 << ", Cantidad: " << cantidades[i] 
                 << ", Precio: S/" << precios[i] << endl;
        }
    }

    bool productoDisponible(int id, int cantidad, string &nombre, float &precio) {
        for (int i = 0; i < total_productos; i++) {
            if (id_productos[i] == id && cantidades[i] >= cantidad) {
                nombre = productos_disponibles[i];
                precio = precios[i];
                return true;
            }
        }
        return false;
    }

    bool actualizarInventario(int id, int cantidad) {
        for (int i = 0; i < total_productos; i++) {
            if (id_productos[i] == id) {
                if (cantidades[i] >= cantidad) {
                    cantidades[i] -= cantidad;
                    if (cantidades[i] == 0) {
                        productos_disponibles[i] = productos_disponibles[total_productos - 1];
                        cantidades[i] = cantidades[total_productos - 1];
                        precios[i] = precios[total_productos - 1];
                        id_productos[i] = id_productos[total_productos - 1];
                        total_productos--;
                    }
                    return true;
                } else {
                    cout << "No hay suficiente stock de " << productos_disponibles[i] << ".\n";
                }
            }
        }
        cout << "El producto con ID " << id << " no esta disponible.\n";
        return false;
    }
};

class GestionPedidos {
private:
    Inventario& inventario;
    int id_clientes[MAX_FACTURAS];
    int id_productos[MAX_FACTURAS];
    string productos[MAX_FACTURAS];
    int cantidades[MAX_FACTURAS];
    float totales[MAX_FACTURAS];
    int total_facturas;

public:
    GestionPedidos(Inventario& inv) : inventario(inv), total_facturas(0) {}

    void realizarPedido() {
        if (total_facturas >= MAX_FACTURAS) {
            cout << "No se pueden registrar mas facturas.\n";
            return;
        }

        int id_cliente;
        cout << "Ingrese el ID del cliente: ";
        cin >> id_cliente;

        bool continuar;
        do {
            int id_producto, cantidad;
            string producto;
            float precio, total;

            cout << "Ingrese el ID del producto: ";
            cin >> id_producto;
            cout << "Ingrese la cantidad: ";
            cin >> cantidad;

            if (inventario.productoDisponible(id_producto, cantidad, producto, precio)) {
                inventario.actualizarInventario(id_producto, cantidad);
                total = cantidad * precio;

                id_clientes[total_facturas] = id_cliente;
                id_productos[total_facturas] = id_producto;
                productos[total_facturas] = producto;
                cantidades[total_facturas] = cantidad;
                totales[total_facturas] = total;

                total_facturas++;

                cout << "Pedido realizado con exito. Total a pagar: S/" << total << endl;
            } else {
                cout << "No se pudo realizar el pedido.\n";
            }

            char respuesta;
            cout << "Desea comprar otro producto? (s/n): ";
            cin >> respuesta;
            continuar = (respuesta == 's' || respuesta == 'S');

        } while (continuar);
    }

    void mostrarFacturas() {
        cout << "\nFacturas registradas:\n";
        for (int i = 0; i < total_facturas; i++) {
            cout << "Cliente ID: " << id_clientes[i] 
                 << ", Producto: " << productos[i] 
                 << " (ID " << id_productos[i] << ")"
                 << ", Cantidad: " << cantidades[i] 
                 << ", Total: S/" << totales[i] << endl;
        }
    }
};

int main() {
    Inventario inventario;
    GestionPedidos pedidos(inventario);
    int opcion;

    do {
        cout << "\nMenu de Gestion de Pedidos:\n";
        cout << "1. Agregar producto\n";
        cout << "2. Ver inventario\n";
        cout << "3. Realizar pedido\n";
        cout << "4. Ver facturas\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                inventario.agregarProducto();
                break;
            case 2:
                inventario.mostrarInventario();
                break;
            case 3:
                pedidos.realizarPedido();
                break;
            case 4:
                pedidos.mostrarFacturas();
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 5);

    return 0;
}