#include "spedizione.h"
#include "coda.h"
#include "destinatario.h"
#include "mittente.h"
#include "utils.h"
#include "pacco.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// inizializzo la coda vuota
QueueNodePtr headPtr = NULL; /* initialize headPtr */
QueueNodePtr tailPtr = NULL; /* initialize tailPtr */ 
 
bool verifica_data(struct tm data)
{
    // Verifica che la data sia valida
    if (data.tm_year < 1900 || data.tm_mon < 1 || data.tm_mon > 12 || data.tm_mday < 1 || data.tm_mday > 31)
    {
        return false;
    }
    // Aggiungere ulteriori controlli per i giorni del mese, considerando gli anni bisestili, ecc.
    return true;
}

void inserimento_spedizione()
{
    Spedizione nuova_sped = {0};

    puts("Inserisci i dati della spedizione:");

    inserimento_pacco(&nuova_sped.p);

    printf("Priorità (1 per alta, 0 per normale): ");
    if (scanf("%d", &nuova_sped.priorita) != 1 || (nuova_sped.priorita != 0 && nuova_sped.priorita != 1))
    {
        puts("Priorità non valida.");
        while (getchar() != '\n')
            ;
        return;
    }

    do
    {

        printf("Data di invio (formato: gg mm aaaa): ");
        if (scanf("%d %d %d", &nuova_sped.data_invio.tm_mday, &nuova_sped.data_invio.tm_mon, &nuova_sped.data_invio.tm_year) != 3 || !verifica_data(nuova_sped.data_invio))
        {
            puts("Data di invio non valida.");
            while (getchar() != '\n')
                ;
            return;
        }

        printf("Data di consegna prevista (formato: gg mm aaaa): ");
        if (scanf("%d %d %d", &nuova_sped.data_consegna.tm_mday, &nuova_sped.data_consegna.tm_mon, &nuova_sped.data_consegna.tm_year) != 3 || !verifica_data(nuova_sped.data_consegna))
        {
            puts("Data di consegna non valida.");
            while (getchar() != '\n');
            return;
        }

    } while (controllo_date(nuova_sped.data_invio, nuova_sped.data_consegna) == false);

    while (getchar() != '\n')
        ; // Pulisci il buffer

    puts("Dati del mittente:");
    inserimento_mittente(&nuova_sped.mittente);

    puts("Dati del destinatario:");
    inserimento_destinatario(&nuova_sped.destinatario);

    puts("Inserire lo stato della spedizione (1 per ordinato, 2 per spedito, 3 per in consegna, 4 per consegnato, 5 per annullato): ");
    if (scanf("%d", &nuova_sped.stato) != 1 || nuova_sped.stato < 1 || nuova_sped.stato > 5)
    {
        puts("Stato non valido.");
        while (getchar() != '\n')
            ;
        return;
    }
    while (getchar() != '\n')
        ; // Pulisci il buffer

    if (nuova_sped.stato == 1)
    {
        // Se il pacco è "ordinato", viene inserito in una coda
        printf("Pacco con ID %s inserito in coda.\n", nuova_sped.p.n);
        // Qui si dovrebbe chiamare la funzione enqueue per inserire il pacco nella coda
        enqueue(&headPtr,&tailPtr, nuova_sped);

    }
    else
    {
        // Altrimenti, viene inserito nel file delle spedizioni
        inserimento_file_spedizioni(nuova_sped);
    }
}





// verifica che la data di invio sia inferiore a quella di consegna
bool controllo_date(struct tm d_invio, struct tm d_cons)
{

    bool corretto = true;

    if (d_invio.tm_year > d_cons.tm_year)
    {
        corretto = false;
        return corretto;
    }
    else if (d_invio.tm_mon > d_cons.tm_mon)
    {
        corretto = false;
        return corretto;
    }
    else if (d_invio.tm_mday > d_cons.tm_mday)
    {
        corretto = false;
        return corretto;
    }

    return corretto;
}

