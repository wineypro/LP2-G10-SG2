#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;
    string dni;
    float nota1, nota2, nota3;

public:
    Estudiante() {
        nombre = "";
        edad = 0;
        dni = "";
        nota1 = nota2 = nota3 = 0;
    }

    Estudiante(string _nombre, int _edad, string _dni, float _nota1, float _nota2, float _nota3) {
        nombre = _nombre;
        edad = _edad;
        dni = _dni;
        nota1 = _nota1;
        nota2 = _nota2;
        nota3 = _nota3;
    }

    float obtenerPromedio() const {
        return (nota1 + nota2 + nota3) / 3.0;
    }

    void mostrar() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << ", DNI: " << dni;
        cout << ", Notas: [" << nota1 << ", " << nota2 << ", " << nota3 << "]";
        cout << ", Promedio: " << obtenerPromedio() << endl;
    }
};

bool validarDNI(const string& dni) {
    return dni.length() == 8 && all_of(dni.begin(), dni.end(), ::isdigit);
}

bool validarNota(float nota) {
    return nota >= 0 && nota <= 20;
}

int main() {
    vector<Estudiante> estudiantes;
    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Ordenar por promedio\n";
        cout << "3. Mostrar estudiantes con promedio mayor a un valor\n";
        cout << "4. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre, dni;
            int edad;
            float n1, n2, n3;

            cout << "Nombre: ";
            cin.ignore();
            getline(cin, nombre);

            cout << "Edad: ";
            cin >> edad;

            do {
                cout << "DNI (8 dígitos): ";
                cin >> dni;
                if (!validarDNI(dni)) {
                    cout << "DNI inválido. Debe tener exactamente 8 dígitos numéricos.\n";
                }
            } while (!validarDNI(dni));

            do {
                cout << "Nota 1 (0-20): ";
                cin >> n1;
                if (!validarNota(n1)) cout << "Nota inválida. Debe estar entre 0 y 20.\n";
            } while (!validarNota(n1));

            do {
                cout << "Nota 2 (0-20): ";
                cin >> n2;
                if (!validarNota(n2)) cout << "Nota inválida. Debe estar entre 0 y 20.\n";
            } while (!validarNota(n2));

            do {
                cout << "Nota 3 (0-20): ";
                cin >> n3;
                if (!validarNota(n3)) cout << "Nota inválida. Debe estar entre 0 y 20.\n";
            } while (!validarNota(n3));

            estudiantes.push_back(Estudiante(nombre, edad, dni, n1, n2, n3));

        } else if (opcion == 2) {
            if (estudiantes.empty()) {
                cout << "No hay estudiantes registrados.\n";
                continue;
            }

            sort(estudiantes.begin(), estudiantes.end(), [](const Estudiante& a, const Estudiante& b) {
                return a.obtenerPromedio() > b.obtenerPromedio(); // De mayor a menor
            });

            cout << "\nEstudiantes ordenados por promedio:\n";
            for (const auto& e : estudiantes) {
                e.mostrar();
            }

        } else if (opcion == 3) {
            if (estudiantes.empty()) {
                cout << "No hay estudiantes registrados.\n";
                continue;
            }

            float limite;
            cout << "Ingrese la nota límite: ";
            cin >> limite;

            cout << "\nEstudiantes con promedio mayor a " << limite << ":\n";
            for (const auto& e : estudiantes) {
                if (e.obtenerPromedio() > limite) {
                    e.mostrar();
                }
            }

        } else if (opcion != 4) {
            cout << "Opción inválida. Intente otra vez.\n";
        }

    } while (opcion != 4);

    return 0;
}
