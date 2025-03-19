#include "GestorInventario.h"
#include "Pedido.h"

int main() {
    // Crear gestor de inventario
    GestorInventario gestor;

    // Agregar productos al inventario
    gestor.agregarProducto(Producto("Laptop", 1200.50, 10));
    gestor.agregarProducto(Producto("Mouse", 25.99, 50));
    gestor.agregarProducto(Producto("Teclado", 45.99, 30));

    // Mostrar inventario inicial
    gestor.mostrarInventario();

    // Crear un pedido
    vector<Producto> productosPedido = {Producto("Laptop", 1200.50, 10), Producto("Mouse", 25.99, 50)};
    vector<int> cantidades = {2, 3};
    Pedido pedido(productosPedido, cantidades, "En proceso");

    // Procesar pedido y actualizar inventario
    gestor.actualizarInventario(pedido);

    // Mostrar inventario después del pedido
    gestor.mostrarInventario();

    return 0;
}
