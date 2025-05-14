#include <iostream>
using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    int anioFabricacion;
    float precio;

public:
    Vehiculo(string _marca, string _modelo, int _anioFabricacion, float _precio) {
        marca = _marca;
        modelo = _modelo;
        anioFabricacion = _anioFabricacion;
        precio = _precio;
    }

    void mostrarDatos() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año de Fabricación: " << anioFabricacion << endl;
        cout << "Precio: $" << precio << endl;
    }
};

class Automovil : public Vehiculo {
private:
    int numeroPuertas;
    string tipoCombustible;

public:
    Automovil(string _marca, string _modelo, int _anioFabricacion, float _precio, int _numeroPuertas, string _tipoCombustible)
        : Vehiculo(_marca, _modelo, _anioFabricacion, _precio) {
        numeroPuertas = _numeroPuertas;
        tipoCombustible = _tipoCombustible;
    }

    void mostrarDatos() {
        Vehiculo::mostrarDatos();
        cout << "Número de Puertas: " << numeroPuertas << endl;
        cout << "Tipo de Combustible: " << tipoCombustible << endl;
    }
};

class Motocicleta : public Vehiculo {
private:
    int cilindrada;

public:
    Motocicleta(string _marca, string _modelo, int _anioFabricacion, float _precio, int _cilindrada)
        : Vehiculo(_marca, _modelo, _anioFabricacion, _precio) {
        cilindrada = _cilindrada;
    }

    void mostrarDatos() {
        Vehiculo::mostrarDatos();
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
    }
};

int main() {
    Automovil auto1("Toyota", "Corolla", 2022, 18000.0, 4, "Gasolina");
    Motocicleta moto1("Yamaha", "MT-07", 2021, 9500.0, 689);

    cout << "--- Datos del Automóvil ---" << endl;
    auto1.mostrarDatos();

    cout << "\n--- Datos de la Motocicleta ---" << endl;
    moto1.mostrarDatos();

    return 0;
}
