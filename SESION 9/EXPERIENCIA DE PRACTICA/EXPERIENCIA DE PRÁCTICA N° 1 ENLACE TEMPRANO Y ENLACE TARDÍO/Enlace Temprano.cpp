#include <iostream>
using namespace std;

class Animal {
public:
    void hacerSonido() {
        cout << "El animal hace un sonido generico." << endl;
    }
};

class Perro : public Animal {
public:
    void hacerSonido() {
        cout << "El perro ladra." << endl;
    }
};

int main() {
    Animal* miAnimal = new Perro();
    miAnimal->hacerSonido(); 
    delete miAnimal;
    return 0;
}
