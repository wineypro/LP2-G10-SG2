#include <iostream>

using namespace std;

class Factura {
private:
    string numeroFactura;
    string fecha;
    double monto;

public:
    Factura(string numeroFactura, string fecha, double monto)
        : numeroFactura(numeroFactura), fecha(fecha), monto(monto) {}

    string getNumeroFactura() {
        return numeroFactura;
    }

    void setNumeroFactura(string nuevoNumero) {
        numeroFactura = nuevoNumero;
    }

    string getFecha() {
        return fecha;
    }

    void setFecha(string nuevaFecha) {
        fecha = nuevaFecha;
    }

    double getMonto() {
        return monto;
    }

    void setMonto(double nuevoMonto) {
        if (nuevoMonto >= 0) {
            monto = nuevoMonto;
        } else {
            cout << "Monto invalido." << endl;
        }
    }

    void mostrarFactura() {
        cout << "Factura N°: " << numeroFactura << ", Fecha: " << fecha << ", Monto: " << monto << " USD" << endl;
    }
};

int main() {
    Factura factura1("001", "2025-03-25", 150.75);
    Factura factura2("002", "2025-03-26", 320.50);

    factura1.mostrarFactura();
    factura2.mostrarFactura();

    factura1.setMonto(200.00);
    factura1.mostrarFactura();

    return 0;
}
