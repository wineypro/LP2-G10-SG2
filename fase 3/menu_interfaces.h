#ifndef MENU_INTERFACES_H
#define MENU_INTERFACES_H

#include "modelos.h"
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

// Función auxiliar para buscar paciente por DNI
Paciente* buscarPacientePorDNI(vector<Paciente>& pacientes, int dni) {
    auto it = find_if(pacientes.begin(), pacientes.end(),
        [dni](const Paciente& p) { return p.getDni() == dni; });
    return (it != pacientes.end()) ? &(*it) : nullptr;
}

// Validación de fecha (DD/MM/AAAA)
bool validarFecha(const string& fecha) {
    if (fecha.length() != 10) return false;
    if (fecha[2] != '/' || fecha[5] != '/') return false;
    
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (!isdigit(fecha[i])) return false;
    }
    
    int dia = stoi(fecha.substr(0, 2));
    int mes = stoi(fecha.substr(3, 2));
    
    return (dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12);
}

// Validación de hora (HH:MM)
bool validarHora(const string& hora) {
    if (hora.length() != 5) return false;
    if (hora[2] != ':') return false;
    
    for (int i = 0; i < 5; i++) {
        if (i == 2) continue;
        if (!isdigit(hora[i])) return false;
    }
    
    int hh = stoi(hora.substr(0, 2));
    int mm = stoi(hora.substr(3, 2));
    
    return (hh >= 0 && hh < 24) && (mm >= 0 && mm < 60);
}

// Función para agendar cita con validaciones
void agendarCita(vector<string>& citas, const vector<Medico>& medicos, const Paciente& paciente) {
    cout << "\n--- AGENDAR NUEVA CITA ---\n";
    
    // Validar fecha
    string fecha;
    do {
        cout << "Ingrese fecha (DD/MM/AAAA): ";
        cin >> fecha;
        if (!validarFecha(fecha)) {
            cout << "Formato inválido. Use DD/MM/AAAA (ej: 25/12/2023)\n";
        } else {
            break;
        }
    } while (true);
    
    // Validar hora
    string hora;
    do {
        cout << "Ingrese hora (HH:MM): ";
        cin >> hora;
        if (!validarHora(hora)) {
            cout << "Formato inválido. Use HH:MM (ej: 14:30)\n";
        } else {
            break;
        }
    } while (true);
    
    // Mostrar médicos disponibles
    cout << "\nMédicos disponibles:\n";
    for (size_t i = 0; i < medicos.size(); i++) {
        cout << i+1 << ". " << medicos[i].getNombre() 
             << " (" << medicos[i].getEspecialidad() << ")\n";
    }
    
    // Seleccionar médico
    int opcion;
    cout << "Seleccione un médico: ";
    cin >> opcion;
    
    if (opcion < 1 || opcion > medicos.size()) {
        cout << "Selección inválida\n";
        return;
    }
    
    // Registrar cita
    string cita = "Paciente: " + paciente.getNombre() +
                  " | Médico: " + medicos[opcion-1].getNombre() +
                  " | Fecha: " + fecha + 
                  " | Hora: " + hora;
    
    citas.push_back(cita);
    cout << "\n✅ Cita agendada exitosamente!\n";
}

// Menú principal del paciente
void mostrarMenuPaciente(vector<string>& citas, vector<Medico>& medicos, vector<Paciente>& pacientes) {
    if (pacientes.empty()) {
        cout << "No hay pacientes registrados\n";
        return;
    }
    
    Paciente& paciente = pacientes[0];
    int opcion;
    
    do {
        cout << "\n=== MENÚ PACIENTE ===\n";
        cout << "Paciente: " << paciente.getNombre() << " (DNI: " << paciente.getDni() << ")\n";
        cout << "1. Actualizar mis datos\n";
        cout << "2. Agendar nueva cita\n";
        cout << "3. Cancelar cita\n";
        cout << "4. Ver mis citas\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                // Actualizar datos
                cout << "\n--- ACTUALIZAR DATOS ---\n";
                string nombre, celular;
                int dni, edad;
                
                cout << "Nuevo nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Nuevo DNI: ";
                cin >> dni;
                cout << "Nueva edad: ";
                cin >> edad;
                cout << "Nuevo celular: ";
                cin >> celular;
                
                paciente.setNombre(nombre);
                paciente.setDni(dni);
                paciente.setEdad(edad);
                paciente.setCelular(celular);
                
                cout << "Datos actualizados correctamente\n";
                break;
            }
            case 2:
                agendarCita(citas, medicos, paciente);
                break;
            case 3: {
                // Cancelar cita
                if (citas.empty()) {
                    cout << "No tiene citas agendadas\n";
                    break;
                }
                
                cout << "\n--- CITAS AGENDADAS ---\n";
                for (size_t i = 0; i < citas.size(); i++) {
                    cout << i+1 << ". " << citas[i] << "\n";
                }
                
                int numCita;
                cout << "Seleccione la cita a cancelar (0 para cancelar): ";
                cin >> numCita;
                
                if (numCita > 0 && numCita <= citas.size()) {
                    citas.erase(citas.begin() + numCita - 1);
                    cout << "Cita cancelada exitosamente\n";
                }
                break;
            }
            case 4:
                // Ver citas
                if (citas.empty()) {
                    cout << "No tiene citas agendadas\n";
                } else {
                    cout << "\n--- SUS CITAS ---\n";
                    for (const auto& cita : citas) {
                        cout << "• " << cita << "\n";
                    }
                }
                break;
            case 5:
                cout << "Saliendo del menú paciente...\n";
                break;
            default:
                cout << "Opción inválida\n";
        }
    } while (opcion != 5);
}

