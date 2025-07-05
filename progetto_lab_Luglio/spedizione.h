
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

void stampa_file_spedizioni();
void inserimento_spedizione(Spedizione s);
void inserimento_file_spedizioni(Spedizione s);

#endif // SPEDIZIONE_H

