#include <iostream>
using namespace std;


class Ruta {
private:
    int id;
    const char* destino;

public:
    Ruta(int idRuta, const char* ciudad) {
        id = idRuta;
        destino = ciudad;
    }

    void mostrarRuta() {
        cout << "Ruta ID: " << id << " - Destino: " << destino << endl;
    }

  
    template <typename T>
    void asignarVehiculo(T vehiculo) {
        cout << "Vehículo asignado a la ruta: " << vehiculo << endl;
    }
};


class Entrega {
private:
    int numeroEntrega;

public:
    Entrega(int num) {
        numeroEntrega = num;
    }

    void mostrarEntrega() {
        cout << "Entrega N°: " << numeroEntrega << endl;
    }

   
    template <typename T>
    void programarHorario(T hora) {
        cout << "Horario programado para entrega: " << hora << endl;
    }
};


int main() {
   
    Ruta r1(101, "Zona Norte");
    r1.mostrarRuta();
    r1.asignarVehiculo("Camión A");
    r1.asignarVehiculo(1234);  

    cout << endl;

    
    Entrega e1(555);
    e1.mostrarEntrega();
    e1.programarHorario("08:30 AM");
    e1.programarHorario(830);  

    return 0;
}
