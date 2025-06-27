#include <iostream>
#include <deque>
#include <string>

using namespace std;

// Funcion para verificar si un caracter es vocal
bool esVocal(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    deque<char> caracteres;
    string cadena;

    cout << "Ingrese una cadena de texto: ";
    getline(cin, cadena);

    // Almacenar cada caracter en el deque
    for (int i = 0; i < cadena.length(); i++) {
        caracteres.push_back(cadena[i]);
    }

    // a) Mostrar caracteres uno por uno con iterador
    cout << "\nCaracteres uno por uno:\n";
    for (deque<char>::iterator it = caracteres.begin(); it != caracteres.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // b) Reemplazar vocales por '*'
    for (deque<char>::iterator it = caracteres.begin(); it != caracteres.end(); ++it) {
        if (esVocal(*it)) {
            *it = '*';
        }
    }

    // c) Mostrar en orden inverso con iterador inverso
    cout << "\nCaracteres en orden inverso:\n";
    for (deque<char>::reverse_iterator rit = caracteres.rbegin(); rit != caracteres.rend(); ++rit) {
        cout << *rit;
    }
    cout << endl;

    // Mostrar cadena modificada final
    cout << "\nCadena resultante:\n";
    for (deque<char>::iterator it = caracteres.begin(); it != caracteres.end(); ++it) {
        cout << *it;
    }
    cout << endl;

    return 0;
}
