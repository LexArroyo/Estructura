#include <iostream>
#include <cstdlib>

using namespace std;

struct Nodo {
    int edad; 
    int documento;  
    Nodo *izq;
    Nodo *der;
};

Nodo *raiz, *aux, *aux2, *padre;


int posicionar() {    
    if (aux->edad > aux2->edad) {  
        if (aux2->izq == NULL) {
            aux2->izq = aux;
        } else {
            aux2 = aux2->izq;
            posicionar();
        }
    } else {
        if (aux2->der == NULL) {
            aux2->der = aux;
        } else {
            aux2 = aux2->der;
            posicionar();
        }
    }
}

int registrar() {
    aux = (struct Nodo *) malloc(sizeof(struct Nodo)); 
    cout << "Edad: ";
    cin >> aux->edad;
    cout << "Documento: ";
    cin >> aux->documento;
    aux->izq = aux->der = NULL;

    if (!raiz) {
        raiz = aux;
    } else {        
        aux2 = raiz;
        posicionar();
    }
    aux = NULL;
}

int recorrer(Nodo *a) {
    if (a->izq != NULL) {
        recorrer(a->izq);
    }
    cout << "Edad: " << a->edad << ", Documento: " << a->documento << endl;    
    if (a->der != NULL) {
        recorrer(a->der);
    }
}

int mostrar() {
    if (raiz) {
        recorrer(raiz);
    }
}


int ubicar(Nodo *a, int aguja) {
    if (a->documento== aguja) {
        aux2 = a;
    } else {
        if (a->izq != NULL) {
            ubicar(a->izq, aguja);
        } 
        if (a->der != NULL) {
            ubicar(a->der, aguja);
        }
    }
}

int buscar(int aguja) {
    aux = NULL;
    if (raiz != NULL) {
        aux = raiz;
        ubicar(aux, aguja);
    }
}

int buscarpaciente() {
    aux2 = NULL;
    int dato;
    cout << "buscar documento: ";
    cin >> dato;
    buscar(dato);
    if (aux2) {
        cout << "Paciente encontrado." << endl;
    } else {
        cout << "El paciente no se encontró." << endl;
    }
}


int ubicarPadre(Nodo *a) {
    if ((a->izq == aux2) || (a->der == aux2)) {
        padre = a;
    } else {
        if (a->izq != NULL) {
            ubicarPadre(a->izq);
        } 
        if (a->der != NULL) {
            ubicarPadre(a->der);
        }
    }
}


int eliminar() {
    buscarpaciente();
    if (aux2) {

        if (aux2 != raiz) {
            ubicarPadre(raiz);
            if (padre->izq == aux2) {
                padre->izq = nullptr;
            } else {
                padre->der = nullptr;
            }
        } else {
            raiz = nullptr;
        }
        free(aux2);
    } else {
        cout << "No se encontró el paciente para eliminar." << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "1. Registrar"<<endl;
        cout<< "2. Mostrar"<<endl;
        cout<< "3. Buscar"<<endl;
        cout<< "4. Eliminar"<<endl;
        cout<< "5. Salir"<<endl;
        cin >> opcion;
        switch (opcion) {
            case 1: registrar(); 
            break;
            case 2: mostrar(); 
            break;
            case 3: buscarpaciente(); 
            break;
            case 4: eliminar(); 
            break;
        }
    } while (opcion != 5);
    return 0;
}
