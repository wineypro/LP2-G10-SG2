#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;


class Producto {
public:
    string nombre;
    double precio;
    int cantidad;

    Producto() : precio(0), cantidad(0) {}
    Producto(const string& n, double p, int c)
        : nombre(n), precio(p), cantidad(c) {}

   
    string toCSV() const {
        ostringstream oss;
        oss << nombre << "," << precio << "," << cantidad;
        return oss.str();
    }
   
    static Producto fromCSV(const string& linea) {
        istringstream iss(linea);
        string token;
        Producto p;
        getline(iss, p.nombre, ',');
        getline(iss, token, ',');  p.precio   = stod(token);
        getline(iss, token, ',');  p.cantidad = stoi(token);
        return p;
    }
};


class GestorAccesoAleatorio {
private:
    const string archivoDatos = "productos.csv";
    const string archivoIndice = "indice.idx";
    
    unordered_map<string, streampos> indice;

   
    void construirIndice() {
        indice.clear();
        ifstream datos(archivoDatos, ios::binary);
        if (!datos) return;

        string linea;
        while (true) {
            streampos pos = datos.tellg();
            if (!getline(datos, linea)) break;
            Producto p = Producto::fromCSV(linea);
            indice[p.nombre] = pos;
        }
        datos.close();

        
        ofstream idx(archivoIndice, ios::binary | ios::trunc);
        for (auto& kv : indice) {
            size_t len = kv.first.size();
            idx.write(reinterpret_cast<const char*>(&len), sizeof(len));
            idx.write(kv.first.data(), len);
            idx.write(reinterpret_cast<const char*>(&kv.second), sizeof(kv.second));
        }
    }

    
    void cargarIndice() {
        indice.clear();
        ifstream idx(archivoIndice, ios::binary);
        if (!idx) return;

        while (idx.peek() != EOF) {
            size_t len;
            idx.read(reinterpret_cast<char*>(&len), sizeof(len));
            string nombre(len, '\0');
            idx.read(&nombre[0], len);
            streampos pos;
            idx.read(reinterpret_cast<char*>(&pos), sizeof(pos));
            indice[nombre] = pos;
        }
    }

public:
    GestorAccesoAleatorio() {
        cargarIndice();
       
        if (indice.empty()) construirIndice();
    }

    
    bool buscarProducto(const string& nombre, Producto& resultado) {
        auto it = indice.find(nombre);
        if (it == indice.end()) return false;

        ifstream datos(archivoDatos, ios::binary);
        datos.seekg(it->second);
        string linea;
        if (!getline(datos, linea)) return false;
        resultado = Producto::fromCSV(linea);
        return true;
    }

  
    void agregarProducto(const Producto& p) {
        ofstream datos(archivoDatos, ios::binary | ios::app);
        datos.seekp(0, ios::end);
        streampos pos = datos.tellp();
        datos << p.toCSV() << "\n";
        datos.close();
        
        indice[p.nombre] = pos;
        construirIndice();
    }

    
    bool modificarProducto(const string& nombreBuscado, const Producto& nuevosDatos) {
        // 1) Leer todos en vector
        vector<Producto> lista;
        ifstream datosIn(archivoDatos, ios::binary);
        string linea;
        while (getline(datosIn, linea)) {
            lista.push_back(Producto::fromCSV(linea));
        }
        datosIn.close();

      
        bool encontrado = false;
        for (auto& p : lista) {
            if (p.nombre == nombreBuscado) {
                p = nuevosDatos;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) return false;

        
        ofstream datosOut(archivoDatos, ios::binary | ios::trunc);
        for (auto& p : lista) {
            datosOut << p.toCSV() << "\n";
        }
        datosOut.close();

       
        construirIndice();
        return true;
    }
};


int main() {
    GestorAccesoAleatorio gestor;

    
    gestor.agregarProducto(Producto("Monitor LCD", 120.0, 8));
    gestor.agregarProducto(Producto("Teclado USB", 25.0, 15));

   
    Producto hallado;
    if (gestor.buscarProducto("Monitor LCD", hallado)) {
        cout << "Encontrado: " << hallado.nombre
             << " | Precio: " << hallado.precio
             << " | Cantidad: " << hallado.cantidad << "\n";
    }

    
    Producto modificado = hallado;
    modificado.cantidad -= 2;
    if (gestor.modificarProducto("Monitor LCD", modificado)) {
        cout << "Venta registrada. Nueva cantidad: " << modificado.cantidad << "\n";
    }

   
    if (gestor.buscarProducto("Monitor LCD", hallado)) {
        cout << "Ahora: " << hallado.nombre
             << " | Cantidad: " << hallado.cantidad << "\n";
    }

    return 0;
}
