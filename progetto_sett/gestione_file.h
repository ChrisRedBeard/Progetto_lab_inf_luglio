/**
 * @file gestione_file.h
 * @brief Funzioni per la gestione delle spedizioni all'interno di un file binario.
 *
 * Questo header contiene le dichiarazioni delle funzioni per la scrittura, lettura,
 * modifica e ordinamento delle spedizioni salvate su file.
 */
#ifndef GESTIONE_FILE_H
#define GESTIONE_FILE_H

#include "dati.h"

#include <stdbool.h>

bool apri_file(char *nome_file, char* modo);

void chiudi_file();

bool salva_coda_su_file(CodaSpedizione *coda, char *nomeFile);
bool carica_coda_da_file(CodaSpedizione *coda, char *nomeFile);

char *trim_left(char *str);



#endif
