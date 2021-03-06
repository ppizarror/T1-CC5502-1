/**
 * Testea puntos.
 * @author Pablo Pizarro
 * @date 18/04/2018
 */

// Importación de librerías
#include <iostream>
#include <cassert>
#include "../elem/punto.h"

/**
 * Testea la creación de un punto entero.
 */
void testIntCreation() {
    // Crea punto inicial
    Punto<int> p1 = Punto<int>(420, 69);

    // Imprime punto
    p1.print();

    // Comprueba que se hayan definido bien los objetos
    assert(p1.getCoordX() == 420);
    assert(p1.getCoordY() != 0);

    // Comprueba sumas
    Punto<int> p2 = Punto<int>(0, -69);
    Punto<int> p3 = p1 + p2;
    assert(p3.getCoordX() == 420 && p3.getCoordY() == 0);

    // Comprueba suma a sí mismo. (0, -69) + (420, 0) = (420, -69)
    p2 += p3;
    assert(p2.getCoordX() == 420 && p2.getCoordY() == -69);

    // Restas
    p2 = -p2;
    assert(p2.getCoordX() == -420 && p2.getCoordY() == 69);

    // Valor absoluto
    p2 = p2.abs();
    assert(p2.getCoordX() == 420 && p2.getCoordY() == 69);

    // Calcula distancia de un punto al eje
    Punto<int> porigin = Punto<int>(0, 0);
    assert(p2.dist(porigin) == 3 * sqrt(20129));

    // Divide por un valor
    p2.setCoordX(5);
    p2.setCoordY(5);
    p2 /= 5;
    assert(p2.getCoordX() == 1 && p2.getCoordY() == 1);

    // Punto uno
    Punto<int> pone = Punto<int>(1, 1);
    assert(p2 == pone);
}

/**
 * Testea punto en flotante.
 */
void testFloatCreation() {
    Punto<float> *p1, *p2;

    // Inicia los puntos
    p1 = new Punto<float>(4.20, 2.10);
    p2 = new Punto<float>(4.20, 2.10);

    // Comprobación a lo bruto sumas y restas
    assert(p1->getCoordY() + p2->getCoordY() == 4.20f);
}

/**
 * Testea igualdad y desigualdad.
 */
void testEqNot() {
    Punto<int> p1 = Punto<int>(1, 1);
    Punto<int> p2 = Punto<int>(2, 4);
    Punto<int> p3 = Punto<int>(1, 1);

    // p1 == p3
    assert(p1 == p3);

    // p1 != p2
    assert(p1 != p2);
}

/**
 * Testea distancia y ángulo, usados por Graham-Scan.
 */
void testDistanciaAngulo() {
    Punto<int> p1 = Punto<int>(0, 0);
    Punto<int> p2 = Punto<int>(3, 4);

    assert(p1.dist(p2) == 5);
    assert(p1.cos(p2) == acos(0.6));
}

/**
 * Corre los test.
 */
int main() {
    std::cout << "Testeando punto" << std::endl;

    // Carga los tests
    testIntCreation();
    testFloatCreation();
    testEqNot();
    testDistanciaAngulo();

    // Retorna
    return 0;
}