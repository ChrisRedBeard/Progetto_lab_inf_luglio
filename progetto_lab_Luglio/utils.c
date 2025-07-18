#include "utils.h"


void input_string(const char *prompt, char *dest, size_t size)
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
}