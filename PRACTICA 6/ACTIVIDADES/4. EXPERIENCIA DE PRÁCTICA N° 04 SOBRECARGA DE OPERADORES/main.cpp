#include <iostream>

using namespace std;

class Vector2D {
private:
    float x, y;

public:
    Vector2D() {
        x = 0;
        y = 0;
    }

    Vector2D(float _x, float _y) {
        x = _x;
        y = _y;
    }

    Vector2D operator+(const Vector2D& otro) const {
        return Vector2D(x + otro.x, y + otro.y);
    }

    Vector2D operator-(const Vector2D& otro) const {
        return Vector2D(x - otro.x, y - otro.y);
    }

    void mostrar() const {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    Vector2D suma = v1 + v2;
    Vector2D resta = v1 - v2;

    cout << "Vector 1: "; v1.mostrar(); cout << endl;
    cout << "Vector 2: "; v2.mostrar(); cout << endl;
    cout << "Suma: "; suma.mostrar(); cout << endl;
    cout << "Resta: "; resta.mostrar(); cout << endl;

    return 0;
}
