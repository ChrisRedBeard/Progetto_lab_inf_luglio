/**
 * @file funzioni.h
 * @brief Dichiarazioni di funzioni di utilità per la gestione delle spedizioni, input, stampa e manipolazione della coda.
 *
 * Questo header contiene le dichiarazioni delle funzioni per l'acquisizione dati da input,
 * la stampa delle spedizioni e delle code, il confronto tra spedizioni e identificativi,
 * e la gestione delle code di spedizioni (ordinamento, rimozione duplicati, inserimento ordinato).
 */

#ifndef FUNZIONI_H
#define FUNZIONI_H

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define WHITE "\033[97m"

#include "dati.h"

/**
 * @brief Tipo intero senza segno usato per lunghezza.
 */
typedef unsigned short int int_pos;

// --- Funzioni input ---

/**
 * @brief Acquisisce una stringa da input utente.
 * @param prompt Messaggio da visualizzare.
 * @param dest Buffer destinazione per la stringa.
 * @param lunghezza Lunghezza massima della stringa.
 */
void input_string(const char *prompt, char *dest, int_pos lunghezza);

/**
 * @brief Acquisisce un valore float da input utente.
 * @param prompt Messaggio da visualizzare.
 * @param dest Puntatore dove salvare il valore.
 * @param min Valore minimo accettato.
 */
void input_float(const char *prompt, float *dest, float min);

/**
 * @brief Acquisisce un identificativo da input utente.
 * @param prompt Messaggio da visualizzare.
 * @param dest Buffer destinazione per l'ID.
 * @param lunghezza Lunghezza massima dell'ID.
 */
void input_id(const char *prompt, char *dest, int_pos lunghezza);

// --- Funzioni stampa ---

/**
 * @brief Stampa il messaggio di uscita dal programma.
 */
void stampa_uscita();

/**
 * @brief Stampa i dettagli di una spedizione.
 * @param s Puntatore alla Spedizione da stampare.
 */
void stampa_spedizione(Spedizione *s);

/**
 * @brief Stampa tutte le spedizioni presenti nella coda.
 * @param coda Puntatore alla CodaSpedizione da stampare.
 */
void stampa_coda_spedizioni(CodaSpedizione *coda);

// --- Funzioni confronto ---

/**
 * @brief Confronta due spedizioni.
 * @param s1 Puntatore alla prima Spedizione.
 * @param s2 Puntatore alla seconda Spedizione.
 * @return 0 se uguali, valore diverso da 0 se diverse.
 */
int confronta_spedizioni(Spedizione *s1, Spedizione *s2);

/**
 * @brief Confronta due identificativi.
 * @param id1 Primo identificativo.
 * @param id2 Secondo identificativo.
 * @return 0 se uguali, valore diverso da 0 se diversi.
 */
int confronta_id(char *id1, char *id2);

// --- Funzioni gestione coda ---

/**
 * @brief Rimuove i duplicati dalla coda delle spedizioni.
 * @param coda Puntatore alla CodaSpedizione.
 * @return true se sono stati rimossi duplicati, false altrimenti.
 */
bool rimuovi_doppioni_coda(CodaSpedizione *coda);

/**
 * @brief Ordina la coda delle spedizioni.
 * @param originale Puntatore alla CodaSpedizione da ordinare.
 */
void ordinaCodaSpedizioni(CodaSpedizione *originale);

#endif // FUNZIONI_H