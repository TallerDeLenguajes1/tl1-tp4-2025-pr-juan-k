// # {} []

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int Energia;
    int PoderDeAtaque;
}Enemigo;


typedef struct TNodoEnemigo
{
    Enemigo Enemigo;
    TNodoEnemigo * Sig;
} TNodoEnemigo;



int main()
{
    TNodoEnemigo *Start = NULL;

    TNodoEnemigo *NNodo1 = (TNodoEnemigo *) malloc (sizeof(TNodoEnemigo));
        NNodo1->Enemigo.Energia = 10;
        NNodo1->Enemigo.PoderDeAtaque = 15;
        NNodo1->Sig = NULL;
        

        TNodoEnemigo *NNodo2 = (TNodoEnemigo *) malloc (sizeof(TNodoEnemigo));
        NNodo2->Enemigo.Energia = 16;
        NNodo2->Enemigo.PoderDeAtaque = 20;
        NNodo2->Sig = NULL;
        
        NNodo1->Sig = NNodo2;

 
    

    return 0;
}

TNodoEnemigo * CrearNodo(int valorEn, int valorAT)
    {
        TNodoEnemigo *NNodo = (TNodoEnemigo *) malloc (sizeof(TNodoEnemigo));
        NNodo->Enemigo.Energia = valorEn;
        NNodo->Enemigo.PoderDeAtaque = valorAT;
        NNodo->Sig = NULL;
        return NNodo;
}
void InsertarNodo(TNodoEnemigo ** Start , TNodoEnemigo *NNodo)
{
    NNodo -> Sig = *Start;
    *Start = NNodo;
}



