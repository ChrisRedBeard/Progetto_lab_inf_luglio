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
 * @typedef int_pos
 * @brief Tipo definito per rappresentare posizioni o dimensioni intere positive.
 */
typedef unsigned short int int_pos;

/**
 * @brief Legge da input una stringa con lunghezza massima specificata.
 *
 * La funzione richiede all'utente di inserire una stringa tramite stdin.
 * L'input viene accettato solo se la stringa è non vuota e non supera la lunghezza massima.
 * Rimuove il carattere di newline se presente.
 * In caso di errore nella lettura o di input non valido, viene richiesto di riprovare.
 *
 * @param prompt Messaggio mostrato all'utente per richiedere l'input.
 * @param dest Buffer dove salvare la stringa inserita.
 * @param size Dimensione massima del buffer (incluso terminatore nullo).
 * @param lunghezza Lunghezza massima accettabile per la stringa (escluso terminatore nullo).
 */
void input_string(const char *prompt, char *dest, int_pos lunghezza);

/**
 * @brief Legge da input un numero in virgola mobile (float) con valore minimo.
 *
 * La funzione richiede all'utente di inserire un valore float tramite stdin.
 * Viene controllato che il valore inserito sia valido e maggiore o uguale al minimo indicato.
 * Se l'input è non valido o minore del minimo, viene chiesto di riprovare.
 *
 * @param prompt Messaggio mostrato all'utente per richiedere l'input.
 * @param dest Puntatore alla variabile float dove salvare il valore inserito.
 * @param min Valore minimo accettabile (incluso).
 */
void input_float(const char *prompt, float *dest, float min);

/**
 * @brief Legge da input uno specifico ID con lunghezza fissa.
 *
 * Questa funzione richiede all'utente di inserire una stringa tramite stdin.
 * L'input viene accettato solo se la stringa ha esattamente la lunghezza richiesta,
 * altrimenti viene chiesta nuovamente.
 * Rimuove il carattere di newline se presente.
 *
 * @param prompt Messaggio mostrato all'utente per richiedere l'input.
 * @param dest Buffer dove salvare la stringa inserita dall'utente.
 * @param size Dimensione massima del buffer (incluso terminatore nullo).
 * @param lunghezza Lunghezza esatta richiesta per l'ID (escluso terminatore nullo).
 */
void input_id(const char *prompt, char *dest, int_pos lunghezza);

/**
 * @brief Stampa un messaggio di uscita con animazione.
 */
void stampa_uscita();

/**
 * @brief Rimuove i nodi duplicati dalla coda in base al campo numID.
 *
 * Questa funzione scorre la coda di spedizioni e elimina tutti i nodi
 * che hanno un campo `sped.n` (numID) già incontrato in precedenza.
 *
 * @param[in,out] coda Puntatore alla coda di spedizioni da elaborare.
 * @return void
 */
bool rimuovi_doppioni_coda(CodaSpedizione coda);

/**
 * @brief Funzione di confronto tra due spedizioni.
 *
 * Utilizzata per ordinare le spedizioni in base a criteri multipli:
 * - priorità (true prima di false)
 * - data di consegna (più vicina prima)
 * - peso (più leggero prima)
 *
 * @param a Puntatore al primo elemento (Spedizione).
 * @param b Puntatore al secondo elemento (Spedizione).
 * @return Valore negativo se a < b, positivo se a > b, 0 se uguali.
 */
int confronta_spedizioni(Spedizione s1, Spedizione s2);

/**
 * @brief Inserisce una spedizione in una coda mantenendo l'ordine.
 *
 * La spedizione viene inserita nella posizione corretta all'interno della coda
 * in base alla funzione di confronto `confronta_spedizioni`.
 *
 * @param ordinata Puntatore alla coda ordinata.
 * @param nuova La spedizione da inserire.
 */
void inserisciOrdinato(CodaSpedizione ordinata, Spedizione nuova);

/**
 * @brief Ordina una coda di spedizioni secondo la priorità e la data di invio.
 *
 * Estrae tutte le spedizioni dalla coda originale, le ordina e le reinserisce
 * in ordine nella stessa coda.
 *
 * @param originale Puntatore alla coda da ordinare.
 */
void ordinaCodaSpedizioni(CodaSpedizione originale);

/**
 * @brief Confronta ID di due spedizioni (funzione di confronto per qsort).
 *
 * @param id1 Puntatore al primo elemento (stringa).
 * @param id2 Puntatore al secondo elemento (stringa).
 * @return Valore negativo, zero o positivo se id1 è minore, uguale o maggiore di id2.
 */
int confronta_id(char* stringa1, char* stringa2);

/**
 * @brief Stampa i dati completi di una spedizione.
 *
 * @param s La spedizione da stampare.
 */
void stampa_spedizione(Spedizione s);


void stampa_Persona(Persona d);

/**
 * @brief Stampa tutte le spedizioni presenti nella coda.
 *
 * Visualizza su stdout le informazioni di ogni spedizione contenuta nella coda,
 * in ordine FIFO (First-In, First-Out).
 *
 * @param coda Puntatore alla coda da stampare.
 */
void stampa_coda_spedizioni(CodaSpedizione coda);

#endif
