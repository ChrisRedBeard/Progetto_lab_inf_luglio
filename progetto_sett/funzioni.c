#include "funzioni.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

void input_id(const char *prompt, char *dest, int_pos lunghezza)
{
    size_t size = sizeof(char) * (lunghezza+1);
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
            printf("%sStringa non valida, riprova.\n%s", RED, RESET); //TODO non funziona?
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

void stampa_uscita(){

     printf("%sUscita",BLUE);
    fflush(stdout);  // Forza la stampa immediata

    for (int i = 0; i < 3; i++) {
        Sleep(500);  // 500 millisecondi = 0.5 secondi
        printf(".");
        fflush(stdout);  // Stampa subito il punto
    }
    printf("%s",RESET);

}

int confronta_spedizioni(const void *a, const void *b)
{
    Spedizione *s1 = (Spedizione *)a;
    Spedizione *s2 = (Spedizione *)b;

    // Priorità: true prima di false
    if (getPriorita(*s1) != getPriorita(*s2))
        return getPriorita(*s2) - getPriorita(*s1);

    // Data invio
    struct tm d1 = getData(*s1, true);
    struct tm d2 = getData(*s2, true);
    time_t t1 = mktime(&d1);
    time_t t2 = mktime(&d2);
    if (t1 != t2)
        return (int)(t1 - t2);

    // Peso: più leggero prima
    if (getPeso((s1->p)) != getPeso((s2->p)))
        return (s1->p.peso < s2->p.peso) ? -1 : 1;

    return 0;
}

void inserisciOrdinato(CodaSpedizione *ordinata, Spedizione nuova)
{
    CodaSpedizione temp;
    initCoda(&temp); // inizializza coda temporanea

    bool inserito = false;

    while (!isEmpty(*ordinata))
    {
        Spedizione *corrente = dequeue(ordinata);

        if (!inserito && confronta_spedizioni(&nuova, &corrente) < 0)
        {
            enqueue(&temp, nuova);
            inserito = true;
        }

        enqueue(&temp, *corrente);
    }

    if (!inserito)
    {
        enqueue(&temp, nuova);
    }

    // Copia la coda temporanea nella coda ordinata
    while (!isEmpty(temp))
    {
        enqueue(ordinata, *(dequeue(&temp)));
    }
}


bool rimuovi_doppioni_coda(CodaSpedizione *coda) {
    if (!coda || !coda->testaPtr)
        return false;

    NodoSpedizione *esterno = coda->testaPtr;

    while (esterno != NULL) {
        char *id_corrente = esterno->sped.p.n;
        NodoSpedizione *precedente = esterno;
        NodoSpedizione *interno = esterno->nextPtr;

        while (interno != NULL) {
            if (strcmp(id_corrente, interno->sped.p.n) == 0) {
                precedente->nextPtr = interno->nextPtr;
                free(interno);
                interno = precedente->nextPtr;
            } else {
                precedente = interno;
                interno = interno->nextPtr;
            }
        }

        esterno = esterno->nextPtr;
    }

    return true;
}


void ordinaCodaSpedizioni(CodaSpedizione *originale)
{

    if (isEmpty(*originale))
    {
        printf("%sNiente da ordinare, coda vuota%s\n", YELLOW, RESET);
        return;
    }
    CodaSpedizione ordinata;
    initCoda(&ordinata);

    while (!isEmpty(*originale))
    {
        Spedizione *s = dequeue(originale);
        inserisciOrdinato(&ordinata, *s);
    }

    // Copia la coda ordinata nella coda originale
    while (!isEmpty(ordinata))
    {
        enqueue(originale, *(dequeue(&ordinata)));
    }
    printf("\n%sCoda ordinata correttamente%s\n", GREEN, RESET);
}
