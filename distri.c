#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}Tarea ;

typedef struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
}Nodo;


Nodo * crearTarea(char *describ,int duracion,int tareaID);
void agregarNodo(Nodo **start,Nodo *nodo);
Nodo *tareasRealizadas(Nodo **start,int inTarea);
void mostrarLista(Nodo *start);
int main(){
    srand(time(NULL));

    Nodo * start = NULL;
    Nodo * start_Trealizadas = NULL;
    int seguir = 0,inDurac = 0,tareaID = 1000,realizada = 0;
    char inDescr[20];
    
        printf("\nDesea cargar tarea 1-si / 2-no:");
        scanf("%d",&seguir);
    while (seguir != 2)
    {
        
        puts("####################");
        printf("\nDescripcion:");
        scanf("%s",inDescr);
        printf("\nDuracion:");
        scanf("%d",&inDurac);

        Nodo *tarea = crearTarea(inDescr,inDurac,tareaID);
        agregarNodo(&start,tarea);

        printf("\nDesea cargar tarea 1-si / 2-no:");
        scanf("%d",&seguir);
        tareaID++;

    };
        printf("\nDesea agregar a TAREA REALIZADAS 1-si / 2-no:");
        scanf("%d",&seguir);

    while (seguir != 2)
    {
        printf("\nTarea a agregar:");
        scanf("%d",&realizada);
        Nodo *tareaR = tareasRealizadas(&start,realizada);
        agregarNodo(&start_Trealizadas,tareaR);



        printf("\nDesea agregar a TAREA REALIZADAS 1-si / 2-no:");
        scanf("%d",&seguir);
        
    }
    
    puts("##################");
    mostrarLista(start);
    printf("\n");
    puts("##################");
    printf("\nTAREAS REALIZADAS");
    mostrarLista(start_Trealizadas);



    return 0;
}
Nodo *crearTarea(char *describ, int duracion,int tareaID) {
    Nodo *carga = (Nodo *)malloc(sizeof(Nodo));
    carga->T.TareaID = tareaID;

    carga->T.Descripcion = (char *)malloc(strlen(describ) + 1);
    strcpy(carga->T.Descripcion, describ);
    carga->T.Duracion = duracion;
    carga->Siguiente = NULL;

    return carga;
}
void agregarNodo(Nodo **start,Nodo *nodo){
    if (*start == NULL) {
        *start = nodo; // Si la lista está vacía, el nuevo nodo es el inicio
    } else {
        Nodo *aux = *start;
        while (aux->Siguiente != NULL) {
            aux = aux->Siguiente; // Avanza hasta el final de la lista
        }
        aux->Siguiente = nodo; // Agrega el nuevo nodo al final
    } 
}
Nodo *tareasRealizadas(Nodo **start,int inTarea){
    Nodo *aux = * start;
    while (aux != NULL && aux->T.TareaID != inTarea)
    {
        aux = aux->Siguiente;
    }
    return aux;
    
}
void mostrarLista(Nodo *start){
    Nodo *aux = start;
    while (aux != NULL)
    {
        
        printf("\n\nTarea id: %d",aux->T.TareaID);
        printf("\nDescripcion: %s",aux->T.Descripcion);
        printf("\nDuracion:%d",aux->T.Duracion);
        aux = aux->Siguiente;
    }
    
}

