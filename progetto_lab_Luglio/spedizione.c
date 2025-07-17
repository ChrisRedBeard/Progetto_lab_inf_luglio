#include "spedizione.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_string(const char *prompt, char *dest, size_t size)
{
    fflush(stdin);
    printf("%s", prompt);
    if (fgets(dest, size, stdin))
    {
        dest[strcspn(dest, "\n")] = 0; // Rimuove il newline finale
    }else{
        perror("Errore nella lettura della stringa");
        dest[0] = '\0';
    }
}

void inserimento_spedizione()
{
    Spedizione nuova_sped = {0};

    puts("Inserisci i dati della spedizione:");

    input_string("ID Pacco [IT1234567]: ", nuova_sped.p.n, sizeof(nuova_sped.p.n));
    if (strlen(nuova_sped.p.n) == 0) {
        puts("ID Pacco non valido.");
        return;
    }

    printf("Peso del pacco (in grammi): ");
    if (scanf("%f", &nuova_sped.p.peso) != 1 || nuova_sped.p.peso <= 0) {
        puts("Peso non valido.");
        while(getchar() != '\n');
        return;
    }

    printf("Volume del pacco (in centimetri cubi): ");
    if (scanf("%f", &nuova_sped.p.volume) != 1 || nuova_sped.p.volume <= 0) {
        puts("Volume non valido.");
        while(getchar() != '\n');
        return;
    }

    printf("Priorità (1 per alta, 0 per normale): ");
    if (scanf("%d", &nuova_sped.priorita) != 1 || (nuova_sped.priorita != 0 && nuova_sped.priorita != 1)) {
        puts("Priorità non valida.");
        while(getchar() != '\n');
        return;
    }

    printf("Data di invio (formato: gg mm aaaa): ");
    if (scanf("%d %d %d", &nuova_sped.data_invio.tm_mday, &nuova_sped.data_invio.tm_mon, &nuova_sped.data_invio.tm_year) != 3 ||
        nuova_sped.data_invio.tm_mday < 1 || nuova_sped.data_invio.tm_mday > 31 ||
        nuova_sped.data_invio.tm_mon < 1 || nuova_sped.data_invio.tm_mon > 12 ||
        nuova_sped.data_invio.tm_year < 1900) {
        puts("Data di invio non valida.");
        while(getchar() != '\n');
        return;
    }

    printf("Data di consegna prevista (formato: gg mm aaaa): ");
    if (scanf("%d %d %d", &nuova_sped.data_consegna.tm_mday, &nuova_sped.data_consegna.tm_mon, &nuova_sped.data_consegna.tm_year) != 3 ||
        nuova_sped.data_consegna.tm_mday < 1 || nuova_sped.data_consegna.tm_mday > 31 ||
        nuova_sped.data_consegna.tm_mon < 1 || nuova_sped.data_consegna.tm_mon > 12 ||
        nuova_sped.data_consegna.tm_year < 1900) {
        puts("Data di consegna non valida.");
        while(getchar() != '\n');
        return;
    }

    //TODO: Aggiungere un controllo per verificare che la data di consegna sia successiva alla data di invio



    while(getchar() != '\n'); // Pulisci il buffer

    puts("Dati del mittente:");
    input_string("Nome: ", nuova_sped.mittente.nome, sizeof(nuova_sped.mittente.nome));
    input_string("Cognome: ", nuova_sped.mittente.cognome, sizeof(nuova_sped.mittente.cognome));
    input_string("Numero di telefono [+00 123 456 7890]: ", nuova_sped.mittente.telefono, sizeof(nuova_sped.mittente.telefono));
    input_string("Indirizzo (via, num. civico): ", nuova_sped.mittente.via, sizeof(nuova_sped.mittente.via));
    input_string("Città: ", nuova_sped.mittente.citta, sizeof(nuova_sped.mittente.citta));
    input_string("Provincia [CC]: ", nuova_sped.mittente.provincia, sizeof(nuova_sped.mittente.provincia));
    input_string("CAP: ", nuova_sped.mittente.cap, sizeof(nuova_sped.mittente.cap));
    input_string("Email: ", nuova_sped.mittente.email, sizeof(nuova_sped.mittente.email));

    puts("Dati del destinatario:");
    input_string("Nome: ", nuova_sped.destinatario.nome, sizeof(nuova_sped.destinatario.nome));
    input_string("Cognome: ", nuova_sped.destinatario.cognome, sizeof(nuova_sped.destinatario.cognome));
    input_string("Numero di telefono [+00 123 456 7890]: ", nuova_sped.destinatario.telefono, sizeof(nuova_sped.destinatario.telefono));
    input_string("Indirizzo (via, num. civico): ", nuova_sped.destinatario.via, sizeof(nuova_sped.destinatario.via));
    input_string("Città: ", nuova_sped.destinatario.citta, sizeof(nuova_sped.destinatario.citta));
    input_string("Provincia [CC]: ", nuova_sped.destinatario.provincia, sizeof(nuova_sped.destinatario.provincia));
    input_string("CAP: ", nuova_sped.destinatario.cap, sizeof(nuova_sped.destinatario.cap));
    input_string("Email: ", nuova_sped.destinatario.email, sizeof(nuova_sped.destinatario.email));

    puts("Inserire lo stato della spedizione (1 per ordinato, 2 per spedito, 3 per in consegna, 4 per consegnato, 5 per annullato): ");
    if (scanf("%d", &nuova_sped.stato) != 1 || nuova_sped.stato < 1 || nuova_sped.stato > 5) {
        puts("Stato non valido.");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n'); // Pulisci il buffer

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

    /*Creare una funzione che riordini il file rispetto alla data di invio*/

    fclose(fp);
}

void stampa_spedizione(Spedizione s){
    puts("<-------------------------------->");
    printf("ID Pacco: %s \n", s.p.n);
    printf("Peso: %.2f grammi, Volume: %.2f cm^3 \n", s.p.peso, s.p.volume);
    printf("Priorità: %s\n", s.priorita ? "Alta" : "Normale");

    printf("Spedito in data: %d/%d/%d \n", s.data_invio.tm_mday, s.data_invio.tm_mon, s.data_invio.tm_year);

    printf("da: %s %s, ", s.mittente.nome, s.mittente.cognome);
    printf("Telefono: %s, Email: %s\n", s.mittente.telefono, s.mittente.email);
    printf("Indirizzo: %s, Città: %s, Provincia: %s, CAP: %s\n",
           s.mittente.via, s.mittente.citta, s.mittente.provincia, s.mittente.cap);

    printf("Consegna prevista in data: %d/%d/%d \n", s.data_consegna.tm_mday, s.data_consegna.tm_mon, s.data_consegna.tm_year);

    printf("a: %s %s, ", s.destinatario.nome, s.destinatario.cognome);
    printf("Telefono: %s, Email: %s\n", s.destinatario.telefono, s.destinatario.email);
    printf("Indirizzo: %s, Città: %s, Provincia: %s, CAP: %s\n",
           s.destinatario.via, s.destinatario.citta, s.destinatario.provincia, s.destinatario.cap);

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
            puts("Scelta non valida.");
        }
    }

    fwrite(s_mod, sizeof(Spedizione), 1, fp);
    fclose(fp);
}

int ricerca_spedizione_per_id(const char *id_pacco, Spedizione *result)
{

    if(!id_pacco || !result){
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