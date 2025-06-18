#include <iostream>
using namespace std;


template <typename T>
class SistemaEntrega {
private:
    T entregas[10];
    int total;

public:
    SistemaEntrega() {
        total = 0;
    }

    void agregarEntrega(T entrega) {
        if (total < 10) {
            entregas[total] = entrega;
            total++;
        } else {
            cout << "No se pueden agregar más entregas." << endl;
        }
    }

    void mostrarEntregas() {
        cout << "Listado de entregas (" << total << " en total):" << endl;
        for (int i = 0; i < total; i++) {
            cout << "- Entrega " << i + 1 << ": " << entregas[i] << endl;
        }
    }

    int cantidadEntregas() {
        return total;
    }
};

int main() {
    
    SistemaEntrega<int> sistemaEnteros;
    sistemaEnteros.agregarEntrega(101);
    sistemaEnteros.agregarEntrega(202);
    sistemaEnteros.mostrarEntregas();

    cout << endl;

   
    SistemaEntrega<const char*> sistemaTexto;
    sistemaTexto.agregarEntrega("Zona Norte");
    sistemaTexto.agregarEntrega("Zona Sur");
    sistemaTexto.mostrarEntregas();

    cout << endl;

    
    SistemaEntrega<float> sistemaPesos;
    sistemaPesos.agregarEntrega(12.5);
    sistemaPesos.agregarEntrega(8.75);
    sistemaPesos.mostrarEntregas();

    return 0;
}
