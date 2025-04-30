#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    double descuento; 

public:
    Producto() : nombre(""), precio(0.0), descuento(0.0) {}

    Producto& setNombre(const string& n) {
        nombre = n;
        return *this;
    }

    Producto& setPrecio(double p) {
        if (p >= 0)
            precio = p;
        return *this;
    }

    Producto& setDescuento(double d) {
        if (d >= 0 && d <= 100)
            descuento = d;
        return *this;
    }

    double calcularPrecioFinal() const {
        return precio * (1 - descuento / 100.0);
    }

    void mostrar() const {
        cout << "Nombre: " << nombre
             << ", Precio: S/" << precio
             << ", Descuento: " << descuento << "%"
             << ", Precio final: S/" << calcularPrecioFinal() << endl;
    }
};

int main() {
    vector<Producto> productos;
    char opcion;

    do {
        string nombre;
        double precio, descuento;

        cout << "Ingrese el nombre del producto: ";
        cin.ignore(); 
        getline(cin, nombre);

        cout << "Ingrese el precio: $";
        cin >> precio;

        cout << "Ingrese el descuento (%): ";
        cin >> descuento;

        Producto p;
        p.setNombre(nombre)
         .setPrecio(precio)
         .setDescuento(descuento);

        productos.push_back(p);

        cout << "¿Desea agregar otro producto? (s/n): ";
        cin >> opcion;
        cout << endl;

    } while (opcion == 's' || opcion == 'S');

    double total = 0.0;
    cout << "--- Lista de productos ---\n";
    for (const auto& p : productos) {
        p.mostrar();
        total += p.calcularPrecioFinal();
    }

    cout << "Total acumulado con descuento: S/" << total << endl;

    return 0;
}
