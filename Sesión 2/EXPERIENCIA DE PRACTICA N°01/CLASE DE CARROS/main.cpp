#include <iostream>

using namespace std;

class Coche {
private:
    string modelo;
    int anio;
    int velocidad;

public:
    Coche(string modelo, int anio)
        : modelo(modelo), anio(anio), velocidad(0)
    {
    }

    void acelerar(int incremento)
    {
        velocidad += incremento;
        cout << "El coche " << modelo << " acelera a " << velocidad << " km/h." << endl;
    }

    void frenar(int decremento)
    {
        velocidad -= decremento;
        if (velocidad < 0)
        {
            velocidad = 0;
        }
        cout << "El coche " << modelo << " reduce su velocidad a " << velocidad << " km/h." << endl;
    }

    void mostrar_info()
    {
        cout << "Modelo: " << modelo << ", Anio: " << anio << ", Velocidad: " << velocidad << " km/h." << endl;
    }
};

int main()
{
    Coche coche1("Toyota Corolla", 2020);
    Coche coche2("Honda Civic", 2018);

    coche1.mostrar_info();
    coche1.acelerar(50);
    coche1.frenar(20);

    coche2.mostrar_info();
    coche2.acelerar(60);
    coche2.frenar(30);

    return 0;
}
