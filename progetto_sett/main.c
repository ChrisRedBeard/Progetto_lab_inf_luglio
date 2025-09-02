#include <windows.h>
#include <stdio.h>

#include "dati.h"
#include "controlli.h"
#include "funzioni.h"
#include "gestione_file.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    CodaSpedizione coda;
    initCoda(&coda);
    /*


        Spedizione nuovaSped;

        inserimento_spedizione(&nuovaSped);

        printf("\nStampa\n");
        stampa_spedizione(nuovaSped);
        getchar();

        enqueue(&coda, nuovaSped);
        */

    int_pos scelta=0;

    printf("\n%sBenvenuto nel Gestore di Magazzino!\nSiamo lieti di avere il tuo supporto. Gestisci le tue spedizioni e il tuo inventario con facilità!\n\n%s", BLUE, RESET);

    do
    {

        printf("\n--- MENU SPEDIZIONI ---\n");
        printf("1. Inserisci spedizione\n");
        printf("2. Stampa spedizioni\n");
        printf("3. Elimina spedizione\n");
        printf("4. Modifica spedizione\n");
        printf("5. Salva su file\n");
        printf("6. Carica da file\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        // Leggi input sicuro
        char buffer[20];  // buffer sicuro
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            char *endptr;
            scelta = strtol(buffer, &endptr, 10); // converte in int

            if (endptr == buffer || *endptr != '\n' && *endptr != '\0') {
                printf("Input non valido! Riprova.\n");
                scelta = -1;
                continue;
            }
        }
        char id[10];

        switch (scelta)
        {
        case 1:
        {
            Spedizione nuovaSped;
            inserimento_spedizione(&nuovaSped);
            
            enqueue(&coda, nuovaSped);
          
            printf("Spedizione inserita!\nSTAMPA CODA DIOPORCO!");
           // stampa_spedizione(*nuovaSped);

           stampa_coda_spedizioni(&coda);
            break;
        }
        case 2:
        {
            stampa_coda_spedizioni(&coda);
            break;
        }
        case 3:
        {
            puts("Inserisci l'ID della spedizione da eliminare");
            input_id("ID[012345678]: ", id, 9);
            elimina_spedizione(&coda, id);
            break;
        }
        case 4:
        {
            //modifica_spedizione(&coda);
            break;
        }
        case 5:
        {
            // salva_coda_su_file(&coda, "spedizioni.txt");
            printf("Coda salvata su file!\n");
            break;
        }
        case 6:{
            //carica_coda_da_file(&coda, "spedizioni.txt");
            puts("Coda caricata da file!");
            break;
        }
        case 0:
        {
            puts("Uscita...");
            break;
        }
        default:
            puts("Scelta non valida!");
        }

    } while (scelta != 0);

    return 0;
}
