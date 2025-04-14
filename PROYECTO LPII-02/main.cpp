#include <iostream>
#include <memory>
#include "sistema.h"

using namespace std;

class App {
private:
    Sistema sistema;

    void mostrarMenuPrincipal() {
        cout << "Menu Principal\n";
        cout << "1. Iniciar sesión\n";
        cout << "2. Registrar usuario\n";
        cout << "3. Salir\n";
        cout << "Elija una opción: ";
    }

    void iniciarSesion() {
        if (!sistema.hayUsuariosRegistrados()) {
            cout << "No hay usuarios registrados en el sistema.\n";
            return;
        }

        UsuarioSistema* usuario = sistema.loginUsuario();
        if (usuario == nullptr) return;

        string tipo = usuario->getTipo();
        if (tipo == "Paciente") {
            cout << "Bienvenido, Paciente\n";
            sistema.menuPaciente();
        } else if (tipo == "Medico") {
            cout << "Bienvenido, Médico\n";
            sistema.menuMedico();
        } else if (tipo == "Administrador") {
            cout << "Bienvenido, Administrador\n";
            sistema.menuAdministrador();
        } else {
            cout << "Tipo de usuario desconocido.\n";
        }
    }

    void registrarUsuario() {
        string username, password;
        int tipo;

        cout << "Ingrese el nombre de usuario: ";
        cin >> username;
        cout << "Ingrese la contraseña: ";
        cin >> password;

        cout << "Seleccione el tipo de usuario:\n";
        cout << "1. Paciente\n";
        cout << "2. Medico\n";
        cout << "3. Administrador\n";
        cout << "Opción: ";
        cin >> tipo;

        sistema.registrarUsuario(username, password, tipo);
    }

public:
    void ejecutar() {
        while (true) {
            int opcion;
            mostrarMenuPrincipal();
            cin >> opcion;

            switch (opcion) {
                case 1:
                    iniciarSesion();
                    break;
                case 2:
                    registrarUsuario();
                    break;
                case 3:
                    cout << "Saliendo del sistema...\n";
                    return;
                default:
                    cout << "Opción no válida. Intente nuevamente.\n";
                    break;
            }
        }
    }
};

int main() {
    App app;
    app.ejecutar();
    return 0;
}
