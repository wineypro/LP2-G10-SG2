#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numeros;
    int n, valor;

    cout << "Cuantos numeros desea ingresar? ";
    cin >> n;

    cout << "Ingrese los numeros:\n";
    for (int i = 0; i < n; i++) {
        cin >> valor;
        numeros.push_back(valor);
    }

    // a) Calcular suma
    int suma = 0;
    for (int i = 0; i < numeros.size(); i++) {
        suma += numeros[i];
    }

    // b) Encontrar maximo y minimo
    int maximo = numeros[0];
    int minimo = numeros[0];
    for (int i = 1; i < numeros.size(); i++) {
        if (numeros[i] > maximo) {
            maximo = numeros[i];
        }
        if (numeros[i] < minimo) {
            minimo = numeros[i];
        }
    }

    // c) Ordenar ascendentemente (metodo burbuja)
    for (int i = 0; i < numeros.size() - 1; i++) {
        for (int j = 0; j < numeros.size() - 1 - i; j++) {
            if (numeros[j] > numeros[j + 1]) {
                int tmp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = tmp;
            }
        }
    }

    // d) Eliminar numeros pares
    vector<int> impares;
    for (int i = 0; i < numeros.size(); i++) {
        if (numeros[i] % 2 != 0) {
            impares.push_back(numeros[i]);
        }
    }
    numeros = impares;

    // Mostrar resultados
    cout << "\nSuma total: " << suma << "\n";
    cout << "Numero maximo: " << maximo << "\n";
    cout << "Numero minimo: " << minimo << "\n";

    cout << "Vector ordenado sin pares:\n";
    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i] << " ";
    }
    cout << "\n";

    return 0;
}
