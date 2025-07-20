#include "spedizione.h"

/* struttura autoreferenziale  */
struct queueNode
{
    Spedizione sp_nodo;        /* il mio nodo contiene la struct spedizione  */
    bool flag; //di accettazione
    struct queueNode *nextPtr; /* puntatore al nodo della coda */
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

// Definizione della struttura della coda
typedef struct
{
     QueueNode *headPtr; // Puntatore al primo nodo della coda
     QueueNode *tailPtr; // Puntatore all'ultimo nodo della coda
} Coda;

/* prototipi di funzione */

void coda_init(Coda *coda);

void printQueue(Coda c);

int isEmpty(Coda c);

Spedizione* dequeue(Coda *c);

void enqueue(Coda *c, Spedizione s);

void convalida_spedizioni(Coda* c);
