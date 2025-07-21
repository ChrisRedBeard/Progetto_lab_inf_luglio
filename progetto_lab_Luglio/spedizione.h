
#ifndef SPEDIZIONE_H
#define SPEDIZIONE_H

#include "pacco.h"
#include "mittente.h"
#include "destinatario.h"

#include <time.h>
#include <stdbool.h>

enum Stati
{
    ordinato = 1,
    spedito,
    in_consegna,
    consegnato,
    annullato
};

typedef struct
{
    Pacco p;
    bool priorita;           // true se il pacco ha priorità, false altrimenti
    struct tm data_invio;    // data di invio del pacco
    struct tm data_consegna; // data di consegna prevista del pacco
    Mittente mittente;
    Destinatario destinatario;
    enum Stati stato;
} Spedizione;

void inserimento_data(const char *prompt, struct tm *data);
//void inserimento_spedizione(Coda *c);
bool controllo_date(struct tm data_invio, struct tm data_consegna);

void stampa_spedizione(Spedizione s);
 
int confronta_id(const void* id1, const void* id2);

#endif // SPEDIZIONE_H
