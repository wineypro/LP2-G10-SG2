#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Clase Asignatura
class Asignatura {
public:
    string codigo;
    string nombre;
    string descripcion;
    string profesorAsignado;

    Asignatura(string cod, string nom, string des, string prof)
        : codigo(cod), nombre(nom), descripcion(des), profesorAsignado(prof) {}
};

// Clase Estudiante
class Estudiante {
public:
    string nombre;
    string direccion;
    string matricula;
    vector<Asignatura*> asignaturasMatriculadas;  // Agregacion (Estudiante -> Asignatura)
    map<Asignatura*, double> notas;
    map<Asignatura*, int> faltas;

    Estudiante(string nom, string dir, string mat)
        : nombre(nom), direccion(dir), matricula(mat) {}

    void matricularAsignatura(Asignatura* asignatura) {
        asignaturasMatriculadas.push_back(asignatura);  
    }

    void registrarNota(Asignatura* asignatura, double nota) {
        notas[asignatura] = nota;
    }

    void registrarFalta(Asignatura* asignatura) {
        faltas[asignatura]++;
    }

    void mostrarDetalles() {
        cout << "Estudiante: " << nombre << "\n";
        cout << "Matricula: " << matricula << "\n";
        cout << "Direccion: " << direccion << "\n";
        cout << "Asignaturas Matriculadas:\n";
        for (auto& asignatura : asignaturasMatriculadas) {
            cout << "- " << asignatura->nombre << " (Profesor: " << asignatura->profesorAsignado << ")\n";
            cout << "  Nota: " << (notas.count(asignatura) ? notas[asignatura] : 0) << "\n";
            cout << "  Faltas: " << (faltas.count(asignatura) ? faltas[asignatura] : 0) << "\n";
        }
        cout << endl;
    }
};

// Clase Profesor
class Profesor {
public:
    string nombre;
    string direccion;
    string telefono;
    vector<Asignatura*> asignaturasImpartidas;  // Agregacion (Profesor -> Asignatura)

    Profesor(string nom, string dir, string tel)
        : nombre(nom), direccion(dir), telefono(tel) {}

    void impartirAsignatura(Asignatura* asignatura) {
        asignaturasImpartidas.push_back(asignatura);  // Agregacion
    }

    void mostrarDetalles() {
        cout << "Profesor: " << nombre << "\n";
        cout << "Telefono: " << telefono << "\n";
        cout << "Direccion: " << direccion << "\n";
        cout << "Asignaturas Impartidas:\n";
        for (auto& asignatura : asignaturasImpartidas) {
            cout << "- " << asignatura->nombre << "\n";
        }
        cout << endl;
    }
};

