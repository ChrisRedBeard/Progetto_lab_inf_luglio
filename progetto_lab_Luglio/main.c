/*
    Progetto di laboratorio di informatica
    Autori: Barbarossa Christian Savino - 825007
            Di Santo Gabriele - 825303

    Descrizione: Progetto per la gestione di un sistema di spedizioni.

*/

#include "coda.h"
#include "spedizione.h"
#include "mittente.h"
#include "destinatario.h"
#include "pacco.h"
#include "utils.h"

int main()
{

    Coda coda;
    coda_init(&coda);

    int_pos scelta;
    // Stampa di benvenuto colorata
    printf("\n%sBenvenuto nel Gestore di Magazzino!\nSiamo lieti di avere il tuo supporto. Gestisci le tue spedizioni e il tuo inventario con facilità!\n\n%s", BLUE, RESET);

    while (scelta != 7)
    {
        puts("<----Scelta delle operazioni---->");
        puts("1. Stampa del file con le spedizioni");
        puts("2. Inserimento nuove spedizioni");
        puts("3. Elimina spedizione dal file");
        puts("4. Modifica dati spedizioni");
        puts("5. Ricerca spedizione per ID nel file");
        puts("7. Esci");
        printf("Inserisci: ");
        scanf("%hd", &scelta);

        switch (scelta)
        {
        case 1:
           
            stampa_file_spedizioni();
             /*ordina_file_id();
             printf("\nstampa ordinata:\n");
            stampa_file_spedizioni();
            */
            break;
        case 2:
        {
            puts("Inserimento nuove spedizioni");

            int_pos scelta_ins = 1;

            while (scelta_ins != 0)
            {
                inserimento_spedizione();
                printf("Inserisci 1 per inserire una nuova spedizione, 0 per uscire: ");
                scanf("%hd", &scelta_ins);
            }

            convalida_spedizioni(&coda);

            //order_by_date(); //ordina il file in BASE ALLA DATA
        }
        break;

        case 3:
        {
            // Funzione per eliminare una spedizione dal file
            char id[10];
            Spedizione trovata;

            input_string("Inserisci l'ID del pacco da eliminare: ", id, sizeof(id), 9);

            int pos = ricerca_spedizione_per_id(id, &trovata);
            if (pos != -1)
            {
            
                elimina_spedizione_in_file(pos); 
                printf("%sSpedizione con ID %s eliminata con successo!%s\n", GREEN, id, RESET);
            }
            else
            {
                printf("%sSpedizione non trovata.%s\n", RED, RESET);
            }
        }

        case 4:
        {
            // Funzione per modificare i dati delle spedizioni

            char id[10];
            int_pos scelta_modifica;
            Spedizione trovata;

            input_string("Inserisci l'ID del pacco da modificare: ", id, sizeof(id), 9);

            int pos = ricerca_spedizione_per_id(id, &trovata);
            if (pos != -1)
            {
                puts("Quali dati vuoi modificare?");
                puts("1. Stato");
                puts("2. Destinatario");
                puts("3. Data di consegna");
                scanf("%hd", &scelta_modifica);

                switch (scelta_modifica)
                {

                case 1:
                    modifica_stato_spedizione_in_file(pos, &trovata);
                    printf("%sStato della spedizione modificato con successo!%s\n", GREEN, RESET);
                    break;

                case 2:
                    modifica_destinatario_spedizione_in_file(pos, &trovata);
                    printf("%sDestinatario della spedizione modificato con successo!%s\n", GREEN, RESET);
                    break;
                case 3:
                    modifica_data_consegna_spedizione_in_file(pos, &trovata);
                    printf("%sData di consegna della spedizione modificata con successo!%s\n", GREEN, RESET);
                    break;
                default:
                    printf("%sScelta non valida, riprova.%s\n", YELLOW, RESET);
                    break;
                }
            }
            else
            {
                printf("%sSpedizione non trovata.%s\n", RED, RESET);
            }
        }
        break;
        case 5:
        {
            // Funzione per la ricerca nel file
            // ricerca per id pacco
            char id[10];
            Spedizione trovata;

            input_string("Inserisci l'ID del pacco da cercare: ", id, sizeof(id), 9);

            int pos = ricerca_spedizione_per_id(id, &trovata);
            if (pos != -1)
            {
                printf("%sSpedizione trovata!%s ID: %s\n", GREEN, RESET, trovata.p.n);
                stampa_spedizione(trovata);
            }
            else
            {
                printf("%sSpedizione non trovata.%s\n", RED, RESET);
            }
        }
        break;

        case 7:
            puts("Uscita dal programma...");
            return 0; // Esce dal programma
        default:
            printf("%sScelta non valida, riprova.%s\n", YELLOW, RESET);
        }
    }
    return 0;
}
