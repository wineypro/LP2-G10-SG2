#include <iostream>

using namespace std;

class Auto {
public:
    string nombre;
    int velocidadMaxima;
    int distanciaRecorrida;

    Auto(string nom, int velMax) {
        nombre = nom;
        velocidadMaxima = velMax;
        distanciaRecorrida = 0;
    }

    void avanzar(int avance, int distanciaTotal) {
        if (avance > velocidadMaxima) {
            cout << " No puedes avanzar mas de " << velocidadMaxima << " metros.\n";
            return;
        } 
        if (avance < 0) {
            cout << " No puedes ingresar un numero negativo.\n";
            return;
        }
        if (distanciaRecorrida + avance > distanciaTotal) {
            cout << " No puedes avanzar mas de la distancia total de la carrera (" << distanciaTotal << " metros).\n";
            return;
        }

        distanciaRecorrida += avance;
    }
};

class Carrera {
private:
    int distanciaTotal;
    int dificultad;
    Auto jugador;
    Auto computadora;
    int turno;  // contador de turnos ( variar el avance de la computadora)lñk

public:
    Carrera(int distancia, int dificultad, string nombreJugador)
        : distanciaTotal(distancia), dificultad(dificultad),
          jugador(nombreJugador, 100), computadora("Computadora", 80 + dificultad * 10), turno(0) {}

    void iniciar() {
        cout << "Comienza la carrera\n";

        while (jugador.distanciaRecorrida < distanciaTotal && computadora.distanciaRecorrida < distanciaTotal) {
            int avanceJugador;

            
            do {
                cout << jugador.nombre << ", ingresa la distancia que deseas avanzar (maximo " 
                     << jugador.velocidadMaxima << "): ";
                cin >> avanceJugador;

                if (avanceJugador > jugador.velocidadMaxima) {
                    cout << " No puedes avanzar mas de " << jugador.velocidadMaxima << " metros.\n";
                } else if (avanceJugador < 0) {
                    cout << "No puedes ingresar un numero negativo.\n";
                }
            } while (avanceJugador > jugador.velocidadMaxima || avanceJugador < 0);

            jugador.avanzar(avanceJugador, distanciaTotal);

            // turno computadora
            int avanceComputadora = (turno % 3 + 1) * 10;  // alterna entre 10, 20 y 30 metros
            if (computadora.distanciaRecorrida + avanceComputadora > distanciaTotal) {
                avanceComputadora = distanciaTotal - computadora.distanciaRecorrida;
            }
            computadora.avanzar(avanceComputadora, distanciaTotal);
            turno++;  // incrementar el turno 

            // progreso
            cout << jugador.nombre << " ha recorrido: " << jugador.distanciaRecorrida << " metros.\n";
            cout << "Computadora ha recorrido: " << computadora.distanciaRecorrida << " metros.\n";
            cout << "--------------------------------\n";
        }

       
        if (jugador.distanciaRecorrida >= distanciaTotal && computadora.distanciaRecorrida >= distanciaTotal) {
            cout << "Es un empate\n";
        } else if (jugador.distanciaRecorrida >= distanciaTotal) {
            cout << jugador.nombre << " ha ganado la carrera\n";
        } else {
            cout << "La computadora ha ganado la carrera\n";
        }
    }
};

int main() {
    string nombreJugador;
    int distancia, dificultad;

    cout << "Bienvenido a la Carrera de Autos\n";
    cout << "Ingresa tu nombre: ";
    cin >> nombreJugador;
    cout << "Ingresa la distancia de la carrera (metros): ";
    cin >> distancia;

    do {
        cout << "Selecciona la dificultad (1-5): ";
        cin >> dificultad;

        if (dificultad < 1 || dificultad > 5) {
            cout << " Dificultad fuera de rango. Debe estar entre 1 y 5.\n";
        }
    } while (dificultad < 1 || dificultad > 5);

    Carrera carrera(distancia, dificultad, nombreJugador);
    carrera.iniciar();

    return 0;
}