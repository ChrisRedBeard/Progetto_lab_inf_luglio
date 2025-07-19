#include "mittente.h"
#include "utils.h"

#include <stdio.h>

void inserimento_mittente(Mittente *m)
{
    input_string("Nome: ", m->nome, sizeof(m->nome), 29);
    input_string("Cognome: ", m->cognome, sizeof(m->cognome), 29);
    input_string("Numero di telefono [+00 123 456 7890]: ", m->telefono, sizeof(m->telefono), 16);
    input_string("Email: ", m->email, sizeof(m->email), 49);
    input_string("Indirizzo [via, num. civico]: ", m->via, sizeof(m->via), 99);
    input_string("Città: ", m->citta, sizeof(m->citta), 49);
    input_string("Provincia [CC]: ", m->provincia, sizeof(m->provincia), 2);
    input_string("CAP: ", m->cap, sizeof(m->cap), 5);
}

void stampa_mittente(Mittente m)
{
    printf("Mittente: %s %s \n", m.nome, m.cognome);
    printf("Telefono: %16s, Email: %s \n", m.telefono, m.email);
    printf("Indirizzo: %s, Città: %s, Provincia: %2s, CAP: %5s\n", m.via, m.citta, m.provincia, m.cap);
}
