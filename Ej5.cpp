/*Ejercicio N°5
Implementar una función que reciba una cola de números enteros y una pila entera vacía, y
separe los elementos de la cola de tal manera que los elementos pares de la cola permanezcan
en la cola, y los elementos impares formen parte de la pila.
Observaciones:
● Al insertar los elementos en la pila, deberán aparecer en orden inverso a como estaban
en la cola: el elemento de la posición 1 de la cola estará al fondo de la pila, el de la
posición 3 será el segundo desde el fondo, etc.
● Si la cola estuviera vacía mostrar mensaje de error.*/

#include <iostream>
#include "Cola/Cola.h"
#include "Pila/Pila.h"
using namespace std;

void funcionParImpar(Cola<int>&cola, Pila<int>&pila){
    Cola<int>aux;

    if (cola.esVacia()){
        cout << "Error cola vacia" << endl;
    }

    while (!cola.esVacia()){
        int x = cola.desencolar();

        if ( x % 2 == 0){
            aux.encolar(x);
        }
        else{
            pila.push(x);
        }
    }

    while (!aux.esVacia()){
        cola.encolar(aux.desencolar());
    }
}

void funcionMostrarPila (Pila<int>&pila){
    Pila<int>aux;

    while (!pila.esVacia()){
        cout << pila.pop() << " ";
    }
    cout << endl;
}

void funcionMostrarCola (Cola<int>&cola){

    Cola<int>aux;
    while (!cola.esVacia()){
        int dato = cola.desencolar();
        cout << dato << " ";
        aux.encolar(dato);
    }
    cout << endl;

    while (!aux.esVacia()){
        cola.encolar(aux.desencolar());
    }
}

int main() {

    cout << "Ejercicio N 5" << endl;
    Cola<int>cola;
    Pila<int>pila;

    cola.encolar(2);
    cola.encolar(3);
    cola.encolar(4);
    cola.encolar(7);
    cola.encolar(1);
    cola.encolar(6);

    funcionParImpar(cola,pila);

    cout << "Cola con numeros pares: " ;
    funcionMostrarCola(cola);
    cout << "Pila con numeros impares: ";
    funcionMostrarPila(pila);
    return 0;
}
