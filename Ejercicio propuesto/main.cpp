#include <iostream>
#include "Tienda.h"
using namespace std;
int main() {
    Tienda t;  // Objetotienda
    int op, id, cant;
    float p;
    char nom[30], cli[30];
    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Agregar Producto\n";
        cout << "2. Vender Producto\n";
        cout << "3. Nuevo Pedido\n";
        cout << "4. Pedido Listo\n";
        cout << "5. Reporte\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        switch (op) {
            case 1: 
                cout << "Nombre: ";
                cin >> nom;
                cout << "ID: ";
                cin >> id;
                cout << "Cantidad: ";
                cin >> cant;
                cout << "Precio: ";
                cin >> p;
                t.agregarProd(nom, id, cant, p);
                break;
            case 2: 
                cout << "ID del producto: ";
                cin >> id;
                cout << "Cantidad vendida: ";
                cin >> cant;
                t.vender(id, cant);
                break;
            case 3: 
                cout << "ID producto: ";
                cin >> id;
                cout << "Cantidad: ";
                cin >> cant;
                cout << "Cliente: ";
                cin >> cli;
                t.nuevoPed(id, cant, cli);
                break;
            case 4: 
                cout << "ID pedido listo: ";
                cin >> id;
                t.pedListo(id);
                break;
            case 5: 
                t.reporte();
                break;
            case 6:
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (op != 6);

    return 0;
}