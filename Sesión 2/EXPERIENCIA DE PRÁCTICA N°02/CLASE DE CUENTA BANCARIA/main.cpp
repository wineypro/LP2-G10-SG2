#include <iostream>

using namespace std;

class CuentaBancaria {
private:
    string titular;
    string numeroCuenta;
    double saldo;

public:
    CuentaBancaria(string titular, string numeroCuenta, double saldoInicial)
        : titular(titular), numeroCuenta(numeroCuenta), saldo(saldoInicial) {}

    string getTitular() {
        return titular;
    }

    void setTitular(string nuevoTitular) {
        titular = nuevoTitular;
    }

    string getNumeroCuenta() {
        return numeroCuenta;
    }

    double getSaldo() {
        return saldo;
    }

    void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "Deposito de " << monto << " realizado. Saldo actual: " << saldo << endl;
        } else {
            cout << "Monto invalido para deposito." << endl;
        }
    }

    void retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            cout << "Retiro de " << monto << " realizado. Saldo actual: " << saldo << endl;
        } else {
            cout << "Retiro invalido. Saldo insuficiente o monto incorrecto." << endl;
        }
    }

    void mostrarInfo() {
        cout << "Titular: " << titular << ", Numero de cuenta: " << numeroCuenta << ", Saldo: " << saldo << endl;
    }
};

int main() {
    CuentaBancaria cuenta1("Juan Perez", "1234567890", 1000.0);
    CuentaBancaria cuenta2("Maria Lopez", "0987654321", 500.0);

    cuenta1.mostrarInfo();
    cuenta1.depositar(200);
    cuenta1.retirar(500);
    cuenta1.retirar(1000); // Intento de retiro invalido

    cuenta2.mostrarInfo();
    cuenta2.depositar(300);
    cuenta2.retirar(700); // Intento de retiro invalido

    return 0;
}
