/*Ejercicio N°1
Diseñe un programa que sea capaz de leer dos colas y mediante un mensaje indicar si son
iguales. Nota: los elementos constitutivos de las colas son caracteres.*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

bool funcion (Cola<char>&cola1, Cola<char>&cola2) {

    while (!cola1.esVacia() && !cola2.esVacia()) {
        if (cola1.peek() != cola2.peek()) {
            return false;
        }

        cola1.desencolar();
        cola2.desencolar();
    }
}

int main() {

    cout << "Ejercicio N 1" << endl;

    Cola<char> cola1;
    Cola<char> cola2;

    cola1.encolar('a');
    cola1.encolar('g');
    cola1.encolar('u');
    cola1.encolar('s');

    cola2.encolar('a');
    cola2.encolar('g');
    cola2.encolar('b');

    if (funcion(cola1,cola2)){
        cout << "Colas iguales" << endl;
    }
    else{
        cout << "Colas distintas" << endl;
    }

    return 0;
}
