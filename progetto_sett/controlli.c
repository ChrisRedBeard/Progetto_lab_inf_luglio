#include <stdbool.h>
#include <time.h>
#include <stdio.h>

#include "controlli.h"
#include "funzioni.h"

/**
 * @brief Verifica che la data di invio sia precedente o uguale alla data di consegna.
 *
 * Se l'anno, mese o giorno della data di invio è maggiore di quello della consegna,
 * viene restituito `false` con messaggio di errore.
 *
 * @param d_invio Data di invio del pacco.
 * @param d_cons Data di consegna prevista del pacco.
 * @return true se la data di invio è antecedente o uguale a quella di consegna, false altrimenti.
 */
bool controllo_date(struct tm d_invio, struct tm d_cons)
{
    if (d_invio.tm_year > d_cons.tm_year)
    {
        printf("%sHai inserito una data di invio con anno superiore a quello di consegna, riprova%s\n", RED, RESET);
        return false;
    }

    if (d_invio.tm_year == d_cons.tm_year && d_invio.tm_mon > d_cons.tm_mon)
    {
        printf("%sHai inserito una data di invio con mese superiore a quello di consegna, riprova%s\n", RED, RESET);
        return false;
    }

    if (d_invio.tm_year == d_cons.tm_year && d_invio.tm_mon == d_cons.tm_mon && d_invio.tm_mday > d_cons.tm_mday)
    {
        printf("%sHai inserito una data di invio con giorno superiore a quello di consegna, riprova%s\n", RED, RESET);
        return false;
    }

    return true;
}