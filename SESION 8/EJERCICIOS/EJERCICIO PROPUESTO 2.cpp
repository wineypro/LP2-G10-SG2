#include <iostream>
#include <string>

using namespace std;


class Reproductor {
public:
    virtual void reproducir(const string& archivo) = 0;
    virtual void pausar() = 0;
    virtual void detener() = 0;
    virtual ~Reproductor() {}
};


class ReproductorMP3 : public Reproductor {
private:
    string archivoActual;
    bool enReproduccion;

public:
    ReproductorMP3() : archivoActual(""), enReproduccion(false) {}

    void reproducir(const string& archivo) override {
        archivoActual = archivo;
        enReproduccion = true;
        cout << "Reproduciendo archivo: " << archivoActual << endl;
    }

    void pausar() override {
        if (enReproduccion) {
            cout << "Pausando la reproduccion de: " << archivoActual << endl;
            enReproduccion = false;
        } else {
            cout << "No hay reproduccion activa para pausar." << endl;
        }
    }

    void detener() override {
        if (archivoActual != "") {
            cout << "Deteniendo la reproduccion de: " << archivoActual << endl;
            archivoActual = "";
            enReproduccion = false;
        } else {
            cout << "No hay ningun archivo en reproduccion para detener." << endl;
        }
    }
};


int main() {
    Reproductor* miReproductor = new ReproductorMP3();

    string archivo;
    cout << "Ingresa el nombre del archivo MP3 a reproducir: ";
    cin >> archivo;

    miReproductor->reproducir(archivo);
    miReproductor->pausar();
    miReproductor->detener();

    delete miReproductor;
    return 0;
}
