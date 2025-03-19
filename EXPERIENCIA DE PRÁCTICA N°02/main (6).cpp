#include "Producto.h"
#include "Pedido.h"

int main() {
    Producto p1("Laptop", 1200.50, 10);
    Producto p2("Mouse", 25.99, 50);
    vector<Producto> productos = {p1, p2};
    vector<int> cantidades = {1, 2};
    Pedido pedido(productos, cantidades, "En proceso");
    
    pedido.mostrar();
    return 0;
}
