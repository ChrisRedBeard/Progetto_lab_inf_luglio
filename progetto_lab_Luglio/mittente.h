#ifndef MITTENTE_H
#define MITTENTE_H

typedef struct
{
    char nome[30];
    char cognome[30];
    char telefono[17]; // formato: +39 123 456 7890
    char via[100];     // Indirizzo (via, numero civico, ecc.)
    char citta[50];    // Città
    char provincia[3]; // Provincia (2 chars + null terminator)
    char cap[6];       // CAP (5 chars + null terminator)
    char email[50];    // e-mail

} Mittente;

void inserimento_mittente(Mittente *m);
void stampa_mittente(Mittente m);

#endif // MITTENTE_H
