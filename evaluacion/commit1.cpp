#include <iostream>
using namespace std;

struct nodo{
    string nombre;
    int documento;
    int destino;
    nodo *sig;
};

nodo *aux, *aux2, *cab;

void registar(){
aux= new nodo;
cout<<"Ingresar nombre: ";
cin>>aux->nombre;
cout<<"Ingresar documento: ";
cin>>aux->documento;
cout<<"Ingresar destino: ";
cin>>aux->destino;
aux->sig=NULL;

if(!cab){
    aux=cab;
} else {
    aux2=cab;
    while(aux2->sig!=NULL){
        aux2=aux2->sig;
    }
}
}
int main()
{
    int option;
    
    do{
        cout<<"1. registar"<<endl<<"2. mostrar"<<endl;
        cin>>option;
        switch(option)
        {
        case 1:
        registar();
        break;
        
        }
    }while(option!=3);
    
    return 0;
}