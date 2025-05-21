#include <iostream>
using namespace std;

const double PI = 3.141592653589793;


class Figura {
public:
    virtual double calcularArea() const = 0; 
    virtual ~Figura() {}
};


class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() const override {
        return PI * radio * radio;
    }
};


class Rectangulo : public Figura {
private:
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() const override {
        return base * altura;
    }
};


class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() const override {
        return (base * altura) / 2;
    }
};


class Cuadrado : public Figura {
private:
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    double calcularArea() const override {
        return lado * lado;
    }
};


class Pentagono : public Figura {
private:
    double lado, apotema;
public:
    Pentagono(double l, double a) : lado(l), apotema(a) {}
    double calcularArea() const override {
        return (5 * lado * apotema) / 2;
    }
};


int main() {
    int opcion;
    Figura* figura = nullptr;

    cout << "Seleccione una figura para calcular el area:\n";
    cout << "1. Circulo\n";
    cout << "2. Rectangulo\n";
    cout << "3. Triangulo\n";
    cout << "4. Cuadrado\n";
    cout << "5. Pentagono\n";
    cout << "Opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1: {
            double radio;
            cout << "Ingrese el radio del circulo: ";
            cin >> radio;
            figura = new Circulo(radio);
            break;
        }
        case 2: {
            double base, altura;
            cout << "Ingrese la base del rectangulo: ";
            cin >> base;
            cout << "Ingrese la altura del rectangulo: ";
            cin >> altura;
            figura = new Rectangulo(base, altura);
            break;
        }
        case 3: {
            double base, altura;
            cout << "Ingrese la base del triangulo: ";
            cin >> base;
            cout << "Ingrese la altura del triangulo: ";
            cin >> altura;
            figura = new Triangulo(base, altura);
            break;
        }
        case 4: {
            double lado;
            cout << "Ingrese el lado del cuadrado: ";
            cin >> lado;
            figura = new Cuadrado(lado);
            break;
        }
        case 5: {
            double lado, apotema;
            cout << "Ingrese el lado del pentagono: ";
            cin >> lado;
            cout << "Ingrese el apotema del pentagono: ";
            cin >> apotema;
            figura = new Pentagono(lado, apotema);
            break;
        }
        default:
            cout << "Opcion invalida." << endl;
            return 1;
    }

    if (figura) {
        cout << "El area de la figura seleccionada es: " << figura->calcularArea() << endl;
        delete figura;
    }

    return 0;
}