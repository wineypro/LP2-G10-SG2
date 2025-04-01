#ifndef IACTUALIZABLE_H
#define IACTUALIZABLE_H

#include <string>

using namespace std;

class IActualizable {
public:
    virtual void actualizarEstado(string _estado) = 0;
    virtual ~IActualizable() {}
};

#endif
