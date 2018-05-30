#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class nodo{
  public:
      int dato;
      nodo *sig;
      nodo(int x){
        dato=x;
        sig=NULL;
      }
};

class lista{
  public:
    nodo *inicio, *aux, *aux2;

    void insertar(nodo *n){
      aux2=n;
      if(inicio==NULL){
        inicio=n;
      }else{
        aux=inicio;
        while(aux->sig!=NULL) {
          aux=aux->sig;
        }
        aux->sig=aux2;
      }
    }

    void mostrar(){
      aux=inicio;
      if(inicio=NULL){
        printf("\nNada");
      }else{
        printf("\n");
        while(aux!=NULL){
          printf("%d\t", aux->dato);
          aux=aux->sig;
        }
        printf("\n");
      }
    }

    lista(){
      inicio=NULL;
      aux=NULL;
      aux2=NULL;
    }
};

int main(){
  int tam=5; //Define el tamaño de la tabla
  lista l[tam];
  nodo *node;
  int opc, num, indice;
  do{
    printf("\n1.-Agregar\n2.-Mostrar\n3.-Salir\n");
    scanf("%d", &opc);
    switch(opc){
      case 1:
        printf("\nIngresar el valor:\t");
        scanf("%d", &num);
        node=new nodo(num);
        indice=num%tam;
        l[indice].insertar(node);
      break;
      case 2:
        for(int i=0;i<tam;i++){
          l[i].mostrar();
        }
      break;
    }
  }while(opc!=3);
  return 0;
}
