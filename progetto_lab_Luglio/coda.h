#include <stdio.h>
#include <stdlib.h>
#include "spedizione.h"

 /* struttura autoreferenziale  */
 struct queueNode {
  Spedizione sp_nodo;  /* il mio nodo contiene la struct spedizione  */
  struct queueNode *nextPtr; /* puntatore al nodo della coda */
 };

 typedef struct queueNode QueueNode;
 typedef QueueNode *QueueNodePtr;

 /* prototipi di funzione */
 void printQueue( QueueNodePtr currentPtr );
 
 int isEmpty( QueueNodePtr headPtr );

 void dequeue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr );

 void enqueue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr, Spedizione s ); 

 //da implementare
 void convalida_spedizioni(QueueNode coda);
