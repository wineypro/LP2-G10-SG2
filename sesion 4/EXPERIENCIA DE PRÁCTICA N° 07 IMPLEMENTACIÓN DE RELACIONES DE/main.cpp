#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;

public:
    Vehiculo(string m, string mod) : marca(m), modelo(mod) {
        cout << "Constructor de la clase base Vehiculo." << endl;
    }

    virtual ~Vehiculo() {
        cout << "Destructor de la clase base Vehiculo." << endl;
    }

    void mostrarDetalles() {
        cout << "Marca: " << marca << ", Modelo: " << modelo << endl;
    }
};

class Coche : public Vehiculo {
private:
    int numeroDePuertas;

public:
    Coche(string m, string mod, int puertas) : Vehiculo(m, mod), numeroDePuertas(puertas) {
        cout << "Constructor de la clase derivada Coche." << endl;
    }

    ~Coche() {
        cout << "Destructor de la clase derivada Coche." << endl;
    }

    void mostrarDetallesCoche() {
        mostrarDetalles();
        cout << "Numero de puertas: " << numeroDePuertas << endl;
    }

    void setNumeroDePuertas(int puertas) {
        numeroDePuertas = puertas;
    }

    int getNumeroDePuertas() {
        return numeroDePuertas;
    }
};

int main() {
    Coche coche1("Ford", "Mustang", 4);

    coche1.mostrarDetallesCoche();  // Llama al método de la clase derivada

    // Modificar atributos de la clase derivada
    coche1.setNumeroDePuertas(2);
    cout << "Después de modificar el número de puertas:" << endl;
    coche1.mostrarDetallesCoche();

    return 0;
}
