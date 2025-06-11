#include <iostream>
using namespace std;

const int MAX_EMPLEADOS = 10;

class Empleado {
public:
    virtual float calcularSalario() const = 0;
    virtual void mostrar() const = 0;
    virtual ~Empleado() {}
};

class Asalariado : public Empleado {
private:
    float salarioMensual;
public:
    Asalariado(float salario) {
        salarioMensual = salario;
    }

    float calcularSalario() const {
        return salarioMensual;
    }

    void mostrar() const {
        cout << "Empleado Asalariado - Salario: " << salarioMensual << "\n";
    }
};

class PorHora : public Empleado {
private:
    float horas;
    float tarifa;
public:
    PorHora(float h, float t) {
        horas = h;
        tarifa = t;
    }

    float calcularSalario() const {
        return horas * tarifa;
    }

    void mostrar() const {
        cout << "Empleado Por Hora - Horas: " << horas << ", Tarifa: " << tarifa << ", Salario: " << calcularSalario() << "\n";
    }
};

class Comisionista : public Empleado {
private:
    float ventas;
    float porcentaje;
public:
    Comisionista(float v, float p) {
        ventas = v;
        porcentaje = p;
    }

    float calcularSalario() const {
        return ventas * (porcentaje / 100.0f);
    }

    void mostrar() const {
        cout << "Empleado Comisionista - Ventas: " << ventas << ", Porcentaje: " << porcentaje << "%, Salario: " << calcularSalario() << "\n";
    }
};

class EmpleadoPersonalizado : public Empleado {
private:
    float salario;
public:
    EmpleadoPersonalizado(float s) {
        salario = s;
    }

    float calcularSalario() const {
        return salario;
    }

    void mostrar() const {
        cout << "Empleado Personalizado - Salario fijo definido: " << salario << "\n";
    }
};

int main() {
    Empleado* empleados[MAX_EMPLEADOS];
    int total = 0;
    char seguir = 's';

    while (seguir == 's' && total < MAX_EMPLEADOS) {
        cout << "\nTipos de empleado:\n";
        cout << "1. Asalariado\n";
        cout << "2. Por hora\n";
        cout << "3. Comisionista\n";
        cout << "4. Otro (personalizado)\n";
        cout << "Seleccione una opcion (1-4): ";
        int opcion;
        cin >> opcion;

        Empleado* nuevo = 0;

        if (opcion == 1) {
            float salario;
            cout << "Ingrese salario mensual: ";
            cin >> salario;
            nuevo = new Asalariado(salario);
        } else if (opcion == 2) {
            float horas, tarifa;
            cout << "Ingrese horas trabajadas: ";
            cin >> horas;
            cout << "Ingrese tarifa por hora: ";
            cin >> tarifa;
            nuevo = new PorHora(horas, tarifa);
        } else if (opcion == 3) {
            float ventas, porcentaje;
            cout << "Ingrese total de ventas: ";
            cin >> ventas;
            cout << "Ingrese porcentaje de comision: ";
            cin >> porcentaje;
            nuevo = new Comisionista(ventas, porcentaje);
        } else if (opcion == 4) {
            float salario;
            cout << "Ingrese salario definido del empleado: ";
            cin >> salario;
            nuevo = new EmpleadoPersonalizado(salario);
        } else {
            cout << "Opcion invalida.\n";
            continue;
        }

        empleados[total++] = nuevo;
        cout << "Empleado agregado correctamente.\n";
        cout << "Desea agregar otro empleado? (s/n): ";
        cin >> seguir;
    }

    cout << "\n--- NOMINA DE EMPLEADOS ---\n";
    for (int i = 0; i < total; i++) {
        empleados[i]->mostrar();
        delete empleados[i];
    }

    return 0;
}
