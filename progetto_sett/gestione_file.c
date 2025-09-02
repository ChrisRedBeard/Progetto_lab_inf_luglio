
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "dati.h"

/* SALVATAGGIO IN BINARIO
bool salva_coda_su_file(CodaSpedizione *coda, char *nomeFile){
    FILE *file = fopen(nomeFile, "wb");
    if (file == NULL) {
        return false; // Errore nell'apertura del file
    }

    NodoSpedizione *corrente = coda->testaPtr;
    while (corrente != NULL) {
        fwrite(&corrente->sped, sizeof(Spedizione), 1, file);
        corrente = corrente->nextPtr;
    }

    fclose(file);
    return true; // Salvataggio riuscito
}

bool carica_coda_da_file(CodaSpedizione *coda, char *nomeFile){
    FILE *file = fopen(nomeFile, "rb");
    if (file == NULL) {
        return false; // Errore nell'apertura del file
    }

    Spedizione s;
    while (fread(&s, sizeof(Spedizione), 1, file) == 1) {
        enqueue(coda, s);
    }

    fclose(file);
    return true; // Caricamento riuscito
}
*/
/* SALVATAGGIO IN TESTO, SENZA SEPARATORE
bool salva_coda_su_file(CodaSpedizione *coda, char *nomeFile)
{
    FILE *file = fopen(nomeFile, "w");
    if (file == NULL)
    {
        return false;
    }

    NodoSpedizione *corrente = coda->testaPtr;
    while (corrente != NULL)
    {
        Spedizione *s = &corrente->sped;
        fprintf(file,
                "%19s %f %f %d %d/%d/%d %d/%d/%d "
                "%19s %19s %15s %39[^\n] %19s %2s %5s %29s "
                "%19s %19s %15s %39[^\n] %19s %2s %5s %29s %d",
                s->p.n, s->p.peso, s->p.volume, s->priorita,
                s->data_invio.tm_mday, s->data_invio.tm_mon, s->data_invio.tm_year,
                s->data_consegna.tm_mday, s->data_consegna.tm_mon, s->data_consegna.tm_year,
                s->mittente.nome, s->mittente.cognome, s->mittente.telefono, s->mittente.via, s->mittente.citta, s->mittente.provincia, s->mittente.cap, s->mittente.email,
                s->destinatario.nome, s->destinatario.cognome, s->destinatario.telefono, s->destinatario.via, s->destinatario.citta, s->destinatario.provincia, s->destinatario.cap, s->destinatario.email,
                s->stato);
        corrente = corrente->nextPtr;
    }

    fclose(file);
    return true;
}

bool carica_coda_da_file(CodaSpedizione *coda, char *nomeFile)
{
    FILE *file = fopen(nomeFile, "r");
    if (file == NULL)
    {
        return false;
    }

    char riga[256];
    while (fgets(riga, sizeof(riga), file))
    {
        Spedizione s = {0};
        int ret = sscanf(riga,
                         "%19s %f %f %d %d/%d/%d %d/%d/%d "
                         "%19s %19s %15s %39[^\n] %19s %2s %5s %29s "
                         "%19s %19s %15s %39[^\n] %19s %2s %5s %29s %d",
                         s.p.n, &s.p.peso, &s.p.volume, &s.priorita,
                         &s.data_invio.tm_mday, &s.data_invio.tm_mon, &s.data_invio.tm_year,
                         &s.data_consegna.tm_mday, &s.data_consegna.tm_mon, &s.data_consegna.tm_year,
                         s.mittente.nome, s.mittente.cognome, s.mittente.telefono, s.mittente.via, s.mittente.citta, s.mittente.provincia, s.mittente.cap, s.mittente.email,
                         s.destinatario.nome, s.destinatario.cognome, s.destinatario.telefono, s.destinatario.via, s.destinatario.citta, s.destinatario.provincia, s.destinatario.cap, s.destinatario.email,
                         &s.stato);

        enqueue(coda, s);
    }

    fclose(file);
    return true;
}*/

// SALVATAGGIO IN TESTO, CON SEPARATORE ;
bool salva_coda_su_file(CodaSpedizione *coda, char *nomeFile)
{
    FILE *file = fopen(nomeFile, "a");
    if (file == NULL)
    {
        return false;
    }

    NodoSpedizione *corrente = coda->testaPtr;
    while (corrente != NULL)
    {
        Spedizione *s = &corrente->sped;
        fprintf(file,
            "%9s;%.2f;%.2f;%d;%02d/%02d/%04d;%02d/%02d/%04d;"
            "%29s;%29s;%16s;%99s;%49s;%2s;%5s;%49s;"
            "%29s;%29s;%16s;%99s;%49s;%2s;%5s;%49s;%d\n",
            s->p.n, s->p.peso, s->p.volume, s->priorita,
            s->data_invio.tm_mday, s->data_invio.tm_mon, s->data_invio.tm_year,
            s->data_consegna.tm_mday, s->data_consegna.tm_mon, s->data_consegna.tm_year,
            s->mittente.nome, s->mittente.cognome, s->mittente.telefono, s->mittente.via, s->mittente.citta, s->mittente.provincia, s->mittente.cap, s->mittente.email,
            s->destinatario.nome, s->destinatario.cognome, s->destinatario.telefono, s->destinatario.via, s->destinatario.citta, s->destinatario.provincia, s->destinatario.cap, s->destinatario.email,
            s->stato
        );
        corrente = corrente->nextPtr;
    }

    fclose(file);
    return true;
}

//TODO non legge correttamente

bool carica_coda_da_file(CodaSpedizione *coda, char *nomeFile)
{
    FILE *file = fopen(nomeFile, "r");
    if (file == NULL)
        return false;

    char riga[512];
    while (fgets(riga, sizeof(riga), file))
    {
        Spedizione s = {0};
        char *token;
        int campo = 0;

        // Array di puntatori ai campi stringa
        char *campi_str[] = {
            s.p.n, s.mittente.nome, s.mittente.cognome, s.mittente.telefono, s.mittente.via,
            s.mittente.citta, s.mittente.provincia, s.mittente.cap, s.mittente.email,
            s.destinatario.nome, s.destinatario.cognome, s.destinatario.telefono, s.destinatario.via,
            s.destinatario.citta, s.destinatario.provincia, s.destinatario.cap, s.destinatario.email
        };

        token = strtok(riga, ";");
        while (token != NULL)
        {
            switch (campo)
            {
                case 0:  strncpy(campi_str[0], token, sizeof(s.p.n)-1); break;
                case 1:  s.p.peso = (float)atof(token); break;
                case 2:  s.p.volume = (float)atof(token); break;
                case 3:  s.priorita = atoi(token); break;
                case 4:  sscanf(token, "%d/%d/%d", &s.data_invio.tm_mday, &s.data_invio.tm_mon, &s.data_invio.tm_year); break;
                case 5:  sscanf(token, "%d/%d/%d", &s.data_consegna.tm_mday, &s.data_consegna.tm_mon, &s.data_consegna.tm_year); break;
                default:
                    if (campo >= 6 && campo <= 21)
                        strncpy(campi_str[campo-6], token, 39); // Adatta la dimensione massima
                    else if (campo == 22)
                        s.stato = atoi(token);
                    break;
            }
            campo++;
            token = strtok(NULL, ";");
        }
        if (campo >= 23) enqueue(coda, s);
    }

    fclose(file);
    return true;
}