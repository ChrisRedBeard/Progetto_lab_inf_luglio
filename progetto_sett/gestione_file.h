
/**
 * @file gestione_file.h
 * @brief Funzioni per la gestione delle spedizioni all'interno di un file di testo.
 *
 * Questo header contiene le dichiarazioni delle funzioni per la scrittura , lettura,
 * apertura e chiusura di file contenenti spedizioni.
 */

#ifndef GESTIONE_FILE_H
#define GESTIONE_FILE_H

#include "dati.h"
#include <stdbool.h>

/**
 * @brief Apre un file con il nome e il modo specificato.
 * @param nome_file Nome del file.
 * @param modo Modalità di apertura (es. "r", "w", "a").
 * @return true se il file è stato aperto con successo, false altrimenti.
 */
bool apri_file(char *nome_file, char *modo);

/**
 * @brief Chiude il file attualmente aperto.
 */

void chiudi_file();

/**
 * @brief Salva la coda di spedizioni su un file di testo.
 * Ogni campo è separato da punto e virgola ';'. I dati vengono scritti in formato leggibile.
 * @param coda Puntatore alla coda delle spedizioni.
 * @param nomeFile Nome del file su cui salvare.
 * @return true se il salvataggio è avvenuto con successo, false altrimenti.
 */
bool salva_coda_su_file(CodaSpedizione coda, char *nomeFile);

/**
 * @brief Carica la coda delle spedizioni da file.
 * I dati vengono letti riga per riga e convertiti in strutture `Spedizione`.
 * @param coda Puntatore alla coda delle spedizioni.
 * @param nomeFile Nome del file da cui caricare.
 * @return true se il caricamento è avvenuto con successo, false altrimenti.
 */
bool carica_coda_da_file(CodaSpedizione coda, char *nomeFile);

/**
 * @brief Rimuove gli spazi e tabulazioni a sinistra da una stringa.
 * @param str Stringa da elaborare.
 * @return Puntatore alla stringa senza spazi iniziali.
 */
char *trim_left(char *str);

#endif
