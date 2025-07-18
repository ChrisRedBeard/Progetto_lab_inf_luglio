#include "utils.h"
#include "destinatario.h"

#include <stdio.h>
#include <string.h>

void inserimento_destinatario(Destinatario *d)
{
    input_string("Nome: ", d->nome, sizeof(d->nome));
    input_string("Cognome: ", d->cognome, sizeof(d->cognome));
    input_string("Numero di telefono [+00 123 456 7890]: ", d->telefono, sizeof(d->telefono));
    input_string("Email: ", d->email, sizeof(d->email));
    input_string("Indirizzo [via, num. civico]: ", d->via, sizeof(d->via));
    input_string("Città: ", d->citta, sizeof(d->citta));
    input_string("Provincia [CC]: ", d->provincia, sizeof(d->provincia));
    input_string("CAP: ", d->cap, sizeof(d->cap));
}

void stampa_destinatario(Destinatario d) {
    printf("Destinatario: %s %s \n",d.nome, d.cognome);
    printf("Telefono: %16s, Email: %s \n", d.telefono, d.email);
    printf("Indirizzo: %s, Città: %s, Provincia: %2s, CAP: %5s\n", d.via, d.citta, d.provincia, d.cap);
}

