#include "spedizione.h"
#include "coda.h"
#include "utils.h"

#include <string.h>
#include <stdlib.h>

void inserimento_data(const char *prompt, struct tm *data)
{
    bool flag = false;
    do
    {
        printf("%s (formato: gg mm aaaa): ", prompt);
        if (scanf("%d %d %d", &data->tm_mday, &data->tm_mon, &data->tm_year) != 3 ||
            data->tm_mday < 1 || data->tm_mday > 31 ||
            data->tm_mon < 1 || data->tm_mon > 12 ||
            data->tm_year < 1900)
        {
            printf("%sData non valida, riprova.%s\n", RED, RESET);
            flag = true;
        }
        else
        {
            flag = false;

            if (data->tm_year % 4 == 0)
            {
                if (data->tm_mon == 2 && data->tm_mday > 29)
                {
                    printf("%sData non valida, riprova.%s\n", RED, RESET);
                    flag = true;
                }
            }
            else
            {
                if (data->tm_mon == 2 && data->tm_mday > 28)
                {
                    printf("%sData non valida, riprova.%s\n", RED, RESET);
                    flag = true;
                }
            }

            if (data->tm_mon == 4 || data->tm_mon == 6 || data->tm_mon == 9 || data->tm_mon == 11)
            {
                if (data->tm_mday > 30)
                {
                    printf("%sData non valida, riprova.%s\n", RED, RESET);
                    flag = true;
                }
            }
        }

    } while (flag);
}

void inserimento_spedizione(Coda *c)
{
    Spedizione nuova_sped = {0};

    puts("Inserisci i dati della spedizione:");

    inserimento_pacco(&nuova_sped.p);

    do
    {
        printf("Priorità (1 per alta, 0 per normale): ");
        if (scanf("%d", &nuova_sped.priorita) != 1 || (nuova_sped.priorita != 0 && nuova_sped.priorita != 1))
        {
            printf("%sPriorità non valida.%s\n", RED, RESET);
        }
    } while (nuova_sped.priorita != 0 && nuova_sped.priorita != 1);

    do
    {
        inserimento_data("Data di invio", &nuova_sped.data_invio);
        inserimento_data("Data di consegna prevista", &nuova_sped.data_consegna);

    } while (!controllo_date(nuova_sped.data_invio, nuova_sped.data_consegna));

    puts("<--Dati del mittente-->");
    inserimento_mittente(&nuova_sped.mittente);

    puts("<--Dati del destinatario-->");
    inserimento_destinatario(&nuova_sped.destinatario);

    do
    {
        puts("Inserire lo stato della spedizione (1 per ordinato, 2 per spedito, 3 per in consegna, 4 per consegnato, 5 per annullato): ");
        if (scanf("%d", &nuova_sped.stato) != 1 || nuova_sped.stato < 1 || nuova_sped.stato > 5)
        {
            printf("%s", RED);
            puts("Stato non valido.");
            printf("%s", RESET);
            while (getchar() != '\n')
                ;
        }
    } while (nuova_sped.stato < 1 || nuova_sped.stato > 5);

    if (nuova_sped.stato == 1)
    {
        // Se il pacco è "ordinato", viene inserito in una coda
        printf("Pacco con ID %s inserito in coda.\n", nuova_sped.p.n);
        enqueue(c, nuova_sped);
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
    if (d_invio.tm_year > d_cons.tm_year)
    {
        printf("%sHai inserito una data di invio con anno superiore a quello di consegna, riprova%s\n", RED, RESET);
        return false;
    }

    if (d_invio.tm_year == d_cons.tm_year && d_invio.tm_mon > d_cons.tm_mon)
    {
        printf("%sHai inserito una data di invio con mese superiore a quello di consegna, riprova%s\n", RED, RESET);
        return false;
    }

    if (d_invio.tm_year == d_cons.tm_year && d_invio.tm_mon == d_cons.tm_mon && d_invio.tm_mday > d_cons.tm_mday)
    {
        printf("%sHai inserito una data di invio con giorno superiore a quello di consegna, riprova%s\n", RED, RESET);
        return false;
    }

    return true;
}

void inserimento_file_spedizioni(Spedizione s)
{
    FILE *fp;

    fp = fopen("spedizioni.dat", "ab");
    if (!fp)
    {
        printf("%s", RED);
        perror("Errore nell'apertura del file");
        printf("%s", RESET);
        return;
    }

    if (fwrite(&s, sizeof(Spedizione), 1, fp) != 1)
    {
        printf("%s", RED);
        perror("Errore nella scrittura nel file");
        printf("%s", RESET);
    }
    else
    {

        printf("%sSpedizione inserita correttamente nel file.%s\n", GREEN, RESET);
    }

    // funzione che riordina il file rispetto alla data di invio
    order_by_date();
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
    case 1:
        puts("Ordinato");
        break;
    case 2:
        puts("Spedito");
        break;
    case 3:
        puts("In consegna");
        break;
    case 4:
        puts("Consegnato");
        break;
    case 5:
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
        printf("%s", RED);
        perror("Errore nell'apertura del file");
        printf("%s", RESET);
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

void modifica_destinatario_spedizione_in_file(int pos, Spedizione *s_mod)
{
    FILE *fp = fopen("spedizioni.dat", "rb+");
    if (!fp)
    {
        printf("%s", RED);
        puts("Errore apertura file!");
        printf("%s", RESET);
        return;
    }

    fseek(fp, pos * sizeof(Spedizione), SEEK_SET);

    inserimento_destinatario(&s_mod->destinatario);

    fwrite(s_mod, sizeof(Spedizione), 1, fp);
    fclose(fp);
}

void modifica_data_consegna_spedizione_in_file(int pos, Spedizione *s_mod)
{
    FILE *fp = fopen("spedizioni.dat", "rb+");
    if (!fp)
    {
        printf("%s", RED);
        puts("Errore apertura file!");
        printf("%s", RESET);
        return;
    }

    fseek(fp, pos * sizeof(Spedizione), SEEK_SET);

    do
    {
        inserimento_data("Data di consegna ", &s_mod->data_consegna);

    } while (!controllo_date(s_mod->data_invio, s_mod->data_consegna));

    fwrite(s_mod, sizeof(Spedizione), 1, fp);
    fclose(fp);
}

void modifica_stato_spedizione_in_file(int pos, Spedizione *s_mod)
{
    FILE *fp = fopen("spedizioni.dat", "rb+");
    if (!fp)
    {
        printf("%s", RED);
        puts("Errore apertura file!");
        printf("%s", RESET);
        return;
    }

    fseek(fp, pos * sizeof(Spedizione), SEEK_SET);

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
            s_mod->stato = ordinato; // Modifica lo stato della spedizione a "ordinato"
            break;
        case 2:
            s_mod->stato = spedito; // Modifica lo stato della spedizione a "spedito"
            break;
        case 3:
            s_mod->stato = in_consegna; // Modifica lo stato della spedizione a "in_consegna"
            break;
        case 4:
            s_mod->stato = consegnato; // Modifica lo stato della spedizione a "consegnato"
            break;
        case 5:
            s_mod->stato = annullato; // Modifica lo stato della spedizione a "annullato"
            break;
        default:
            printf("%s", RED);
            puts("Scelta non valida.");
            printf("%s", RESET);
        }
    }

    fwrite(s_mod, sizeof(Spedizione), 1, fp);
    fclose(fp);
}

