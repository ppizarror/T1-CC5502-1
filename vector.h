/**
 * Clase Vector.
 * @author Pablo Pizarro
 * @date 19/04/2018
 */

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#ifndef T1_CC5502_1_VECTOR_H
#define T1_CC5502_1_VECTOR_H
#endif //T1_CC5502_1_VECTOR_H

// Importación de librerías
#include <iostream>

template<class T>
class Vector {
private:
    T *c = new T[3];
    int dim;
public:

    // Inicia un vector con 2 componentes
    Vector(T i, T j);

    // Inicia un vector con 3 componentes
    Vector(T i, T j, T k);

    // Destructor
    ~Vector();

    // Obtiene la coordenada x
    T getI() const;

    // Obtiene la coordenada y
    T getJ() const;

    // Obtiene la coordenada z
    T getK() const;

    // Establece la coordenada x
    void setI(T i);

    // Establece la coordenada y
    void setJ(T j);

    // Establece una coordenada z
    void setK(T k);

    // Retorna el punto en forma de String
    std::string toString() const;

    // Imprime el punto en la consola
    void print() const;
};

template<class T>
/**
 * Constructor vector 2 componentes.
 * @tparam T
 * @param i Componente eje x
 * @param j Componente eje y
 */
Vector<T>::Vector(T i, T j) {
    this->c[0] = i;
    this->c[1] = j;
    this->dim = 2;
}

template<class T>
/**
 * Constructor vector 3 componentes.
 * @tparam T
 * @param i Componente eje x
 * @param j Componente eje y
 * @param k Componente eje z
 */
Vector<T>::Vector(T i, T j, T k) {
    this->c[0] = i;
    this->c[1] = j;
    this->c[2] = k;
    this->dim = 2;
}

template<class T>
/**
 * Destructor
 * @tparam T Template
 */
Vector<T>::~Vector() {
    delete[] this->c;
}

template<class T>
/**
 * Crea un string con el vector.
 * @tparam T Template
 * @return
 */
std::string Vector<T>::toString() const {
    std::string s = "<" + std::to_string(this->getI()) + "," + std::to_string(this->getJ());
    if (this->dim == 2) {
        s += ">";
    } else {
        s += "," + std::to_string(this->getK()) + ">";
    }
    return s;
}

template<class T>
/**
 * Establece componente i (en x).
 * @tparam T Template
 * @param i Valor de la componente
 */
void Vector<T>::setI(T i) {
    this->c[0] = i;
}

template<class T>
/**
 * Establece componente j (en y).
 * @tparam T Template
 * @param j Valor de la componente
 */
void Vector<T>::setJ(T j) {
    this->c[1] = j;
}

template<class T>
/**
 * Establece componente k (en z).
 * @tparam T Template
 * @param k Valor de la componente
 */
void Vector<T>::setK(T k) {
    this->c[2] = k;
    if (this->dim == 2) {
        this->dim = 3;
    }
}

template<class T>
/**
 * Retorna la componente en x.
 * @tparam T Template
 * @return
 */
T Vector<T>::getI() const {
    return this->c[0];
}

template<class T>
/**
 * Retorna la componente en y.
 * @tparam T Template
 * @return
 */
T Vector<T>::getJ() const {
    return this->c[1];
}

template<class T>
/**
 * Retorna la componente en k.
 * @tparam T Template
 * @return
 */
T Vector<T>::getK() const {
    if (this->dim < 3) {
        throw std::logic_error("La componente K no existe en un vector 2D");
    }
    return this->c[2];
}

template<class T>
/**
 * Imprime el vector en consola.
 * @tparam T
 */
void Vector<T>::print() const {
    std::cout << this->toString() << std::endl;
}

#pragma clang diagnostic pop