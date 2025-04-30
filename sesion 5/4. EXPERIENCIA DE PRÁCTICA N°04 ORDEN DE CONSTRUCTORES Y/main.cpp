#include <iostream>
#include <string>
using namespace std;

class ComponenteA {
public:
    ComponenteA() {
        cout << "Constructor de ComponenteA" << endl;
    }
    ~ComponenteA() {
        cout << "Destructor de ComponenteA" << endl;
    }
};

class ComponenteB {
public:
    ComponenteB() {
        cout << "Constructor de ComponenteB" << endl;
    }
    ~ComponenteB() {
        cout << "Destructor de ComponenteB" << endl;
    }
};

class Sistema {
private:
    ComponenteA a;
    ComponenteB b;
public:
    Sistema() : a(), b() {
        cout << "Constructor de Sistema" << endl;
    }
    ~Sistema() {
        cout << "Destructor de Sistema" << endl;
    }
    void mostrarComponentes() const {
        cout << "Sistema con componentes inicializados." << endl;
    }
};

class A {
public:
    A() {
        cout << "Constructor de A" << endl;
    }
    ~A() {
        cout << "Destructor de A" << endl;
    }
};

class B {
private:
    A a;
public:
    B() : a() {
        cout << "Constructor de B" << endl;
    }
    ~B() {
        cout << "Destructor de B" << endl;
    }
    void mostrar() const {
        cout << "Objeto B contiene un objeto A." << endl;
    }
};

int main() {
    cout << "--- Creando objeto Sistema ---" << endl;
    Sistema sistema;
    sistema.mostrarComponentes();
    cout << "--- Fin del objeto Sistema ---" << endl;

    cout << endl;

    cout << "--- Creando objeto B ---" << endl;
    B objB;
    objB.mostrar();
    cout << "--- Fin del objeto B ---" << endl;

    return 0;
}
