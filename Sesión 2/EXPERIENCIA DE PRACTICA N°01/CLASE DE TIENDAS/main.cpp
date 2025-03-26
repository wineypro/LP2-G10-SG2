#include <iostream>

using namespace std;

class Tienda {
private:
    string nombre;
    string direccion;
    string tipoDeTienda;
    int stock;

public:
    Tienda(string nombre, string direccion, string tipoDeTienda, int stockInicial)
        : nombre(nombre), direccion(direccion), tipoDeTienda(tipoDeTienda), stock(stockInicial) {}

    void agregarProducto(int cantidad)
    {
        stock += cantidad;
        cout << "Se agregaron " << cantidad << " productos a " << nombre << ". Stock actual: " << stock << endl;
    }

    void venderProducto(int cantidad)
    {
        if (stock >= cantidad)
        {
            stock -= cantidad;
            cout << "Se vendieron " << cantidad << " productos en " << nombre << ". Stock restante: " << stock << endl;
        }
        else
        {
            cout << "No hay suficiente stock en " << nombre << ". Stock disponible: " << stock << endl;
        }
    }

    void mostrarInfo()
    {
        cout << "Tienda: " << nombre << ", Direccion: " << direccion << ", Tipo: " << tipoDeTienda << ", Stock: " << stock << endl;
    }
};

int main()
{
    Tienda tienda1("Moda Express", "Av. Central 123", "Ropa", 50);
    Tienda tienda2("Tech World", "Calle Principal 456", "Electronicos", 20);

    tienda1.mostrarInfo();
    tienda1.agregarProducto(10);
    tienda1.venderProducto(30);

    tienda2.mostrarInfo();
    tienda2.agregarProducto(5);
    tienda2.venderProducto(10);

    return 0;
}
