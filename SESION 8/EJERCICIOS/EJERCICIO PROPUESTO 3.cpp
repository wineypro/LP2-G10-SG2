#include <iostream>
using namespace std;

class Empleado {
protected:
    const char* nombre;
public:
    Empleado(const char* n) : nombre(n) {}
    virtual double calcularSalario() const = 0;
    virtual void mostrarSalario() const {
        cout << "Empleado: " << nombre << ", Salario: S/ " << calcularSalario() << endl;
    }
    virtual ~Empleado() {}
};

class EmpleadoTiempoCompleto : public Empleado {
    double salarioMensual;
public:
    EmpleadoTiempoCompleto(const char* n, double salario)
        : Empleado(n), salarioMensual(salario) {}

    double calcularSalario() const override {
        return salarioMensual;
    }
};

class EmpleadoMedioTiempo : public Empleado {
    double salarioHora;
    int horas;
public:
    EmpleadoMedioTiempo(const char* n, double porHora, int h)
        : Empleado(n), salarioHora(porHora), horas(h) {}

    double calcularSalario() const override {
        return salarioHora * horas;
    }
};

int main() {
    int opcion;
    char nombre[50];
    double salario, porHora;
    int horas;

    cout << "Seleccione tipo de empleado:\n";
    cout << "1. Tiempo completo\n";
    cout << "2. Medio tiempo\n";
    cout << "Opción: ";
    cin >> opcion;

    cout << "Ingrese nombre del empleado: ";
    cin.ignore();
    cin.getline(nombre, 50);

    if (opcion == 1) {
        cout << "Ingrese salario mensual en soles: ";
        cin >> salario;
        EmpleadoTiempoCompleto empleado(nombre, salario);
        empleado.mostrarSalario();
    }
    else if (opcion == 2) {
        cout << "Ingrese salario por hora en soles: ";
        cin >> porHora;
        cout << "Ingrese cantidad de horas trabajadas: ";
        cin >> horas;
        EmpleadoMedioTiempo empleado(nombre, porHora, horas);
        empleado.mostrarSalario();
    }
    else {
        cout << "Opción no válida." << endl;
    }

    return 0;
}
