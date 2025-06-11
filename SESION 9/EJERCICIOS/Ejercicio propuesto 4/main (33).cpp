#include <iostream>
using namespace std;

const int MAX_PERSONAJES = 10;

class Personaje {
public:
    virtual void atacar() const = 0;
    virtual void defender() const = 0;
    virtual void habilidadEspecial() const = 0;
    virtual ~Personaje() {}
};

class Guerrero : public Personaje {
public:
    void atacar() const { cout << "Guerrero ataca con espada!\n"; }
    void defender() const { cout << "Guerrero bloquea con escudo!\n"; }
    void habilidadEspecial() const { cout << "Guerrero usa Furia Berserker!\n"; }
};

class Mago : public Personaje {
public:
    void atacar() const { cout << "Mago lanza un rayo magico!\n"; }
    void defender() const { cout << "Mago crea un escudo de energia!\n"; }
    void habilidadEspecial() const { cout << "Mago usa Bola de Fuego!\n"; }
};

class Arquero : public Personaje {
public:
    void atacar() const { cout << "Arquero dispara una flecha!\n"; }
    void defender() const { cout << "Arquero se esconde rapidamente!\n"; }
    void habilidadEspecial() const { cout << "Arquero usa Lluvia de Flechas!\n"; }
};

class PersonajePersonalizado : public Personaje {
private:
    char accionAtacar[50];
    char accionDefender[50];
    char accionEspecial[50];

    void copiar(char* destino, const char* origen) {
        int i = 0;
        while (origen[i] != '\0' && i < 49) {
            destino[i] = origen[i];
            i++;
        }
        destino[i] = '\0';
    }

public:
    PersonajePersonalizado(const char* a, const char* d, const char* e) {
        copiar(accionAtacar, a);
        copiar(accionDefender, d);
        copiar(accionEspecial, e);
    }

    void atacar() const { cout << accionAtacar << "\n"; }
    void defender() const { cout << accionDefender << "\n"; }
    void habilidadEspecial() const { cout << accionEspecial << "\n"; }
};

int main() {
    Personaje* personajes[MAX_PERSONAJES];
    int total = 0;
    char seguir = 's';

    while (seguir == 's' && total < MAX_PERSONAJES) {
        cout << "\nTipos de personaje:\n";
        cout << "1. Guerrero\n";
        cout << "2. Mago\n";
        cout << "3. Arquero\n";
        cout << "4. Otro (personalizado)\n";
        cout << "Seleccione una opcion (1-4): ";
        int opcion;
        cin >> opcion;

        Personaje* nuevo = 0;

        if (opcion == 1) {
            nuevo = new Guerrero();
        } else if (opcion == 2) {
            nuevo = new Mago();
        } else if (opcion == 3) {
            nuevo = new Arquero();
        } else if (opcion == 4) {
            char atacar[50], defender[50], especial[50];
            cin.ignore(); 
            cout << "Descripcion del ataque: ";
            cin.getline(atacar, 50);
            cout << "Descripcion de la defensa: ";
            cin.getline(defender, 50);
            cout << "Descripcion de la habilidad especial: ";
            cin.getline(especial, 50);
            nuevo = new PersonajePersonalizado(atacar, defender, especial);
        } else {
            cout << "Opcion invalida.\n";
            continue;
        }

        personajes[total++] = nuevo;
        cout << "Personaje creado con exito.\n";
        cout << "Desea agregar otro personaje? (s/n): ";
        cin >> seguir;
    }

    cout << "\n--- COMBATE ---\n";
    for (int i = 0; i < total; i++) {
        cout << "\nPersonaje #" << (i + 1) << ":\n";
        personajes[i]->atacar();
        personajes[i]->defender();
        personajes[i]->habilidadEspecial();
        delete personajes[i];
    }

    return 0;
}
