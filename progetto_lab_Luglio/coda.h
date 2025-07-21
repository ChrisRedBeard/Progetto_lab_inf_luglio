/**
 * @file coda.h
 * @brief Gestione di una coda di spedizioni.
 *
 * Questo modulo fornisce la definizione della struttura dati per la coda (`Coda`)
 * e le relative operazioni per gestire spedizioni, come inserimento, rimozione,
 * stampa e convalida.
 */
#ifndef CODA_H
#define CODA_H

#include "spedizione.h"
/**
 * @struct queueNode
 * @brief Nodo della coda che contiene una spedizione.
 */
struct queueNode
{
    Spedizione sp_nodo;        
    struct queueNode *nextPtr; 
};

typedef struct queueNode QueueNode; /**< Alias per la struct queueNode. */
typedef QueueNode *QueueNodePtr; /**< Puntatore a un nodo della coda. */

/**
 * @struct Coda
 * @brief Struttura che rappresenta una coda FIFO di spedizioni.
 */
typedef struct
{
     QueueNode *headPtr; /**< Puntatore alla testa della coda. */
     QueueNode *tailPtr; /**< Puntatore alla coda della coda. */
} Coda;

/**
 * @brief Inizializza una coda vuota.
 * @param coda Puntatore alla coda da inizializzare.
 */
void coda_init(Coda *coda);

/**
 * @brief Stampa (salva su file) tutti gli elementi della coda.
 * @param c Coda da stampare.
 */
void printQueue(Coda c);

/**
 * @brief Verifica se la coda è vuota.
 * @param c Coda da controllare.
 * @return 1 se la coda è vuota, 0 altrimenti.
 */
int isEmpty(Coda c);

/**
 * @brief Rimuove un elemento dalla testa della coda.
 * @param c Puntatore alla coda.
 * @return Puntatore alla spedizione rimossa (allocata dinamicamente).
 */
Spedizione* dequeue(Coda *c);

/**
 * @brief Inserisce una spedizione in coda.
 * @param c Puntatore alla coda.
 * @param s Spedizione da inserire.
 */
void enqueue(Coda *c, Spedizione s);

/**
 * @brief Convalida le spedizioni presenti nella coda.
 * Le spedizioni vengono mostrate all’utente che può decidere se convalidarle, eliminarle o lasciarle nella coda.
 * @param c Puntatore alla coda.
 */
void convalida_spedizioni(Coda* c);

/**
 * @brief Inserisce una nuova spedizione (con eventuale richiesta all'utente).
 * @param c Puntatore alla coda.
 */
void inserimento_spedizione(Coda *c);

#endif /* CODA_H */