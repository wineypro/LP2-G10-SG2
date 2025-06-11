#include <iostream>
using namespace std;

//raiz cuadrada
float raizCuadrada(float numero) {
    float x = numero;
    float y = 1;
    float e = 0.0001f;
    while (x - y > e) {
        x = (x + y) / 2;
        y = numero / x;
    }
    return x;
}


class Forma {
public:
    virtual ~Forma() {}
    virtual float area() = 0;
    virtual float perimetro() = 0;
    virtual void mostrarInfo() = 0;
    virtual void definirParametros() = 0;
};


class Circulo : public Forma {
    float radio;
public:
    void definirParametros() override {
        cout << "Radio del circulo: ";
        cin >> radio;
    }
    float area() override { return 3.1416f * radio * radio; }
    float perimetro() override { return 2 * 3.1416f * radio; }
    void mostrarInfo() override {
        cout << "CIRCULO: Radio=" << radio 
             << ", Area=" << area()
             << ", Perimetro=" << perimetro() << endl;
    }
};


class Rectangulo : public Forma {
    float base, altura;
public:
    void definirParametros() override {
        cout << "Base del rectangulo: ";
        cin >> base;
        cout << "Altura del rectangulo: ";
        cin >> altura;
    }
    float area() override { return base * altura; }
    float perimetro() override { return 2 * (base + altura); }
    void mostrarInfo() override {
        cout << "RECTANGULO: Base=" << base 
             << ", Altura=" << altura
             << ", Area=" << area()
             << ", Perimetro=" << perimetro() << endl;
    }
};


class Triangulo : public Forma {
    float lado1, lado2, lado3;
public:
    void definirParametros() override {
        cout << "Lado 1 del triangulo: ";
        cin >> lado1;
        cout << "Lado 2 del triangulo: ";
        cin >> lado2;
        cout << "Lado 3 del triangulo: ";
        cin >> lado3;
    }
    float area() override {
        float s = perimetro() / 2;
        float prod = s * (s - lado1) * (s - lado2) * (s - lado3);
        return (prod > 0) ? raizCuadrada(prod) : 0;
    }
    float perimetro() override { return lado1 + lado2 + lado3; }
    void mostrarInfo() override {
        cout << "TRIANGULO: Lados=" << lado1 << "," << lado2 << "," << lado3
             << ", Area=" << area()
             << ", Perimetro=" << perimetro() << endl;
    }
};


class FormaPersonalizada : public Forma {
    float* parametros;
    int numParametros;
    string nombre;
public:
    FormaPersonalizada(string nom, int numParams) : nombre(nom), numParametros(numParams) {
        parametros = new float[numParams];
    }
    
    ~FormaPersonalizada() {
        delete[] parametros;
    }
    
    void definirParametros() override {
        cout << "Definiendo " << nombre << " (" << numParametros << " parametros):\n";
        for(int i = 0; i < numParametros; i++) {
            cout << "Parametro " << (i+1) << ": ";
            cin >> parametros[i];
        }
    }
    
    float area() override {
        float resultado = 0;
        for(int i = 0; i < numParametros; i++) {
            resultado += parametros[i];  // suma
        }
        return resultado;
    }
    
    float perimetro() override {
        if (numParametros == 0) return 0;
        float resultado = 1;
        for(int i = 0; i < numParametros; i++) {
            resultado *= parametros[i];  //  producto
        }
        return resultado;
    }
    
    void mostrarInfo() override {
        cout << nombre << " personalizado: ";
        for(int i = 0; i < numParametros; i++) {
            cout << "P" << (i+1) << "=" << parametros[i] << " ";
        }
        cout << ", Area=" << area()
             << ", Perimetro=" << perimetro() << endl;
    }
};


int main() {
    Forma* forma = nullptr;
    int opcion;
    
    do {
        cout << "1. Circulo\n2. Rectangulo\n3. Triangulo\n";
        cout << "4. Crear nueva forma\n5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        if(opcion >= 1 && opcion <= 3) {
            switch(opcion) {
                case 1: forma = new Circulo(); break;
                case 2: forma = new Rectangulo(); break;
                case 3: forma = new Triangulo(); break;
            }
            forma->definirParametros();
            forma->mostrarInfo();
            delete forma;
        }
        else if(opcion == 4) {
            string nombre;
            int numParams;
            
            cout << "Nombre de la nueva forma: ";
            cin >> nombre;
            cout << "Numero de parametros requeridos: ";
            cin >> numParams;
            
            forma = new FormaPersonalizada(nombre, numParams);
            forma->definirParametros();
            forma->mostrarInfo();
            delete forma;
        }
        
    } while(opcion != 5);
    
    return 0;
}