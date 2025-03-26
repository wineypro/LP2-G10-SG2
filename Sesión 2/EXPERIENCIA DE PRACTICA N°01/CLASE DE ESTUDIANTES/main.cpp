#include <iostream>

using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;
    string grado;
    float calificacion;

public:
    Estudiante(string nombre, int edad, string grado)
        : nombre(nombre), edad(edad), grado(grado), calificacion(0.0)
    {
    }

    void tomarExamen()
    {
        cout << nombre << " ha tomado el examen." << endl;
    }

    void recibirCalificacion(float nota)
    {
        calificacion = nota;
        cout << nombre << " ha recibido una calificacion de " << calificacion << endl;
    }

    void mostrar_info()
    {
        cout << "Nombre: " << nombre << ", Edad: " << edad << ", Grado: " << grado << ", Calificacion: " << calificacion << endl;
    }
};

int main()
{
    Estudiante estudiante1("Carlos", 20, "Universidad");
    Estudiante estudiante2("Ana", 18, "Preparatoria");

    estudiante1.mostrar_info();
    estudiante1.tomarExamen();
    estudiante1.recibirCalificacion(85.5);

    estudiante2.mostrar_info();
    estudiante2.tomarExamen();
    estudiante2.recibirCalificacion(90.0);

    return 0;
}