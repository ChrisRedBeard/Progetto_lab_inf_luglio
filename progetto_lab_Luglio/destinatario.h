#ifndef DESTINATARIO_H
#define DESTINATARIO_H

typedef struct 
{
    char nome[30];
    char cognome[30];
    char telefono[17]; // formato: +39 123 456 7890, ho modificato la lunghezza a 17 per il formato  
    char via[100];     // Indirizzo (via, numero civico, ecc.)
    char citta[50];    // Città
    char provincia[3]; // Provincia
    char cap[6];       // CAP
    char email[50];    // e-mail

} Destinatario; 

void stampa_destinatario(Destinatario d);


void modifica_indirizzo(Destinatario *d);

//controllare prima se il pacco sia stato spedito o meno
void modifica_destinatario(Destinatario dest);


#endif // DESTINATARIO_H
