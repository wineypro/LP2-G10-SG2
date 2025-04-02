#ifndef COMENTARIO_H
#define COMENTARIO_H

#include "IComentario.h"
#include "Usuario.h"
#include <string>
#include <ctime>

using namespace std;

class Comentario : public IComentario {
private:
    int id;
    string contenido;
    Usuario* autor;
    string fecha;

public:
    Comentario(int _id, const string& _contenido, Usuario* _autor)
        : id(_id), contenido(_contenido), autor(_autor) {
        time_t now = time(0);
        char* dt = ctime(&now);
        fecha = string(dt);
    }

    int obtenerId() const override {
        return id;
    }

    string obtenerContenido() const override {
        return contenido;
    }

    Usuario* obtenerAutor() const override {
        return autor;
    }

    string obtenerFecha() const override {
        return fecha;
    }

    void agregarComentario(const string& _contenido) override {
        contenido = _contenido;
        time_t now = time(0);
        char* dt = ctime(&now);
        fecha = string(dt);
    }

    virtual ~Comentario() {}
};

#endif