int ricerca_spedizione_per_id(const char *id_pacco, Spedizione *result)
{

    if (!id_pacco || !result)
    {
        printf("%s", RED);
        perror("Parametri inseriti non validi");
        printf("%s", RESET);
        return -1;
    }

    FILE *fp = fopen("spedizioni.dat", "rb");
    if (!fp)
    {
        printf("%s", RED);
        puts("Errore apertura file!");
        printf("%s", RESET);
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

void elimina_spedizione_in_file(int pos)
{

    FILE *fp = fopen("spedizioni.dat", "rb");
    if (!fp)
    {
        printf("%s", RED);
        puts("Errore apertura file!");
        printf("%s", RESET);
        return;
    }

    FILE *tmp = fopen("spedizioni_tmp.dat", "wb");
    if (!tmp)
    {
        printf("%s", RED);
        puts("Errore creazione file temporaneo!");
        printf("%s", RESET);
        fclose(fp);
        return;
    }

    Spedizione s;
    int index = 0;
    while (fread(&s, sizeof(Spedizione), 1, fp) == 1)
    {
        if (index != pos)
        {
            fwrite(&s, sizeof(Spedizione), 1, tmp);
        }
        index++;
    }

    fclose(fp);
    fclose(tmp);

    remove("spedizioni.dat");
    rename("spedizioni_tmp.dat", "spedizioni.dat");
}

Spedizione estrai_min_data(Coda *c)
{
    Coda temp;
    coda_init(&temp);

    Spedizione min, corrente;
    bool primo = true;

    while (!isEmpty(*c)) {
        corrente = *(dequeue(c));
        //se true, il primo è più piccolo del secondo
        if (controllo_date(corrente.data_consegna, min.data_consegna)) {
            if (!primo) enqueue(&temp, min);
            min = corrente;
            primo = false;
        } else {
            enqueue(&temp, corrente);
        }
    }

    // Rimetto gli altri nella coda originale (senza il minimo)
    while (!isEmpty(temp)) {
        enqueue(c, *(dequeue(&temp)));
    }

    return min;
}


void order_by_date()
{
    Spedizione tmp;
    Coda c;
    coda_init(&c);
    FILE *fp = fopen("spedizioni.dat", "rb");
    if (!fp)
    {
        perror("Errore nell'aprire il file");
        return;
    }

    while (fread(&tmp, sizeof(Spedizione), 1, fp) == 1) {
        enqueue(&c, tmp);
    }

    fclose(fp);
    // Ordinare le spedizioni in base alla data di invio
   // qsort(spedizioni, shipment_count, sizeof(Spedizione), compare_spedizioni);

    Coda ordinata;
    coda_init(&ordinata);
    while (!isEmpty(ordinata)) {
        Spedizione min= estrai_min_data(&c);
        enqueue(&ordinata, min);
    }
   
    // Scrivere le spedizioni ordinate in un nuovo file
    FILE *nuovo_file = fopen("sped_ord.dat", "wb");

    if (!nuovo_file)
    {
        perror("Errore nell'aprire il file di output");
      //  free(spedizioni);
        return;
    }

    while (!isEmpty(ordinata)) {
        Spedizione s = *(dequeue(&ordinata));
        stampa_spedizione(s);
        fwrite(&s, sizeof(Spedizione), 1, nuovo_file);
    }

    fclose(fp);
   // fwrite(spedizioni, sizeof(Spedizione), shipment_count, nuovo_file);
    fclose(nuovo_file);

    //free(spedizioni);

    // Sovrascrivi l'originale
    if (remove("spedizioni.dat") != 0)
    {
        printf("%s", RED);
        perror("Errore nell'eliminare spedizioni.dat");
        printf("%s", RESET);
        return;
    }

    if (rename("sped_ord.dat", "spedizioni.dat") != 0)
    {
        printf("%s", RED);
        perror("Errore nel rinominare il file ordinato");
        printf("%s", RESET);
        return;
    }
    //
}