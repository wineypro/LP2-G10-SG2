#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Funcion para convertir una cadena a mayusculas
string aMayusculas(string palabra) {
    transform(palabra.begin(), palabra.end(), palabra.begin(), ::toupper);
    return palabra;
}

int main() {
    list<string> palabras;
    string entrada;

    cout << "Ingrese palabras (escriba 'fin' para terminar):\n";
    while (true) {
        cin >> entrada;
        if (entrada == "fin") break;
        palabras.push_back(entrada);
    }

    // a) Ya se almacenaron las palabras en una lista

    // b) Ordenar alfabeticamente
    palabras.sort();

    // c) Contar una palabra especifica
    string palabraBuscar;
    cout << "\nIngrese la palabra que desea contar: ";
    cin >> palabraBuscar;
    int cantidad = count(palabras.begin(), palabras.end(), palabraBuscar);

    // d) Convertir todas a mayusculas
    transform(palabras.begin(), palabras.end(), palabras.begin(), aMayusculas);

    // e) Mostrar resultados
    cout << "\nLista de palabras en mayusculas:\n";
    for (const string& palabra : palabras) {
        cout << palabra << endl;
    }

    cout << "\nLa palabra '" << palabraBuscar << "' aparece " << cantidad << " veces (en minusculas).\n";

    return 0;
}
