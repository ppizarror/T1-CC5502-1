/**
 * Clase Punto
 * @author Pablo Pizarro
 * @date 18/04/2018
 */

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#ifndef T1_CC5502_1_PUNTO_H
#define T1_CC5502_1_PUNTO_H
#endif //T1_CC5502_1_PUNTO_H

// Importación de librerías
#include <stdexcept>

template<class T>
/**
 * Clase Punto en 2D o 3D
 * @tparam T Template
 */
class Punto {
private:
    T *coord = new T[3]; // Vector
    int dim; // Dimensión del punto
public:

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

    // Retorna el punto en forma de String
    std::string toString() const;

    // Imprime el punto en la consola
    void print() const;

    // Suma dos puntos y retorna un tercero
    Punto<T> operator+(Punto<T> &p) const;

    // Suma dos puntos y retorna un tercero
    Punto<T> operator-(Punto<T> &p) const;

    // Suma un punto a sí mismo
    Punto<T> &operator+=(Punto<T> &p);
};

template<class T>
/**
 * Crea punto en 2D.
 * @tparam T Template
 * @param x Coordenada x
 * @param y Coordenada y
 */
Punto<T>::Punto(T x, T y) {
    this->coord[0] = x;
    this->coord[1] = y;
    this->dim = 2;
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
    this->coord[0] = x;
    this->coord[1] = y;
    this->coord[2] = z;
    this->dim = 3;
}

template<class T>
/**
 * Elimina el objeto de la memoria
 * @tparam T Template
 */
Punto<T>::~Punto() {
    delete[] this->coord;
}

template<class T>
/**
 * Retorna coordenada x
 * @tparam T Template
 * @return Coordenada
 */
T Punto<T>::getCoordX() const {
    return coord[0];
}

template<class T>
/**
 * Retorna coordenada y
 * @tparam T Template
 * @return Coordenada
 */
T Punto<T>::getCoordY() const {
    return coord[1];
}

template<class T>
/**
 * Retorna coordenada z. Sólo válido en un punto 3D
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
 * Retorna un string con el punto
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
 * Imprime el punto en la consola
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
Punto<T> Punto<T>::operator+(Punto<T> &p) const {
    if (this->dim == 2 && p.dim == 2) {
        return Punto<T>(this->getCoordX() + p.getCoordX(), this->getCoordY() + p.getCoordY());
    } else if (this->dim == 3 && p.dim == 3) {
        return Punto<T>(this->getCoordX() + p.getCoordX(), this->getCoordY() + p.getCoordY(),
                        this->getCoordZ() + p.getCoordZ());
    } else {
        throw std::logic_error("Las dimensiones no son correctas para la operación +");
    }
}

template<class T>
/**
 * Suma un punto al objeto
 * @tparam T Template
 * @param p Punto a sumar
 */
Punto<T> &Punto<T>::operator+=(Punto<T> &p) {
    // Se suman primero componente x e y
    this->coord[0] += p.getCoordX();
    this->coord[1] += p.getCoordY();

    // Comprobación dimensiones
    if (this->dim == 2 && p.dim == 2) {
    } else if (this->dim == 3 && p.dim == 3) {
        this->coord[2] += p.getCoordZ();
    } else {
        throw std::logic_error("Las dimensiones no son correctas para la operación +=");
    }
    return *this;
}

template<class T>
Punto<T> Punto<T>::operator-(Punto<T> &p) const {
    return Punto<T>(T(), T());
}


#pragma clang diagnostic pop