#include <iostream>

using namespace std;

class Animal {
protected:
    string nombre;
    int edad;
    string tipo;

public:
    Animal(string nombre, int edad, string tipo)
        : nombre(nombre),
          edad(edad),
          tipo(tipo) 
    {
    }

    void alimentar() 
    {
        cout << nombre << " esta siendo alimentado." << endl;
    }
    
    void hacer_sonido() 
    {
        cout << nombre << " hace un sonido generico." << endl;
    }
};

class Perro : public Animal 
{
public:
    Perro(string nombre, int edad)
        : Animal(nombre, edad, "Perro")
    {
    }

    void hacer_sonido()  
    {
        cout << nombre << " ladra: Guau guau" << endl;
    }
};

class Gato : public Animal 
{
public:
    Gato(string nombre, int edad)
        : Animal(nombre, edad, "Gato")
    {
    }

    void hacer_sonido()  
    {
        cout << nombre << " maulla: Miau miau" << endl;
    }
};

class Caballo : public Animal 
{
public:
    Caballo(string nombre, int edad)
        : Animal(nombre, edad, "Caballo")
    {
    }

    void hacer_sonido()  
    {
        cout << nombre << " relincha: Hiiiii" << endl;
    }
};

int main() 
{
    Perro perro("Max", 3);
    Gato gato("Luna", 2);
    Caballo caballo("Rayo", 5);

    perro.alimentar();
    perro.hacer_sonido();

    gato.alimentar();
    gato.hacer_sonido();

    caballo.alimentar();
    caballo.hacer_sonido();

    return 0;
}
