#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int buscarContacto(const vector<string>& nombres, const string& nombre) {
    for (int i = 0; i < nombres.size(); i++) {
        if (nombres[i] == nombre) return i;
    }
    return -1;
}


void agregarContacto(vector<string>& nombres,
                     vector<string>& telefonos,
                     vector<string>& correos) {
    string nombre, telefono, correo;
    cout << "Ingrese nombre: ";
    cin.ignore();
    getline(cin, nombre);
    if (buscarContacto(nombres, nombre) != -1) {
        cout << "Error: contacto ya existe.\n";
        return;
    }
    cout << "Ingrese telefono: ";
    getline(cin, telefono);
    cout << "Ingrese correo: ";
    getline(cin, correo);
    nombres.push_back(nombre);
    telefonos.push_back(telefono);
    correos.push_back(correo);
    cout << "Contacto agregado.\n";
}


void mostrarContacto(const vector<string>& nombres,
                     const vector<string>& telefonos,
                     const vector<string>& correos) {
    if (nombres.empty()) {
        cout << "La agenda esta vacia.\n";
        return;
    }
    string nombre;
    cout << "Ingrese nombre a buscar: ";
    cin.ignore();
    getline(cin, nombre);
    int idx = buscarContacto(nombres, nombre);
    if (idx == -1) {
        cout << "Contacto no encontrado.\n";
    } else {
        cout << "Nombre: "   << nombres[idx]
             << " | Telefono: " << telefonos[idx]
             << " | Correo: "   << correos[idx] << "\n";
    }
}


void actualizarContacto(vector<string>& nombres,
                        vector<string>& telefonos,
                        vector<string>& correos) {
    if (nombres.empty()) {
        cout << "La agenda esta vacia.\n";
        return;
    }
    string nombre;
    cout << "Ingrese nombre del contacto a actualizar: ";
    cin.ignore();
    getline(cin, nombre);
    int idx = buscarContacto(nombres, nombre);
    if (idx == -1) {
        cout << "Contacto no existe.\n";
        return;
    }
    string telefono, correo;
    cout << "Ingrese nuevo telefono: ";
    getline(cin, telefono);
    cout << "Ingrese nuevo correo: ";
    getline(cin, correo);
    telefonos[idx] = telefono;
    correos[idx] = correo;
    cout << "Contacto actualizado.\n";
}


void mostrarAgenda(const vector<string>& nombres,
                   const vector<string>& telefonos,
                   const vector<string>& correos) {
    int n = nombres.size();
    if (n == 0) {
        cout << "La agenda esta vacia.\n";
        return;
    }
   
    vector<int> indices(n);
    for (int i = 0; i < n; i++) indices[i] = i;
    
    sort(indices.begin(), indices.end(),
         [&](int a, int b) {
             return nombres[a] < nombres[b];
         });
    cout << "\n--- Lista de contactos ---\n";
    for (int i : indices) {
        cout << "Nombre: "   << nombres[i]
             << " | Telefono: " << telefonos[i]
             << " | Correo: "   << correos[i] << "\n";
    }
    cout << "--------------------------\n";
}

int main() {
    vector<string> nombres;
    vector<string> telefonos;
    vector<string> correos;
    int opcion;

    do {
        cout << "\nMENU AGENDA DE CONTACTOS\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Buscar contacto\n";
        cout << "3. Actualizar contacto\n";
        cout << "4. Mostrar agenda ordenada\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarContacto(nombres, telefonos, correos);
                break;
            case 2:
                mostrarContacto(nombres, telefonos, correos);
                break;
            case 3:
                actualizarContacto(nombres, telefonos, correos);
                break;
            case 4:
                mostrarAgenda(nombres, telefonos, correos);
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
