#ifndef RUEDA_H
#define RUEDA_H

using namespace std;

class Rueda {
private:
    int tamano;
public:
    Rueda(int _tamano) : tamano(_tamano) {}

    int getTamano() const { return tamano; }
    void setTamano(int _tamano) { tamano = _tamano; }
};

#endif
