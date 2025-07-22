
/**
 * @file destinatario.c
 * @brief Implementazione delle funzioni relative alla gestione del destinatario.
 *
 * Questo file contiene le funzioni per l'inserimento e la stampa delle informazioni
 * del destinatario di una spedizione.
 */

#include "utils.h"
#include "destinatario.h"

/**
 * @brief Inserisce i dati del destinatario tramite input da tastiera.
 *
 * I dati inseriti includono:
 * - Nome
 * - Cognome
 * - Numero di telefono (formato: +00 123 456 7890)
 * - Email
 * - Indirizzo (via e numero civico)
 * - Città
 * - Provincia (sigla di 2 lettere)
 * - CAP (Codice di Avviamento Postale)
 *
 * @param d Puntatore alla struttura Destinatario da compilare.
 */
void inserimento_destinatario(Destinatario *d)
{
    input_string("Nome: ", d->nome, sizeof(d->nome), 29);
    input_string("Cognome: ", d->cognome, sizeof(d->cognome), 29);
    input_string("Numero di telefono [+00 123 456 7890]: ", d->telefono, sizeof(d->telefono), 16);
    input_string("Email: ", d->email, sizeof(d->email), 49);
    input_string("Indirizzo [via, num. civico]: ", d->via, sizeof(d->via), 99);
    input_string("Città: ", d->citta, sizeof(d->citta), 49);
    input_string("Provincia [CC]: ", d->provincia, sizeof(d->provincia), 2);
    input_string("CAP: ", d->cap, sizeof(d->cap), 5);
}

/**
 * @brief Stampa le informazioni del destinatario sul terminale.
 *
 * Le informazioni stampate includono:
 * - Nome e Cognome
 * - Telefono ed Email
 * - Indirizzo completo, città, provincia e CAP
 *
 * @param d Struttura Destinatario da stampare.
 */
void stampa_destinatario(Destinatario d)
{
    printf("%sMittente%s: %s %s \n", WHITE,RESET,d.nome, d.cognome);
    printf("%sTelefono%s: %16s, ",WHITE ,RESET,d.telefono);
    printf("%sEmail%s: %s\n",WHITE,RESET,d.email);
    printf("%sIndirizzo%s: %s, ",WHITE,RESET,d.via);
    printf("%sCittà%s: %s, ",WHITE,RESET, d.citta);
    printf("%sProvincia%s: %2s, ",WHITE,RESET,d.provincia);
    printf("%sCAP%s: %5s\n",WHITE,RESET,d.cap);
}
