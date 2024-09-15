/*Ejercicio N°4
Crear un programa que solicite números enteros al usuario hasta que desee, almacenar los
números en una cola, pedir también un numero entero "n". Luego crear una función que
recibiendo una cola y un número entero “n”, si el "n" se encuentra en una de las posiciones de
la cola. Devuelva la suma de los elementos de la cola hasta llegar a "n" (sin incluir a n). Si el
número "n" no se encuentra en la cola, la función devuelve la suma de todos los elementos de
la cola. Imprimir primero la cola antes de la suma de sus elementos.*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

int funcionSuma (Cola<int>&cola,int n){
    int suma = 0;
    bool x = false;

    while (!cola.esVacia()){
        int dato = cola.desencolar();

        if (dato == n){
            x = true;
        }
        if (!x){
            suma=suma+dato;
        }
    }
    return suma;
}

void funcionMostrar(Cola<int>&cola){
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

    cout << "Ejercicio N 4" << endl;
    Cola<int> cola;
    int nums, n, m;

    cout << "Ingrese la cantidad de numeros en la cola" << endl;
    cin >> m;

    cout << "Ingrese los numeros" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> nums;
        cola.encolar(nums);
    }

    cout << "Ingrese un numero entero" << endl;
    cin >> n;

    cout << "Cola original" << endl;
    funcionMostrar(cola);

    cout << "Suma de los elementos hasta " << n << ": " << funcionSuma(cola,n) << endl;

    return 0;
}
