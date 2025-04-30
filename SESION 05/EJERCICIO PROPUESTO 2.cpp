#include <iostream>
#include <string>

using namespace std;

class FechaRegistro {
private:
    int dia, mes, anio;
public:
    FechaRegistro(int d, int m, int a) : dia(d), mes(m), anio(a) {}
    void mostrar() const {
        cout << dia << "/" << mes << "/" << anio << endl;
    }
};

class Direccion {
private:
    string calle;
    string ciudad;
    string pais;
public:
    Direccion(const string& c, const string& ciu, const string& p)
        : calle(c), ciudad(ciu), pais(p) {}

    void mostrar() const {
        cout << "Calle: " << calle << ", Ciudad: " << ciudad << ", Pais: " << pais << endl;
    }
};

class Cliente {
private:
    string nombre;
    FechaRegistro fecha;
    Direccion direccion;
public:
    Cliente(const string& nom, const FechaRegistro& f, const Direccion& d)
        : nombre(nom), fecha(f), direccion(d) {}

    void mostrar() const {
        cout << "Nombre del Cliente: " << nombre << endl;
        cout << "Fecha de Registro: ";
        fecha.mostrar();
        cout << "Direccion: ";
        direccion.mostrar();
    }
};

int main() {
    string nombre, calle, ciudad, pais;
    int dia, mes, anio;

    cout << "Ingrese el nombre del cliente: ";
    getline(cin, nombre);

    cout << "Ingrese la calle: ";
    getline(cin, calle);

    cout << "Ingrese la ciudad: ";
    getline(cin, ciudad);

    cout << "Ingrese el pais: ";
    getline(cin, pais);

    cout << "Ingrese la fecha de registro (dia mes anio): ";
    cin >> dia >> mes >> anio;

    FechaRegistro fecha(dia, mes, anio);
    Direccion direccion(calle, ciudad, pais);
    Cliente cliente(nombre, fecha, direccion);

    cout << "\n--- Informacion del Cliente ---\n";
    cliente.mostrar();

    return 0;
}