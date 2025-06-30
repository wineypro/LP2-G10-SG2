#ifndef MENU_INTERFACES_H
#define MENU_INTERFACES_H

#include "modelos.h"
#include "exceptions.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

void mostrarMenuPaciente(vector<string>& citas, vector<Medico>& medicos, vector<Paciente>& pacientes) {
    if (pacientes.empty() || medicos.empty()) {
        cout << "Debe haber al menos un paciente y un médico registrados.\n";
        return;
    }

    int opcion;
    do {
        try {
            cout << "\n=== MENÚ PACIENTE ===\n";
            cout << "1. Actualizar datos de usuario\n";
            cout << "2. Agendar cita\n";
            cout << "3. Cancelar cita\n";
            cout << "4. Pagar cita\n";
            cout << "5. Ingresar reclamos\n";
            cout << "6. Reportes de citas realizadas\n";
            cout << "7. Salir\n";
            cout << "Elija una opción: ";
            
            if (!(cin >> opcion)) throw InputDataException();

            switch (opcion) {
                case 1: {
                    string nombre, celular;
                    int dni, edad;
                    
                    try {
                        cout << "Ingrese nuevo nombre: ";
                        if (!(cin >> nombre)) throw InputDataException();
                        cout << "Ingrese nuevo DNI: ";
                        if (!(cin >> dni)) throw InputDataException();
                        cout << "Ingrese nueva edad: ";
                        if (!(cin >> edad)) throw InputDataException();
                        cout << "Ingrese nuevo celular: ";
                        if (!(cin >> celular)) throw InputDataException();
                    }
                    catch (const SistemaCriticalException& e) {
                        cerr << "ERROR: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    
                    pacientes[0].setNombre(nombre);
                    pacientes[0].setDni(dni);
                    pacientes[0].setEdad(edad);
                    pacientes[0].setCelular(celular);
                    
                    cout << "Datos actualizados correctamente.\n";
                    break;
                }
                case 2: {
                    int esp;
                    try {
                        cout << "Seleccione especialidad:\n1. cardiologia\n2. pediatria\n3. dermatologia\nOpción: ";
                        if (!(cin >> esp)) throw InputDataException();
                    }
                    catch (const SistemaCriticalException& e) {
                        cerr << "ERROR: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    
                    string especialidad = (esp == 1) ? "cardiologia" : (esp == 2) ? "pediatria" : "dermatologia";

                    vector<Medico> medicosEsp;
                    for (auto& m : medicos) {
                        if (m.getEspecialidad() == especialidad) {
                            medicosEsp.push_back(m);
                        }
                    }

                    if (medicosEsp.empty()) {
                        cout << "No hay médicos disponibles para esa especialidad.\n";
                        break;
                    }

                    cout << "Médicos disponibles:\n";
                    for (size_t i = 0; i < medicosEsp.size(); i++) {
                        cout << i+1 << ". " << medicosEsp[i].getNombre() << " - " << medicosEsp[i].getHorario() << endl;
                    }

                    int indiceMed;
                    try {
                        cout << "Seleccione médico: ";
                        if (!(cin >> indiceMed)) throw InputDataException();
                    }
                    catch (const SistemaCriticalException& e) {
                        cerr << "ERROR: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    
                    if (indiceMed < 1 || indiceMed > medicosEsp.size()) {
                        cout << "Opción no válida.\n";
                        break;
                    }

                    string horario;
                    try {
                        cout << "Ingrese horario deseado (ej: 10:00am): ";
                        if (!(cin >> horario)) throw InputDataException();
                    }
                    catch (const SistemaCriticalException& e) {
                        cerr << "ERROR: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    citas.push_back("Cita con " + medicosEsp[indiceMed-1].getNombre() + " a las " + horario);
                    cout << "Cita agendada con éxito.\n";
                    break;
                }
                case 3: {
                    if (citas.empty()) {
                        cout << "No hay citas agendadas.\n";
                        break;
                    }
                    
                    cout << "Citas agendadas:\n";
                    for (size_t i = 0; i < citas.size(); i++) {
                        cout << i+1 << ". " << citas[i] << endl;
                    }

                    int cancelar;
                    try {
                        cout << "Seleccione cita a cancelar: ";
                        if (!(cin >> cancelar)) throw InputDataException();
                    }
                    catch (const SistemaCriticalException& e) {
                        cerr << "ERROR: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    
                    if (cancelar < 1 || cancelar > citas.size()) {
                        cout << "Opción no válida.\n";
                        break;
                    }

                    citas.erase(citas.begin() + cancelar - 1);
                    cout << "Cita cancelada exitosamente.\n";
                    break;
                }
                case 4: {
                    if (citas.empty()) {
                        cout << "No hay citas agendadas.\n";
                        break;
                    }
                    
                    cout << "Citas pendientes de pago:\n";
                    for (size_t i = 0; i < citas.size(); i++) {
                        cout << i+1 << ". " << citas[i] << endl;
                    }

                    int pagar;
                    try {
                        cout << "Seleccione cita a pagar: ";
                        if (!(cin >> pagar)) throw InputDataException();
                    }
                    catch (const SistemaCriticalException& e) {
                        cerr << "ERROR: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    
                    if (pagar < 1 || pagar > citas.size()) {
                        cout << "Opción no válida.\n";
                        break;
                    }

                    cout << "Cita pagada exitosamente.\n";
                    break;
                }
                case 5: {
                    string reclamo;
                    try {
                        cout << "Ingrese su reclamo: ";
                        cin.ignore();
                        getline(cin, reclamo);
                        if (cin.fail()) throw InputDataException();
                    }
                    catch (const SistemaCriticalException& e) {
                        cerr << "ERROR: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    cout << "Reclamo registrado exitosamente.\n";
                    break;
                }
                case 6: {
                    if (citas.empty()) {
                        cout << "No hay citas realizadas.\n";
                        break;
                    }
                    
                    cout << "Historial de citas:\n";
                    for (const auto& cita : citas) {
                        cout << "- " << cita << endl;
                    }
                    break;
                }
                case 7:
                    cout << "Saliendo del menú paciente.\n";
                    break;
                default:
                    cout << "Opción no válida.\n";
            }
        }
        catch (const SistemaCriticalException& e) {
            cerr << "ERROR CRÍTICO: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
    } while (opcion != 7);
}

void mostrarMenuMedico(vector<Paciente>& pacientes, vector<Medico>& medicos) {
    static map<int, string> historiasClinicas;
    static map<int, vector<string>> recetasMedicas;
    static map<int, bool> pacientesInternados;

    if (medicos.empty()) {
        cout << "No hay médicos registrados.\n";
        return;
    }

    // Obtenemos el médico actual (asumimos que es el primero en el vector)
    Medico& medicoActual = medicos[0];
    string especialidadMedico = medicoActual.getEspecialidad();

    int opcion;
    do {
        try {
            cout << "\n=== MENÚ MÉDICO ===\n";
            cout << "1. Actualizar datos\n";
            cout << "2. Iniciar consulta\n";
            cout << "3. Salir\n";
            cout << "Elija una opción: ";
            
            if (!(cin >> opcion)) throw InputDataException();

            switch (opcion) {
                case 1: {
                    string nombre, especialidad, horario;
                    try {
                        cout << "Ingrese nuevo nombre: ";
                        cin.ignore();
                        getline(cin, nombre);
                        if (cin.fail()) throw InputDataException();
                        cout << "Ingrese nueva especialidad: ";
                        getline(cin, especialidad);
                        if (cin.fail()) throw InputDataException();
                        cout << "Ingrese nuevo horario: ";
                        getline(cin, horario);
                        if (cin.fail()) throw InputDataException();
                    }
                    catch (const SistemaCriticalException& e) {
                        cerr << "ERROR: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    medicoActual.setNombre(nombre);
                    medicoActual.setEspecialidad(especialidad);
                    medicoActual.setHorario(horario);
                    
                    // Actualizamos la especialidad local
                    especialidadMedico = especialidad;
                    
                    cout << "Datos actualizados correctamente.\n";
                    break;
                }
                case 2: {
                    int dni;
                    try {
                        cout << "Ingrese el DNI del paciente: ";
                        if (!(cin >> dni)) throw InputDataException();
                    }
                    catch (const SistemaCriticalException& e) {
                        cerr << "ERROR: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    auto it = find_if(pacientes.begin(), pacientes.end(),
                                    [dni](Paciente& p) { return p.getDni() == dni; });

                    if (it == pacientes.end()) {
                        cout << "Paciente no encontrado.\n";
                        break;
                    }

                    int subopcion;
                    do {
                        try {
                            cout << "\nOpciones de consulta:\n";
                            cout << "1. Consulta general\n";
                            cout << "2. Consulta con especialista (" << especialidadMedico << ")\n";
                            cout << "3. Crear historia clínica\n";
                            cout << "4. Actualizar historia clínica\n";
                            cout << "5. Crear receta médica\n";
                            cout << "6. Internar paciente\n";
                            cout << "7. Dar de alta\n";
                            cout << "8. Regresar\n";
                            cout << "Seleccione una opción: ";
                            
                            if (!(cin >> subopcion)) throw InputDataException();

                            switch (subopcion) {
                                case 1: {
                                    string fecha, notas;
                                    try {
                                        cout << "Fecha de consulta: ";
                                        cin >> fecha;
                                        cout << "Notas: ";
                                        cin.ignore();
                                        getline(cin, notas);
                                        if (cin.fail()) throw InputDataException();
                                    }
                                    catch (const SistemaCriticalException& e) {
                                        cerr << "ERROR: " << e.what() << endl;
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        break;
                                    }
                                    
                                    cout << "Consulta general registrada exitosamente.\n";
                                    break;
                                }
                                case 2: {
                                    string fecha, notas;
                                    try {
                                        cout << "Fecha de consulta: ";
                                        cin >> fecha;
                                        cout << "Notas: ";
                                        cin.ignore();
                                        getline(cin, notas);
                                        if (cin.fail()) throw InputDataException();
                                    }
                                    catch (const SistemaCriticalException& e) {
                                        cerr << "ERROR: " << e.what() << endl;
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        break;
                                    }
                                    
                                    cout << "Consulta con especialista (" << especialidadMedico << ") registrada exitosamente.\n";
                                    break;
                                }
                                case 3: {
                                    string historia;
                                    try {
                                        cin.ignore();
                                        cout << "Ingrese historia clínica: ";
                                        getline(cin, historia);
                                        if (cin.fail()) throw InputDataException();
                                    }
                                    catch (const SistemaCriticalException& e) {
                                        cerr << "ERROR: " << e.what() << endl;
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        break;
                                    }
                                    historiasClinicas[dni] = historia;
                                    cout << "Historia clínica creada exitosamente.\n";
                                    break;
                                }
                                case 4: {
                                    if (historiasClinicas.find(dni) == historiasClinicas.end()) {
                                        cout << "No existe historia clínica previa.\n";
                                        break;
                                    }
                                    
                                    string nuevaInfo;
                                    try {
                                        cin.ignore();
                                        cout << "Historia actual:\n" << historiasClinicas[dni] << "\n";
                                        cout << "Ingrese información adicional: ";
                                        getline(cin, nuevaInfo);
                                        if (cin.fail()) throw InputDataException();
                                    }
                                    catch (const SistemaCriticalException& e) {
                                        cerr << "ERROR: " << e.what() << endl;
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        break;
                                    }
                                    historiasClinicas[dni] += "\n" + nuevaInfo;
                                    cout << "Historia clínica actualizada exitosamente.\n";
                                    break;
                                }
                                case 5: {
                                    string receta;
                                    try {
                                        cin.ignore();
                                        cout << "Ingrese receta médica: ";
                                        getline(cin, receta);
                                        if (cin.fail()) throw InputDataException();
                                    }
                                    catch (const SistemaCriticalException& e) {
                                        cerr << "ERROR: " << e.what() << endl;
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        break;
                                    }
                                    recetasMedicas[dni].push_back(receta);
                                    cout << "Receta médica creada exitosamente.\n";
                                    break;
                                }
                                case 6: {
                                    pacientesInternados[dni] = true;
                                    cout << "Paciente internado exitosamente.\n";
                                    break;
                                }
                                case 7: {
                                    if (!pacientesInternados[dni]) {
                                        cout << "El paciente no está internado.\n";
                                    } else {
                                        pacientesInternados[dni] = false;
                                        cout << "Paciente dado de alta exitosamente.\n";
                                    }
                                    break;
                                }
                                case 8:
                                    cout << "Regresando al menú principal...\n";
                                    break;
                                default:
                                    cout << "Opción no válida.\n";
                            }
                        }
                        catch (const SistemaCriticalException& e) {
                            cerr << "ERROR: " << e.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                    } while (subopcion != 8);
                    break;
                }
                case 3:
                    cout << "Saliendo del menú médico.\n";
                    break;
                default:
                    cout << "Opción no válida.\n";
            }
        }
        catch (const SistemaCriticalException& e) {
            cerr << "ERROR CRÍTICO: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
    } while (opcion != 3);
}

void mostrarMenuAdministrador(vector<Paciente>& pacientes, vector<string>& citas) {
    static map<int, string> historiasClinicas;
    
    int opcion;
    do {
        try {
            cout << "\n=== MENÚ ADMINISTRADOR ===\n";
            cout << "1. Consultar historia de paciente\n";
            cout << "2. Reportes de ventas\n";
            cout << "3. Salir\n";
            cout << "Elija una opción: ";
            
            if (!(cin >> opcion)) throw InputDataException();

            switch (opcion) {
                case 1: {
                    int dni;
                    try {
                        cout << "Ingrese el DNI del paciente: ";
                        if (!(cin >> dni)) throw InputDataException();
                    }
                    catch (const SistemaCriticalException& e) {
                        cerr << "ERROR: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    auto it = find_if(pacientes.begin(), pacientes.end(),
                                    [dni](Paciente& p) { return p.getDni() == dni; });

                    if (it == pacientes.end()) {
                        cout << "Paciente no encontrado.\n";
                        break;
                    }

                    if (historiasClinicas.find(dni) == historiasClinicas.end()) {
                        cout << "El paciente no tiene historia clínica registrada.\n";
                    } else {
                        cout << "Historia clínica del paciente " << it->getNombre() << ":\n";
                        cout << historiasClinicas[dni] << endl;
                    }
                    break;
                }
                case 2: {
                    cout << "Reporte de citas:\n";
                    cout << "Total de citas agendadas: " << citas.size() << endl;
                    
                    if (!citas.empty()) {
                        cout << "\nDetalle de citas:\n";
                        for (const auto& cita : citas) {
                            cout << "- " << cita << endl;
                        }
                    }
                    break;
                }
                case 3:
                    cout << "Saliendo del menú administrador.\n";
                    break;
                default:
                    cout << "Opción no válida.\n";
            }
        }
        catch (const SistemaCriticalException& e) {
            cerr << "ERROR CRÍTICO: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
    } while (opcion != 3);
}

#endif