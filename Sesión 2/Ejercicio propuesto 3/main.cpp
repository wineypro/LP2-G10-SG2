#include <iostream>
#include <vector>
#include "Mision.h"
#include "Avion.h"

using namespace std;

void mostrarMenu() {
    cout << "\n--- Menú ---\n";
    cout << "1. Crear misión\n";
    cout << "2. Ver misiones\n";
    cout << "3. Simular misión\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    vector<Mision> misiones;
    Avion avion("Boeing 747", 5000, 10); // Modelo, capacidad de combustible, tripulación máxima

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string destino;
            double duracion;
            int tripulacion;

            cout << "Ingrese destino: ";
            getline(cin, destino);
            cout << "Ingrese duración en horas: ";
            cin >> duracion;
            cout << "Ingrese tripulación necesaria: ";
            cin >> tripulacion;

            misiones.push_back(Mision(destino, duracion, tripulacion));
            cout << "Misión creada con éxito.\n";
        } 
        else if (opcion == 2) {
            if (misiones.empty()) {
                cout << "No hay misiones registradas.\n";
            } else {
                cout << "\nMisiones registradas:\n";
                for (size_t i = 0; i < misiones.size(); i++) {
                    cout << i + 1 << ". Destino: " << misiones[i].getDestino()
                         << ", Duración: " << misiones[i].getDuracion() << " horas"
                         << ", Tripulación: " << misiones[i].getTripulacion() << endl;
                }
            }
        } 
        else if (opcion == 3) {
            if (misiones.empty()) {
                cout << "No hay misiones para simular.\n";
            } else {
                int mIndex;
                cout << "Seleccione una misión (número): ";
                cin >> mIndex;

                if (mIndex < 1 || mIndex > (int)misiones.size()) {
                    cout << "Misión no válida.\n";
                    continue;
                }

                Mision &misionSeleccionada = misiones[mIndex - 1];

                while (!avion.verificarMision(misionSeleccionada)) { // Método corregido
                    cout << "La misión no es posible debido a restricciones de combustible o tripulación.\n";
                    cout << "1. Modificar misión\n";
                    cout << "2. Volver al menú\n";
                    cout << "Seleccione una opción: ";
                    int subOpcion;
                    cin >> subOpcion;

                    if (subOpcion == 1) {
                        double nuevaDuracion;
                        int nuevaTripulacion;

                        cout << "Ingrese nueva duración en horas: ";
                        cin >> nuevaDuracion;
                        misionSeleccionada.setDuracion(nuevaDuracion);

                        cout << "Ingrese nueva tripulación necesaria: ";
                        cin >> nuevaTripulacion;
                        misionSeleccionada.setTripulacion(nuevaTripulacion);
                    } else {
                        break;
                    }
                }

                if (avion.verificarMision(misionSeleccionada)) {
                    avion.ejecutarMision(misionSeleccionada); // Método corregido
                }
            }
        }

    } while (opcion != 4);

    return 0;
}
