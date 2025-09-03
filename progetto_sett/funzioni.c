#include "funzioni.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

/**
 * @brief Legge da input uno specifico ID con lunghezza fissa.
 *
 * Questa funzione richiede all'utente di inserire una stringa tramite stdin.
 * L'input viene accettato solo se la stringa ha esattamente la lunghezza richiesta,
 * altrimenti viene chiesta nuovamente.
 * Rimuove il carattere di newline se presente.
 *
 * @param prompt Messaggio mostrato all'utente per richiedere l'input.
 * @param dest Buffer dove salvare la stringa inserita dall'utente.
 * @param size Dimensione massima del buffer (incluso terminatore nullo).
 * @param lunghezza Lunghezza esatta richiesta per l'ID (escluso terminatore nullo).
 */
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

/**
 * @brief Legge da input una stringa con lunghezza massima specificata.
 *
 * La funzione richiede all'utente di inserire una stringa tramite stdin.
 * L'input viene accettato solo se la stringa è non vuota e non supera la lunghezza massima.
 * Rimuove il carattere di newline se presente.
 * In caso di errore nella lettura o di input non valido, viene richiesto di riprovare.
 *
 * @param prompt Messaggio mostrato all'utente per richiedere l'input.
 * @param dest Buffer dove salvare la stringa inserita.
 * @param size Dimensione massima del buffer (incluso terminatore nullo).
 * @param lunghezza Lunghezza massima accettabile per la stringa (escluso terminatore nullo).
 */
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

/**
 * @brief Legge da input un numero in virgola mobile (float) con valore minimo.
 *
 * La funzione richiede all'utente di inserire un valore float tramite stdin.
 * Viene controllato che il valore inserito sia valido e maggiore o uguale al minimo indicato.
 * Se l'input è non valido o minore del minimo, viene chiesto di riprovare.
 *
 * @param prompt Messaggio mostrato all'utente per richiedere l'input.
 * @param dest Puntatore alla variabile float dove salvare il valore inserito.
 * @param min Valore minimo accettabile (incluso).
 */
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