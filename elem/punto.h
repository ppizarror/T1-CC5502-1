/**
 * Clase Punto.
 * @author Pablo Pizarro
 * @date 18/04/2018
 */

// Definición de constantes
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

// Importación de librerías
#ifndef T1_CC5502_1_PUNTO_H
#define T1_CC5502_1_PUNTO_H

#include <cmath>
#include <iostream>
#include <ctgmath>
#include <stdexcept>

template<class T>
/**
 * Clase Punto en 2D o 3D.
 * @tparam T Template
 */
class Punto {
private:
    T *coord = new T[3]; // Vector
    int dim; // Dimensión del punto
public:

    // Punto vacío
    Punto();

    // Constructor punto en 2D
    Punto(T x, T y);

    // Constructor punto en 3D
    Punto(T x, T y, T z);

    // Destructor
    ~Punto();

    // Obtiene la coordenada x
    T getCoordX() const;

    // Obtiene la coordenada y
    T getCoordY() const;

    // Obtiene la coordenada z
    T getCoordZ() const;

    // Establece la coordenada x
    void setCoordX(T x);

    // Establece la coordenada y
    void setCoordY(T y);

    // Establece una coordenada z
    void setCoordZ(T z);

    // Retorna el punto en forma de String
    std::string toString() const;

    // Imprime el punto en la consola
    void print() const;

    // Suma dos puntos y retorna un tercero
    Punto<T> operator+(const Punto<T> &p) const;

    // Suma un punto a sí mismo
    Punto<T> &operator+=(const Punto<T> &p);

    // Suma dos puntos y retorna un tercero
    Punto<T> operator-(Punto<T> &p) const;

    // Resta unaria
    Punto<T> operator-() const;

    // Suma un punto a sí mismo
    Punto<T> &operator-=(const Punto<T> &p);

    // Asignación
    Punto<T> &operator=(const Punto<T> &p);

    // Divide por un valor
    Punto<T> operator/(T v) const;

    // Multiplica por un valor
    Punto<T> operator*(T v) const;

    // Divide por un valor y guarda el punto
    Punto<T> &operator/=(T v);

    // Multiplica por un valor y guarda el punto
    Punto<T> &operator*=(T v);

    // Comprobación igualdad
    bool operator==(const Punto<T> &p) const;

    // Comprobación desigualdad
    bool operator!=(const Punto<T> &p) const;

    // Retorna valor absoluto
    Punto<T> abs() const;

    // Calcula la distancia entre dos puntos
    double dist(Punto<T> &p) const;

    // Calcula la distancia al cuadrado entre dos puntos
    double dist2(Punto<T> &p) const;

    // Retorna distancia punto al origen
    double distOrigin() const;

    // Retorna la dimensión del punto
    int getDimension() const;

    // Operación concatenación con string
    template<class U>
    friend std::ostream &operator<<(std::ostream &out, const Punto<U> &p);

    // Verifica si el punto y los puntos a, b forman una vuelta en ccw
    // +1   ccw
    // 0    colineal
    // -1   no ccw
    int ccw(Punto<T> &a, Punto<T> &b);

    // Clona el punto
    Punto<T> clonar();

    // Obtiene el coseno del ángulo entre un punto y otro
    double cos(Punto<T> &a);

    // Obtiene el coseno del ángulo entre un punto y otro
    double cos(Punto<T> &a, double dist);
};

template<class T>
/**
 * Punto vacío.
 * @tparam T
 */
Punto<T>::Punto() {
    this->dim = 0;
}

template<class T>
/**
 * Crea punto en 2D.
 * @tparam T Template
 * @param x Coordenada x
 * @param y Coordenada y
 */
Punto<T>::Punto(T x, T y) {
    this->dim = 2;
    this->setCoordX(x);
    this->setCoordY(y);
}

template<class T>
/**
 * Crea punto en 3D.
 * @tparam T Template
 * @param x Coordenada x
 * @param y Coordenada y
 * @param z Coordenada z
 */
Punto<T>::Punto(T x, T y, T z) {
    this->dim = 3;
    this->setCoordX(x);
    this->setCoordY(y);
    this->setCoordZ(z);
}

template<class T>
/**
 * Elimina el objeto de la memoria.
 * @tparam T Template
 */
