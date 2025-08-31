#include "dati.h"
#include "funzioni.h"
#include "controlli.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setNome(char *str, Persona *p)
{
    strcpy(p->nome, str);
}

char *getNome(Persona *d)
{

    return d->nome;
}

void setCognome(char *str, Persona *p)
{
    strcpy(p->cognome, str);
}
char *getCognome(Persona *d)
{
    return d->cognome;
}

void setTelefono(char *str, Persona *p)
{
    strcpy(p->telefono, str);
}

char *getTelefono(Persona *p)
{
    return p->telefono;
}

void setVia(char *str, Persona *p)
{
    strcpy(p->via, str);
}
char *getVia(Persona *p)
{
    return p->via;
}

void setCitta(char *str, Persona *p)
{
    strcpy(p->citta, str);
}
char *getCitta(Persona *p)
{
    return p->citta;
}

void setProv(char *str, Persona *p)
{
    strcpy(p->provincia, str);
}
char *getProv(Persona *p)
{
    return p->provincia;
}

void setCAP(char *str, Persona *p)
{
    strcpy(p->cap, str);
}
char *getCAP(Persona *p)
{
    return p->cap;
}

void setMail(char *str, Persona *p)
{
    strcpy(p->email, str);
}

char *getMail(Persona *p)
{
    return p->email;
}

// da vedere
void inserimento_Persona(Persona *p)
{
    char stringa[100] = {'\0'};

    input_string("Nome: ", stringa, 29);
    setNome(stringa, p);
    stringa[0] = '\0';

    input_string("Cognome: ", stringa, 29);
    setCognome(stringa, p);
    stringa[0] = '\0';

    input_string("Numero di telefono [+00 123 456 7890]: ", stringa, 16);
    setTelefono(stringa, p);
    stringa[0] = '\0';

    input_string("Email: ", stringa, 49);
    setMail(stringa, p);
    stringa[0] = '\0';

    input_string("Indirizzo [via, num. civico]: ", stringa, 99);
    setVia(stringa, p);
    stringa[0] = '\0';

    input_string("Città: ", stringa, 49);
    setCitta(stringa, p);
    stringa[0] = '\0';

    input_string("Provincia [CC]: ", stringa, 2);
    setProv(stringa, p);
    stringa[0] = '\0';

    input_string("CAP: ", stringa, 5);
    setCAP(stringa, p);
    stringa[0] = '\0';
}

void setPersona(Spedizione *s, Persona *p, bool tipo)
{
    if (tipo)
    {
        s->mittente = *p;
    }
    else
    {
        s->destinatario = *p;
    }
}

Persona getPersona(Spedizione *s, bool tipo)
{
    if (tipo)
    {
        return s->mittente;
    }
    else
        return s->destinatario;
}

// stampare le mittente/destinatario fuori
void stampa_Persona(Persona d)
{
    printf("%sNome e cognome%s: %s %s \n", WHITE, RESET, getNome(&d), getCognome(&d));
    printf("%sTelefono%s: %16s, ", WHITE, RESET, getTelefono(&d));
    printf("%sEmail%s: %s\n", WHITE, RESET, getMail(&d));
    printf("%sIndirizzo%s: %s, ", WHITE, RESET, getVia(&d));
    printf("%sCittà%s: %s, ", WHITE, RESET, getCitta(&d));
    printf("%sProvincia%s: %2s, ", WHITE, RESET, getProv(&d));
    printf("%sCAP%s: %5s\n", WHITE, RESET, getCAP(&d));
}

void set_numID(char *str, Pacco *p)
{
    strcpy(p->n, str);
}

int confronta_id(const void *id1, const void *id2)
{
    return strcmp(((Spedizione *)id1)->p.n, ((Spedizione *)id2)->p.n);
}

char *get_numID(Pacco *p)
{
    return p->n;
}

void setPeso(float f, Pacco *p)
{
    p->peso = f;
}
float getPeso(Pacco p)
{
    return p.peso;
}

void setVolume(float f, Pacco *p)
{
    p->volume = f;
}
float getVolume(Pacco p)
{
    return p.volume;
}

void inserimento_pacco(Pacco *p)
{
    char stringa[100] = {'\0'};
    input_id("ID[012345678]: ", stringa, 9);
    set_numID(stringa, p);

    float f = 0; // TODO: perchè avevi usato il puntatore?

    input_float("Peso: ", &f, 0);
    setPeso(f, p);

    f = 0;
    input_float("Volume: ", &f, 0);
    setVolume(f, p);
}

void stampa_pacco(Pacco p)
{
    printf("%sID Pacco%s: %s \n", WHITE, RESET, p.n);
    printf("%sPeso%s: %.2f grammi, Volume: %.2f cm^3 \n", WHITE, RESET, p.peso, p.volume);
}

