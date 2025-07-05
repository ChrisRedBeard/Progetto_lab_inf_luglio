/*
    Progetto di laboratorio di informatica
    Autori: Barbarossa Christian Savino - 825007
            Di Santo Gabriele - 825303
            Lorusso Marila - 827384

    Descrizione: Progetto per la gestione di un sistema di spedizioni.

*/

#include <stdio.h>
#include <stdlib.h>

#include "coda.h"
#include "spedizione.h"
#include "mittente.h"
#include "destinatario.h"
#include "pacco.h"

// Sequenze di escape ANSI per i colori
const char *RED = "\033[31m";    // Rosso
const char *GREEN = "\033[32m";  // Verde
const char *YELLOW = "\033[33m"; // Giallo
const char *RESET = "\033[0m";   // Reset del colore

int main()
{

    // Stampa di benvenuto colorata
    printf("%sBenvenuto nel Gestore di Magazzino!%s\n", GREEN, RESET);
    printf("%sSiamo lieti di avere il tuo supporto.%s\n", YELLOW, RESET);
    printf("%sGestisci le tue spedizioni e il tuo inventario con facilità!%s\n", RED, RESET);

    short int scelta;

    puts("Scelta delle operazioni");
    puts("1. Stampa del file con le spedizioni");
    puts("2. Inserimento nuove spedizioni"); // una volta inserita la spedizione, se il pacco è "ordinato" l'oggetto verrà messo in una coda, successivamente all'inserimento verrà convalidato e "spedito"
    puts("3. Modifica stato spedizioni");
    puts("4. Modifica dati spedizioni");
    puts("5. Ricerca nel file");
    puts("6. Stampa statistiche spedizioni");
    puts("7. Esci");
    scanf("%hd", &scelta);

    switch (scelta)
    {
    case 1:
        stampa_file_spedizioni(); // Funzione per stampare il file con le spedizioni
        puts("Stampa completata.");
        break;
    case 2:
        // Funzione per inserire nuove spedizioni
        /*
        Inserimento di una nuova spedizione:
        1. L'utente inserisce varie spedizioni finchè non decide di uscire.
        2. Dopo l'inserimento si passa alla convalida.
        3. Se il pacco è "ordinato", viene inserito in una coda.
            3.1 Si chiede all'utente se vuole convalidare il pacco.
            3.2 Se l'utente risponde "si", il pacco viene convalidato e lo stato viene cambiato in "spedito".
            3.3 Se l'utente risponde "no", il pacco rimane in stato "ordinato" e viene inserito nella coda (in coda).
        4. Se il pacco è in un qualsiasi altro stato, viene inserito nel file delle spedizioni.
        */

        puts("Inserimento nuove spedizioni");

        short int scelta_ins = 1;

        while (scelta_ins != 0)
        {
            Spedizione nuova_sped;
            puts("Inserisci i dati della spedizione: ");

            puts("ID Pacco [IT1234567]: ");
            scanf("%s", &nuova_sped.p.n);
            puts("Peso del pacco (in grammi): ");
            scanf("%f", &nuova_sped.p.peso);
            puts("Volume del pacco (in centimetri cubi): ");
            scanf("%f", &nuova_sped.p.volume);

            puts("Priorità (1 per alta, 0 per normale): ");
            scanf("%d", &nuova_sped.priorita);

            puts("Data di invio (formato: gg mm aaaa): ");
            scanf("%d %d %d", &nuova_sped.data_invio.tm_mday, &nuova_sped.data_invio.tm_mon, &nuova_sped.data_invio.tm_year);
            puts("Data di consegna prevista (formato: gg mm aaaa): ");
            scanf("%d %d %d", &nuova_sped.data_consegna.tm_mday, &nuova_sped.data_consegna.tm_mon, &nuova_sped.data_consegna.tm_year);
            
            puts("Dati del mittente: ");
            puts("Nome:");
            fflush(stdin); // Pulisce il buffer di input
            fgets(nuova_sped.mittente.nome, sizeof(nuova_sped.mittente.nome), stdin);
            puts("Cognome:");
            fflush(stdin);
            fgets(nuova_sped.mittente.cognome, sizeof(nuova_sped.mittente.cognome), stdin);

            puts("Numero di telefono [+00 123 456 7890]:");
            fflush(stdin);
            fgets(nuova_sped.mittente.telefono, sizeof(nuova_sped.mittente.telefono), stdin);
            puts("Indirizzo (via, num. civico):");
            fflush(stdin);
            fgets(nuova_sped.mittente.via, sizeof(nuova_sped.mittente.via), stdin);
            // Rimuovi il newline finale se necessario
            // nuova_sped.mittente.via[strcspn(nuova_sped.mittente.via, "\n")] = 0;
            puts("Città:");
            scanf(" %s", nuova_sped.mittente.citta);
            puts("Provincia [CC]:");
            scanf(" %s", nuova_sped.mittente.provincia);
            puts("CAP:");
            scanf(" %s", nuova_sped.mittente.cap);
            puts("Email:");
            scanf(" %s", nuova_sped.mittente.email);

            puts("Dati del destinatario: ");
            puts("Nome:");
            fflush(stdin);
            fgets(nuova_sped.destinatario.nome, sizeof(nuova_sped.mittente.nome), stdin);
            puts("Cognome:");
            fflush(stdin);
            fgets(nuova_sped.destinatario.cognome, sizeof(nuova_sped.mittente.cognome), stdin);
            puts("Numero di telefono [+00 123 456 7890]:");
            fflush(stdin);
            fgets(nuova_sped.destinatario.telefono, sizeof(nuova_sped.mittente.telefono), stdin);
            puts("Indirizzo (via, num. civico):");
            fflush(stdin);
            fgets(nuova_sped.destinatario.via, sizeof(nuova_sped.mittente.via), stdin);
            // Rimuovi il newline finale se necessario
            // nuova_sped.mittente.via[strcspn(nuova_sped.mittente.via, "\n")
            puts("Città:");
            scanf(" %s", nuova_sped.destinatario.citta);
            puts("Provincia [CC]:");
            scanf(" %s", nuova_sped.destinatario.provincia);
            puts("CAP:");
            scanf(" %s", nuova_sped.destinatario.cap);
            puts("Email:");
            scanf(" %s", nuova_sped.destinatario.email);

            puts("Inserire lo stato della spedizione(1 per ordinato, 2 per spedito, 3 per in consegna, 4 per consegnato, 5 per annullato): ");
            scanf("%d", &nuova_sped.stato);

            if (nuova_sped.stato == 1)
            {
                // Se il pacco è "ordinato", viene inserito in una coda
                printf("Pacco con ID %s inserito in coda.\n", nuova_sped.p.n);
                // Qui si dovrebbe chiamare la funzione enqueue per inserire il pacco nella coda
                // enqueue(&headPtr, &tailPtr, nuova_sped);
            }
            else
            {
                // Altrimenti, viene inserito nel file delle spedizioni
                inserimento_file_spedizioni(nuova_sped);
            }

            puts("Inserisci 1 per inserire una nuova spedizione, 0 per uscire: ");
            scanf("%hd", &scelta_ins);
        }

        break;
    case 3:
        // Funzione per modificare lo stato delle spedizioni
        break;
    case 4:
        // Funzione per modificare i dati delle spedizioni
        break;
    case 5:
        // Funzione per la ricerca nel file
        break;
    case 6:
        // Funzione per stampare le statistiche delle spedizioni
        break;
    case 7:
        puts("Uscita dal programma...");
        return 0; // Esce dal programma
    default:
        puts("Scelta non valida, riprova.");
    }

    return 0;
}
