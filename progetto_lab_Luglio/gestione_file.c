
/**
 * @file gestione_file.c
 * @brief Implementazione delle funzioni per la gestione delle spedizioni su file.
 */

#include "gestione_file.h"
#include "utils.h"
#include <string.h>
#include <stdlib.h>

/**
 * @brief Inserisce una spedizione alla fine del file binario "spedizioni.dat".
 * @param s Struttura di tipo Spedizione da inserire.
 */
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

    fclose(fp);
}


/**
 * @brief Stampa tutte le spedizioni salvate nel file "spedizioni.dat".
 */
void stampa_file_spedizioni()
{
    FILE *fp;
    Spedizione s;

    fp = fopen("..\..\..\..\..\Documents\GitHub\Progetto_lab_inf_luglio\spedizioni.dat", "rb");
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


/**
 * @brief Modifica il destinatario di una spedizione già presente nel file.
 * @param pos Posizione della spedizione nel file.
 * @param s_mod Puntatore alla struttura Spedizione da modificare.
 */
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

/**
 * @brief Modifica la data di consegna di una spedizione nel file.
 * @param pos Posizione della spedizione nel file.
 * @param s_mod Puntatore alla struttura Spedizione da modificare.
 */
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


/**
 * @brief Ricerca una spedizione nel file tramite l'ID del pacco.
 * @param id_pacco ID del pacco da cercare.
 * @param result Puntatore a Spedizione dove salvare il risultato trovato.
 * @return Posizione della spedizione nel file se trovata, -1 altrimenti.
 */
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


/**
 * @brief Elimina una spedizione dal file sulla base della sua posizione.
 * @param pos Posizione della spedizione da eliminare.
 */
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

/**
 * @brief Modifica lo stato di una spedizione (es. ordinato, spedito, ecc.).
 * @param pos Posizione della spedizione nel file.
 * @param s_mod Puntatore alla struttura Spedizione da aggiornare.
 */
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

/**
 * @brief Ordina il contenuto del file "spedizioni.dat" in base all'ID del pacco.
 */
void ordina_file_id()
{
    Spedizione spedizioni[100];

    FILE *fp = fopen("spedizioni.dat", "rb");

    int_pos n = 0;

    while(fread(&spedizioni[n], sizeof(Spedizione), 1, fp) == 1 && n < 100) {
        n++;
    }

    fclose(fp);

    qsort(spedizioni, n, sizeof(Spedizione), confronta_id);

    fp = fopen("spedizioni.dat", "wb");

    for (int_pos i = 0; i < n; i++)
    {
        fwrite(&spedizioni[i], sizeof(Spedizione), 1, fp);
    }

    fclose(fp);

}
