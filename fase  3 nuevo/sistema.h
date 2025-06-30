#ifndef SISTEMA_H
#define SISTEMA_H

#include "modelos.h"
#include "menu_interfaces.h"
#include "exceptions.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <limits>
#include <fstream>
#include <sstream>

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
        
        try {
            cout << "Nombre de usuario: ";
            if (!(cin >> username)) throw InputDataException();
            
            cout << "Contraseña: ";
            if (!(cin >> password)) throw InputDataException();

            for (auto& u : usuarios) {
                if (u.getUsername() == username && u.getPassword() == password) {
                    return &u;
                }
            }
            cout << "Usuario o contraseña incorrectos.\n";
            return nullptr;
        } 
        catch (const SistemaCriticalException& e) {
            cerr << "ERROR CRÍTICO: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return nullptr;
        }
    }

    void registrarUsuario(string username, string password, int tipo) {
        string tipoStr;
        
        try {
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
                
                try {
                    cout << "Ingrese nombre del paciente: ";
                    if (!(cin >> nombre)) throw InputDataException();
                    cout << "Ingrese DNI: ";
                    if (!(cin >> dni)) throw InputDataException();
                    cout << "Ingrese edad: ";
                    if (!(cin >> edad)) throw InputDataException();
                    cout << "Ingrese celular: ";
                    if (!(cin >> celular)) throw InputDataException();
                }
                catch (const SistemaCriticalException& e) {
                    cerr << "ERROR: " << e.what() << endl;
                    usuarios.pop_back();
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    return;
                }

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
                
                try {
                    cout << "Ingrese nombre del médico: ";
                    if (!(cin >> nombre)) throw InputDataException();
                    cout << "Ingrese especialidad (cardiologia, pediatria, dermatologia): ";
                    if (!(cin >> especialidad)) throw InputDataException();
                    cout << "Ingrese horario: ";
                    if (!(cin >> horario)) throw InputDataException();
                }
                catch (const SistemaCriticalException& e) {
                    cerr << "ERROR: " << e.what() << endl;
                    usuarios.pop_back();
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    return;
                }

                medicos.push_back(Medico(nombre, especialidad, horario));
                cout << "Usuario registrado exitosamente.\n";
            } 
            else if (tipoStr == "Administrador") {
                string nombre;
                
                try {
                    cout << "Ingrese nombre del administrador: ";
                    if (!(cin >> nombre)) throw InputDataException();
                }
                catch (const SistemaCriticalException& e) {
                    cerr << "ERROR: " << e.what() << endl;
                    usuarios.pop_back();
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    return;
                }

                administradores.push_back(Administrador(nombre));
                cout << "Usuario registrado exitosamente.\n";
            }
        }
        catch (const exception& e) {
            cerr << "ERROR inesperado: " << e.what() << endl;
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

    // ========== SISTEMA DE ARCHIVOS ==========
    void guardarDatos() {
        guardarUsuarios();
        guardarPacientes();
        guardarMedicos();
        guardarCitas();
        guardarHistoriasClinicas();
        cout << "Datos guardados correctamente.\n";
    }

    void cargarDatos() {
        cargarUsuarios();
        cargarPacientes();
        cargarMedicos();
        cargarCitas();
        cargarHistoriasClinicas();
    }

    void guardarUsuarios() {
        ofstream archivo("usuarios.txt");
        if (archivo.is_open()) {
            for (const auto& usuario : usuarios) {
                archivo << usuario.getUsername() << "," 
                        << usuario.getPassword() << "," 
                        << usuario.getTipo() << "\n";
            }
            archivo.close();
        }
    }

    void cargarUsuarios() {
        ifstream archivo("usuarios.txt");
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                stringstream ss(linea);
                string username, password, tipo;
                
                getline(ss, username, ',');
                getline(ss, password, ',');
                getline(ss, tipo);
                
                if (!username.empty()) {
                    usuarios.emplace_back(username, password, tipo);
                }
            }
            archivo.close();
        }
    }

    void guardarPacientes() {
        ofstream archivo("pacientes.txt");
        if (archivo.is_open()) {
            for (const auto& paciente : pacientes) {
                archivo << paciente.getNombre() << ","
                        << paciente.getDni() << ","
                        << paciente.getEdad() << ","
                        << paciente.getCelular() << "\n";
            }
            archivo.close();
        }
    }

    void cargarPacientes() {
        ifstream archivo("pacientes.txt");
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                stringstream ss(linea);
                string nombre, celular, temp;
                int dni, edad;
                
                getline(ss, nombre, ',');
                getline(ss, temp, ',');
                dni = stoi(temp);
                getline(ss, temp, ',');
                edad = stoi(temp);
                getline(ss, celular);
                
                if (!nombre.empty()) {
                    pacientes.emplace_back(nombre, dni, edad, celular);
                }
            }
            archivo.close();
        }
    }

    void guardarMedicos() {
        ofstream archivo("medicos.txt");
        if (archivo.is_open()) {
            for (const auto& medico : medicos) {
                archivo << medico.getNombre() << ","
                        << medico.getEspecialidad() << ","
                        << medico.getHorario() << "\n";
            }
            archivo.close();
        }
    }

    void cargarMedicos() {
        ifstream archivo("medicos.txt");
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                stringstream ss(linea);
                string nombre, especialidad, horario;
                
                getline(ss, nombre, ',');
                getline(ss, especialidad, ',');
                getline(ss, horario);
                
                if (!nombre.empty()) {
                    medicos.emplace_back(nombre, especialidad, horario);
                }
            }
            archivo.close();
        }
    }

    void guardarCitas() {
        ofstream archivo("citas.txt");
        if (archivo.is_open()) {
            for (const auto& cita : citas) {
                archivo << cita << "\n";
            }
            archivo.close();
        }
    }

    void cargarCitas() {
        ifstream archivo("citas.txt");
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                if (!linea.empty()) {
                    citas.push_back(linea);
                }
            }
            archivo.close();
        }
    }

    void guardarHistoriasClinicas() {
        ofstream archivo("historias_clinicas.txt");
        if (archivo.is_open()) {
            for (const auto& hc : historiasClinicas) {
                archivo << hc.first << "|" << hc.second << "\n";
            }
            archivo.close();
        }
    }

    void cargarHistoriasClinicas() {
        ifstream archivo("historias_clinicas.txt");
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                size_t pos = linea.find('|');
                if (pos != string::npos) {
                    int dni = stoi(linea.substr(0, pos));
                    string historia = linea.substr(pos + 1);
                    historiasClinicas[dni] = historia;
                }
            }
            archivo.close();
        }
    }
};

#endif