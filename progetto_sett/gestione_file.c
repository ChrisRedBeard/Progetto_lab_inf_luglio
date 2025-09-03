
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "dati.h"

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
                s->stato);
        corrente = corrente->nextPtr;
    }

    fclose(file);
    return true;
}

char *trim_left(char *str)
{
    while (*str == ' ' || *str == '\t')
        str++;
    return str;
}

bool carica_coda_da_file(CodaSpedizione *coda, char *nomeFile)
{
    FILE *file = fopen(nomeFile, "r");
    if (file == NULL)
        return false;

    char riga[1024]; // buffer più grande per righe lunghe
    while (fgets(riga, sizeof(riga), file))
    {

        Spedizione s = {0};
        char *token;
        int campo = 0;

        token = strtok(riga, ";");



        while (token != NULL)
        {
            token = trim_left(token);
            switch (campo)
            {
            case 0:
                strncpy(s.p.n, token, sizeof(s.p.n) - 1);

                break;
            case 1:
                s.p.peso = (float)atof(token);
                break;
            case 2:
                s.p.volume = (float)atof(token);
                break;
            case 3:
                s.priorita = atoi(token);
                break;
            case 4:
                sscanf(token, "%d/%d/%d", &s.data_invio.tm_mday, &s.data_invio.tm_mon, &s.data_invio.tm_year);
                break;
            case 5:
                sscanf(token, "%d/%d/%d", &s.data_consegna.tm_mday, &s.data_consegna.tm_mon, &s.data_consegna.tm_year);
                break;
            case 6:
                strncpy(s.mittente.nome, token, sizeof(s.mittente.nome) - 1);

                break;
            case 7:
                strncpy(s.mittente.cognome, token, sizeof(s.mittente.cognome) - 1);

                break;
            case 8:
                strncpy(s.mittente.telefono, token, sizeof(s.mittente.telefono) - 1);

                break;
            case 9:
                strncpy(s.mittente.via, token, sizeof(s.mittente.via) - 1);

                break;
            case 10:
                strncpy(s.mittente.citta, token, sizeof(s.mittente.citta) - 1);

                break;
            case 11:
                strncpy(s.mittente.provincia, token, sizeof(s.mittente.provincia) - 1);

                break;
            case 12:
                strncpy(s.mittente.cap, token, sizeof(s.mittente.cap) - 1);

                break;
            case 13:
                strncpy(s.mittente.email, token, sizeof(s.mittente.email) - 1);

                break;
            case 14:
                strncpy(s.destinatario.nome, token, sizeof(s.destinatario.nome) - 1);

                break;
            case 15:
                strncpy(s.destinatario.cognome, token, sizeof(s.destinatario.cognome) - 1);

                break;
            case 16:
                strncpy(s.destinatario.telefono, token, sizeof(s.destinatario.telefono) - 1);

                break;
            case 17:
                strncpy(s.destinatario.via, token, sizeof(s.destinatario.via) - 1);

                break;
            case 18:
                strncpy(s.destinatario.citta, token, sizeof(s.destinatario.citta) - 1);

                break;
            case 19:
                strncpy(s.destinatario.provincia, token, sizeof(s.destinatario.provincia) - 1);

                break;
            case 20:
                strncpy(s.destinatario.cap, token, sizeof(s.destinatario.cap) - 1);

                break;
            case 21:
                strncpy(s.destinatario.email, token, sizeof(s.destinatario.email) - 1);

                break;
            case 22:
                s.stato = atoi(token);
                break;
            default:
                break;
            }
            campo++;
            token = strtok(NULL, ";");
        }
        if (campo >= 23)
            enqueue(coda, s);
    }

    fclose(file);
    return true;
}