Punto<T>::~Punto() {
}

template<class T>
/**
 * Retorna coordenada x.
 * @tparam T Template
 * @return Coordenada
 */
T Punto<T>::getCoordX() const {
    return coord[0];
}

template<class T>
/**
 * Retorna coordenada y.
 * @tparam T Template
 * @return Coordenada
 */
T Punto<T>::getCoordY() const {
    return coord[1];
}

template<class T>
/**
 * Retorna coordenada z. Sólo válido en un punto 3D.
 * @tparam T Template
 * @return Coordenada
 */
T Punto<T>::getCoordZ() const {
    if (this->dim < 3) {
        throw std::logic_error("La coordenada Z no existe en un punto 2D");
    }
    return coord[2];
}

template<class T>
/**
 * Retorna un string con el punto.
 * @tparam T Template
 * @return String en forma (x,y) o (x,y,z)
 */
std::string Punto<T>::toString() const {
    std::string s = "(" + std::to_string(this->getCoordX()) + "," + std::to_string(this->getCoordY()); // Punto
    if (this->dim == 2) {
        s += ")";
    } else {
        s += "," + std::to_string(this->getCoordZ()) + ")";
    }
    return s;
}

template<class T>
/**
 * Imprime el punto en la consola.
 * @tparam T Template
 */
void Punto<T>::print() const {
    std::cout << this->toString() << std::endl;
}

template<class T>
/**
 * Suma el punto con otro y retorna un nuevo punto.
 * @tparam T Template
 * @param p Punto a sumar
 * @return Nuevo punto
 */
Punto<T> Punto<T>::operator+(const Punto<T> &p) const {
    if (this->dim == 2 && p.dim == 2) {
        return Punto<T>(this->getCoordX() + p.getCoordX(), this->getCoordY() + p.getCoordY());
    } else if (this->dim == 3 && p.dim == 3) {
        return Punto<T>(this->getCoordX() + p.getCoordX(), this->getCoordY() + p.getCoordY(),
                        this->getCoordZ() + p.getCoordZ());
    } else {
        throw std::logic_error("Las dimensiones no son correctas para la operacion +");
    }
}

template<class T>
/**
 * Suma un punto al objeto.
 * @tparam T Template
 * @param p Punto a sumar
 */
Punto<T> &Punto<T>::operator+=(const Punto<T> &p) {
    // Se suman primero componente x e y
    this->coord[0] += p.getCoordX();
    this->coord[1] += p.getCoordY();

    // Comprobación dimensiones
    if (this->dim == 2 && p.dim == 2) {
    } else if (this->dim == 3 && p.dim == 3) {
        this->coord[2] += p.getCoordZ();
    } else {
        throw std::logic_error("Las dimensiones no son correctas para la operacion +=");
    }
    return *this;
}

template<class T>
/**
 * Resta el punto con otro y retorna uno nuevo.
 * @tparam T Template
 * @param p Puntp
 * @return
 */
Punto<T> Punto<T>::operator-(Punto<T> &p) const {
    if (this->dim == 2 && p.dim == 2) {
        return Punto<T>(this->getCoordX() - p.getCoordX(), this->getCoordY() - p.getCoordY());
    } else if (this->dim == 3 && p.dim == 3) {
        return Punto<T>(this->getCoordX() - p.getCoordX(), this->getCoordY() - p.getCoordY(),
                        this->getCoordZ() - p.getCoordZ());
    } else {
        throw std::logic_error("Las dimensiones no son correctas para la operacion -");
    }
}

template<class T>
/**
 * Resta un punto al objeto.
 * @tparam T Template
 * @param p Punto a sumar
 */
Punto<T> &Punto<T>::operator-=(const Punto<T> &p) {
    // Se suman primero componente x e y
    this->coord[0] -= p.getCoordX();
    this->coord[1] -= p.getCoordY();

    // Comprobación dimensiones
    if (this->dim == 2 && p.dim == 2) {
    } else if (this->dim == 3 && p.dim == 3) {
        this->coord[2] -= p.getCoordZ();
    } else {
        throw std::logic_error("Las dimensiones no son correctas para la operacion -=");
    }
    return *this;
}

