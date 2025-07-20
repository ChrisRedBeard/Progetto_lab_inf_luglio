
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

bool verifica_data(struct tm data);
void inserimento_spedizione();
bool controllo_date(struct tm data_invio, struct tm data_consegna);
void inserimento_file_spedizioni(Spedizione s);
void stampa_spedizione(Spedizione s);
void stampa_file_spedizioni();
void modifica_destinatario_spedizione_in_file(int pos, Spedizione *s_mod);
void modifica_data_consegna_spedizione_in_file(int pos, Spedizione *s_mod);
void modifica_stato_spedizione_in_file(int pos, Spedizione *s_mod);
int ricerca_spedizione_per_id(const char *id_pacco, Spedizione *result);
int compare_spedizioni(struct tm a, struct tm b);
void order_by_date();

//TODO Elimina spedizione da file tramite id
void elimina_spedizione_in_file();

#endif // SPEDIZIONE_H
