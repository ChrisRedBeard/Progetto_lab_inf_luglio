
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "dati.h"
#include "gestione_file.h"

FILE *fp;


bool salva_coda_su_file(CodaSpedizione *coda, char *nomeFile)
{  if(isEmpty(*coda)){
      printf("\nLa coda è vuota\n");
        return false;
    }
    int scelta=0;

    do{
      printf("\nOpzioni\n1)Per sovrascrivere il file\n2)Per scrivere in coda\nScegli: ");
      scanf("%d",&scelta);
    }while(scelta<1 || scelta>2);

    if(scelta==1){
        if(apri_file(nomeFile, "w")==false){
            return false;
        }
    }else{
        if(apri_file(nomeFile, "a")==false){
            return false;
        }

    }


    NodoSpedizione *corrente = coda->testaPtr;

    while (corrente != NULL)
    {

        Spedizione *s = &corrente->sped;
        fprintf(fp,
                "%9s;%.2f;%.2f;%d;%02d/%02d/%04d;%02d/%02d/%04d;"
                "%29s;%29s;%16s;%99s;%49s;%2s;%5s;%49s;"
                "%29s;%29s;%16s;%99s;%49s;%2s;%5s;%49s;%d\n",
                get_numID(getPacco(s)), getPeso(*getPacco(s)), getVolume(*getPacco(s)), getPriorita(*s),
                s->data_invio.tm_mday, s->data_invio.tm_mon, s->data_invio.tm_year,
                s->data_consegna.tm_mday, s->data_consegna.tm_mon, s->data_consegna.tm_year,
                getNome(getPersona(s,true)), getCognome(getPersona(s,true)), getTelefono(getPersona(s,true)), getVia(getPersona(s,true)), getCitta(getPersona(s,true)), getProv(getPersona(s,true)), getCAP(getPersona(s,true)),getMail(getPersona(s,true)),
               getNome(getPersona(s,false)), getCognome(getPersona(s,false)), getTelefono(getPersona(s,false)),getVia(getPersona(s,false)), getCitta(getPersona(s,false)), getProv(getPersona(s,false)), getCAP(getPersona(s,false)), getMail(getPersona(s,false)),
                getStato(*s));
        corrente = corrente->nextPtr;
    }

    chiudi_file();
    return true;
}

char *trim_left(char *str)
{
    while (*str == ' ' || *str == '\t')
        str++; //sposta il puntatore della stringa al carattere successi
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

        Spedizione s;
        initSpedizione(&s);

        token = strtok(riga, ";");

        while (token != NULL)
        {
            token = trim_left(token);
            switch (campo)
            {
            case 0:
                strncpy(get_numID(getPacco(&s)), token, sizeof(get_numID(getPacco(&s))) - 1);

                break;
            case 1:
               // s.p.peso = (float)atof(token);
                setPeso((float)atof(token),getPacco(&s));
                break;
            case 2:
              //  s.p.volume = (float)atof(token);
                 setVolume((float)atof(token),getPacco(&s));
                break;
            case 3:
                //s.priorita = atoi(token);
                setPriorita(atoi(token),&s);
                break;
            case 4:
                sscanf(token, "%d/%d/%d", &s.data_invio.tm_mday, &s.data_invio.tm_mon, &s.data_invio.tm_year);
                break;
            case 5:
                sscanf(token, "%d/%d/%d", &s.data_consegna.tm_mday, &s.data_consegna.tm_mon, &s.data_consegna.tm_year);
                break;
            case 6:
            // mittente 
                strncpy(getNome(getPersona(&s,true)), token, sizeof(getNome(getPersona(&s,true))) - 1);

                break;
            case 7:
                strncpy(getCognome(getPersona(&s,true)), token, sizeof(getCognome(getPersona(&s,true))) - 1);

                break;
            case 8:
                strncpy(getTelefono(getPersona(&s,true)), token, sizeof(getTelefono(getPersona(&s,true))) - 1);

                break;
            case 9:
                strncpy(getVia(getPersona(&s,true)), token, sizeof(getVia(getPersona(&s,true))) - 1);

                break;
            case 10:
                strncpy(getCitta(getPersona(&s,true)), token, sizeof(getCitta(getPersona(&s,true))) - 1);

                break;
            case 11:
                strncpy(getProv(getPersona(&s,true)), token, sizeof(getProv(getPersona(&s,true))) - 1);

                break;
            case 12:
                strncpy(getCAP(getPersona(&s,true)), token, sizeof(getCAP(getPersona(&s,true))) - 1);

                break; 
            case 13:
                strncpy(getMail(getPersona(&s,true)), token, sizeof(getMail(getPersona(&s,true))) - 1);

                break;
            case 14:  //detinatario
                strncpy(getNome(getPersona(&s,false)), token, sizeof(getNome(getPersona(&s,false))) - 1);

                break;
            case 15:
                strncpy(getCognome(getPersona(&s,false)), token, sizeof(getCognome(getPersona(&s,false))) - 1);

                break;
            case 16:
                strncpy(getTelefono(getPersona(&s,false)), token, sizeof(getTelefono(getPersona(&s,false))) - 1);

                break;
            case 17:
                strncpy(getVia(getPersona(&s,false)), token, sizeof(getVia(getPersona(&s,false))) - 1);

                break;
            case 18:
                strncpy(getCitta(getPersona(&s,false)), token, sizeof(getCitta(getPersona(&s,false))) - 1);

                break;
            case 19:
                strncpy(getProv(getPersona(&s,false)), token, sizeof(getProv(getPersona(&s,false))) - 1);

                break;
            case 20:
                strncpy(getCAP(getPersona(&s,false)), token, sizeof(getCAP(getPersona(&s,false))) - 1);

                break;
            case 21:
                strncpy(getMail(getPersona(&s,false)), token, sizeof(getMail(getPersona(&s,false))) - 1);

                break;
            case 22:
                //s.stato = atoi(token);
                setStato(atoi(token),&s);
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


