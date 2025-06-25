#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Producto {
private:
    string nombre;
    double precio;
    int cantidad;
public:
  
    Producto(const string& nom = "", double pre = 0.0, int cant = 0)
        : nombre(nom), precio(pre), cantidad(cant) {}

    
    void establecerNombre(const string& nom) { nombre = nom; }
    string obtenerNombre() const             { return nombre; }
    void establecerPrecio(double pre)        { precio = pre; }
    double obtenerPrecio() const             { return precio; }
    void establecerCantidad(int cant)        { cantidad = cant; }
    int obtenerCantidad() const              { return cantidad; }

    
    void escribirEn(ofstream& os) const {
        // serializar campos
        size_t len = nombre.size();
        os.write(reinterpret_cast<const char*>(&len), sizeof(len));
        os.write(nombre.data(), len);
        os.write(reinterpret_cast<const char*>(&precio), sizeof(precio));
        os.write(reinterpret_cast<const char*>(&cantidad), sizeof(cantidad));
    }
    bool leerDe(ifstream& is) {
        
        size_t len;
        if (!is.read(reinterpret_cast<char*>(&len), sizeof(len))) return false;
        nombre.resize(len);
        is.read(&nombre[0], len);
        is.read(reinterpret_cast<char*>(&precio), sizeof(precio));
        is.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));
        return true;
    }
};


void agregarProducto(const Producto& p);
bool actualizarProducto(const string& nombre, const Producto& datosNuevos);
bool venderProducto(const string& nombre, int cantidadAVender);
void generarInforme();


int main() {
    
    Producto p1("Teclado MX", 45.50, 10);
    agregarProducto(p1);

    
    Producto nuevosDatos("Teclado MX", 42.00, 15);
    if (actualizarProducto("Teclado MX", nuevosDatos)) {
        cout << "Actualizacion exitosa.\n";
    }

    
    if (venderProducto("Teclado MX", 3)) {
        cout << "Venta realizada.\n";
    }

   
    generarInforme();

    return 0;
}
