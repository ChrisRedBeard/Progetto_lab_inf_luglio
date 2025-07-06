/*
    Progetto di laboratorio di informatica
    Autori: Barbarossa Christian Savino - 825007
            Di Santo Gabriele - 825303
            Lorusso Marila - 827384

    Descrizione: Progetto per la gestione di un sistema di spedizioni.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    short int scelta;
    // Stampa di benvenuto colorata
    printf("%sBenvenuto nel Gestore di Magazzino!%s\n", GREEN, RESET);
    printf("%sSiamo lieti di avere il tuo supporto.%s\n", YELLOW, RESET);
    printf("%sGestisci le tue spedizioni e il tuo inventario con facilità!%s\n", RED, RESET);

    while (scelta != 7)
    {
        puts("<----Scelta delle operazioni---->");
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
            puts("\n<----Stampa completata---->\n");
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
                inserimento_spedizione();
                puts("Inserisci 1 per inserire una nuova spedizione, 0 per uscire: ");
                scanf("%hd", &scelta_ins);
            }

            break;
        case 3:
        { // Funzione per modificare lo stato delle spedizioni
            // ricerca per id pacco
            char id[10];
            Spedizione trovata;
            printf("Inserisci l'ID del pacco da modificare lo stato: ");
            scanf("%s", id);
            int pos = ricerca_spedizione_per_id(id, &trovata);
            if (pos != -1)
            {
                modifica_stato_spedizione_in_file(pos, &trovata);
                puts("Stato della spedizione modificato con successo!");
            }
            else
            {
                puts("Spedizione non trovata.");
            }
        }
        break;
        case 4:
            // Funzione per modificare i dati delle spedizioni
            break;
        case 5:
        {
            // Funzione per la ricerca nel file
            // ricerca per id pacco
            char id[10];
            Spedizione trovata;
            printf("Inserisci l'ID del pacco da cercare: ");
            scanf("%s", id);
            int pos = ricerca_spedizione_per_id(id, &trovata);
            if (pos != -1)
            {
                printf("Spedizione trovata! ID: %s\n", trovata.p.n);
                stampa_spedizione(trovata);
            }
            else
            {
                puts("Spedizione non trovata.");
            }
        }
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
    }
    return 0;
}