// Menú del médico con validación de fecha
void mostrarMenuMedico(vector<Paciente>& pacientes, vector<Medico>& medicos, map<int, string>& historiasClinicas) {
    if (medicos.empty()) {
        cout << "No hay médicos registrados\n";
        return;
    }
    
    Medico& medico = medicos[0];
    int opcion;
    
    do {
        cout << "\n=== MENÚ MÉDICO ===\n";
        cout << "Dr. " << medico.getNombre() << " - " << medico.getEspecialidad() << "\n";
        cout << "1. Registrar consulta\n";
        cout << "2. Ver historial de paciente\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                // Registrar consulta
                cout << "\n--- REGISTRAR CONSULTA ---\n";
                int dni;
                cout << "Ingrese DNI del paciente: ";
                cin >> dni;
                
                Paciente* paciente = buscarPacientePorDNI(pacientes, dni);
                if (!paciente) {
                    cout << "Paciente no encontrado\n";
                    break;
                }
                
                // Validar fecha
                string fecha;
                do {
                    cout << "Fecha de consulta (DD/MM/AAAA): ";
                    cin >> fecha;
                    if (!validarFecha(fecha)) {
                        cout << "Formato inválido. Use DD/MM/AAAA\n";
                    } else {
                        break;
                    }
                } while (true);
                
                string diagnostico;
                cout << "Diagnóstico: ";
                cin.ignore();
                getline(cin, diagnostico);
                
                // Registrar en historial
                string registro = "Fecha: " + fecha + 
                                 "\nMédico: " + medico.getNombre() +
                                 "\nDiagnóstico: " + diagnostico + "\n\n";
                
                historiasClinicas[dni] += registro;
                cout << "Consulta registrada exitosamente\n";
                break;
            }
            case 2: {
                // Ver historial
                cout << "\n--- HISTORIAL MÉDICO ---\n";
                int dni;
                cout << "Ingrese DNI del paciente: ";
                cin >> dni;
                
                if (historiasClinicas.find(dni) != historiasClinicas.end()) {
                    cout << historiasClinicas[dni];
                } else {
                    cout << "No se encontraron registros\n";
                }
                break;
            }
            case 3:
                cout << "Saliendo del menú médico...\n";
                break;
            default:
                cout << "Opción inválida\n";
        }
    } while (opcion != 3);
}

// Menú del administrador
void mostrarMenuAdministrador(vector<Paciente>& pacientes, vector<string>& citas, const map<int, string>& historiasClinicas) {
    int opcion;
    
    do {
        cout << "\n=== MENÚ ADMINISTRADOR ===\n";
        cout << "1. Ver todas las citas\n";
        cout << "2. Ver historiales clínicos\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                if (citas.empty()) {
                    cout << "No hay citas agendadas\n";
                } else {
                    cout << "\n--- CITAS PROGRAMADAS ---\n";
                    for (const auto& cita : citas) {
                        cout << "• " << cita << "\n";
                    }
                }
                break;
            case 2: {
                cout << "\n--- HISTORIALES CLÍNICOS ---\n";
                int dni;
                cout << "Ingrese DNI del paciente: ";
                cin >> dni;
                
                auto it = historiasClinicas.find(dni);
                if (it != historiasClinicas.end()) {
                    cout << it->second;
                } else {
                    cout << "No se encontraron registros\n";
                }
                break;
            }
            case 3:
                cout << "Saliendo del menú administrador...\n";
                break;
            default:
                cout << "Opción inválida\n";
        }
    } while (opcion != 3);
}

#endif