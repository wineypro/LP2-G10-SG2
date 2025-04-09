#include <iostream>
#include <string>
using namespace std;

class Motor {
public:
    string tipo;
    int potencia;

    Motor(string t, int p) : tipo(t), potencia(p) {}

    void mostrarInformacion() {
        cout << "Motor: Tipo = " << tipo << ", Potencia = " << potencia << " caballos." << endl;
    }
};

class Coche {
private:
    Motor* motor;

public:
    string marca;
    string modelo;

    Coche(string m, string mod, string t, int p) : marca(m), modelo(mod) {
        motor = new Motor(t, p);
    }

    ~Coche() {
        delete motor;
    }

    void mostrarDetalles() {
        cout << "Coche: Marca = " << marca << ", Modelo = " << modelo << endl;
        motor->mostrarInformacion();
    }

    Motor* obtenerMotor() {
        return motor;
    }
};

int main() {
    Coche coche1("Ford", "Mustang", "V8", 450);

    coche1.mostrarDetalles();

    Motor* motor = coche1.obtenerMotor();
    motor->tipo = "V6"; // Modificando el tipo de motor

    cout << "\nDespués de modificar el motor:" << endl;
    coche1.mostrarDetalles();

    return 0;
}
