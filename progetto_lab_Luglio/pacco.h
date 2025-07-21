/**
 * @file pacco.h
 * @brief Definizione della struttura Pacco e delle relative funzioni di gestione.
 *
 * Questo file contiene la dichiarazione della struttura `Pacco` e i prototipi
 * delle funzioni per l'inserimento e la stampa delle sue informazioni.
 */

#ifndef PACCO_H
#define PACCO_H

/**
 * @struct Pacco
 * @brief Rappresenta un pacco spedito.
 *
 * Contiene informazioni identificative e fisiche del pacco:
 * - codice identificativo (`n`)
 * - peso in grammi
 * - volume in centimetri cubi
 */
typedef struct
{
    char n[10];   // codice identificativo del pacco, ad esempio "IT1234567"
    float peso;   // in grammi
    float volume; // in centimetri cubi
} Pacco;

/**
 * @brief Richiede all'utente i dati del pacco e li inserisce nella struttura.
 *
 * @param[out] p Puntatore alla struttura Pacco da riempire.
 */
void inserimento_pacco(Pacco *p);

/**
 * @brief Stampa a video le informazioni del pacco.
 *
 * @param[in] p La struttura Pacco da visualizzare.
 */
void stampa_pacco(Pacco p);

#endif // PACCO_H