template<class T>
/**
 * Resta unaria.
 * @tparam T Template
 * @return
 */
Punto<T> Punto<T>::operator-() const {
    if (this->dim == 2) {
        return Punto<T>(-this->getCoordX(), -this->getCoordY());
    } else {
        return Punto<T>(-this->getCoordX(), -this->getCoordY(), -this->getCoordZ());
    }
}

template<class T>
/**
 * Operación asignación.
 * @tparam T Template
 * @param p Punto
 * @return
 */
Punto<T> &Punto<T>::operator=(const Punto<T> &p) {
    this->coord[0] = p.getCoordX();
    this->coord[1] = p.getCoordY();

    // Comprobación dimensiones
    if (p.getDimension() == 3) {
        this->dim = 3;
        this->coord[2] = p.getCoordZ();
    } else {
        this->dim = 2;
    }
    return *this;
}

template<class T>
/**
 * Retorna el valor absoluto del punto.
 * @tparam T Template
 * @return
 */
Punto<T> Punto<T>::abs() const {
    if (this->dim == 2) {
        return Punto<T>(std::abs(this->getCoordX()), std::abs(this->getCoordY()));
    } else {
        return Punto<T>(std::abs(this->getCoordX()), std::abs(this->getCoordY()), std::abs(this->getCoordZ()));
    }
}

template<class T>
/**
 * Retorna distancia al origen del punto.
 * @tparam T Template
 * @return
 */
double Punto<T>::distOrigin() const {
    double d;
    if (this->dim == 2) {
        d = sqrt(pow(this->getCoordX(), 2) + pow(this->getCoordY(), 2));
    } else {
        d = sqrt(pow(this->getCoordX(), 2) + pow(this->getCoordY(), 2) + pow(this->getCoordZ(), 2));
    }
    return d;
}

template<class T>
/**
 * Calcula la distancia al cuadrado entre dos puntos.
 * @tparam Template
 * @param p Punto
 * @return
 */
double Punto<T>::dist2(Punto<T> &p) const {
    if (this->dim == 2) {
        return pow(this->getCoordX() - p.getCoordX(), 2) + pow(this->getCoordY() - p.getCoordY(), 2);
    } else {
        return pow(this->getCoordX() - p.getCoordX(), 2) + pow(this->getCoordY() - p.getCoordY(), 2) +
               pow(this->getCoordZ() - p.getCoordZ(), 2);
    }
}

template<class T>
/**
 * Calcula la distancia entre dos puntos.
 * @tparam Template
 * @param p Punto
 * @return
 */
double Punto<T>::dist(Punto<T> &p) const {
    return sqrt(this->dist2(p));
}

template<class T>
/**
 * Divide el punto por un valor.
 * @tparam T Template
 * @param v valor
 * @return
 */
Punto<T> Punto<T>::operator/(T v) const {
    if (this->dim == 2) {
        return Punto<T>(this->getCoordX() / v, this->getCoordY() / v);
    } else {
        return Punto<T>(this->getCoordX() / v, this->getCoordY() / v, this->getCoordZ() / v);
    }
}

template<class T>
/**
 * Multiplica el punto por un valor.
 * @tparam T Template
 * @param v valor
 * @return
 */
Punto<T> Punto<T>::operator*(T v) const {
    if (this->dim == 2) {
        return Punto<T>(this->getCoordX() * v, this->getCoordY() * v);
    } else {
        return Punto<T>(this->getCoordX() * v, this->getCoordY() * v, this->getCoordZ() * v);
    }
}

template<class T>
/**
 * Define coordenada x.
 * @tparam T Template
 * @param x Valor de la coordenada
 */
void Punto<T>::setCoordX(T x) {
    this->coord[0] = x;
}

template<class T>
/**
 * Define coordenada y.
 * @tparam T Template
 * @param y Valor de la coordenada
 */
void Punto<T>::setCoordY(T y) {
    this->coord[1] = y;
}

template<class T>
/**
 * Define coordenada z, aumenta dimensión.
 * @tparam T Template
 * @param z Valor de la coordenada
 */
void Punto<T>::setCoordZ(T z) {
    this->coord[2] = z;
    if (this->dim == 2) {
        this->dim = 3;
    }
}

