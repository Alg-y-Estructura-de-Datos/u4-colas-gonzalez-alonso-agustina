/*Ejercicio N°6
Implementar un programa con un menú de opciones para manejar un sistema de citas en un
consultorio médico. Añadiremos funcionalidades adicionales, como mostrar pacientes, agregar
nuevos pacientes y atender a los pacientes en espera. También manejaremos los datos de
pacientes de manera más detallada, como con nombres y números de teléfono.*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

struct Paciente {
    string nombre;
    string telefono;

    Paciente() {}

    Paciente(const string& nombre, const string& telefono) : nombre(nombre), telefono(telefono) {}

    void imprimir() const {
        cout << "Nombre: " << nombre << ", Telefono: " << telefono << endl;
    }

};

void mostrarPaciente(const Paciente& paciente) {
    paciente.imprimir();
}

void Mostrar (Cola<Paciente>cola){
    Cola<Paciente>aux;

    while (!cola.esVacia()){
        Paciente paciente = cola.desencolar();
        mostrarPaciente(paciente);
        aux.encolar(paciente);
    }
    cout << endl;

    while (!aux.esVacia()){
        cola.encolar(aux.desencolar());
    }
}

void Agregar (Cola<Paciente>& cola) {
    string nombre, telefono;
    cout << "Ingrese el nombre del paciente: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el telefono del paciente: ";
    getline(cin, telefono);

    Paciente nuevoPaciente(nombre, telefono);
    cola.encolar(nuevoPaciente);
    cout << "Paciente agregado." << endl;
}

void Atender (Cola<Paciente>& cola) {
    if (cola.esVacia()) {
        cout << "No hay pacientes en espera." << endl;
        return;
    }

    Paciente pacienteAtendido = cola.desencolar();
    cout << "Atendiendo a: ";
    mostrarPaciente(pacienteAtendido);
}

int main() {

    cout << "Ejercicio N 6" << endl;

    Cola<Paciente>cola;
    int opcion;

    do{
        cout << "----------------MENU----------------" << endl;
        cout << "1. Mostrar pacientes" << endl;
        cout << "2. Agregar paciente" << endl;
        cout << "3. Atender paciente" << endl;
        cout << "4. Salir" << endl;
        cin>> opcion;

        switch (opcion) {
            case 1:
                Mostrar(cola);
                break;
            case 2:
                Agregar(cola);
                break;
            case 3:
                Atender(cola);
                break;
            case 4:
                break;
        }
    } while (opcion!=4);

    return 0;
}
