#ifndef SISTEMA_H
#define SISTEMA_H

#include "modelos.h"
#include "menu_interfaces.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Sistema {
private:
    vector<UsuarioSistema> usuarios;
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<Administrador> administradores;
    vector<string> citas;
    map<int, string> historiasClinicas;
    map<int, vector<string>> recetasMedicas;
    map<int, bool> pacientesInternados;

public:
    bool hayUsuariosRegistrados() {
        return !usuarios.empty();
    }

    bool usuarioExiste(string username, string tipo) {
        for (const auto& u : usuarios) {
            if (u.getUsername() == username && u.getTipo() == tipo) {
                return true;
            }
        }
        return false;
    }

    UsuarioSistema* loginUsuario() {
        string username, password;
        cout << "Nombre de usuario: ";
        cin >> username;
        cout << "Contraseña: ";
        cin >> password;

        for (auto& u : usuarios) {
            if (u.getUsername() == username && u.getPassword() == password) {
                return &u;
            }
        }

        cout << "Usuario o contraseña incorrectos.\n";
        return nullptr;
    }

    void registrarUsuario(string username, string password, int tipo) {
        string tipoStr;
        if (tipo == 1) {
            tipoStr = "Paciente";
        } else if (tipo == 2) {
            tipoStr = "Medico";
        } else if (tipo == 3) {
            tipoStr = "Administrador";
        } else {
            cout << "Tipo de usuario no válido.\n";
            return;
        }

        if (usuarioExiste(username, tipoStr)) {
            cout << "Ya existe un usuario con ese nombre y tipo.\n";
            return;
        }

        usuarios.push_back(UsuarioSistema(username, password, tipoStr));

        if (tipoStr == "Paciente") {
            string nombre, celular;
            int dni, edad;
            cout << "Ingrese nombre del paciente: ";
            cin >> nombre;
            cout << "Ingrese DNI: ";
            cin >> dni;
            cout << "Ingrese edad: ";
            cin >> edad;
            cout << "Ingrese celular: ";
            cin >> celular;

            for (const auto& p : pacientes) {
                if (p.getDni() == dni) {
                    cout << "Paciente ya registrado.\n";
                    usuarios.pop_back();
                    return;
                }
            }

            pacientes.push_back(Paciente(nombre, dni, edad, celular));
            cout << "Usuario registrado exitosamente.\n";
        } 
        else if (tipoStr == "Medico") {
            string nombre, especialidad, horario;
            cout << "Ingrese nombre del médico: ";
            cin >> nombre;
            cout << "Ingrese especialidad (cardiologia, pediatria, dermatologia): ";
            cin >> especialidad;
            cout << "Ingrese horario: ";
            cin >> horario;

            medicos.push_back(Medico(nombre, especialidad, horario));
            cout << "Usuario registrado exitosamente.\n";
        } 
        else if (tipoStr == "Administrador") {
            string nombre;
            cout << "Ingrese nombre del administrador: ";
            cin >> nombre;

            administradores.push_back(Administrador(nombre));
            cout << "Usuario registrado exitosamente.\n";
        }
    }

    void menuPaciente() {
        mostrarMenuPaciente(citas, medicos, pacientes);
    }

    void menuMedico() {
        mostrarMenuMedico(pacientes, medicos);
    }

    void menuAdministrador() {
        mostrarMenuAdministrador(pacientes, citas);
    }
};

#endif