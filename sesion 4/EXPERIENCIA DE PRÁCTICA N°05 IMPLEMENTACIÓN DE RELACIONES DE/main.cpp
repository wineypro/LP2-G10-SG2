#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Producto {
public:
    string nombre;
    double precio;

    Producto(string nom, double pre) : nombre(nom), precio(pre) {}

    void mostrarInformacion() {
        cout << "Producto: " << nombre << ", Precio: $" << precio << endl;
    }
};

class Tienda {
private:
    vector<Producto*> productos;

public:
    void agregarProducto(Producto* producto) {
        productos.push_back(producto);
    }

    void eliminarProducto(Producto* producto) {
        for (auto it = productos.begin(); it != productos.end(); ++it) {
            if (*it == producto) {
                productos.erase(it);
                cout << "Producto eliminado: " << producto->nombre << endl;
                return;
            }
        }
        cout << "Producto no encontrado." << endl;
    }

    Producto* obtenerProducto(int id) {
        if (id >= 0 && id < productos.size()) {
            return productos[id];
        } else {
            cout << "Producto no encontrado." << endl;
            return nullptr;
        }
    }

    void mostrarProductos() {
        for (auto& producto : productos) {
            producto->mostrarInformacion();
        }
    }
};

int main() {
    Tienda tienda;
    
    Producto* p1 = new Producto("Camiseta", 19.99);
    Producto* p2 = new Producto("Zapatos", 49.99);
    Producto* p3 = new Producto("Pantalón", 29.99);

    tienda.agregarProducto(p1);
    tienda.agregarProducto(p2);
    tienda.agregarProducto(p3);

    tienda.mostrarProductos();

    Producto* p = tienda.obtenerProducto(1);
    if (p != nullptr) {
        cout << "Producto obtenido: " << p->nombre << endl;
    }

    tienda.eliminarProducto(p2);
    tienda.mostrarProductos();

    delete p1;
    delete p2;
    delete p3;

    return 0;
}
