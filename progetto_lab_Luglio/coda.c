#include "coda.h"
#include "spedizione.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

Coda *coda_init()
{
    Coda *coda = (Coda *)malloc(sizeof(Coda));
    if (coda == NULL)
    {
        fprintf(stderr, "Errore di allocazione della memoria per la coda.\n");
        exit(EXIT_FAILURE); // Termina il programma in caso di errore
    }
    coda->headPtr = NULL; // Inizializza il puntatore front a NULL
    coda->tailPtr = NULL; // Inizializza il puntatore rear a NULL
    return coda;
}

// per noi stampa la coda significa stamparli nel file
void printQueue(QueueNodePtr currentPtr)
{

    /* Se la coda è vuota  */
    if (currentPtr == NULL)
    {
        printf("La coda è vuota.\n");
    }
    else
    {
        while (currentPtr != NULL)
        {
            /*inserimento_file_spedizioni(Spedizione s)*/
            inserimento_file_spedizioni(currentPtr->sp_nodo); // Inserisce la spedizione nel file delle spedizioni
            currentPtr = currentPtr->nextPtr;                 // spostamento al nodo successivo
        }
    }
}

int isEmpty(QueueNodePtr headPtr)
{

    return headPtr == NULL; // ritorna 1 se la coda è vuota, altrimenti ritorna 0
}

/* Rimuove un nodo(quindi una spedizione) dalla coda */
/*modifica da fare, modificare lo stato della spedizione */
Spedizione* dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{

    Spedizione *s=(Spedizione*)malloc(sizeof(Spedizione));
    QueueNodePtr tempPtr; // puntatore al nodo da rimuovere

    *s = (*headPtr)->sp_nodo; // recupero la spedizione dal nodo da rimuovere
    tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    /*Se la coda è vuota   */
    if (*headPtr == NULL)
    {
        *tailPtr = NULL; // se la coda è vuota, il puntatore alla coda viene impostato a NULL
    }

    free(tempPtr); // rilascio la memoria del nodo rimosso

   return s;
}

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, Spedizione s)
{

    QueueNodePtr newPtr;                // puntatore al nuovo nodo
    newPtr = malloc(sizeof(QueueNode)); // allocazione memoria per il nuovo nodo

    // se c'è memoria disponibile
    if (newPtr != NULL)
    {
        newPtr->sp_nodo = s; // inserimento della spedizione nel nodo
        newPtr->nextPtr = NULL;

        if (isEmpty(*headPtr))
        {
            *headPtr = newPtr; // se è vuota, il nuovo nodo diventa la testa della coda
        }
        else
        {
            (*tailPtr)->nextPtr = newPtr; // altrimenti il nuovo nodo viene inserito alla fine della coda
        }

        *tailPtr = newPtr; // il nuovo nodo diventa la coda della coda
    }
    else
    {

        printf("la spedizione con id: %s non è stata inserita nella coda, poiché non c'è memoria disponibile!! \n", s.p.n);
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

    while (!isEmpty(c->headPtr))
    {
        stampa_spedizione(c->headPtr->sp_nodo);
        
       s = dequeue(&(c->headPtr), &(c->tailPtr));

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
            enqueue(&(c->headPtr), &(c->tailPtr),*s);
            

            if (c->tailPtr->flag==true && convalida == 0)
            {
                puts("Vuoi eliminare la spedizione? (1=>Si 0=>No)");
                scanf("%hd",&scelta);
                if(scelta==1){
                      s = dequeue(&(c->headPtr), &(c->tailPtr));
                }else
                {

                //   enqueue(&(c->headPtr), &(c->tailPtr),*s);

                }
                

            }
            
        }
    }

}
