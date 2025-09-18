#include <windows.h>
#include <stdio.h>

#include "dati.h"
#include "controlli.h"
#include "funzioni.h"
#include "gestione_file.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    char *nomeFile = "spedizioni.txt";
    int_pos scelta = 0;
    CodaSpedizione coda;

    initCoda(coda);

    printf("\n%sBenvenuto nel Gestore di Magazzino!\nSiamo lieti di avere il tuo supporto. Gestisci le tue spedizioni e il tuo inventario con facilità!\n%s", BLUE, RESET);

    do
    {
        printf("\n--- MENU SPEDIZIONI ---\n");
        printf("1. Inserisci spedizione\n");
        printf("2. Stampa spedizioni\n");
        printf("3. Elimina spedizione\n");
        printf("4. Modifica spedizione\n");
        printf("5. Salva su file\n");
        printf("6. Carica da file\n");
        printf("7. Ordina coda spedizioni\n");
        printf("0. Esci\n");
        printf("Scelta: ");

        scanf("%hu", &scelta);

        switch (scelta)
        {
        case 1:
        {
            Spedizione nuovaSped;
            initSpedizione(nuovaSped);
            inserimento_spedizione(nuovaSped);

            enqueue(coda, nuovaSped);
            rimuovi_doppioni_coda(coda);
            
            printf("%sSpedizione inserita!%s\n", GREEN, RESET);

            break;
        }
        case 2:
        {
            stampa_coda_spedizioni(coda);
            break;
        }
        case 3:
        {
            elimina_spedizione(coda);
            break;
        }
        case 4:
        {
            modifica_spedizione(coda);
            break;
        }
        case 5:
        {
            if (salva_coda_su_file(coda, nomeFile))
                printf("%sCoda salvata su file con successo!%s\n", GREEN, RESET);
            else
                printf("%sErrore nel salvataggio su file!%s\n", RED, RESET);

            break;
        }
        case 6:
        {
            if (carica_coda_da_file(coda, nomeFile))
                printf("%sCoda caricata da file con successo!%s\n", GREEN, RESET);
            else
                printf("%sErrore nel caricamento da file!%s\n", RED, RESET);

            break;
        }
        case 7:
        {
            ordinaCodaSpedizioni(coda);
            break;
        }
        case 0:
        {
            stampa_uscita();
            break;
        }
        default:
            puts("Scelta non valida!");
        }

    } while (scelta != 0);

    return 0;
}
