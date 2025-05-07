#include <iostream>
using namespace std;

class Circulo {
private:
    double radio;
    double diametro;

public:
    Circulo(double r) {
        radio = r;
        diametro = 2 * r;
    }

    void mostrarDatos() const {
        cout << "Radio: " << radio << ", Diametro: " << diametro << endl;
    }

    friend double calcularArea(const Circulo& c);
};

double calcularArea(const Circulo& c) {
    return 3.1416 * c.radio * c.radio;
}

int main() {
    Circulo c1(3.5);
    Circulo c2(5.0);

    c1.mostrarDatos();
    cout << "Area del circulo 1: " << calcularArea(c1) << endl;

    c2.mostrarDatos();
    cout << "Area del circulo 2: " << calcularArea(c2) << endl;

    return 0;
}
