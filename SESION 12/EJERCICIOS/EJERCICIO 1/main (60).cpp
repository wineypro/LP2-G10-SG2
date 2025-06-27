#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int buscarProducto(const vector<string>& codigos, const string& codigo) {
    for (int i = 0; i < codigos.size(); i++) {
        if (codigos[i] == codigo) return i;
    }
    return -1;
}


void agregarProducto(vector<string>& codigos,
                     vector<string>& descripciones,
                     vector<int>& cantidades) {
    string codigo, descripcion;
    int cantidad;
    cout << "Ingrese codigo del producto: ";
    cin >> codigo;
    if (buscarProducto(codigos, codigo) != -1) {
        cout << "Error: ya existe un producto con ese codigo.\n";
        return;
    }
    cout << "Ingrese descripcion: ";
    cin.ignore();
    getline(cin, descripcion);
    cout << "Ingrese cantidad inicial: ";
    cin >> cantidad;
    codigos.push_back(codigo);
    descripciones.push_back(descripcion);
    cantidades.push_back(cantidad);
    cout << "Producto agregado correctamente.\n";
}


void actualizarCantidad(vector<string>& codigos,
                        vector<int>& cantidades) {
    string codigo;
    cout << "Ingrese codigo del producto a actualizar: ";
    cin >> codigo;
    int idx = buscarProducto(codigos, codigo);
    if (idx == -1) {
        cout << "No se encontro producto con ese codigo.\n";
        return;
    }
    int nuevaCant;
    cout << "Ingrese nueva cantidad: ";
    cin >> nuevaCant;
    cantidades[idx] = nuevaCant;
    cout << "Cantidad actualizada.\n";
}


void buscarYMostrar(const vector<string>& codigos,
                    const vector<string>& descripciones,
                    const vector<int>& cantidades) {
    string codigo;
    cout << "Ingrese codigo del producto a buscar: ";
    cin >> codigo;
    int idx = buscarProducto(codigos, codigo);
    if (idx == -1) {
        cout << "No se encontro producto con ese codigo.\n";
    } else {
        cout << "Codigo: "      << codigos[idx]
             << " | Descripcion: " << descripciones[idx]
             << " | Cantidad: "    << cantidades[idx] << "\n";
    }
}


void mostrarOrdenado(const vector<string>& codigos,
                     const vector<string>& descripciones,
                     const vector<int>& cantidades) {
    int n = codigos.size();
    if (n == 0) {
        cout << "El inventario esta vacio.\n";
        return;
    }
  
    vector<int> indices(n);
    for (int i = 0; i < n; i++) indices[i] = i;
   
    sort(indices.begin(), indices.end(),
         [&](int a, int b) {
             return descripciones[a] < descripciones[b];
         });
    cout << "\n--- Inventario ordenado por descripcion ---\n";
    for (int idx : indices) {
        cout << "Codigo: "      << codigos[idx]
             << " | Descripcion: " << descripciones[idx]
             << " | Cantidad: "    << cantidades[idx] << "\n";
    }
    cout << "------------------------------------------\n";
}

int main() {
    vector<string> codigos;
    vector<string> descripciones;
    vector<int> cantidades;
    int opcion;

    do {
        cout << "\nMENU DE GESTION DE INVENTARIO\n";
        cout << "1. Agregar nuevo producto\n";
        cout << "2. Actualizar cantidad de producto\n";
        cout << "3. Buscar producto por codigo\n";
        cout << "4. Mostrar inventario ordenado por descripcion\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarProducto(codigos, descripciones, cantidades);
                break;
            case 2:
                actualizarCantidad(codigos, cantidades);
                break;
            case 3:
                buscarYMostrar(codigos, descripciones, cantidades);
                break;
            case 4:
                mostrarOrdenado(codigos, descripciones, cantidades);
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}
