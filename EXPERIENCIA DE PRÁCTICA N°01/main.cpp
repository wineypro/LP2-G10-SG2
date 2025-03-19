#include <iostream>
#include <vector>
using namespace std;

struct Producto { string nombre; float precio; int stock; };
struct Pedido { string nombre; int cantidad; };

void registrarProducto(Producto &p) {
    cout << "Nombre: "; cin >> p.nombre;
    cout << "Precio: "; cin >> p.precio;
    cout << "Stock: "; cin >> p.stock;
}

Pedido crearPedido() {
    Pedido ped;
    cout << "Producto a pedir: "; cin >> ped.nombre;
    cout << "Cantidad: "; cin >> ped.cantidad;
    return ped;
}

void mostrarProducto(const Producto &p) {
    cout << "\n--- Producto ---\n";
    cout << "Nombre: " << p.nombre << "\nPrecio: $" << p.precio << "\nStock: " << p.stock << endl;
}

void mostrarPedido(const Pedido &ped) {
    cout << "\n--- Pedido ---\n";
    cout << "Producto: " << ped.nombre << "\nCantidad: " << ped.cantidad << endl;
}

int main() {
    vector<Producto> productos;
    vector<Pedido> pedidos;
    int n, m;

    cout << "Cantidad de productos a registrar: "; cin >> n;
    for (int i = 0; i < n; i++) {
        Producto p;
        registrarProducto(p);
        productos.push_back(p);
    }

    cout << "\nCantidad de pedidos a registrar: "; cin >> m;
    for (int i = 0; i < m; i++) {
        pedidos.push_back(crearPedido());
    }

    cout << "\n... LISTA DE PRODUCTOS ..";
    for (const auto &p : productos) mostrarProducto(p);

    cout << "\n... LISTA DE PEDIDOS ...";
    for (const auto &ped : pedidos) mostrarPedido(ped);

    return 0;
}