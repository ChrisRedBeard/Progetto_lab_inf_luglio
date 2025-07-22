
/**
 * @file mittente.c
 *
 * @brief Implementazione delle funzioni relative alla struttura Mittente.
 * Questo file contiene le definizioni delle funzioni per inserire e stampare le informazioni del mittente.
 *
 */

#include "mittente.h"
#include "utils.h"


/**
 * @brief Inserisce i dati del mittente.
 *
 * Richiede all'utente l'inserimento di nome, cognome, telefono, email,
 * indirizzo, città, provincia e CAP. Ogni campo viene acquisito tramite `input_string`.
 *
 * @param[out] m Puntatore alla struttura Mittente da riempire.
 */
void inserimento_mittente(Mittente *m)
{
    input_string("Nome: ", m->nome, sizeof(m->nome), 29);
    input_string("Cognome: ", m->cognome, sizeof(m->cognome), 29);
    input_string("Numero di telefono [+00 123 456 7890]: ", m->telefono, sizeof(m->telefono), 16);
    input_string("Email: ", m->email, sizeof(m->email), 49);
    input_string("Indirizzo [via, num. civico]: ", m->via, sizeof(m->via), 99);
    input_string("Città: ", m->citta, sizeof(m->citta), 49);
    input_string("Provincia [CC]: ", m->provincia, sizeof(m->provincia), 2);
    input_string("CAP: ", m->cap, sizeof(m->cap), 5);
}

/**
 * @brief Stampa i dati del mittente.
 *
 * Visualizza su schermo le informazioni contenute nella struttura `Mittente`.
 *
 * @param[in] m Struttura Mittente di cui stampare i dati.
 */
void stampa_mittente(Mittente m)
{
    printf("%sMittente%s: %s %s \n", WHITE,RESET,m.nome, m.cognome);
    printf("%sTelefono%s: %16s, ",WHITE ,RESET,m.telefono);
    printf("%sEmail%s: %s\n",WHITE,RESET,m.email);
    printf("%sIndirizzo%s: %s, ", WHITE,RESET,m.via);
    printf("%sCittà%s: %s, ",WHITE,RESET, m.citta);
    printf("%sProvincia%s: %2s, ",WHITE,RESET,m.provincia);
    printf("%sCAP%s: %5s\n",WHITE,RESET,m.cap);
}
