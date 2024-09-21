#include <iostream>

using namespace std;

struct nodo {
    string nombre;
    string telefono;
    nodo* sig;
};

nodo* cab = nullptr;  
nodo* cabAnterior = nullptr;  
nodo *aux, *aux2;


void copiarLista() {
    nodo* temp = cab;
    nodo* nuevo, *ultimo = nullptr;

    
    while (cabAnterior != nullptr) {
        nodo* eliminar = cabAnterior;
        cabAnterior = cabAnterior->sig;
        delete eliminar;
    }

    while (temp != nullptr) {
        nuevo = new nodo;
        nuevo->nombre = temp->nombre;
        nuevo->telefono = temp->telefono;
        nuevo->sig = nullptr;

        if (cabAnterior == nullptr) {
            cabAnterior = nuevo;
        } else {
            ultimo->sig = nuevo;
        }
        ultimo = nuevo;
        temp = temp->sig;
    }
}

void registrar() {
    aux = new nodo;
    
    cout << "Nombre del contacto: ";
    cin >> aux->nombre;
    cout << "Numero de telefono: ";
    cin >> aux->telefono;
    aux->sig = nullptr;

    copiarLista();
    
    if (!cab) {
        cab = aux;
    } else {
        aux2 = cab;
        while (aux2->sig != nullptr) {
            aux2 = aux2->sig;
        }
        aux2->sig = aux;  
    }
}

void mostrar(nodo* cabecera) {
    nodo* temp = cabecera;
    if (!temp) {
        cout << "No hay contactos registrados." << endl;
    } else {
        while (temp != nullptr) {
            cout << "Nombre: " << temp->nombre << ", Telefono: " << temp->telefono << endl;
            temp = temp->sig;
        }
    }
}

void mostrarActual() {
    cout << "\n--- Contactos Actuales ---" << endl;
    mostrar(cab);
}

void mostrarRetroactivo() {
    cout << "\n--- Contactos Anteriores (Memoria Retroactiva) ---" << endl;
    mostrar(cabAnterior);
}

int main() {
    int opcion;
    
    do {
        cout << "\nMenu\n1. Insertar Contacto\n2. Mostrar Contactos Actuales\n3. Mostrar Memoria Retroactiva\n5. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
        case 1:
            registrar();
            break;
        case 2:
            mostrarActual();
            break;
        case 3:
            mostrarRetroactivo();
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (opcion != 5);
    
    return 0;
}

