#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const char* NOMBRE_ARCHIVO = "inventario.dat";




vector<Producto> leerInventario() {
    vector<Producto> lista;
    ifstream ifs(NOMBRE_ARCHIVO, ios::binary);
    if (!ifs) return lista;  

    Producto p;
    while (p.leerDe(ifs)) {
        lista.push_back(p);
    }
    return lista;
}


void agregarProducto(const Producto& p) {
    ofstream ofs(NOMBRE_ARCHIVO, ios::binary | ios::app);
    if (!ofs) {
        cerr << "Error al abrir archivo para agregar.\n";
        return;
    }
    p.escribirEn(ofs);
    ofs.close();
    cout << "Producto agregado al archivo.\n";
}


bool actualizarProducto(const string& nombreBuscado, const Producto& datosNuevos) {
   
    auto inventario = leerInventario();
    bool encontrado = false;

    for (auto& p : inventario) {
        if (p.obtenerNombre() == nombreBuscado) {
            p = datosNuevos;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) return false;

    
    ofstream ofs(NOMBRE_ARCHIVO, ios::binary | ios::trunc);
    for (const auto& p : inventario) {
        p.escribirEn(ofs);
    }
    ofs.close();
    cout << "Producto actualizado en el archivo.\n";
    return true;
}


bool venderProducto(const string& nombreBuscado, int cantidadAVender) {
    auto inventario = leerInventario();
    bool encontrado = false;

    for (auto& p : inventario) {
        if (p.obtenerNombre() == nombreBuscado) {
            if (p.obtenerCantidad() < cantidadAVender) {
                cout << "Stock insuficiente.\n";
                return false;
            }
            p.establecerCantidad(p.obtenerCantidad() - cantidadAVender);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) return false;

    ofstream ofs(NOMBRE_ARCHIVO, ios::binary | ios::trunc);
    for (const auto& p : inventario) {
        p.escribirEn(ofs);
    }
    ofs.close();
    cout << "Venta registrada en el archivo.\n";
    return true;
}


int main() {
  
    Producto p1("Mouse Gamer", 25.0, 20);
    agregarProducto(p1);

    
    Producto p1n("Mouse Gamer", 22.5, 30);
    if (!actualizarProducto("Mouse Gamer", p1n))
        cout << "No se encontro el producto para actualizar.\n";

   
    if (!venderProducto("Mouse Gamer", 5))
        cout << "Error al vender producto.\n";

   
    auto todos = leerInventario();
    cout << "\n--- Inventario actual ---\n";
    for (const auto& p : todos) {
        cout << p.obtenerNombre()
             << " | Precio: " << p.obtenerPrecio()
             << " | Cantidad: " << p.obtenerCantidad() << "\n";
    }

    return 0;
}
