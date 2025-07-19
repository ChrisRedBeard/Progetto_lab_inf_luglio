#include "utils.h"

#include <stdbool.h>

#include <string.h>

void input_string(const char *prompt, char *dest, int_pos size, int_pos lunghezza)
{

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
            perror("Errore nella lettura della stringa");
            dest[0] = '\0';
        }

        if (strlen(dest) == 0 && strlen(dest) > lunghezza)
            flag = true;
        else
            flag = false;

        flag ? true : puts("Stringa non valida, riprova.");

    } while (!flag);
}

void input_float(const char *prompt, float *dest, float min)
{
    bool flag = false;

    do
    {
        printf("%s", prompt);

        if (scanf("%f", dest) != 1 || *dest < min)
        {
            puts("Valore non valido, riprova.");
            flag = true;
            while (getchar() != '\n')
                ; // Pulisce il buffer di input
        }
        else
            flag = false;

    } while (flag);
}