#include <iostream>
using namespace std;

class Banco {
private:
    static double tasaInteres;

public:
    static void cambiarTasaInteres(double nuevaTasa) {
        tasaInteres = nuevaTasa;
    }

    static double obtenerTasaInteres() {
        return tasaInteres;
    }
};

double Banco::tasaInteres = 0.03;

class CuentaBancaria {
private:
    double saldo;

public:
    CuentaBancaria(double saldoInicial) {
        saldo = saldoInicial;
    }

    void depositar(double monto) {
        saldo += monto;
    }

    void retirar(double monto) {
        if (monto <= saldo) {
            saldo -= monto;
        } else {
            cout << "Fondos insuficientes" << endl;
        }
    }

    double calcularInteresGanado() const {
        return saldo * Banco::obtenerTasaInteres();
    }

    void mostrarSaldo() const {
        cout << "Saldo actual: " << saldo << endl;
    }
};

int main() {
    CuentaBancaria cuenta1(1000);
    cuenta1.mostrarSaldo();
    cout << "Interes ganado: " << cuenta1.calcularInteresGanado() << endl;

    Banco::cambiarTasaInteres(0.05);
    cuenta1.depositar(500);
    cuenta1.retirar(200);
    cuenta1.mostrarSaldo();
    cout << "Nuevo interes ganado: " << cuenta1.calcularInteresGanado() << endl;

    return 0;
}
