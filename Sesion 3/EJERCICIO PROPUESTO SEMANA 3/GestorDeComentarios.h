#ifndef GESTORDECOMENTARIOS_H
#define GESTORDECOMENTARIOS_H

#include <vector>
#include "Comentario.h"

using namespace std;

class GestorDeComentarios {
private:
    vector<Comentario*> comentarios;

public:
    void agregarComentario(Comentario* comentario) {
        comentarios.push_back(comentario);
    }

    vector<Comentario*> obtenerComentarios() {
        return comentarios;
    }

    Comentario* obtenerComentarioPorId(int id) {
        for (auto comentario : comentarios) {
            if (comentario->obtenerId() == id) {
                return comentario;
            }
        }
        return nullptr;
    }

    bool eliminarComentario(int id) {
        for (auto it = comentarios.begin(); it != comentarios.end(); ++it) {
            if ((*it)->obtenerId() == id) {
                delete *it;
                comentarios.erase(it);
                return true;
            }
        }
        return false;
    }

    ~GestorDeComentarios() {
        for (auto comentario : comentarios) {
            delete comentario;
        }
    }
};

#endif

