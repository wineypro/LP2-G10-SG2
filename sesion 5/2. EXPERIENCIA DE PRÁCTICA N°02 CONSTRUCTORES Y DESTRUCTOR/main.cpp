#include <iostream>
#include <string>
using namespace std;

class Dispositivo{
    private:
        string marca;
        string modelo;
        int anioFabricacion;
        
    public:
        Dispositivo(){
            marca = "desconocida";
            modelo = "desconocido";
            anioFabricacion = 0;
        }
        Dispositivo(string ma, string mo, int a){
            marca = ma;
            modelo = mo;
            anioFabricacion = a;
        }
        Dispositivo(const Dispositivo& D){
            marca = D.marca;
            modelo = D.modelo;
            anioFabricacion = D.anioFabricacion;
        }
        ~Dispositivo(){
            cout<<modelo<<endl;
        }
        void mostrar(){
            cout<<"la marca es "<<marca<<" el modelo es "<<modelo<<" y el año es "<<anioFabricacion<<endl;
        }
};
int main() {
    Dispositivo dispositivos[3] = {
        Dispositivo(),
        Dispositivo("lg","Laptop", 2020),
        Dispositivo(dispositivos[1]),
    };

    for (int i = 0; i < 3; i++) {
        dispositivos[i].mostrar();
    }

    return 0;
}