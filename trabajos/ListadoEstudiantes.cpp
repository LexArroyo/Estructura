#include <iostream>
using namespace std;

struct nodo{
    string nombre;
    int codigo;
    float nota;
    nodo *sig;
};

nodo *cab=NULL, *aux=NULL, *aux2=NULL;

void registrar(){
    aux = new nodo;
    cout<<"Ingresar nombre: ";
    cin>>aux->nombre;
    cout<<"ingresar codigo: ";
    cin>>aux->codigo;
    cout<<"Ingrese la nota del estudiante: ";
    cin>>aux->nota;
    aux->sig = NULL;
    
    if(!cab){
        cab = aux;
    } else {
        aux2=cab;
        while(aux2->sig!=NULL){
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
    }
}


void mostrar(){
    aux=cab;
    if (!aux) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }
    while (aux !=NULL) {
        cout <<"Nombre: "<<aux->nombre<<endl;
        cout<<"Código: "<<aux->codigo<<endl;
        cout<<"Nota: "<<aux->nota<<endl;
        aux = aux->sig;
    }
}
void OrdenarPorNota(){
    string temporalNombre;
    int temporalCodigo;
    float temporalNota;
    
    do{
        
        aux=cab;
        while (aux->sig != NULL){
            if(aux->nota < aux->sig->nota){
                
                temporalNombre = aux->nombre;
                aux->nombre = aux->sig->nombre;
                aux->sig->nombre = temporalNombre;
                
                temporalCodigo = aux->codigo;
                aux->codigo = aux->sig->codigo;
                aux->sig->codigo = temporalCodigo;
                
                temporalNota = aux->nota;
                aux->nota = aux->sig->nota;
                aux->sig->nota = temporalNota;
            }
            aux=aux->sig;
        }
    } while(aux != NULL);
}   

void OrdenarPorCodigo(){
    
    string temporalNombre;
    int temporalCodigo;
    float temporalNota;
    do{
        
        aux=cab;
        while (aux->sig != NULL){
            if(aux->nota < aux->sig->nota){
                
                temporalNombre = aux->nombre;
                aux->nombre = aux->sig->nombre;
                aux->sig->nombre = temporalNombre;
                
                temporalCodigo = aux->codigo;
                aux->codigo = aux->sig->codigo;
                aux->sig->codigo = temporalCodigo;
                
                temporalNota = aux->nota;
                aux->nota = aux->sig->nota;
                aux->sig->nota = temporalNota;
                
            }
            aux=aux->sig;
        }
    } while(cab != NULL);
} 

void mayorNota() {
    aux = cab;
    nodo *mayor = aux;
    while (aux != NULL) {
        if (aux->nota > mayor->nota) {
            mayor = aux;
        }
        aux = aux->sig;
    }
    cout << "El estudiante con la mayor nota es: " << mayor->nombre << " con una nota de " << mayor->nota << endl;
}
    
    void menorNota() {
    
    aux = cab;
    nodo *menor = aux;
    while (aux != NULL) {
        if (aux->nota < menor->nota) {
            menor = aux;
        }
        aux = aux->sig;
    }
    cout << "El estudiante con la menor nota es: " << menor->nombre << " con una nota de " << menor->nota << endl;
}

void PromedioNotas(){
     aux = cab;
    float suma = 0;
    int contador = 0;
    while (aux != NULL) {
        suma += aux->nota;
        contador++;
        aux = aux->sig;
    }
    cout << "El promedio de las notas es: " << suma / contador << endl;
}

int main(){
    
    int opcion;
    do{
        cout<<"1. Ingresar nombre del estudiante"<<endl<<"2. Mostrar"<<endl<<"3. Ordenar por nota"<<endl<<"4. ordenar por codigo"<<endl<<"5. Mayor nota"<<endl<<"6. Menor nota"<<endl<<"7. mostrar promedio notas"<<endl;
        
        cin>>opcion;
        switch(opcion){
            case 1:
            registrar();
            break;
            case 2:
            mostrar();
            break;
            case 3:
            OrdenarPorNota();
            break;
            case 4:
            OrdenarPorCodigo();
            break;
            case 5:
            mayorNota();
            break;
            case 6:
            menorNota();
            break;
            case 7:
            PromedioNotas();
            break;
        }
    }while(opcion=! 8);
    return 0;
}
