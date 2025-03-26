#include <iostream>

using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    string dni;

public:
    Persona(string nombre, int edad, string dni)
        : nombre(nombre), edad(edad), dni(dni) {}

    string getNombre() {
        return nombre;
    }

    void setNombre(string nuevoNombre) {
        nombre = nuevoNombre;
    }

    int getEdad() {
        return edad;
    }

    void setEdad(int nuevaEdad) {
        if (nuevaEdad >= 0 && nuevaEdad <= 120) {
            edad = nuevaEdad;
        } else {
            cout << "Edad invalida." << endl;
        }
    }

    string getDNI() {
        return dni;
    }

    void setDNI(string nuevoDNI) {
        if (nuevoDNI.length() == 8) {
            dni = nuevoDNI;
        } else {
            cout << "DNI invalido." << endl;
        }
    }

    void mostrarInfo() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << ", DNI: " << dni << endl;
    }
};

int main() {
    Persona persona1("Carlos", 25, "12345678");
    Persona persona2("Ana", 30, "87654321");

    persona1.mostrarInfo();
    persona2.mostrarInfo();

    persona1.setEdad(150); // Intento de asignar una edad invalida
    persona1.setDNI("1234"); // Intento de asignar un DNI invalido

    persona1.setEdad(28);
    persona1.setDNI("87651234");

    persona1.mostrarInfo();
    return 0;
}
