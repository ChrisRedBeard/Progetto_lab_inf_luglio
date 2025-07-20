#include "coda.h"
#include "spedizione.h"
#include "utils.h"

#include <stdlib.h>

void coda_init(Coda *coda)
{
    coda->headPtr = NULL; // Inizializza il puntatore front a NULL
    coda->tailPtr = NULL; // Inizializza il puntatore rear a NULL
}

// per noi stampa la coda significa stamparli nel file
void printQueue(Coda c)
{

    /* Se la coda è vuota  */
    if (isEmpty(c)==1)
    {
        printf("%sLa coda è vuota.%s\n",YELLOW,RESET);
    }
    else
    {
        while (c.headPtr != NULL)
        {
            /*inserimento_file_spedizioni(Spedizione s)*/
            inserimento_file_spedizioni(c.headPtr->sp_nodo); // Inserisce la spedizione nel file delle spedizioni
            c.headPtr = c.headPtr->nextPtr;                 // spostamento al nodo successivo
        }
    }
}

int isEmpty(Coda c)
{
    return (c.headPtr) == NULL; // ritorna 1 se la coda è vuota, altrimenti ritorna 0
}

/* Rimuove un nodo(quindi una spedizione) dalla coda */
/*modifica da fare, modificare lo stato della spedizione */
Spedizione* dequeue(Coda *c)
{

    Spedizione *s=(Spedizione*)malloc(sizeof(Spedizione));
    QueueNodePtr tempPtr; // puntatore al nodo da rimuovere

    *s = (c->headPtr)->sp_nodo; // recupero la spedizione dal nodo da rimuovere
    tempPtr = c->headPtr;
    c->headPtr = c->headPtr->nextPtr;

    /*Se la coda è vuota   */
    if (c->headPtr == NULL)
    {
        c->tailPtr = NULL; // se la coda è vuota, il puntatore alla coda viene impostato a NULL
    }

    free(tempPtr); // rilascio la memoria del nodo rimosso

   return s;
}

void enqueue(Coda *c, Spedizione s)
{

    QueueNodePtr newPtr;                // puntatore al nuovo nodo
    newPtr = malloc(sizeof(QueueNode)); // allocazione memoria per il nuovo nodo

    // se c'è memoria disponibile
    if (newPtr != NULL)
    {
        newPtr->sp_nodo = s; // inserimento della spedizione nel nodo
        newPtr->nextPtr = NULL;

        if (isEmpty(*c))
        {
            c->headPtr = newPtr; // se è vuota, il nuovo nodo diventa la testa della coda
        }
        else
        {
            (c->tailPtr)->nextPtr = newPtr; // altrimenti il nuovo nodo viene inserito alla fine della coda
        }

        c->tailPtr = newPtr; // il nuovo nodo diventa la coda della coda
    }
    else
    {
       
        printf("\n%sLa spedizione con id: %s non è stata inserita nella coda, poiché non c'è memoria disponibile!!\n",RED,s.p.n,RESET);

    }
}

// metodo per la convalida
/*
viene visualizzato il primo elemento della coda e si chiede se si vuole convalidare
se risponde "si", il pacco viene convalidato (scritto nel file) e il suo stato cambia in "spedito"
se risponde "no", il pacco resta nella coda con lo stato "ordinato", e viene spostato in ultima posizione
*/

void convalida_spedizioni(Coda *c)
{

    int_pos convalida = 0;
    int_pos scelta;
    Spedizione *s;

    while (!isEmpty(*c))
    {
        stampa_spedizione(c->headPtr->sp_nodo);
        
       s = dequeue(c);

       stampa_spedizione(*s); //stampa sul terminale e poi chiede all'utente se vuole convalidarlo o meno

        printf("Vuoi convalidare il pacco? (1=>Si 0=>No) : ");
        scanf("%hd", &convalida);
        if (convalida == 1)
        {
            // lo tolgo dalla coda e poi gli cambio lo stato per stamparlo nel file
     
            s->stato= spedito;
            inserimento_file_spedizioni(*s);

        }
        else
        {
     

            //flag =true
            c->tailPtr->flag=true;
            //la coda e la spedizione
            enqueue(c,*s);
            

            if (c->tailPtr->flag==true && convalida == 0)
            {
                puts("Vuoi eliminare la spedizione? (1=>Si 0=>No)");
                scanf("%hd",&scelta);
                if(scelta==1){
                      s = dequeue(c);
                }else
                {

                //   enqueue(&(c->headPtr), &(c->tailPtr),*s);

                }
                

            }
            
        }
    }

}
