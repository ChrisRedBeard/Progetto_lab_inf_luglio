#include "utils.h"

#include <stdbool.h>

#include <string.h>

void input_id(const char *prompt, char *dest, int_pos size, int_pos lunghezza)
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
            printf("%s", RED);
            perror("Errore nella lettura della stringa");
            printf("%s", RESET);
            dest[0] = '\0';
        }

        if (strlen(dest) != lunghezza)
        {
            flag = true;
            fflush(stdin);
            printf("%sStringa non valida, riprova.\n%s", RED, RESET);
        }
        else
        {
            flag = false;
        }

    } while (flag);
}

void input_string(const char *prompt, char *dest, int_pos size, int_pos lunghezza)
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
                fflush(stdin);
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