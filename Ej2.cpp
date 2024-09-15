/*Ejercicio N°2
Implementar una función que suprima de la cola todos los elementos mayores que un número
“n” dado como límite. Al final se debe imprimir la cola depurada sin perder el orden que había
desde la cola original.*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void funcionMayor (Cola<int>&cola, int n){

    Cola<int>aux;
    while (!cola.esVacia()){
        int x = cola.desencolar();
        if (x <= n){
            aux.encolar(x);
        }
    }

    while (!aux.esVacia()){
        cola.encolar(aux.desencolar());
    }
}

int main() {

    cout << "Ejercicio N 2" << endl;

    Cola<int> cola;
    int n;

    cola.encolar(1);
    cola.encolar(4);
    cola.encolar(6);
    cola.encolar(8);
    cola.encolar(5);

    cout << "Ingrese un numero entero" << endl;
    cin >> n;

    funcionMayor(cola,n);

    while (!cola.esVacia()){
        cout << cola.desencolar() << endl;
    }
    return 0;
}
