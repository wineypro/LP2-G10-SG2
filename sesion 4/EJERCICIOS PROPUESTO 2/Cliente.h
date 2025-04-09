#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
using namespace std;

class Cliente {
public:
    string nombre, direccion, telefono;
    vector<string> compras;
    vector<float> pagos;

    Cliente(string _nombre, string _direccion, string _telefono) {
        nombre = _nombre;
        direccion = _direccion;
        telefono = _telefono;
    }

    void agregarCompra(string producto) {
        compras.push_back(producto);
    }

    void registrarPago(float monto) {
        pagos.push_back(monto);
    }
};

#endif
