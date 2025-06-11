#include <iostream>
using namespace std;

const int MAX_ANIMALES = 10;

class Animal {
public:
    virtual void comer() const = 0;
    virtual void dormir() const = 0;
    virtual void moverse() const = 0;
    virtual ~Animal() {}
};

class Mamifero : public Animal {
public:
    void comer() const { cout << "El mamifero mastica su comida.\n"; }
    void dormir() const { cout << "El mamifero duerme acostado.\n"; }
    void moverse() const { cout << "El mamifero camina o corre.\n"; }
};

class Ave : public Animal {
public:
    void comer() const { cout << "El ave picotea su alimento.\n"; }
    void dormir() const { cout << "El ave duerme en su nido.\n"; }
    void moverse() const { cout << "El ave vuela por los cielos.\n"; }
};

class Reptil : public Animal {
public:
    void comer() const { cout << "El reptil traga sin masticar.\n"; }
    void dormir() const { cout << "El reptil duerme al sol.\n"; }
    void moverse() const { cout << "El reptil se arrastra.\n"; }
};

class AnimalPersonalizado : public Animal {
private:
    char come[50];
    char duerme[50];
    char mueve[50];
public:
    AnimalPersonalizado(const char* c, const char* d, const char* m) {
        copiar(come, c);
        copiar(duerme, d);
        copiar(mueve, m);
    }

    void comer() const { cout << come << "\n"; }
    void dormir() const { cout << duerme << "\n"; }
    void moverse() const { cout << mueve << "\n"; }

    void copiar(char* dest, const char* src) {
        int i = 0;
        while (src[i] != '\0' && i < 49) {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
};

int main() {
    Animal* animales[MAX_ANIMALES];
    int totalAnimales = 0;
    char seguir = 's';

    while (seguir == 's' && totalAnimales < MAX_ANIMALES) {
        cout << "\nTipos disponibles:\n";
        cout << "1. Mamifero\n";
        cout << "2. Ave\n";
        cout << "3. Reptil\n";
        cout << "4. Nuevo tipo\n";
        cout << "Seleccione una opcion (1-4): ";
        int opcion;
        cin >> opcion;

        Animal* nuevo = 0;

        if (opcion == 1) {
            nuevo = new Mamifero();
        } else if (opcion == 2) {
            nuevo = new Ave();
        } else if (opcion == 3) {
            nuevo = new Reptil();
        } else if (opcion == 4) {
            char come[50], duerme[50], mueve[50];
            cin.ignore();
            cout << "Nombre del nuevo tipo (solo referencia): ";
            char nombre[20];
            cin.getline(nombre, 20);
            cout << "Como come el " << nombre << "?: ";
            cin.getline(come, 50);
            cout << "Como duerme el " << nombre << "?: ";
            cin.getline(duerme, 50);
            cout << "Como se mueve el " << nombre << "?: ";
            cin.getline(mueve, 50);
            nuevo = new AnimalPersonalizado(come, duerme, mueve);
        } else {
            cout << "Opcion invalida.\n";
            continue;
        }

        animales[totalAnimales++] = nuevo;
        cout << "Animal agregado correctamente.\n";
        cout << "Deseas agregar otro animal? (s/n): ";
        cin >> seguir;
    }

    cout << "\n--- SIMULACION DE ANIMALES ---\n";
    for (int i = 0; i < totalAnimales; i++) {
        animales[i]->comer();
        animales[i]->dormir();
        animales[i]->moverse();
        cout << "-----------------------------\n";
        delete animales[i];
    }

    return 0;
}
