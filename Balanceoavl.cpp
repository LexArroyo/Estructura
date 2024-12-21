#include <iostream>
using namespace std;

struct nodo {
    struct nodo *izq;
    int valor;
    int altura;
    int peso;
    int equilibrio; 
    struct nodo *der;
};

struct nodo *raiz, *aux, *aux2, *padre;

int calcularpeso(struct nodo *a){
    if (a == NULL) return 0;
    return 1 + calcularpeso(a->izq) + calcularpeso(a->der);
}

int calcularaltura(struct nodo *a) {
    if (a == NULL) return 0;
    return 1 + max(calcularaltura(a->izq), calcularaltura(a->der));
}

int calcularequilibrio(struct nodo *a) {
    if (a == NULL) return 0;
    return calcularaltura(a->izq) - calcularaltura(a->der);
}

struct nodo* rotacionderecha(struct nodo *y) {
    struct nodo *x = y->izq;
    struct nodo *T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = calcularaltura(y);
    y->peso = calcularpeso(y);
    x->altura = calcularaltura(x);
    x->peso = calcularpeso(x);

    return x;
}

struct nodo* rotacionizquierda(struct nodo *x) {
    struct nodo *y = x->der;
    struct nodo *T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = calcularaltura(x);
    x->peso = calcularpeso(x);
    y->altura = calcularaltura(y);
    y->peso = calcularpeso(y);

    return y;
}

int posicionar(){    

    if(aux->valor < aux2->valor){        
        if(aux2->izq==NULL){
            aux2->izq = aux;            
            return 0;
        }

        else {
            aux->altura++; 
            aux2 = aux2->izq;
            posicionar();
        }
    } 

    else {
        if(aux2->der==NULL){
            aux2->der = aux;            
            return 0;
        } else {
            aux->altura++;
            aux2 = aux2->der;
            posicionar();
        }
    }
    
    aux2->altura = calcularaltura(aux2);
    aux2->peso = calcularpeso(aux2);
    aux2->equilibrio = calcularequilibrio(aux2);

    if (aux2->equilibrio > 1) {
        if (aux->valor < aux2->izq->valor) {
            (raiz = rotacionderecha(aux2));
        } else {
            aux2->izq = rotacionizquierda(aux2->izq);
            (raiz = rotacionderecha(aux2));
        }
    }

    if (aux2->equilibrio < -1) {
        if (aux->valor > aux2->der->valor) {
            (raiz = rotacionizquierda(aux2));
        } else {
            aux2->der = rotacionderecha(aux2->der);
            (raiz = rotacionizquierda(aux2));
        }
    }
    return 0;
}


int insertar(){

    aux = ((struct nodo *) malloc (sizeof(struct nodo)));
    cout<<"Digite el valor del nodo: ";
    cin>>aux->valor;
    aux->izq = aux->der = NULL;
    aux->altura = 0;
    aux->peso = 0;
    aux->equilibrio = 0;

    if(!raiz){
        raiz = aux; 
        aux = NULL;
        free(aux);
    }

    else {        
        aux2 = raiz;
        aux->altura = 1;
        aux->peso = 1;
        posicionar();
        aux = NULL;
        free(aux);
    }
    return 0;
}

int recorrer(nodo *a) {

    cout<<"Valor: "<<a->valor<<" con altura: " << a->altura <<" con peso: "<< a->peso <<" equilibrio: "<<a->equilibrio<<endl; 
    if(a->izq!=NULL){
        recorrer(a->izq);
    }
    if(a->der!=NULL){
        recorrer(a->der);
    }
    return 0;
}

int mostrar(){
    if(raiz){        
        recorrer(raiz);
    }
    return 0;
}

int ubicar(nodo *b, int aguja) {
    if (b->valor== aguja) {
        aux2 = b;
    } else {
        if (b->izq != NULL) {
            ubicar(b->izq, aguja);
        } 
        if (b->der != NULL) {
            ubicar(b->der, aguja);
        }
    }
    return 0;
}

int ubicarPadre(nodo *a) {
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
    return 0;
}

int eliminar() {
    int valor;
    cout << "Ingrese el valor a eliminar: ";
    cin >> valor;

    aux2 = NULL;
    ubicar(raiz, valor);

    if (aux2) {
        if (aux2 != raiz) {
            ubicarPadre(raiz);
            if (padre->izq == aux2) {
                padre->izq = (aux2->izq) ? aux2->izq : aux2->der;
            } else {
                padre->der = (aux2->der) ? aux2->der : aux2->izq;
            }
        } else {
            raiz = (aux2->izq) ? aux2->izq : aux2->der;
        }
        free(aux2);
    } else {
        cout << "No se encontró el valor para eliminar." << endl;
    }
    return 0;
}

int main(){

    int opcion;
    do{
        cout<<"1.Insertar";
        cout<<"\n2.Mostrar";
        cout<<"\n3.Eliminar";
        cout<<"\n4.Salir";
        cout<<"\nOpcion: ";
        cin>>opcion;

        switch (opcion)
        {                
            case 1:
                insertar();
            break;
            case 2:
                mostrar();
            break;
            case 3:
                eliminar();
            break;
            case 4:
            cout << "Saliendo..." << endl;
            break;
            default:
            cout << "Opción inválida." << endl;
        }

     } while(opcion!=4);
}
