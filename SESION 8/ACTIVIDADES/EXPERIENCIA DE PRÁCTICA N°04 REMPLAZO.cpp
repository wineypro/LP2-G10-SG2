#include <iostream>
using namespace std;


class Vehiculo {
public:
    virtual void acelerar() const {
        cout << "Acelerando el vehiculo" << endl;
    }

    virtual ~Vehiculo() {}
};


class Coche : public Vehiculo {
public:
    void acelerar() const override {
        cout << "Acelerando el coche" << endl;
    }

    void encenderLuces() const {
        cout << "Luces del coche encendidas" << endl;
    }
};


class Motocicleta : public Vehiculo {
public:
    void acelerar() const override {
        cout << "Acelerando la motocicleta" << endl;
    }
};


int main() {
    
    Coche miCoche;
    cout << "Coche:" << endl;
    miCoche.acelerar();        
    miCoche.encenderLuces();   

    cout << endl;

    
    Motocicleta miMoto;
    cout << "Motocicleta:" << endl;
    miMoto.acelerar();         

    return 0;
}
