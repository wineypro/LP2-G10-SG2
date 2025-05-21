#include <iostream>

using namespace std;


const double PI = 3.141592653589793;

class Figura {
public:
    virtual void dibujar() const = 0;
    virtual double calcularArea() const = 0;
    virtual ~Figura() {}
};

class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {}

    void dibujar() const override {
        cout << "Dibujando un circulo con radio " << radio << endl;
    }

    double calcularArea() const override {
        return PI * radio * radio;
    }
};

class Rectangulo : public Figura {
private:
    double ancho;
    double alto;

public:
    Rectangulo(double a, double h) : ancho(a), alto(h) {}

    void dibujar() const override {
        cout << "Dibujando un rectangulo de " << ancho << " x " << alto << endl;
    }

    double calcularArea() const override {
        return ancho * alto;
    }
};


class Triangulo : public Figura {
private:
    double base;
    double altura;

public:
    Triangulo(double b, double h) : base(b), altura(h) {}

    void dibujar() const override {
        cout << "Dibujando un triangulo con base " << base << " y altura " << altura << endl;
    }

    double calcularArea() const override {
        return (base * altura) / 2.0;
    }
};


int main() {
    int opcion;
    Figura* figura = nullptr;

    cout << "Selecciona una figura:" << endl;
    cout << "1. Circulo" << endl;
    cout << "2. Rectangulo" << endl;
    cout << "3. Triangulo" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    if (opcion == 1) {
        double r;
        cout << "Ingresa el radio del circulo: ";
        cin >> r;
        figura = new Circulo(r);
    }
    else if (opcion == 2) {
        double a, h;
        cout << "Ingresa el ancho del rectangulo: ";
        cin >> a;
        cout << "Ingresa el alto del rectangulo: ";
        cin >> h;
        figura = new Rectangulo(a, h);
    }
    else if (opcion == 3) {
        double b, h;
        cout << "Ingresa la base del triangulo: ";
        cin >> b;
        cout << "Ingresa la altura del triangulo: ";
        cin >> h;
        figura = new Triangulo(b, h);
    }
    else {
        cout << "Opcion invalida." << endl;
        return 1;
    }

    cout << endl;
    figura->dibujar();
    cout << "Area: " << figura->calcularArea() << endl;

    delete figura;
    return 0;
}
