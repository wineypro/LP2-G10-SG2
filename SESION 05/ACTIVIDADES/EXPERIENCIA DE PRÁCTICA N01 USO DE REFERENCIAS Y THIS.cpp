#include <iostream>
#include <string>

using namespace std;

class CuentaBancaria {
private:
    string numero;
    string titular;
    double saldo;

public:
    CuentaBancaria(const string& numero, const string& titular, double saldoInicial = 0)
        : numero(numero), titular(titular), saldo(saldoInicial) {}

    CuentaBancaria& depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
        } else {
            cout << "Monto inválido para depósito." << endl;
        }
        return *this;
    }

    CuentaBancaria& retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
        } else {
            cout << "Monto inválido o saldo insuficiente." << endl;
        }
        return *this;
    }

    void mostrarSaldo() const {
        cout << "Saldo actual de " << titular << " (" << numero << "): $" << saldo << endl;
    }
};

int main() {
    CuentaBancaria cuenta("001122", "Juan Pérez", 500);

    cuenta.depositar(1000).retirar(200).mostrarSaldo();

    return 0;
}
