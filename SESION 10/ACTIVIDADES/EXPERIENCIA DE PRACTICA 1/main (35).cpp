#include <iostream>
using namespace std;


template <typename T>
T raizCuadrada(T n) {
    T x = n;
    T y = 1;
    T e = 0.000001;
    while (x - y > e) {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}


template <typename T>
T calcularDistancia(T x1, T y1, T x2, T y2) {
    T dx = x2 - x1;
    T dy = y2 - y1;
    return raizCuadrada(dx * dx + dy * dy);
}

template <typename T>
T calcularTiempoEntrega(T distancia, T velocidad) {
    if (velocidad == 0) return 0;
    return distancia / velocidad;
}


template <typename T>
void generarReporte(T dato, const char* descripcion) {
    cout << descripcion << ": " << dato << endl;
}


void generarReporteTiempo(double tiempoDecimal, const char* descripcion) {
    int horas = (int)tiempoDecimal;
    int minutos = (int)((tiempoDecimal - horas) * 60 + 0.5); 
    cout << descripcion << ": " << horas << " horas y " << minutos << " minutos" << endl;
}

int main() {
    double x1 = 0, y1 = 0, x2 = 3, y2 = 4;

    double distancia = calcularDistancia(x1, y1, x2, y2);      
    double tiempo = calcularTiempoEntrega(distancia, 60.0);    
    generarReporte(distancia, "Distancia calculada");
    generarReporteTiempo(tiempo, "Tiempo estimado de entrega");
    generarReporte(3, "Número de entregas");
    generarReporte("Zona Norte", "Área de entrega");

    return 0;
}
