#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int buscarEvento(const vector<string>& nombres, const string& nombre) {
    for (int i = 0; i < nombres.size(); i++) {
        if (nombres[i] == nombre) return i;
    }
    return -1;
}


void agregarEvento(vector<string>& nombres,
                   vector<string>& fechas,
                   vector<vector<string>>& asistentes) {
    string nombre, fecha;
    cout << "Ingrese nombre del evento: ";
    cin.ignore();
    getline(cin, nombre);
    if (buscarEvento(nombres, nombre) != -1) {
        cout << "Error: ya existe un evento con ese nombre.\n";
        return;
    }
    cout << "Ingrese fecha (DD/MM/AAAA): ";
    getline(cin, fecha);
    nombres.push_back(nombre);
    fechas.push_back(fecha);
    asistentes.push_back(vector<string>()); 
    cout << "Evento agregado correctamente.\n";
}


void agregarAsistentes(vector<string>& nombres,
                       vector<vector<string>>& asistentes) {
    if (nombres.empty()) {
        cout << "No hay eventos registrados.\n";
        return;
    }
    string nombre;
    cout << "Ingrese nombre del evento: ";
    cin.ignore();
    getline(cin, nombre);
    int idx = buscarEvento(nombres, nombre);
    if (idx == -1) {
        cout << "Evento no encontrado.\n";
        return;
    }
    cout << "Ingrese nombre de asistente (fin para terminar):\n";
    while (true) {
        string persona;
        getline(cin, persona);
        if (persona == "fin") break;
        asistentes[idx].push_back(persona);
    }
    cout << "Asistentes agregados.\n";
}


void mostrarAsistentes(const vector<string>& nombres,
                       const vector<vector<string>>& asistentes) {
    if (nombres.empty()) {
        cout << "No hay eventos registrados.\n";
        return;
    }
    string nombre;
    cout << "Ingrese nombre del evento: ";
    cin.ignore();
    getline(cin, nombre);
    int idx = buscarEvento(nombres, nombre);
    if (idx == -1) {
        cout << "Evento no encontrado.\n";
        return;
    }
    vector<string> lista = asistentes[idx];
    if (lista.empty()) {
        cout << "No hay asistentes para este evento.\n";
        return;
    }
    sort(lista.begin(), lista.end());
    cout << "\nAsistentes de " << nombre << ":\n";
    for (const string& a : lista) {
        cout << " - " << a << "\n";
    }
}


void buscarEventosPorFecha(const vector<string>& nombres,
                          const vector<string>& fechas) {
    if (nombres.empty()) {
        cout << "No hay eventos registrados.\n";
        return;
    }
    string fecha;
    cout << "Ingrese fecha a buscar (DD/MM/AAAA): ";
    cin.ignore();
    getline(cin, fecha);
    bool encontrado = false;
    cout << "\nEventos en " << fecha << ":\n";
    for (int i = 0; i < fechas.size(); i++) {
        if (fechas[i] == fecha) {
            cout << " - " << nombres[i] << "\n";
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron eventos en esa fecha.\n";
    }
}

int main() {
    vector<string> nombres;
    vector<string> fechas;
    vector<vector<string>> asistentes;
    int opcion;

    do {
        cout << "\nMENU GESTION DE EVENTOS\n";
        cout << "1. Agregar nuevo evento\n";
        cout << "2. Agregar asistentes a evento\n";
        cout << "3. Mostrar asistentes de un evento\n";
        cout << "4. Buscar eventos por fecha\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarEvento(nombres, fechas, asistentes);
                break;
            case 2:
                agregarAsistentes(nombres, asistentes);
                break;
            case 3:
                mostrarAsistentes(nombres, asistentes);
                break;
            case 4:
                buscarEventosPorFecha(nombres, fechas);
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}
