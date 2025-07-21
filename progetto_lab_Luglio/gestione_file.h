
#ifndef GESTIONE_FILE_H
#define GESTIONE_FILE_H


#include <stdio.h>
#include "spedizione.h"


void inserimento_file_spedizioni(Spedizione s);
void stampa_file_spedizioni();
void modifica_destinatario_spedizione_in_file(int pos, Spedizione *s_mod);
void modifica_data_consegna_spedizione_in_file(int pos, Spedizione *s_mod);
int ricerca_spedizione_per_id(const char *id_pacco, Spedizione *result);
void elimina_spedizione_in_file(int pos);
void modifica_stato_spedizione_in_file(int pos, Spedizione *s_mod);
void ordina_file_id();


#endif