void inserimento_file_spedizioni(Spedizione s)
{
    FILE *fp;

    fp = fopen("spedizioni.dat", "ab");
    if (!fp)
    {
        perror("Errore nell'apertura del file");
        return;
    }

    if (fwrite(&s, sizeof(Spedizione), 1, fp) != 1)
    {
        perror("Errore nella scrittura nel file");
    }
    else
    {

        printf("Spedizione inserita correttamente nel file.\n");
    }

    //TODO: Creare una funzione che riordini il file rispetto alla data di invio

    fclose(fp);
}

void stampa_spedizione(Spedizione s)
{
    puts("<-------------------------------->");

    stampa_pacco(s.p);

    printf("Priorità: %s\n", s.priorita ? "Alta" : "Normale");

    printf("Spedito in data: %d/%d/%d \n", s.data_invio.tm_mday, s.data_invio.tm_mon, s.data_invio.tm_year);
    stampa_mittente(s.mittente);
    printf("Consegna prevista in data: %d/%d/%d \n", s.data_consegna.tm_mday, s.data_consegna.tm_mon, s.data_consegna.tm_year);
    stampa_destinatario(s.destinatario);

    printf("Stato della spedizione: ");
    switch (s.stato)
    {
    case ordinato:
        puts("Ordinato");
        break;
    case spedito:
        puts("Spedito");
        break;
    case in_consegna:
        puts("In consegna");
        break;
    case consegnato:
        puts("Consegnato");
        break;
    case annullato:
        puts("Annullato");
        break;
    default:
        puts("Stato sconosciuto");
    }
}

void stampa_file_spedizioni()
{
    FILE *fp;
    Spedizione s;

    fp = fopen("spedizioni.dat", "rb");
    if (fp == NULL)
    {
        perror("Errore nell'apertura del file");
        return;
    }

    printf("Contenuto del file spedizioni.dat:\n");
    while (fread(&s, sizeof(Spedizione), 1, fp))
    {
        stampa_spedizione(s);
    }

    fclose(fp);
    puts("\n<----Stampa completata---->\n");
}

void mod_stato_sped(Spedizione *s)
{
    int scelta;
    while (scelta < 1 || scelta > 5)
    {
        puts("Modifica stato della spedizione:");
        puts("1. Ordinato");
        puts("2. Spedito");
        puts("3. In consegna");
        puts("4. Consegnato");
        puts("5. Annullato");
        printf("Inserisci la tua scelta (1-5): ");
        scanf("%d", &scelta);

        switch (scelta)
        {
        case 1:
            s->stato = ordinato; // Modifica lo stato della spedizione a "ordinato"
            break;
        case 2:
            s->stato = spedito; // Modifica lo stato della spedizione a "spedito"
            break;
        case 3:
            s->stato = in_consegna; // Modifica lo stato della spedizione a "in_consegna"
            break;
        case 4:
            s->stato = consegnato; // Modifica lo stato della spedizione a "consegnato"
            break;
        case 5:
            s->stato = annullato; // Modifica lo stato della spedizione a "annullato"
            break;
        default:
            puts("Scelta non valida.");
        }
    }
}

void modifica_stato_spedizione_in_file(int pos, Spedizione *s_mod)
{
    FILE *fp = fopen("spedizioni.dat", "rb+");
    if (!fp)
    {
        puts("Errore apertura file!");
        return;
    }

    fseek(fp, pos * sizeof(Spedizione), SEEK_SET);

    mod_stato_sped(s_mod);

    fwrite(s_mod, sizeof(Spedizione), 1, fp);
    fclose(fp);
}

int ricerca_spedizione_per_id(const char *id_pacco, Spedizione *result)
{

    if (!id_pacco || !result)
    {
        perror("Parametri inseriti non validi");
        return -1;
    }

    FILE *fp = fopen("spedizioni.dat", "rb");
    if (!fp)
    {
        puts("Errore apertura file!");
        return -1;
    }
    Spedizione s;
    int index = 0;
    while (fread(&s, sizeof(Spedizione), 1, fp) == 1)
    {
        if (strcmp(s.p.n, id_pacco) == 0)
        {
            if (result)
                *result = s;
            fclose(fp);
            return index; // Restituisce la posizione
        }
        index++;
    }
    fclose(fp);
    return -1; // Non trovato
}