#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trabajador {
public:
    string nombre;
    string cargo;
    vector<Trabajador*> companeros;

    Trabajador(string nom, string car) : nombre(nom), cargo(car) {}

    virtual ~Trabajador() {} // Destructor virtual

    void agregarCompanero(Trabajador* compañero) {
        companeros.push_back(compañero);
    }

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Cargo: " << cargo << endl;
        if (!companeros.empty()) {
            cout << "Compañeros a cargo: ";
            for (auto& compañero : companeros) {
                cout << compañero->nombre << " ";
            }
            cout << endl;
        } else {
            cout << "No tiene compañeros a cargo." << endl;
        }
    }
};

class Gerente : public Trabajador {
public:
    Gerente(string nom) : Trabajador(nom, "Gerente") {}

    void agregarTrabajador(Trabajador* trabajador) {
        agregarCompanero(trabajador);
    }
};

int main() {
    const int MAX_TRABAJADORES = 5;
    Trabajador* trabajadores[MAX_TRABAJADORES];

    trabajadores[0] = new Trabajador("Juan", "Desarrollador");
    trabajadores[1] = new Trabajador("Maria", "Analista");
    trabajadores[2] = new Gerente("Carlos");
    trabajadores[3] = new Trabajador("Pedro", "Tester");
    trabajadores[4] = new Trabajador("Lucia", "Desarrollador");

    Gerente* gerenteCarlos = dynamic_cast<Gerente*>(trabajadores[2]);
    if (gerenteCarlos) {
        gerenteCarlos->agregarTrabajador(trabajadores[0]);
        gerenteCarlos->agregarTrabajador(trabajadores[1]);
        gerenteCarlos->agregarTrabajador(trabajadores[3]);
        gerenteCarlos->agregarTrabajador(trabajadores[4]);
    }

    for (int i = 0; i < MAX_TRABAJADORES; i++) {
        trabajadores[i]->mostrarInformacion();
    }

    for (int i = 0; i < MAX_TRABAJADORES; i++) {
        delete trabajadores[i];
    }

    return 0;
}
