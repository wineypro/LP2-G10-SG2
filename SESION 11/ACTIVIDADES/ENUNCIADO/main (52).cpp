#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char* NOMBRE_ARCHIVO = "inventario.dat";
const int LONGITUD_NOMBRE = 50;

class Producto {
private:
    char nombre[LONGITUD_NOMBRE];
    double precio;
    int cantidad;
public:
    Producto() {
        for (int i = 0; i < LONGITUD_NOMBRE; ++i) nombre[i] = '\0';
        precio = 0.0;
        cantidad = 0;
    }

    void establecerNombre(const string& s) {
        int n = s.size() < LONGITUD_NOMBRE ? s.size() : LONGITUD_NOMBRE - 1;
        for (int i = 0; i < n; ++i) nombre[i] = s[i];
        nombre[n] = '\0';
    }
    void establecerPrecio(double p) { precio = p; }
    void establecerCantidad(int q) { cantidad = q; }

    string obtenerNombre() const { return string(nombre); }
    double obtenerPrecio() const { return precio; }
    int obtenerCantidad() const { return cantidad; }

  
    void escribirEn(ostream& os) const {
        os.write(reinterpret_cast<const char*>(this), sizeof(Producto));
    }
    void leerDe(istream& is) {
        is.read(reinterpret_cast<char*>(this), sizeof(Producto));
    }
};

void limpiarEntrada() {
    cin.clear();
    cin.ignore(1000, '\n');
}

void agregarProducto() {
    string nombre;
    double precio;
    int cantidad;

    cout << "Nombre del producto: ";
    limpiarEntrada();
    getline(cin, nombre);

    cout << "Precio: ";
    if (!(cin >> precio) || precio < 0) {
        cout << "Precio invalido.\n";
        return;
    }

    cout << "Cantidad disponible: ";
    if (!(cin >> cantidad) || cantidad < 0) {
        cout << "Cantidad invalida.\n";
        return;
    }

    Producto p;
    p.establecerNombre(nombre);
    p.establecerPrecio(precio);
    p.establecerCantidad(cantidad);

    ofstream ofs(NOMBRE_ARCHIVO, ios::binary | ios::app);
    if (!ofs) {
        cout << "Error al abrir archivo para escritura.\n";
        return;
    }
    p.escribirEn(ofs);
    cout << "Producto agregado correctamente.\n";
}

streampos buscarPosicion(const string& nombre) {
    ifstream ifs(NOMBRE_ARCHIVO, ios::binary);
    if (!ifs) return -1;
    Producto p;
    streampos pos = 0;
    while (true) {
        p.leerDe(ifs);
        if (!ifs) break;
        if (p.obtenerNombre() == nombre) {
            return pos;
        }
        pos = ifs.tellg();
    }
    return -1;
}

void actualizarProducto() {
    cout << "Nombre del producto a actualizar: ";
    limpiarEntrada();
    string nombre;
    getline(cin, nombre);

    streampos pos = buscarPosicion(nombre);
    if (pos < 0) {
        cout << "Producto no encontrado.\n";
        return;
    }

    fstream fs(NOMBRE_ARCHIVO, ios::binary | ios::in | ios::out);
    if (!fs) {
        cout << "Error al abrir archivo para actualizacion.\n";
        return;
    }

    fs.seekg(pos);
    Producto p;
    p.leerDe(fs);

    cout << "Precio actual: " << p.obtenerPrecio()
         << "\nNuevo precio (o negativo para no cambiar): ";
    double nuevoPrecio;
    if (!(cin >> nuevoPrecio)) {
        cout << "Entrada invalida.\n";
        return;
    }
    if (nuevoPrecio >= 0) p.establecerPrecio(nuevoPrecio);

    cout << "Cantidad actual: " << p.obtenerCantidad()
         << "\nNueva cantidad (o negativa para no cambiar): ";
    int nuevaCantidad;
    if (!(cin >> nuevaCantidad)) {
        cout << "Entrada invalida.\n";
        return;
    }
    if (nuevaCantidad >= 0) p.establecerCantidad(nuevaCantidad);

    fs.seekp(pos);
    p.escribirEn(fs);
    cout << "Producto actualizado correctamente.\n";
}

void venderProducto() {
    cout << "Nombre del producto a vender: ";
    limpiarEntrada();
    string nombre;
    getline(cin, nombre);

    streampos pos = buscarPosicion(nombre);
    if (pos < 0) {
        cout << "Producto no encontrado.\n";
        return;
    }

    fstream fs(NOMBRE_ARCHIVO, ios::binary | ios::in | ios::out);
    if (!fs) {
        cout << "Error al abrir archivo para venta.\n";
        return;
    }

    fs.seekg(pos);
    Producto p;
    p.leerDe(fs);

    cout << "Cantidad disponible: " << p.obtenerCantidad()
         << "\nCantidad a vender: ";
    int cantVendida;
    if (!(cin >> cantVendida) || cantVendida <= 0) {
        cout << "Cantidad de venta invalida.\n";
        return;
    }
    if (cantVendida > p.obtenerCantidad()) {
        cout << "Stock insuficiente.\n";
        return;
    }

    p.establecerCantidad(p.obtenerCantidad() - cantVendida);
    fs.seekp(pos);
    p.escribirEn(fs);
    cout << "Venta realizada. Nueva cantidad: " << p.obtenerCantidad() << "\n";
}

void mostrarInventario() {
    ifstream ifs(NOMBRE_ARCHIVO, ios::binary);
    if (!ifs) {
        cout << "No hay productos en inventario.\n";
        return;
    }

    Producto p;
    cout << "\n--- Inventario ---\n";
    cout << "Nombre\t\tPrecio\t\tCantidad\n";
    cout << "---------------------------------------\n";
    while (true) {
        p.leerDe(ifs);
        if (!ifs) break;
        cout << p.obtenerNombre() << "\t\t"
             << p.obtenerPrecio() << "\t\t"
             << p.obtenerCantidad() << "\n";
    }
    cout << "---------------------------------------\n\n";
}

int main() {
    int opcion = -1;
    while (opcion != 0) {
        cout << "\n1. Agregar producto\n"
             << "2. Actualizar producto\n"
             << "3. Vender producto\n"
             << "4. Mostrar inventario\n"
             << "0. Salir\n"
             << "Elige una opcion: ";
        if (!(cin >> opcion)) {
            cout << "Opcion invalida.\n";
            limpiarEntrada();
            continue;
        }
        switch (opcion) {
            case 1: agregarProducto();    break;
            case 2: actualizarProducto(); break;
            case 3: venderProducto();     break;
            case 4: mostrarInventario();  break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion no reconocida.\n";
        }
    }
    return 0;
}

