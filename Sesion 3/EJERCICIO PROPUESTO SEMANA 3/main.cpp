#include "GestorTareas.h"
#include "TareaConPrioridad.h"
#include "TareaEstandar.h"
#include "Usuario.h"
#include "TareaRepository.h"
#include <vector>
#include <iostream>
// main.cpp
#include "Tarea.h"      
#include "IProyecto.h"  
#include "Usuario.h"    

using namespace std;

int main() {
    TareaRepository* tareaRepository = new TareaRepository();
    GestorTareas gestor(tareaRepository);
    vector<Usuario> usuarios;
    int opcion;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Agregar usuario\n";
        cout << "2. Agregar tarea\n";
        cout << "3. Mostrar tareas\n";
        cout << "4. Actualizar estado de tarea\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            int id;
            string nombre;
            cout << "ID del usuario: ";
            cin >> id;
            cin.ignore();
            cout << "Nombre del usuario: ";
            getline(cin, nombre);
            usuarios.push_back(Usuario(id, nombre));
            cout << "Usuario agregado correctamente.\n";
        } 
        else if (opcion == 2) {
            if (usuarios.empty()) {
                cout << "Error: No hay usuarios registrados. Agregue un usuario primero.\n";
                continue;
            }

            int id, idUsuario, tipo;
            string descripcion, fechaLimite;

            cout << "ID de la tarea: ";
            cin >> id;
            cin.ignore();
            cout << "Descripcion: ";
            getline(cin, descripcion);
            cout << "Fecha limite (YYYY-MM-DD): ";
            getline(cin, fechaLimite);
            cout << "ID del usuario asignado: ";
            cin >> idUsuario;
            cout << "Tipo de tarea (1: Estandar, 2: Con Prioridad): ";
            cin >> tipo;

            bool usuarioValido = false;
            for (Usuario u : usuarios) {
                if (u.obtenerId() == idUsuario) {
                    usuarioValido = true;
                    break;
                }
            }

            if (!usuarioValido) {
                cout << "Error: Usuario no encontrado.\n";
                continue;
            }

            if (tipo == 1) {
                gestor.agregarTarea(new TareaEstandar(id, descripcion, fechaLimite, idUsuario));
                cout << "Tarea estandar agregada correctamente.\n";
            } 
            else if (tipo == 2) {
                int prioridad;
                cout << "Prioridad (0-10): ";
                cin >> prioridad;
                gestor.agregarTarea(new TareaConPrioridad(id, descripcion, fechaLimite, idUsuario, prioridad));
                cout << "Tarea con prioridad agregada correctamente.\n";
            } 
            else {
                cout << "Error: Tipo de tarea invalido.\n";
            }
        } 
        else if (opcion == 3) {
            cout << "Lista de tareas:\n";
            gestor.mostrarTareas();
        } 
        else if (opcion == 4) {
            int id;
            string nuevoEstado;
            cout << "ID de la tarea a actualizar: ";
            cin >> id;
            cin.ignore();
            cout << "Nuevo estado: ";
            getline(cin, nuevoEstado);
            gestor.actualizarEstadoTarea(id, nuevoEstado);
            cout << "Estado actualizado.\n";
        } 
        else if (opcion != 5) {
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 5);

    delete tareaRepository;
    cout << "Saliendo del programa...\n";
    return 0;
}

