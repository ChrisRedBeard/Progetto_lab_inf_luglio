#include "funzioni.h"
#include "dati.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

void input_id(const char *prompt, char *dest, int_pos lunghezza)
{
    size_t size = sizeof(char) * (lunghezza + 1);
    bool flag = false;

    do
    {
        fflush(stdin);
        printf("%s", prompt);

        if (fgets(dest, size, stdin))
        {
            dest[strcspn(dest, "\n")] = 0; // Rimuove il newline finale
        }
        else
        {
            printf("%s", RED);
            perror("Errore nella lettura della stringa");
            printf("%s", RESET);
            dest[0] = '\0';
        }

        if (strlen(dest) != lunghezza)
        {
            flag = true;
            fflush(stdin);
            printf("%sStringa non valida, riprova.\n%s", RED, RESET); // TODO non funziona?
        }
        else
        {
            flag = false;
        }

    } while (flag);
}

void input_string(const char *prompt, char *dest, int_pos lunghezza)
{
    bool flag = false;
    char buffer[100] = {'\0'};

    do
    {
        fflush(stdin);
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin))
        {
            buffer[strcspn(buffer, "\n")] = 0; // Rimuove il newline finale

            if (strlen(buffer) == 0 || strlen(buffer) > lunghezza)
            {
                flag = true;
                printf("%s\nStringa non valida, riprova.\n%s", RED, RESET);
            }
            else
            {
                flag = false;
                if (sscanf(buffer, "%[^\n]", dest) != 1)
                    dest[0] = '\0';
            }
        }
        else
        {
            printf("%s", RED);
            perror("Errore nella lettura della stringa");
            printf("%s", RED);
            dest[0] = '\0';
            flag = true;
        }

    } while (flag);
}

void input_float(const char *prompt, float *dest, float min)
{
    bool flag = false;

    do
    {
        fflush(stdin);
        printf("%s", prompt);

        if (scanf("%f", dest) != 1 || *dest < min || *dest == 0)
        {
            printf("%s", RED);
            puts("Valore non valido, riprova.");
            printf("%s", RESET);
            flag = true;
            while (getchar() != '\n')
                ; // Pulisce il buffer di input
        }
        else
            flag = false;

    } while (flag);
}

void stampa_uscita()
{

    printf("%sUscita", BLUE);
    fflush(stdout); // Forza la stampa immediata

    for (int i = 0; i < 3; i++)
    {
        Sleep(500); // 500 millisecondi = 0.5 secondi
        printf(".");
        fflush(stdout); // Stampa subito il punto
    }
    printf("%s", RESET);
}

int confronta_spedizioni(Spedizione s1, Spedizione s2)
{
    // Priorità: true prima di false
    if (getPriorita(s1) != getPriorita(s2))
        return getPriorita(s2) - getPriorita(s1);

    // Data invio
    struct tm d1 = getData(s1, true);
    struct tm d2 = getData(s2, true);
    time_t t1 = mktime(&d1);
    time_t t2 = mktime(&d2);
    if (t1 != t2)
        return (int)(t1 - t2);

    // Peso: più leggero prima
    if (getPeso(getPacco(s1)) != getPeso(getPacco(s2)))
        return (getPeso(getPacco(s1)) < getPeso(getPacco(s1))) ? -1 : 1;

    return 0;
}

void inserisciOrdinato(CodaSpedizione ordinata, Spedizione nuova)
{
    CodaSpedizione temp;
    initCoda(temp); // inizializza coda temporanea

    bool inserito = false;

    while (!isEmpty(ordinata))
    {
        Spedizione corrente = dequeue(ordinata);

        if (!inserito && confronta_spedizioni(nuova, corrente) < 0)
        {
            enqueue(temp, nuova);
            inserito = true;
        }

        enqueue(temp, corrente);
    }

    if (!inserito)
    {
        enqueue(temp, nuova);
    }

    // Copia la coda temporanea nella coda ordinata
    while (!isEmpty(temp))
    {
        enqueue(ordinata, (dequeue(temp)));
    }
}

