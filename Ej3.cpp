/*Ejercicio N°3
Crear una función que reciba una cola por referencia y un número. Dicha función debe: Eliminar
todas las ocurrencias de dicho número, menos la primera. Si dicho número no se repite, deja la
cola como esta. Si dicho número no está en la cola, debe anunciar un mensaje de error. Imprimir
la cola al final para verificar si hubo o no modificaciones.*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void numRep (Cola<int>cola, int n){
    Cola<int> aux;
    bool num = false;
    bool pri = false;

    while (!cola.esVacia()){
        int x = cola.desencolar();

        if (n == x){
            if (num){
            num = true;
            }
            pri=true;
        }
        aux.encolar(x);
    }

    if (!num){
        cout << "No se encuentra el numero en la cola" << endl;
    }


}

int main() {

    cout << "Ejercicio N 3" << endl;

    Cola<int>cola;
    int n;

    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(3);
    cola.encolar(2);
    cola.encolar(4);

    cout << "Ingrese un numero entero" << endl;
    cin >> n;

    return 0;
}