void setPriorita(bool b, Spedizione *s)
{
    s->priorita = b;
}

bool getPriorita(Spedizione s)
{
    return s.priorita;
}

void setStato(int i, Spedizione *s)
{

    while (i < 1 || i > 5)
    {
        printf("%sErrore%s - Inserisci un valore da 1 a 5.", RED, RESET);
        scanf("%d", &i);
    }
    s->stato = i;
}

int getStato(Spedizione s)
{
    return s.stato;
}
// capire cosa fare per impostare
void setData(const char *prompt, Spedizione *s, bool scelta)
{
    bool flag = false;
    struct tm *data;
    if (scelta == true)
    {
        data = &s->data_invio;
    }
    else
    {
        data = &s->data_consegna;
    }

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

struct tm getData(Spedizione s, bool scelta)
{
    if (scelta == true)
    {
        return s.data_invio;
    }
    else
    {
        return s.data_consegna;
    }
}

void stampa_spedizione(Spedizione s)
{
    puts("<-------------------------------->");

    stampa_pacco(s.p);

    printf("%sPriorità%s: %s\n", WHITE, RESET, getPriorita(s) ? "Alta" : "Normale");

    printf("%sSpedito in data%s: %d/%d/%d \n", WHITE, RESET, getData(s, true).tm_mday, getData(s, true).tm_mon, getData(s, true).tm_year);
    printf("---Mittente---");
    stampa_Persona(getPersona(&s, true));

    printf("%sConsegna prevista in data%s: %d/%d/%d \n", WHITE, RESET, getData(s, false).tm_mday, getData(s, false).tm_mon, getData(s, false).tm_year);
    printf("---Destinatario---");
    stampa_Persona(getPersona(&s, false));

    printf("%sStato della spedizione%s: ", WHITE, RESET);
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

void inserimento_spedizione(Spedizione *s)
{
    puts("Inserisci i dati della spedizione:");
    inserimento_pacco(&(s->p));
    // scelta priorità
    bool prior;
    do
    {
        printf("Priorità (1 per alta, 0 per normale): ");

        if (scanf("%d", &prior) != 1 || (prior != 0 && prior != 1))
        {
            printf("%sPriorità non valida.%s\n", RED, RESET);
        }
    } while (prior != 0 && prior != 1);

    setPriorita(prior, s);

    do
    {
        setData("Data di invio", s, true);
        setData("Data di consegna", s, false);

    } while (!controllo_date(getData(*s, true), getData(*s, false)));

    puts("<--Dati del mittente-->");
    Mittente *m = malloc(sizeof(Mittente));
    inserimento_Persona(m);
    setPersona(s, m, true);

    free(m);

    puts("<--Dati del destinatario-->");
    Destinatario *d = malloc(sizeof(Destinatario));
    inserimento_Persona(d);
    setPersona(s, d, false);

    free(d);

    enum Stati stato;
    do
    {
        puts("Inserire lo stato della spedizione (1 per ordinato, 2 per spedito, 3 per in consegna, 4 per consegnato, 5 per annullato): ");
        if (scanf("%d", &stato) != 1 || stato < 1 || stato > 5)
        {
            printf("%s", RED);
            puts("Stato non valido.");
            printf("%s", RESET);
            while (getchar() != '\n')
                ;
        }
    } while (stato < 1 || stato > 5);

    setStato(stato, s);
}

void initCoda(CodaSpedizione *coda)
{
    coda->testaPtr = NULL;
    coda->codaPtr = NULL;
}

void enqueue(CodaSpedizione *coda, Spedizione sped)
{
    NodoSpedizione *nuovoNodo = malloc(sizeof(NodoSpedizione));
    nuovoNodo->sped = sped;
    nuovoNodo->nextPtr = NULL;

    if (coda->codaPtr)
    {
        coda->codaPtr->nextPtr = nuovoNodo;
    }
    else
    {
        coda->testaPtr = nuovoNodo;
    }

    coda->codaPtr = nuovoNodo;
}

int dequeue(CodaSpedizione *coda, Spedizione *sped)
{
    if (coda->testaPtr == NULL)
    {
        return 0; // coda vuota
    }

    NodoSpedizione *nodoDaRimuovere = coda->testaPtr;
    *sped = nodoDaRimuovere->sped;
    coda->testaPtr = nodoDaRimuovere->nextPtr;

    if (coda->testaPtr == NULL)
    {
        coda->codaPtr = NULL; // coda vuota dopo la rimozione
    }

    free(nodoDaRimuovere);
    return 1; // successo
}
