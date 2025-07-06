
#ifndef SPEDIZIONE_H
#define SPEDIZIONE_H

#include "pacco.h"
#include "mittente.h"
#include "destinatario.h"
#include <time.h>
#include <stdbool.h>

enum Stati {ordinato = 1, spedito, in_consegna, consegnato, annullato};

typedef struct 
{ 
    Pacco p; 
    bool priorita; // true se il pacco ha priorità, false altrimenti 
    struct tm data_invio; // data di invio del pacco 
    struct tm data_consegna; // data di consegna prevista del pacco 
    Mittente mittente; 
    Destinatario destinatario; 
    enum Stati stato; 
} Spedizione;

void input_string(const char *prompt, char *dest, size_t size);
void inserimento_spedizione();
void inserimento_file_spedizioni(Spedizione s);
void stampa_spedizione(Spedizione s);
void stampa_file_spedizioni();
void mod_stato_sped(Spedizione *s);
int ricerca_spedizione_per_id(const char *id_pacco, Spedizione *result);
void modifica_stato_spedizione_in_file(int pos, Spedizione *s_mod);

#endif // SPEDIZIONE_H

