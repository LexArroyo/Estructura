#include <iostream>
using namespace std;

struct nodo {
    char nombre[30];
    int documento;
    int destino;
    nodo *sig;
};

nodo *cab, *aux, *aux2;

void registrar(){
    aux = (struct nodo *) malloc(sizeof(nodo));
    
    cout << "Nombre: ";
    cin >> aux->nombre;
    cout << "Documento: ";
    cin >> aux->documento;
    cout << "Destino (1: La Bocana, 2: Piangüita, 3: Ladrilleros): ";
    cin >> aux->destino;
    aux->sig=NULL;
    
    if(!cab) {
        cab = aux;
    } else {
        aux2 = cab;
        while(aux2->sig != NULL) {
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
    }
}

void mostrar() {
     aux = cab;
    while(aux != NULL) {
        cout << "Nombre: " << aux->nombre 
             << ", Documento: " << aux->documento 
             << ", Destino: " << aux->destino << endl;
        aux = aux->sig;
    }
}

void ordenar(){
    int temporalDoc, temporalDestino;
    char temporalNombre[30];
    
    aux2 = cab;
    while(aux2->sig != NULL) {
        aux = cab;
        while(aux->sig != NULL) {

            if ((aux->destino > aux->sig->destino) ||
                (aux->destino == aux->sig->destino && aux->documento > aux->sig->documento)) {

                temporalDestino = aux->destino;
                aux->destino = aux->sig->destino;
                aux->sig->destino = temporalDestino;

                temporalDoc = aux->documento;
                aux->documento = aux->sig->documento;
                aux->sig->documento = temporalDoc;

                temporalNombre, aux->nombre;
                aux->nombre, aux->sig->nombre;
                aux->sig->nombre, temporalNombre;
            }
            aux = aux->sig;
        }
        aux2 = aux2->sig;
    }
}
    

int main(){
    int opcion;

    do {
        cout <<"1. Registrar pasajero"<<endl<< "2. Mostrar pasajeros"<<endl<<"3. Ordenar pasajeros"<<endl;
        cin >> opcion;

        switch (opcion) {
        case 1:
            registrar();
            break;
        case 2:
            mostrar();
            break;
        case 3:
            ordenar();
            break;
        }
    } while(opcion != 4);

    return 0;
}