#include <iostream>
using namespace std;

class Calculadora {
public:
    int sumar(int a, int b) {
        return a + b;
    }

    double sumar(double a, double b) {
        return a + b;
    }

    int sumar(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculadora calc;
    cout << "Suma de enteros (2, 3): " << calc.sumar(2, 3) << endl;
    cout << "Suma de decimales (2.5, 3.5): " << calc.sumar(2.5, 3.5) << endl;
    cout << "Suma de tres enteros (1, 2, 3): " << calc.sumar(1, 2, 3) << endl;
    return 0;
}