template<class T>
/**
 * Divide y guarda en el mismo punto.
 * @tparam T Template
 * @param v Valor a dividir
 */
Punto<T> &Punto<T>::operator/=(T v) {
    // Se suman primero componente x e y
    this->coord[0] /= v;
    this->coord[1] /= v;

    // Comprobación dimensiones
    if (this->dim == 3) {
        this->coord[2] /= v;
    }
    return *this;
}

template<class T>
/**
 * Multiplica y guarda en el mismo punto.
 * @tparam T Template
 * @param v Valor a dividir
 */
Punto<T> &Punto<T>::operator*=(T v) {
    // Se suman primero componente x e y
    this->coord[0] *= v;
    this->coord[1] *= v;

    // Comprobación dimensiones
    if (this->dim == 3) {
        this->coord[2] *= v;
    }
    return *this;
}

template<class T>
/**
 * Verifica igualdad con otro punto.
 * @tparam T Template
 * @param p Punto
 * @return
 */
bool Punto<T>::operator==(const Punto<T> &p) const {
    if (this->dim == 2 && p.dim == 2) {
        return this->getCoordX() == p.getCoordX() && this->getCoordY() == p.getCoordY();
    } else if (this->dim == 3 && p.dim == 3) {
        return this->getCoordX() == p.getCoordX() && this->getCoordY() == p.getCoordY() &&
               this->getCoordZ() == p.getCoordZ();
    } else {
        throw std::logic_error("Las dimensiones no son correctas al comprobar igualdad");
    }
}

template<class T>
/**
 * Retorna la dimensión del punto.
 * @tparam T Template
 * @return Dimensión en N
 */
int Punto<T>::getDimension() const {
    return this->dim;
}

template<class T>
/**
 * Operador concatenación con strings.
 * @return
 */
std::ostream &operator<<(std::ostream &out, const Punto<T> &p) {
    out << p.toString();
    return out;
}

template<class T>
/**
 * Operador desigualdad
 * @tparam T Template
 * @param p Punto
 * @return
 */
bool Punto<T>::operator!=(const Punto<T> &p) const {
    return !(*this == p);
}

template<class T>
/**
 * Comprueba el orden ccw entre el punto y a, b
 * @tparam T Template
 * @param a Punto a
 * @param b Punto b
 * @return
 */
int Punto<T>::ccw(Punto<T> &a, Punto<T> &b) {
    T area = (a.getCoordX() - this->getCoordX()) * (b.getCoordY() - this->getCoordY()) -
             (a.getCoordY() - this->getCoordY()) * (b.getCoordX() - this->getCoordX());
    if (area > 0.0f)
        return -1; // No son ccw
    else
        return 1; // ccw
}

template<class T>
/**
 * Clona el punto
 * @tparam T Template
 * @return
 */
Punto<T> Punto<T>::clonar() {
    if (this->dim < 3)
        return Punto<T>(this->getCoordX(), this->getCoordY());
    else
        return Punto<T>(this->getCoordZ(), this->getCoordY(), this->getCoordZ());
}

template<class T>
/**
 * Obtiene el coseno del ángulo entre el punto y otro
 * @tparam T - Template
 * @param a - Punto
 * @return
 */
double Punto<T>::cos(Punto<T> &a) {
    if (a.getCoordX() == this->getCoordX())
        return 0.0f;
    if (a.getCoordY() == this->getCoordY()) {
        if (a.getCoordX() > this->getCoordX()) return 1;
        else return -1;
    }
    return ((a.getCoordX() - this->getCoordX())) / (this->dist2(a));
}

template<class T>
/**
 * Obtiene el coseno del ángulo entre el punto y otro
 * @tparam T - Template
 * @param a - Punto
 * @return
 */
double Punto<T>::cos(Punto<T> &a, double dist) {
    if (a.getCoordX() == this->getCoordX() || dist == 0)
        return 0;
    if (a.getCoordY() == this->getCoordY()) {
        if (a.getCoordX() > this->getCoordX()) return 1;
        else return -1;
    }
    return ((a.getCoordX() - this->getCoordX()) / dist);
}

#pragma clang diagnostic pop
#endif //T1_CC5502_1_PUNTO_H