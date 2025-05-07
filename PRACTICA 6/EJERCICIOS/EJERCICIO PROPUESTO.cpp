#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Alumno {
public:
    string nombre;
    int edad;
    float promedio;

    Alumno(const string& nom, int ed, float prom)
        : nombre(nom), edad(ed), promedio(prom) {}

    string toString() const {
        return "Nombre: " + nombre + ", Edad: " + to_string(edad) + ", Promedio: " + to_string(promedio);
    }

    bool esMenor(const Alumno& otro) const {
        return promedio < otro.promedio;
    }
};

class Grupo {
private:
    vector<Alumno> alumnos;
    int cantidad;
public:
    Grupo(int cant) : cantidad(cant) {
        alumnos.reserve(cant);
    }

    string toString() const {
        string salida = "Grupo de " + to_string(alumnos.size()) + " alumnos:\n";
        for (const auto& al : alumnos) {
            salida += " - " + al.toString() + "\n";
        }
        return salida;
    }

    void agregarAlumno(const string& nom, int ed, float prom) {
        if ((int)alumnos.size() < cantidad) {
            alumnos.emplace_back(nom, ed, prom);
        } else {
            cerr << "No se puede agregar más alumnos, grupo lleno." << endl;
        }
    }

    void ordenarPorPromedio() {
        int n = alumnos.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (!alumnos[j].esMenor(alumnos[j+1])) {
                    Alumno temp = alumnos[j];
                    alumnos[j] = alumnos[j+1];
                    alumnos[j+1] = temp;
                }
            }
        }
    }

    float promedioGeneral() const {
        if (alumnos.empty()) return 0.0;
        float suma = 0.0;
        for (const auto& al : alumnos) {
            suma += al.promedio;
        }
        return suma / alumnos.size();
    }

    Alumno mejorAlumno() const {
        int idx = 0;
        for (int i = 1; i < (int)alumnos.size(); ++i) {
            if (alumnos[idx].esMenor(alumnos[i])) {
                idx = i;
            }
        }
        return alumnos[idx];
    }
};

int main() {
    const int n = 5;
    Grupo grupo(n);
    cout << "Ingrese datos de " << n << " alumnos:" << endl;

    for (int i = 0; i < n; ++i) {
        string nombre;
        int edad;
        float promedio;
        cout << "\nAlumno " << (i + 1) << " - Nombre: ";
        getline(cin, nombre);
        cout << "Edad: ";
        cin >> edad;
        cout << "Promedio: ";
        cin >> promedio;
        cin.ignore();
        grupo.agregarAlumno(nombre, edad, promedio);
    }

    grupo.ordenarPorPromedio();

    cout << "\n" << grupo.toString() << endl;
    cout << "Promedio general: " << grupo.promedioGeneral() << endl;
    cout << "Mejor alumno: " << grupo.mejorAlumno().toString() << endl;

    return 0;
}
