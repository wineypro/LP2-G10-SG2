#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void mostrarArchivo(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: no se pudo abrir el archivo \"" << filename << "\".\n";
        return;
    }

    cout << "\nContenido de \"" << filename << "\":\n";
    string line;
    while (getline(file, line)) {
        cout << line << '\n';
    }
    file.close();
}


double divide(int numerador, int divisor) {
    if (divisor == 0) {
        throw runtime_error("Error: no se puede dividir por cero.");
    }
    return static_cast<double>(numerador) / divisor;
}

int main() {
    
    cout << "Introduce el nombre del archivo de texto: ";
    string filename;
    getline(cin, filename);
    mostrarArchivo(filename);

    
    cout << "\n--- Ahora ingresa hasta 3 divisiones ---\n";
    for (int i = 1; i <= 3; ++i) {
        cout << "\nDivisión #" << i << ":\n";
        cout << "  Numerador: ";
        int num;
        cin >> num;
        cout << "  Divisor: ";
        int div;
        cin >> div;

        try {
            double resultado = divide(num, div);
            cout << "  Resultado: " << num << " / " << div << " = " << resultado << "\n";
        }
        catch (const runtime_error& e) {
            cerr <<e.what() << "\n";
        }
    }

    return 0;
}