int main() {
    vector<Profesor> profesores;
    vector<Asignatura*> asignaturas;
    vector<Estudiante> estudiantes;
    
    int opcion;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Registrar Profesor\n";
        cout << "2. Registrar Asignatura\n";
        cout << "3. Registrar Estudiante\n";
        cout << "4. Matricular Estudiante en Asignaturas\n";
        cout << "5. Registrar Notas y Faltas\n";
        cout << "6. Ver Detalles de Estudiantes\n";
        cout << "7. Ver Detalles de Profesores\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                string nombre, direccion, telefono;
                cout << "\nIngrese el nombre del profesor: ";
                getline(cin, nombre);
                cout << "Ingrese la direccion del profesor: ";
                getline(cin, direccion);
                cout << "Ingrese el telefono del profesor: ";
                getline(cin, telefono);
                Profesor profesor(nombre, direccion, telefono);
                profesores.push_back(profesor);
                break;
            }
            case 2: {
                string codigo, nombre, descripcion, profesorAsignado;
                cout << "\nIngrese el codigo de la asignatura: ";
                getline(cin, codigo);
                cout << "Ingrese el nombre de la asignatura: ";
                getline(cin, nombre);
                cout << "Ingrese la descripcion de la asignatura: ";
                getline(cin, descripcion);

                cout << "\nLista de Profesores:\n";
                for (int i = 0; i < profesores.size(); i++) {
                    cout << i + 1 << ". " << profesores[i].nombre << "\n";
                }

                cout << "\nIngrese el numero del profesor para la asignatura: ";
                int profesorSeleccionado;
                cin >> profesorSeleccionado;

                if (profesorSeleccionado > 0 && profesorSeleccionado <= profesores.size()) {
                    profesorAsignado = profesores[profesorSeleccionado - 1].nombre;

                    Asignatura* asignatura = new Asignatura(codigo, nombre, descripcion, profesorAsignado);
                    asignaturas.push_back(asignatura);

                    profesores[profesorSeleccionado - 1].impartirAsignatura(asignatura);  // Asociacion Bidireccional
                } else {
                    cout << "Profesor no encontrado. No se puede crear la asignatura.\n";
                }
                break;
            }
            case 3: {
                string nombre, direccion, matricula;
                cout << "\nIngrese el nombre del estudiante: ";
                getline(cin, nombre);
                cout << "Ingrese la direccion del estudiante: ";
                getline(cin, direccion);
                cout << "Ingrese la matricula del estudiante: ";
                getline(cin, matricula);
                Estudiante estudiante(nombre, direccion, matricula);
                estudiantes.push_back(estudiante);
                break;
            }
            case 4: {
                string matricula;
                cout << "\nIngrese la matricula del estudiante: ";
                getline(cin, matricula);

                Estudiante* estudianteSeleccionado = nullptr;
                for (auto& estudiante : estudiantes) {
                    if (estudiante.matricula == matricula) {
                        estudianteSeleccionado = &estudiante;
                        break;
                    }
                }

                if (estudianteSeleccionado != nullptr) {
                    for (auto& asignatura : asignaturas) {
                        char matricular;
                        cout << "¿Matricular a " << estudianteSeleccionado->nombre << " en la asignatura "
                             << asignatura->nombre << "? (s/n): ";
                        cin >> matricular;
                        if (matricular == 's' || matricular == 'S') {
                            estudianteSeleccionado->matricularAsignatura(asignatura);  // Asociacion Unidireccional
                        }
                    }
                } else {
                    cout << "Estudiante no encontrado.\n";
                }
                break;
            }
            case 5: {
                string matricula;
                cout << "\nIngrese la matricula del estudiante: ";
                getline(cin, matricula);

                Estudiante* estudianteSeleccionado = nullptr;
                for (auto& estudiante : estudiantes) {
                    if (estudiante.matricula == matricula) {
                        estudianteSeleccionado = &estudiante;
                        break;
                    }
                }

                if (estudianteSeleccionado != nullptr) {
                    for (auto& asignatura : estudianteSeleccionado->asignaturasMatriculadas) {
                        double nota;
                        int faltas;
                        cout << "\nIngrese la nota de " << estudianteSeleccionado->nombre << " en la asignatura "
                             << asignatura->nombre << ": ";
                        cin >> nota;
                        estudianteSeleccionado->registrarNota(asignatura, nota);

                        cout << "Ingrese las faltas de " << estudianteSeleccionado->nombre << " en la asignatura "
                             << asignatura->nombre << ": ";
                        cin >> faltas;
                        for (int f = 0; f < faltas; f++) {
                            estudianteSeleccionado->registrarFalta(asignatura);  // Asociacion Unidireccional
                        }
                    }
                } else {
                    cout << "Estudiante no encontrado.\n";
                }
                break;
            }
            case 6: {
                
                for (auto& estudiante : estudiantes) {
                    estudiante.mostrarDetalles();
                }
                break;
            }
            case 7: {
               
                for (auto& profesor : profesores) {
                    profesor.mostrarDetalles();
                }
                break;
            }
            case 8:
                cout << "Saliendo del programa\n";
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while (opcion != 8);

    return 0;
}
