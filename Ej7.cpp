/*Ejercicio N°7
Imagina una oficina con varias impresoras compartidas por varios empleados. Cada vez que un
empleado envía un documento para imprimir, este se coloca en una cola de impresión. Las
impresoras trabajan de manera que el primer documento enviado es el primero en ser impreso.
Si una impresora está ocupada, el documento queda en espera en la cola hasta que la impresora
esté disponible.
Implementar un sistema de gestión de colas de impresión en el que se:
 Agreguen documentos a la cola de impresión.
 Se impriman documentos en el orden en que fueron enviados.
 Se pueda mostrar el estado de la cola de impresión y los documentos pendientes.*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

struct Documento {
    string nombre;
    int paginas;

    Documento(const string& nombre = "", int paginas = 0) : nombre(nombre), paginas(paginas) {}

    void mostrar() const {
        cout << "Documento: " << nombre << ", Paginas: " << paginas << endl;
    }
};

void Mostrar (Cola<Documento>&cola){
    Cola<Documento>aux;

    cout << "Estado actual de la cola de impresion:" << endl;
    while (!cola.esVacia()) {
        Documento doc = cola.desencolar();
        doc.mostrar();
        aux.encolar(doc);
    }

    // Restaurar la cola original
    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }
}

void Agregar (Cola<Documento>&cola){
    string nom;
    int pag;
    cout << "Ingrese nombre del doc" << endl;
    cin.ignore();
    getline(cin, nom);
    cout << "Ingrese el numero de paginas" << endl;
    cin >> pag;

    Documento doc(nom, pag);
    cola.encolar(doc);
    cout << "Documento agregado" << endl;
}

void Imprimir (Cola<Documento>&cola){

    if(!cola.esVacia()){
        cout << "No hay documentos para imprimir" << endl;
        return;
    }

    Documento imprimir = cola.desencolar();
    imprimir.mostrar();
}

int main() {

    cout << "Ejercicio N 7" << endl;
    Cola<Documento>cola;
    int opcion;

    do{
        cout << "------------MENU-------------" << endl;
        cout << "1. Mostrar cola de impresion" << endl;
        cout << "2. Agregar nuevo documento a la cola" << endl;
        cout << "3. Imprimir siguiente documento" << endl;
        cout << "4. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                Mostrar(cola);
                break;
            case 2:
                Agregar(cola);
                break;
            case 3:
                Imprimir(cola);
                break;
            case 4:
                break;
            default:
                cout << "Opción invalida" << endl;
                break;
        }
    }while (opcion != 4);



    return 0;
}
