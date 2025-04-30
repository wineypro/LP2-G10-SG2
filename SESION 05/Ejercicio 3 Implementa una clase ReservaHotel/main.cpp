#include <iostream>
#include <string>
using namespace std;

class Habitacion {
private:
    int numero;
    string tipo;
    double precioPorNoche;

public:
    Habitacion() : numero(0), tipo(""), precioPorNoche(0.0) {}

    Habitacion(int num, string t, double precio)
        : numero(num), tipo(t), precioPorNoche(precio) {}

    int getNumero() const {
        return numero;
    }

    double getPrecio() const {
        return precioPorNoche;
    }

    void mostrar() const {
        cout << "Habitación " << numero << " (" << tipo << ") - Precio por noche: $" << precioPorNoche << endl;
    }
};

class ReservaHotel {
private:
    Habitacion* habitaciones;
    int cantidad;

public:
    ReservaHotel(int cant) : cantidad(cant) {
        habitaciones = new Habitacion[cantidad];
    }

    ~ReservaHotel() {
        delete[] habitaciones;
    }

    bool numeroRepetido(int num, int hasta) const {
        for (int i = 0; i < hasta; ++i) {
            if (habitaciones[i].getNumero() == num) {
                return true;
            }
        }
        return false;
    }

    void ingresarDatos() {
        for (int i = 0; i < cantidad; ++i) {
            int numero;
            string tipo;
            double precio;

            cout << "Habitación #" << (i + 1) << endl;

            while (true) {
                cout << "Número: ";
                cin >> numero;
                if (numeroRepetido(numero, i)) {
                    cout << "Ese número de habitación ya fue ingresado. Intenta con otro.\n";
                } else {
                    break;
                }
            }

            cin.ignore();
            cout << "Tipo: ";
            getline(cin, tipo);

            while (true) {
                cout << "Precio por noche: ";
                cin >> precio;
                if (precio <= 0) {
                    cout << "El precio debe ser mayor que 0. Intenta de nuevo.\n";
                } else {
                    break;
                }
            }

            habitaciones[i] = Habitacion(numero, tipo, precio);
            cout << endl;
        }
    }

    void mostrarHabitaciones() const {
        for (int i = 0; i < cantidad; ++i) {
            habitaciones[i].mostrar();
        }
    }

    double calcularTotalPorNoche() const {
        double total = 0;
        for (int i = 0; i < cantidad; ++i) {
            total += habitaciones[i].getPrecio();
        }
        return total;
    }
};

int main() {
    int opcion;
    ReservaHotel* hotel = nullptr;

    do {
        cout << "\n--- MENU RESERVA HOTEL ---" << endl;
        cout << "1. Ingresar habitaciones" << endl;
        cout << "2. Mostrar habitaciones" << endl;
        cout << "3. Calcular total por noche" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int n;
            if (hotel != nullptr) {
                delete hotel;
            }
            cout << "Ingrese la cantidad de habitaciones: ";
            cin >> n;
            hotel = new ReservaHotel(n);
            hotel->ingresarDatos();
            break;
        }
        case 2:
            if (hotel != nullptr) {
                hotel->mostrarHabitaciones();
            } else {
                cout << "Primero debe ingresar habitaciones." << endl;
            }
            break;
        case 3:
            if (hotel != nullptr) {
                cout << "Total por noche: $" << hotel->calcularTotalPorNoche() << endl;
            } else {
                cout << "Primero debe ingresar habitaciones." << endl;
            }
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción inválida." << endl;
        }

    } while (opcion != 4);

    if (hotel != nullptr) {
        delete hotel;
    }

    return 0;
}
