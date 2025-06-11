#include <iostream>
using namespace std;

const int MAX_PRODUCTOS = 10;

class Producto {
public:
    virtual float calcularValorTotal() const = 0;
    virtual void mostrar() const = 0;
    virtual ~Producto() {}
};

class Electronico : public Producto {
private:
    float precio;
    int cantidad;
public:
    Electronico(float p, int c) {
        precio = p;
        cantidad = c;
    }

    float calcularValorTotal() const {
        return (precio * cantidad) * 0.90f; 
    }

    void mostrar() const {
        cout << "Producto Electronico - Precio: " << precio << ", Cantidad: " << cantidad
             << ", Valor con descuento: " << calcularValorTotal() << "\n";
    }
};

class Ropa : public Producto {
private:
    float precio;
    int cantidad;
public:
    Ropa(float p, int c) {
        precio = p;
        cantidad = c;
    }

    float calcularValorTotal() const {
        return (precio * cantidad) * 0.85f; 
    }

    void mostrar() const {
        cout << "Producto Ropa - Precio: " << precio << ", Cantidad: " << cantidad
             << ", Valor con descuento: " << calcularValorTotal() << "\n";
    }
};

class Alimento : public Producto {
private:
    float precio;
    int cantidad;
public:
    Alimento(float p, int c) {
        precio = p;
        cantidad = c;
    }

    float calcularValorTotal() const {
        return (precio * cantidad);
    }

    void mostrar() const {
        cout << "Producto Alimento - Precio: " << precio << ", Cantidad: " << cantidad
             << ", Valor total: " << calcularValorTotal() << "\n";
    }
};

class ProductoPersonalizado : public Producto {
private:
    float precio;
    int cantidad;
    float descuento;
public:
    ProductoPersonalizado(float p, int c, float d) {
        precio = p;
        cantidad = c;
        descuento = d;
    }

    float calcularValorTotal() const {
        return (precio * cantidad) * ((100.0f - descuento) / 100.0f);
    }

    void mostrar() const {
        cout << "Producto Personalizado - Precio: " << precio << ", Cantidad: " << cantidad
             << ", Descuento: " << descuento << "%, Valor final: " << calcularValorTotal() << "\n";
    }
};

int main() {
    Producto* inventario[MAX_PRODUCTOS];
    int total = 0;
    char seguir = 's';

    while (seguir == 's' && total < MAX_PRODUCTOS) {
        cout << "\nTipos de producto:\n";
        cout << "1. Electronico\n";
        cout << "2. Ropa\n";
        cout << "3. Alimento\n";
        cout << "4. Otro (personalizado)\n";
        cout << "Seleccione una opcion (1-4): ";
        int opcion;
        cin >> opcion;

        float precio;
        int cantidad;
        Producto* nuevo = 0;

        if (opcion == 1) {
            cout << "Ingrese precio y cantidad: ";
            cin >> precio >> cantidad;
            nuevo = new Electronico(precio, cantidad);
        } else if (opcion == 2) {
            cout << "Ingrese precio y cantidad: ";
            cin >> precio >> cantidad;
            nuevo = new Ropa(precio, cantidad);
        } else if (opcion == 3) {
            cout << "Ingrese precio y cantidad: ";
            cin >> precio >> cantidad;
            nuevo = new Alimento(precio, cantidad);
        } else if (opcion == 4) {
            float descuento;
            cout << "Ingrese precio, cantidad y descuento (%): ";
            cin >> precio >> cantidad >> descuento;
            nuevo = new ProductoPersonalizado(precio, cantidad, descuento);
        } else {
            cout << "Opcion invalida.\n";
            continue;
        }

        inventario[total++] = nuevo;
        cout << "Producto agregado con exito.\n";
        cout << "Desea agregar otro producto? (s/n): ";
        cin >> seguir;
    }

    float totalGeneral = 0.0f;

    cout << "\n--- INVENTARIO ---\n";
    for (int i = 0; i < total; i++) {
        inventario[i]->mostrar();
        totalGeneral += inventario[i]->calcularValorTotal();
        delete inventario[i];
    }

    cout << "\nValor total del inventario: " << totalGeneral << "\n";

    return 0;
}

