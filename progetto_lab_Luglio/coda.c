

#include "coda.h"
#include "spedizione.h"

 
 void printQueue( QueueNodePtr currentPtr ){

    /* Se la coda è vuota  */
    if(currentPtr==NULL){
        printf("La coda è vuota.\n");

    }else{
        while (currentPtr!=NULL)
        {
            /*inserimento_file_spedizioni(Spedizione s)*/
            inserimento_file_spedizioni(currentPtr->sp_nodo); // Inserisce la spedizione nel file delle spedizioni
            currentPtr = currentPtr->nextPtr; // spostamento al nodo successivo
        }
        
    }
 }


 int isEmpty( QueueNodePtr headPtr ){

    return headPtr == NULL; // ritorna 1 se la coda è vuota, altrimenti ritorna 0
 }

/* Rimuove un nodo(quindi una spedizione) dalla coda */
/*modifica da fare, modificare lo stato della spedizione */
void dequeue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr ){
  
   Spedizione s;
    QueueNodePtr tempPtr; // puntatore al nodo da rimuovere

    s = ( *headPtr )->sp_nodo; // recupero la spedizione dal nodo da rimuovere
    tempPtr = *headPtr; 
    *headPtr = (*headPtr)->nextPtr;
    
    /*Se la coda è vuota   */
    if(*headPtr == NULL){
        *tailPtr = NULL; // se la coda è vuota, il puntatore alla coda viene impostato a NULL
    }

    free(tempPtr); // rilascio la memoria del nodo rimosso
    
    s.stato = spedito; // Modifica lo stato della spedizione a "spedito"
   inserimento_file_spedizioni(s); // Inserisce la spedizione nel file delle spedizioni

}




 void enqueue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr, Spedizione s){

    QueueNodePtr newPtr; // puntatore al nuovo nodo
    newPtr = malloc( sizeof( QueueNode ) ); // allocazione memoria per il nuovo nodo    

    //se c'è memoria disponibile
    if(newPtr != NULL){
        newPtr->sp_nodo = s; // inserimento della spedizione nel nodo
        newPtr->nextPtr = NULL;


            if(isEmpty(*headPtr)){
                *headPtr= newPtr; // se è vuota, il nuovo nodo diventa la testa della coda 
            }else{
                (*tailPtr)->nextPtr = newPtr; // altrimenti il nuovo nodo viene inserito alla fine della coda
            }

            *tailPtr = newPtr; // il nuovo nodo diventa la coda della coda
    }    
        else{

            printf("la spedizione con id: %s non è stata inserita nella coda, poiché non c'è memoria disponibile!! \n", s.p.n);
        }
  }

