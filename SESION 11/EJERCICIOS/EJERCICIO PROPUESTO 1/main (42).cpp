#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename;
    cout << "Introduce el nombre del archivo de texto: ";
    getline(cin, filename);

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: no se pudo abrir el archivo \"" << filename << "\".\n";
        return 1;
    }

    cout << "\nContenido de \"" << filename << "\":\n\n";
    string line;
    while (getline(file, line)) {
        cout << line << '\n';
    }

    file.close();
    return 0;
}
