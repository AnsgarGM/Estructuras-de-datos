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

    void Agregar(nodo *n){
      aux2=n;
      if(inicio==NULL){
        inicio=aux2;
      }else{
        aux=inicio;
        while(aux->sig!=NULL){
          aux=aux->sig;
        }
        aux->sig=aux2;
      }
      system("clear");
      printf("\nAgregado\n");
    }

    void Eliminar(int aux_num){
        system("clear");
        if(inicio==NULL){
          printf("\nNada");
        }else{
          aux=inicio;
          aux2=inicio->sig;
          while(aux!=NULL){
            if(aux->dato==aux_num){
              inicio=aux->sig;
              delete(aux);
            }else if(aux2->dato==aux_num){
              aux->sig=aux2->sig;
              delete(aux2);
            }
            aux=aux->sig;
            aux2=aux2->sig;
          }
        }
    }

    void Mostrar(){
      system("clear");
      if(inicio==NULL){
        printf("\nNada\n");
      }else{
        printf("\n");
        aux=inicio;
        while(aux!=NULL){
          printf("%d -> ", aux->dato);
          aux=aux->sig;
        }
        printf("NULL\n");
      }
    }

    lista(){
      inicio=NULL;
      aux=NULL;
      aux2=NULL;
    }
};

int main(){
  lista l;
  nodo *node;
  int num, opc;
  do{
    printf("\n1.-Ingresar\n2.-Mostrar\n3.-Eliminar\n4.-Salir\n");
    scanf("%d", &opc);
    switch(opc){
      case 1:
        printf("\nNumero:\t");
        scanf("%d", &num);
        node=new nodo(num);
        l.Agregar(node);
      break;
      case 2:
        l.Mostrar();
      break;
      case 3:
        printf("\nNumero a eliminar (Se eliminan todos los numeros):\t");
        scanf("%d", &num);
        l.Eliminar(num);
      break;
      case 4:
        printf("\n***Adios***\n");
      break;
    }
  }while(opc!=4);
  return 0;
}
