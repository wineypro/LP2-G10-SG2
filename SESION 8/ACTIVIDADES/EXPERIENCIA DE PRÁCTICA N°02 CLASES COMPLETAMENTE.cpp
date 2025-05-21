#include <iostream>
using namespace std;


const double PI = 3.141592653589793;


class Forma {
public:
    virtual double calcularPerimetro() const = 0; 
    virtual ~Forma() {}
};


class Circulo : public Forma {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularPerimetro() const override {
        return 2 * PI * radio;
    }
};


class Rectangulo : public Forma {
private:
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}
    double calcularPerimetro() const override {
        return 2 * (base + altura);
    }
};


class Triangulo : public Forma {
private:
    double lado1, lado2, lado3;
public:
    Triangulo(double a, double b, double c) : lado1(a), lado2(b), lado3(c) {}
    double calcularPerimetro() const override {
        return lado1 + lado2 + lado3;
    }
};


int main() {
    int opcion;
    Forma* forma = nullptr;

    cout << "Seleccione una forma para calcular el perimetro:\n";
    cout << "1. Circulo\n";
    cout << "2. Rectangulo\n";
    cout << "3. Triangulo\n";
    cout << "Opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1: {
            double radio;
            cout << "Ingrese el radio del circulo: ";
            cin >> radio;
            forma = new Circulo(radio);
            break;
        }
        case 2: {
            double base, altura;
            cout << "Ingrese la base del rectangulo: ";
            cin >> base;
            cout << "Ingrese la altura del rectangulo: ";
            cin >> altura;
            forma = new Rectangulo(base, altura);
            break;
        }
        case 3: {
            double l1, l2, l3;
            cout << "Ingrese los tres lados del triangulo:\n";
            cout << "Lado 1: "; cin >> l1;
            cout << "Lado 2: "; cin >> l2;
            cout << "Lado 3: "; cin >> l3;
            forma = new Triangulo(l1, l2, l3);
            break;
        }
        default:
            cout << "Opcion invalida." << endl;
            return 1;
    }

    if (forma) {
        cout << "El perimetro de la forma seleccionada es: " << forma->calcularPerimetro() << endl;
        delete forma;
    }

    return 0;
}
