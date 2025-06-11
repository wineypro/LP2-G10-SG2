#include <iostream>
using namespace std;

class Figura {
public:
    virtual double calcularArea() const = 0;
    virtual ~Figura() {}
};

class Circulo : public Figura {
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() const override {
        double pi = 3.1416;
        return pi * radio * radio;
    }
};

class Rectangulo : public Figura {
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() const override {
        return base * altura;
    }
};

class Triangulo : public Figura {
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() const override {
        return (base * altura) / 2.0;
    }
};

int main() {
    Figura* figuras[3];
    figuras[0] = new Circulo(5);
    figuras[1] = new Rectangulo(4, 6);
    figuras[2] = new Triangulo(3, 4);

    for (int i = 0; i < 3; ++i) {
        cout << "Area de figura " << i + 1 << ": " << figuras[i]->calcularArea() << endl;
        delete figuras[i];
    }

    return 0;
}
