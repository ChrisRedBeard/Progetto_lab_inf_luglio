/**
 *
 *@file mittente.h
 *
 *@brief Dichiarazioni relative alla gestione del mittente di una spedizione.
 *
 *Questo file contiene la definizione della struttura Mittente e le dichiarazioni
 *
 *delle funzioni per l'inserimento e la stampa dei dati del mittente.
 */
#ifndef MITTENTE_H
#define MITTENTE_H

/**
 * @struct Mittente
 * @brief Definisce la struttura Mittente con  le relative informazioni per una spedizione.
 *
 * Contiene tutte le informazioni necessarie per identificare e contattare il mittente
 * di una spedizione, inclusi nome, cognome, contatti e indirizzo.
 */
typedef struct
{
    char nome[30];
    char cognome[30];
    char telefono[17]; // formato: +39 123 456 7890
    char via[100];     // Indirizzo (via, numero civico, ecc.)
    char citta[50];    // Città
    char provincia[3]; // Provincia (2 chars + null terminator)
    char cap[6];       // CAP (5 chars + null terminator)
    char email[50];    // e-mail

} Mittente;

/**
 * @brief Permette l'inserimento dei dati del mittente.
 *
 * Chiede all'utente di inserire i campi della struttura Mittente,
 * uno alla volta, con controlli sulla lunghezza.
 *
 * @param[out] m Puntatore alla struttura Mittente da riempire.
 */
void inserimento_mittente(Mittente *m);


/**
 * @brief Stampa a video le informazioni del mittente.
 *
 * Visualizza su stdout i dati contenuti in una struttura Mittente in formato leggibile.
 *
 * @param[in] m Mittente da stampare.
 */
void stampa_mittente(Mittente m);

#endif // MITTENTE_H
