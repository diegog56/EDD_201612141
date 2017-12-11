#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int valor;
    struct nodo *anterior;
    struct nodo *siguiente;
}Nodo;

typedef struct lista{
    Nodo *primero;
    Nodo *ultimo;
}Lista;


void insertar(Lista *listaDoble, int valor_){
	Nodo *nuevo=malloc(sizeof(Nodo));
	nuevo->valor=valor_;
	nuevo->anterior=NULL;
	nuevo->siguiente=NULL;
	if(listaDoble->primero==NULL){
		listaDoble->primero=nuevo;
		listaDoble->ultimo=nuevo;
	}else{
		nuevo->anterior=listaDoble->ultimo;
		listaDoble->ultimo->siguiente=nuevo;
		listaDoble->ultimo=nuevo;
	}
}

void mostrar(Lista *listaDoble){
    printf("\n\n");
	Nodo *aux=listaDoble->primero;
	printf("%d",aux->valor);
    aux=aux->siguiente;
	while(aux!=NULL){
		printf(", %d",aux->valor);
		aux=aux->siguiente;
	}
	free(aux);
	printf("\n\n");
}

int eliminar(Lista *listaDoble, int valor_){
    int cont=0;
    Nodo *aux=listaDoble->primero;
    if(listaDoble->primero->valor==valor_){
        if(listaDoble->primero==listaDoble->ultimo){
            listaDoble->primero=NULL;
            listaDoble->ultimo=NULL;
            return 1;
        }
        listaDoble->primero=listaDoble->primero->siguiente;
        listaDoble->primero->anterior=NULL;
        aux=aux->siguiente;
        cont++;
    }
    if(listaDoble->ultimo->valor==valor_){
        listaDoble->ultimo=listaDoble->ultimo->anterior;
        listaDoble->ultimo->siguiente=NULL;
        cont++;
    }
    while(aux!=NULL){
        if(aux->valor==valor_){
            Nodo *temp=aux;
            temp->anterior->siguiente=aux->siguiente;
            temp->siguiente->anterior=aux->anterior;
            free(temp);
            cont++;
        }else{
            aux=aux->siguiente;
        }
    }
    free(aux);
    return cont;
}

int menu(){
    int opcion=0;
    printf("------LISTAS DE ENTEROS-------\n");
    printf("1. Insertar-------\n");
    printf("2. Mostrar  -------\n");
    printf("3. Eliminar-------\n");
    printf("4. Salir   -------\n");
    scanf("%i",&opcion);
    system("cls");
    return opcion;
}
int main()
{
    int opcion=menu();
    Lista *listaDoble=malloc(sizeof(Lista));
	listaDoble->primero=NULL;
	listaDoble->ultimo=NULL;

    while(opcion!=4){
        int valor, e;
        switch(opcion){
        case 1:
        	printf("Ingrese el numero a insertar\n");
        	scanf("%d",&valor);
        	insertar(listaDoble,valor);
            system("cls");
            printf("Insercion exitosa (%d)\n\n", valor);
            break;
        case 2:
        	mostrar(listaDoble);
        	break;
        case 3:
        	printf("Ingrese el numero a eliminar\n");
        	scanf("%d",&valor);
        	e=eliminar(listaDoble,valor);
        	system("cls");
            if(e==0) printf("El valor no existe en la lista");
            else printf("Eliminacion de %d nodos con el valor %d fue exitosa\n",e,valor);
        	break;
        default:
            system("cls");
            printf("Valor no valido\n\n");
        }
        opcion=menu();
    }
    return 0;
}

