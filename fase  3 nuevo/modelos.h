#ifndef MODELOS_H
#define MODELOS_H

#include <iostream>
#include <string>

using namespace std;

class IUsuario {
public:
    virtual string getUsername() const = 0;
    virtual string getPassword() const = 0;
    virtual string getTipo() const = 0;
    virtual ~IUsuario() = default;
};

class UsuarioSistema : public IUsuario {
protected:
    string username;
    string password;
    string tipo;

public:
    UsuarioSistema(string _username, string _password, string _tipo)
        : username(_username), password(_password), tipo(_tipo) {}

    string getUsername() const override { return username; }
    string getPassword() const override { return password; }
    string getTipo() const override { return tipo; }

    void setPassword(const string& newPassword) { password = newPassword; }
};

class Paciente {
private:
    string nombre;
    int dni;
    int edad;
    string celular;

public:
    Paciente(string _nombre, int _dni, int _edad, string _celular)
        : nombre(_nombre), dni(_dni), edad(_edad), celular(_celular) {}

    string getNombre() const { return nombre; }
    int getDni() const { return dni; }
    int getEdad() const { return edad; }
    string getCelular() const { return celular; }

    void setNombre(const string& newNombre) { nombre = newNombre; }
    void setDni(int newDni) { dni = newDni; }
    void setEdad(int newEdad) { edad = newEdad; }
    void setCelular(const string& newCelular) { celular = newCelular; }
};

class Medico {
private:
    string nombre;
    string especialidad;
    string horario;

public:
    Medico(string _nombre, string _especialidad, string _horario)
        : nombre(_nombre), especialidad(_especialidad), horario(_horario) {}

    string getNombre() const { return nombre; }
    string getEspecialidad() const { return especialidad; }
    string getHorario() const { return horario; }

    void setNombre(const string& newNombre) { nombre = newNombre; }
    void setEspecialidad(const string& newEspecialidad) { especialidad = newEspecialidad; }
    void setHorario(const string& newHorario) { horario = newHorario; }
};

class Administrador {
private:
    string nombre;

public:
    Administrador(string _nombre) : nombre(_nombre) {}

    string getNombre() const { return nombre; }

    void setNombre(const string& newNombre) { nombre = newNombre; }
};

#endif