#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class nodo{
  public:
    int dato;
    int id, id_padre;
    nodo *sig;
    nodo(int x, int y, int z){
      dato=x;
      id=y;
      id_padre=z;
      sig=NULL;
    }
};

class ArbolSimulado{
  public:
    nodo *inicio, *aux, *aux2;

    void ingresar(nodo *n){
      aux=n;
      aux2=inicio;
      if(inicio==NULL){
        inicio=aux;
        inicio->sig=NULL;
      }else{
        while(aux2->sig!=NULL){
          aux2=aux2->sig;
        }
        aux2->sig=aux;
      }
      system("clear");
      printf("\nAgregado\n");
    }

    void eliminar(int borrar){
        aux=inicio;
        /*while(aux->sig!=NULL){
            if(aux->id==borrar){
                //Aqui borra pero hay que buscar todos los hijos  los desendientes
            }
            if(aux->id_padre==borrar){

            }
            aux=aux->sig;
        }*/

        printf("\nBorrado\n");
    }

    void borrar(nodo *otro){

    }

    void mostrar(int cont){
        int aux_cont;
      aux=inicio;
      aux2=inicio;
      if(inicio==NULL){
        system("clear");
        printf("\nNada que mostrar\n");
      }else{
        system("clear");
        printf("\n%d\n", cont);

        //Imprime por orde de ID padre
        printf("\nID Padre\tID\tDato\n");
        for(aux_cont=0;aux_cont<=cont;aux_cont++){
            aux=inicio;
            while(aux!=NULL){
              if(aux->id_padre==aux_cont){
                printf("\n\t%d\t%d\t%d", aux->id_padre, aux->id, aux->dato);
              }
              aux=aux->sig;
            }
        }
        aux=inicio;
        //Imprime por orden de ID propio de cada nodo
        /*printf("\nID Padre\tID\tDato\n");
        while(aux!=NULL){
            printf("\n\t%d\t%d\t%d", aux->id_padre, aux->id, aux->dato);
            aux=aux->sig;
        }*/

        printf("\n");
      }
    }

    ArbolSimulado(){
        inicio=NULL;
        aux=NULL;
    }
};

int main(){
  ArbolSimulado arbol;
  nodo *node;
  int opc, num, aux_padre=0, cont_id=1, aborrar;

  do {
    printf("\n1.-Agregar\n2.-Mostrar\n3.-Salir\n");
    scanf("%d", &opc);
    switch(opc){
      case 1:
        printf("\nIngrese el valor:\t");
        scanf("%d", &num);
        if(cont_id>1){
          printf("\nHijo de qiuen?\t");
          scanf("%d", &aux_padre);
        }
        if(aux_padre>=cont_id){
            system("clear");
            printf("\nEl nodo %d no existe\n", aux_padre);
        }else{
            node = new nodo(num, cont_id, aux_padre);
            arbol.ingresar(node);
            cont_id++;
        }
      break;
      case 2:
        arbol.mostrar(cont_id);
      break;
      /*case 3:
        //Para borrar se tienen que borrar todos los hijos que tenga, empezando por el nivel mas bajo hasta el nodo que se desea borrar
        printf("\nQue nodo desea eliminar?\t");
        scanf("%d", &aborrar);
        if(aborrar>cont_id){
            printf("\nNo existe ese nodo");
        }else{
            arbol.eliminar(aborrar);
        }
      break;*/
      case 3:

      break;
      default:
        printf("***Opcion Invalida***");
    }
  } while(opc!=3);
  return 0;
}