bool rimuovi_doppioni_coda(CodaSpedizione coda)
{
    if (!coda || !getNodoTesta(coda))
        return false;

    NodoSpedizione esterno = getNodoTesta(coda);

    while (esterno != NULL)
    {
        char *id_corrente = get_numID((getPacco(getSpedDaNodo(esterno))));
        NodoSpedizione precedente = esterno;
        NodoSpedizione interno = getProssimoNodo(esterno);

        while (interno != NULL)
        {
            if (confronta_id(id_corrente, get_numID((getPacco(getSpedDaNodo(interno))))) == 0)
            {
                setProssimoNodo(esterno, getProssimoNodo(interno));
                free(interno);
                interno = getProssimoNodo(precedente);
            }
            else
            {
                precedente = interno;
                interno = getProssimoNodo(interno);
            }
        }

        esterno = getProssimoNodo(esterno);
    }

    return true;
}

void ordinaCodaSpedizioni(CodaSpedizione originale)
{

    if (isEmpty(originale))
    {
        printf("%sNiente da ordinare, coda vuota%s\n", YELLOW, RESET);
        return;
    }
    CodaSpedizione ordinata;
    initCoda(ordinata);

    while (!isEmpty(originale))
    {
        Spedizione s = dequeue(originale);
        inserisciOrdinato(ordinata, s);
    }

    // Copia la coda ordinata nella coda originale
    while (!isEmpty(ordinata))
    {
        enqueue(originale, dequeue(ordinata));
    }
    printf("\n%sCoda ordinata correttamente%s\n", GREEN, RESET);
}

int confronta_id(char* stringa1, char* stringa2)
{
    return strcmp(stringa1, stringa2);
}

void stampa_spedizione(Spedizione s)
{
    puts("<-------------------------------->");

    printf("%s---Pacco---%s\n", BLUE, RESET);

    stampa_pacco(getPacco(s));

    printf("%sPriorità%s: %s\n", WHITE, RESET, getPriorita(s) ? "Alta" : "Normale");

    printf("%sSpedito in data%s: %d/%d/%d \n", WHITE, RESET, getGiorno(getData(s, true)), getMese(getData(s, true)), getAnno(getData(s, true)));
    printf("%sConsegna prevista in data%s: %d/%d/%d \n", WHITE, RESET, getGiorno(getData(s, false)), getMese(getData(s, false)), getAnno(getData(s, false)));

    printf("%s---Mittente---%s\n", BLUE, RESET);
    stampa_Persona(getPersona(s, true));

    printf("%s---Destinatario---%s\n", BLUE, RESET);
    stampa_Persona(getPersona(s, false));

    printf("%sStato della spedizione%s: ", WHITE, RESET);
    switch (getStato(s))
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
    puts("<-------------------------------->");
}

// stampare le mittente/destinatario fuori
void stampa_Persona(Persona d)
{
    printf("%sNome e cognome%s: %s %s \n", WHITE, RESET, getNome(d), getCognome(d));
    printf("%sTelefono%s: %16s, ", WHITE, RESET, getTelefono(d));
    printf("%sEmail%s: %s\n", WHITE, RESET, getMail(d));
    printf("%sIndirizzo%s: %s, ", WHITE, RESET, getVia(d));
    printf("%sCittà%s: %s, ", WHITE, RESET, getCitta(d));
    printf("%sProvincia%s: %2s, ", WHITE, RESET, getProv(d));
    printf("%sCAP%s: %5s\n", WHITE, RESET, getCAP(d));
}


void stampa_coda_spedizioni(CodaSpedizione coda)
{
    // #TODO modificare
    NodoSpedizione corrente = getNodoTesta(coda);
    if (corrente == NULL)
    {
        printf("\n%sLa coda è vuota!%s\n", YELLOW, RESET);
        return;
    }
    while (corrente != NULL)
    {
        stampa_spedizione(getSpedDaNodo(corrente));
        corrente = getProssimoNodo(corrente);
    }
}