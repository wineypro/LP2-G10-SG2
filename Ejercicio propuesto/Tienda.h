#ifndef TIENDA_H
#define TIENDA_H
#include "Notificacion.h"
#define MAX_PROD 100  
#define MAX_PED 50    
// producto
struct Prod {
    char nom[30];
    int id;
    int cant;
    float p;
};
// venta
struct Vent {
    int idProd;
    int cantVend;
    float total;
};
// pedido
struct Ped {
    int idProd;
    int cant;
    bool listo;
    char cli[30];  
};
// Clase Tienda
class Tienda {
private:
    Prod inv[MAX_PROD];  // Inventario
    Vent ventas[MAX_PROD]; // Lista  ventas
    Ped pedidos[MAX_PED]; // Lista pedidos
    int totalProd;
    int totalVent;
    int totalPed;
public:
    Tienda();
    void agregarProd(const char* nom, int id, int cant, float p);
    void vender(int id, int cant);
    void nuevoPed(int id, int cant, const char* cli);
    void pedListo(int id);
    void reporte();
};
#endif