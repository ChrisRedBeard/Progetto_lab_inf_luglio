/**
 * @file spedizione.h
 * @brief Definizione della struttura Spedizione e delle relative funzioni di utilità.
 *
 * Questo file definisce la struttura `Spedizione`, l'enumerazione degli stati di spedizione
 * e alcune funzioni utili per la gestione delle spedizioni.
 */
#ifndef SPEDIZIONE_H
#define SPEDIZIONE_H

#include "pacco.h"
#include "mittente.h"
#include "destinatario.h"

#include <time.h>
#include <stdbool.h>

/**
 * @enum Stati
 * @brief Elenco degli stati possibili di una spedizione.
 */
enum Stati
{
    ordinato = 1,
    spedito,
    in_consegna,
    consegnato,
    annullato
};

/**
 * @struct Spedizione
 * @brief Rappresenta una spedizione completa, con mittente, destinatario, data spedizione ,data consegna e stato.
 */
typedef struct
{
    Pacco p;
    bool priorita;           // true se il pacco ha priorità, false altrimenti
    struct tm data_invio;    // data di invio del pacco
    struct tm data_consegna; // data di consegna prevista del pacco
    Mittente mittente;
    Destinatario destinatario;
    enum Stati stato;
} Spedizione;

/**
 * @brief Inserisce una data (giorno, mese, anno) fornita dall'utente.
 *
 * @param prompt Messaggio da mostrare all'utente.
 * @param data Puntatore alla struttura `tm` dove salvare la data.
 */
void inserimento_data(const char *prompt, struct tm *data);

/**
 * @brief Controlla che la data di invio sia precedente a quella di consegna.
 *
 * @param data_invio Data di invio del pacco.
 * @param data_consegna Data di consegna del pacco.
 * @return true se le date sono coerenti, false altrimenti.
 */
bool controllo_date(struct tm data_invio, struct tm data_consegna);


/**
 * @brief Stampa i dati completi di una spedizione.
 *
 * @param s La spedizione da stampare.
 */
void stampa_spedizione(Spedizione s);


/**
 * @brief Confronta due ID di pacchi (funzione di confronto per qsort).
 *
 * @param id1 Puntatore al primo elemento (stringa).
 * @param id2 Puntatore al secondo elemento (stringa).
 * @return Valore negativo, zero o positivo se id1 è minore, uguale o maggiore di id2.
 */
int confronta_id(const void* id1, const void* id2);

#endif // SPEDIZIONE_H
