#include <iostream>
using namespace std;

struct nodo {
    string tipo;
    int movimientos;
    int totalrecaudado = 0;
    int recaudo;
    nodo *sig;
};

struct nodo *top, *top2, *aux;

int registrar() {
    aux = (struct nodo*) malloc(sizeof(struct nodo));
    int tipoVehiculo;
    cout << "Registre el tipo de vehiculo (1. Moto, 2. Auto): ";
    cin >> tipoVehiculo;
    aux->tipo = (tipoVehiculo == 1) ? "Moto" : "Auto";
    aux->movimientos = 0;
    aux->recaudo = 0;
    
    if (!top) {
        top = aux;
        top->sig = NULL;
    } else {
        aux->sig = top;
        top = aux;
    }
    aux = NULL;
  return 0;
}

int salirvehiculo() {
    if (top == NULL) {
        cout << "No hay vehículos en el estacionamiento." << endl;
        return 0;
    }

    cout << "Ingrese los movimientos del vehículo al salir: ";
    cin >> top->movimientos;

    int costoBase = (top->tipo == "Moto") ? 1000 : 2000;
    int costoMovimientos = top->movimientos * 100;
    int costoTotal = costoBase + costoMovimientos;

    top->totalrecaudado = costoTotal;

    cout << "El vehiculo (" << top->tipo << ") ha salido. Costo total: $" << costoTotal << endl;

    aux = top;
    top = top->sig;
    free(aux);
}

int mostrartotalrecaudado() {
    int generalRecaudado = 0;

    cout << "Total recaudado hasta ahora:" << endl;
    
    while (top != NULL) {
        generalRecaudado += top->totalrecaudado;
        cout << "Recaudo del vehiculo: $" << top->totalrecaudado << endl;
        
        if (top == NULL) {
            top2 = top;
            top = top->sig;
            top2->sig = NULL;
        } else {
            aux = top;
            top = top->sig;
            aux->sig = top2;
            top2 = aux;
            aux = NULL;
        }
    }

    while (top2 != NULL) {
        if (top == NULL) {
            top = top2;
            top2 = top2->sig;
            top->sig = NULL;
        } else {
            aux = top2;
            top2 = top2->sig;
            aux->sig = top;
            top = aux;
            aux = NULL;
        }
    }

    cout << "Total general recaudado: $" << generalRecaudado << endl;
}

int main() {
    int opcion;

    do {
        cout << "- Menu Estacionamiento -" << endl;
        cout << "1. Registrar vehiculo" << endl;
        cout << "2. Salir vehiculo" << endl;
        cout << "3. Mostrar total recaudado" << endl;
        cout << "4. Salir del programa" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                registrar();
                break;
            case 2:
                salirvehiculo();
                break;
            case 3:
                mostrartotalrecaudado();
                break;
        }
    } while (opcion != 4);

    return 0;
}