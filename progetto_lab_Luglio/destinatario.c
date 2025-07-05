
#include "destinatario.h"
#include <stdio.h>
#include <string.h>

// gli passo il puntatore per modificare direttamente l'indirizzo del destinatario
void modifica_indirizzo(Destinatario *d){
 printf("\n Inserisci il nuovo indirizzo del destinatario\n");
 printf("Inserire via: ");
 scanf("%100s", d->via);
 printf("Inserire città: ");
 scanf("%50s", d->citta);
 printf("Inserire provincia: ");
 scanf("%2s", d->provincia);
 printf("Inserire CAP: ");
 scanf("%5s", d->cap);
}

void stampa_destinatario(Destinatario d) {
    printf("Destinatario:\n");
    printf("Nome: %s\n", d.nome);
    printf("Cognome: %s\n", d.cognome);
    printf("Telefono: %16s\n", d.telefono);
    printf("Via: %s\n", d.via);
    printf("Città: %s\n", d.citta);
    printf("Provincia: %2s\n", d.provincia);
    printf("CAP: %5s\n", d.cap);
    printf("Email: %s\n", d.email);
}


//controllare prima se il pacco sia stato spedito o meno
void modifica_destinatario(Destinatario dest);
