#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "dati.h"
#include "gestione_file.h"

FILE *fp;

bool salva_coda_su_file(CodaSpedizione *coda, char *nomeFile)

{
    if (isEmpty(coda))
    {
        printf("\nLa coda è vuota\n");
        return false;
    }
    int scelta = 0;

    do
    {
        printf("\nOpzioni\n1)Per sovrascrivere il file\n2)Per scrivere in coda\nScegli: ");
        scanf("%d", &scelta);
    } while (scelta < 1 || scelta > 2);

    if (scelta == 1)
    {
        if (apri_file(nomeFile, "w") == false)
        {
            return false;
        }
    }
    else
    {
        if (apri_file(nomeFile, "a") == false)
        {
            return false;
        }
    }

    NodoSpedizione *corrente = getNodoTesta(coda);

    while (corrente != NULL)
    {

        Spedizione *s = getSpedDaNodo(corrente);

        fprintf(fp,
                "%9s;%.2f;%.2f;%d;%02d/%02d/%04d;%02d/%02d/%04d;"
                "%29s;%29s;%16s;%99s;%49s;%2s;%5s;%49s;"
                "%29s;%29s;%16s;%99s;%49s;%2s;%5s;%49s;%d\n",
                get_numID(getPacco(s)), getPeso(getPacco(s)), getVolume(getPacco(s)), getPriorita(s),
                getGiorno(*getData(s, true)), getMese(*getData(s, true)), getAnno(*getData(s, true)),
                getGiorno(*getData(s, false)), getMese(*getData(s, false)), getAnno(*getData(s, false)),
                getNome(getPersona(s, true)), getCognome(getPersona(s, true)), getTelefono(getPersona(s, true)), getVia(getPersona(s, true)), getCitta(getPersona(s, true)), getProv(getPersona(s, true)), getCAP(getPersona(s, true)), getMail(getPersona(s, true)),
                getNome(getPersona(s, false)), getCognome(getPersona(s, false)), getTelefono(getPersona(s, false)), getVia(getPersona(s, false)), getCitta(getPersona(s, false)), getProv(getPersona(s, false)), getCAP(getPersona(s, false)), getMail(getPersona(s, false)),
                getStato(s));
        corrente = getProssimoNodo(corrente);
    }

    chiudi_file();
    return true;
}


/**
 * @brief Rimuove gli spazi e tabulazioni a sinistra da una stringa.
 * @param str Stringa da elaborare.
 * @return Puntatore alla stringa senza spazi iniziali.
 */
char *trim_left(char *str);


char *trim_left(char *str)
{
    while (*str == ' ' || *str == '\t')
        str++; // sposta il puntatore della stringa al carattere successi
    return str;
}

bool carica_coda_da_file(CodaSpedizione *coda, char *nomeFile)
{

    if (apri_file(nomeFile, "r") == false)
    {
        return false;
    }

    char riga[1024]; // buffer più grande per righe lunghe
    while (fgets(riga, sizeof(riga), fp))
    {
        char *token;
        int campo = 0;

        Spedizione *s = creaSpedizione();

        token = strtok(riga, ";");

        while (token != NULL)
        {
            token = trim_left(token);
            switch (campo)
            {
            case 0:
            {
                char *id = get_numID(getPacco(s));
                size_t size = sizeof(char) * 9;
                strncpy(id, token, size);
                break;
            }

            case 1:
                // s.p.peso = (float)atof(token);
                setPeso((float)atof(token), getPacco(s));
                break;
            case 2:
                //  s.p.volume = (float)atof(token);
                setVolume((float)atof(token), getPacco(s));
                break;
            case 3:
                // s.priorita = atoi(token);
                setPriorita(atoi(token), s);
                break;
            case 4:
                sscanf(token, "%d/%d/%d", &getData(s, true)->tm_mday, &getData(s, true)->tm_mon, &getData(s, true)->tm_year);

                break;
            case 5:
                sscanf(token, "%d/%d/%d", &getData(s, false)->tm_mday, &getData(s, false)->tm_mon, &getData(s, false)->tm_year);
                break;
            case 6:
            {
                // mittente
                size_t size = sizeof(char) * 29;
                strncpy(getNome(getPersona(s, true)), token, size);

                break;
            }
            case 7:
            {
                size_t size = sizeof(char) * 29;

                strncpy(getCognome(getPersona(s, true)), token, size);

                break;
            }
            case 8:
            {
                size_t size = sizeof(char) * 16;
                strncpy(getTelefono(getPersona(s, true)), token, size);

                break;
            }
            case 9:
            {
                strncpy(getVia(getPersona(s, true)), token, sizeof(char) * 99);

                break;
            }
            case 10:
            {
                strncpy(getCitta(getPersona(s, true)), token, sizeof(char) * 49);

                break;
            }
            case 11:
            {
                strncpy(getProv(getPersona(s, true)), token, sizeof(char) * 2);

                break;
            }
            case 12:
            {
                strncpy(getCAP(getPersona(s, true)), token, sizeof(char) * 5);

                break;
            }
            case 13:
            {
                strncpy(getMail(getPersona(s, true)), token, sizeof(char) * 49);

                break;
            }
            case 14:
            { // detinatario
                strncpy(getNome(getPersona(s, false)), token, sizeof(char) * 29);

                break;
            }
            case 15:
            {
                strncpy(getCognome(getPersona(s, false)), token, sizeof(char) * 29);

                break;
            }
            case 16:
            {
                strncpy(getTelefono(getPersona(s, false)), token, sizeof(char) * 16);

                break;
            }
            case 17:
            {
                strncpy(getVia(getPersona(s, false)), token, sizeof(char) * 99);

                break;
            }
            case 18:
            {
                strncpy(getCitta(getPersona(s, false)), token, sizeof(char) * 49);

                break;
            }
            case 19:
            {
                strncpy(getProv(getPersona(s, false)), token, sizeof(char) * 2);

                break;
            }
            case 20:
            {
                strncpy(getCAP(getPersona(s, false)), token, sizeof(char) * 5);

                break;
            }
            case 21:
            {
                strncpy(getMail(getPersona(s, false)), token, sizeof(char) * 49);

                break;
            }
            case 22:
                // s.stato = atoi(token);
                setStato(atoi(token), s);
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

    chiudi_file();
    return true;
}

bool apri_file(char *nome_file, char *modo)
{

    fp = fopen(nome_file, modo);
    if (fp == NULL)
    {
        perror("Impossibile aprire il file\n");
        return false;
    }
    else
    {
        return true;
    }
}

void chiudi_file()
{
    fclose(fp);
}
