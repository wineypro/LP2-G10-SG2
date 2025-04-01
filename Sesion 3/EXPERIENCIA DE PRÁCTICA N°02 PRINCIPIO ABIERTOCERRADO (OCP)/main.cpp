#include "GestorTareas.h"
#include "TareaConPrioridad.h"
#include "Usuario.h"
#include <vector>

int main() {
    GestorTareas gestor;
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

            int id, idUsuario, prioridad;
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
            cout << "Prioridad (0-10): ";
            cin >> prioridad;

            bool usuarioValido = false;
            for (Usuario u : usuarios) {
                if (u.obtenerId() == idUsuario) {
                    usuarioValido = true;
                    break;
                }
            }

            if (usuarioValido) {
                gestor.agregarTarea(new TareaConPrioridad(id, descripcion, fechaLimite, idUsuario, prioridad));
                cout << "Tarea agregada correctamente.\n";
            } else {
                cout << "Error: Usuario no encontrado.\n";
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

    cout << "Saliendo del programa...\n";
    return 0;
}
