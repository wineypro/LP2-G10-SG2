#include <iostream>
using namespace std;

class Cliente {
protected:
    string nombre;
    string apellido;
    string dni;
    double saldo;

protected:
    string encriptarTexto(string texto) {
        string resultado = "";
        for (int i = texto.length() - 1; i >= 0; i--) {
            resultado += texto[i];
        }
        return resultado;
    }

public:
    Cliente(string n, string a, string d, double s)
        : nombre(n), apellido(a), dni(d), saldo(s) {}

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << " " << apellido << endl;
        cout << "DNI: " << dni << endl;
        cout << "Saldo: S/" << saldo << endl;
    }
};

class ClienteSeguro : public Cliente {
private:
    string contrasena;

public:
    ClienteSeguro(string n, string a, string d, double s, string pass)
        : Cliente(n, a, d, s) {
        contrasena = encriptarTexto(pass);
    }

    bool verificarAutenticidad(string intento) {
        return contrasena == encriptarTexto(intento);
    }

    void mostrarInfoSegura() {
        cout << "--- INFORMACION DEL CLIENTE SEGURO ---" << endl;
        mostrarInformacion();
        cout << "Contrasena (encriptada): " << contrasena << endl;
    }
};

int main() {
    ClienteSeguro cliente("Ana", "Torres", "12345678", 1500.0, "clave123");

    cliente.mostrarInfoSegura();

    string intento;
    cout << "\nIngrese su contrasena para verificar autenticidad: ";
    cin >> intento;

    if (cliente.verificarAutenticidad(intento)) {
        cout << "Autenticacion exitosa. Acceso concedido." << endl;
    } else {
        cout << "Contrasena incorrecta. Acceso denegado." << endl;
    }

    return 0;
}