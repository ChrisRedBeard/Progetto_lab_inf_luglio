/**
 * @file destinatario.h
 * @brief Definizione della struttura e delle funzioni relative al destinatario.
 *
 * Questo header definisce la struttura `Destinatario` che rappresenta le informazioni
 * anagrafiche e di contatto del destinatario di una spedizione, oltre alle funzioni
 * per l'inserimento e la stampa dei dati.
 */


#ifndef DESTINATARIO_H
#define DESTINATARIO_H

/**
 * @struct Destinatario
 * @brief Definisce la struttura Destinatario con  le relative informazioni per una spedizione.
 */
typedef struct
{
    char nome[30];
    char cognome[30];
    char telefono[17]; // formato: +39 123 456 7890, ho modificato la lunghezza a 17 per il formato
    char via[100];     // Indirizzo (via, numero civico, ecc.)
    char citta[50];    // Città
    char provincia[3]; // Provincia
    char cap[6];       // CAP
    char email[50];    // e-mail

} Destinatario;


void set_destinatario();

Destinatario get_destinatario();
/**
 * @brief Permette l'inserimento dei dati del destinatario tramite input da tastiera.
 * @param d Puntatore alla struttura Destinatario da riempire.
 */
void inserimento_destinatario(Destinatario *d);

/**
 * @brief Stampa a video le informazioni del destinatario.
 * @param d Struttura Destinatario da stampare.
 */
void stampa_destinatario(Destinatario d);

#endif // DESTINATARIO_H
