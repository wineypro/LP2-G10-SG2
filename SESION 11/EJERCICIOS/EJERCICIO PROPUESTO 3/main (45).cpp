#include <iostream>
#include <fstream>
#include <string>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    string direccion;

    
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int ) {
        ar & nombre;
        ar & edad;
        ar & direccion;
    }

public:
    Persona() : nombre(""), edad(0), direccion("") {}
    Persona(const string& n, int e, const string& d)
        : nombre(n), edad(e), direccion(d) {}

   
    void setNombre(const string& n){ 
        nombre = n; 
        
    }
    void setEdad(int e){
        edad = e; 
        
    }
    void setDireccion(const string& d){
        direccion = d; 
        
    }

   
    string getNombre() const{ 
        return nombre; 
        
    }
    
    int    getEdad() const{ 
        return edad;
    }
    
    string getDireccion() const {
        return direccion; 
        
    }
};

int main() {
    
    cout << "Crear Persona \n";
    cout << "Nombre: ";
    string n; 
    getline(cin, n);
    cout << "Edad: ";
    int e; 
    cin >> e;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Direccion: ";
    string d;
    getline(cin, d);

    Persona p(n, e, d);

  
    {
        ofstream ofs("persona.dat", ios::binary);
        if (!ofs) {
            cerr << "No se pudo crear el archivo de serializacion.\n";
            return 1;
        }
        boost::archive::binary_oarchive oa(ofs);
        oa << p;
    }

  
    Persona p2;
    {
        ifstream ifs("persona.dat", ios::binary);
        if (!ifs) {
            cerr << "No se pudo abrir el archivo de serializacion.\n";
            return 1;
        }
        boost::archive::binary_iarchive ia(ifs);
        ia >> p2;
    }

    
    cout << "\nPersona Deserializada\n";
    cout << "Nombre:   " << p2.getNombre()    << "\n";
    cout << "Edad:     " << p2.getEdad()      << "\n";
    cout << "Dirección:" << p2.getDireccion() << "\n";

    return 0;
}

