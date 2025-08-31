/**
 * @file gestione_file.h
 * @brief Funzioni per la gestione delle spedizioni all'interno di un file binario.
 *
 * Questo header contiene le dichiarazioni delle funzioni per la scrittura, lettura,
 * modifica e ordinamento delle spedizioni salvate su file.
 */
#ifndef GESTIONE_FILE_H
#define GESTIONE_FILE_H


#include <stdio.h>
#include "dati.h"
#include "controlli.h"

/**
 * @brief Inserisce una spedizione nel file delle spedizioni.
 *
 * @param s La struttura Spedizione da salvare.
 */
void inserimento_file_spedizioni(Spedizione s);

/**
 * @brief Stampa tutte le spedizioni presenti nel file.
 */
void stampa_file_spedizioni();

/**
 * @brief Modifica i dati del destinatario di una spedizione specifica nel file.
 *
 * @param pos Posizione (indice) della spedizione da modificare.
 * @param s_mod Puntatore alla nuova spedizione con i dati aggiornati.
 */
void modifica_destinatario_spedizione_in_file(int pos, Spedizione *s_mod);

/**
 * @brief Modifica la data di consegna prevista di una spedizione nel file.
 *
 * @param pos Posizione (indice) della spedizione da aggiornare.
 * @param s_mod Puntatore alla spedizione modificata.
 */
void modifica_data_consegna_spedizione_in_file(int pos, Spedizione *s_mod);

/**
 * @brief Cerca una spedizione nel file a partire dal suo ID pacco.
 *
 * @param id_pacco ID del pacco da cercare.
 * @param result Puntatore dove salvare la spedizione trovata.
 * @return La posizione della spedizione nel file se trovata, -1 altrimenti.
 */
int ricerca_spedizione_per_id(const char *id_pacco, Spedizione *result);

/**
 * @brief Elimina una spedizione dal file, sovrascrivendola o rimuovendola logicamente.
 *
 * @param pos Posizione (indice) della spedizione da eliminare.
 */
void elimina_spedizione_in_file(int pos);

/**
 * @brief Modifica lo stato di una spedizione nel file.
 *
 * @param pos Posizione (indice) della spedizione da aggiornare.
 * @param s_mod Puntatore alla spedizione modificata.
 */
void modifica_stato_spedizione_in_file(int pos, Spedizione *s_mod);

/**
 * @brief Ordina le spedizioni presenti nel file in base all'ID del pacco.
 */
void ordina_file_id();


#endif
