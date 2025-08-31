/**
 * @file spedizione.c
 * @brief Implementazione delle funzioni per la gestione delle spedizioni.
 *
 * Questo file contiene le definizioni delle funzioni per l'inserimento e la stampa delle
 * spedizioni, la verifica delle date e il confronto tra ID pacchi.
 */
#include "spedizione.h"
#include "coda.h"
#include <string.h>
#include <stdlib.h>


/**
 * @brief Richiede all'utente di inserire una data nel formato gg mm aaaa.
 *
 * La funzione controlla la validità della data inserita, considerando mesi con 30/31 giorni,
 * febbraio e anni bisestili.
 *
 * @param prompt Messaggio da visualizzare all'utente.
 * @param data Puntatore alla struttura `tm` da riempire con la data inserita.
 */
void inserimento_data(const char *prompt, struct tm *data)
{
    bool flag = false;
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

/**
 * @brief Stampa a video i dettagli completi di una spedizione.
 *
 * La funzione stampa i dati del pacco, la priorità, le date di invio e consegna,
 * il mittente, il destinatario e lo stato della spedizione.
 *
 * @param s Struttura `Spedizione` da stampare.
 */
void stampa_spedizione(Spedizione s)
{
    puts("<-------------------------------->");

    stampa_pacco(s.p);

    printf("%sPriorità%s: %s\n",WHITE, RESET,s.priorita ? "Alta" : "Normale");

    printf("%sSpedito in data%s: %d/%d/%d \n", WHITE,RESET,s.data_invio.tm_mday, s.data_invio.tm_mon, s.data_invio.tm_year);
    stampa_mittente(s.mittente);

    printf("%sConsegna prevista in data%s: %d/%d/%d \n", WHITE,RESET,s.data_consegna.tm_mday, s.data_consegna.tm_mon, s.data_consegna.tm_year);
    stampa_destinatario(s.destinatario);

    printf("%sStato della spedizione%s: ",WHITE,RESET);
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

/**
 * @brief Confronta due spedizioni in base all'ID del pacco.
 *
 * Funzione utile per ordinamenti (ad esempio con `qsort`). Gli ID vengono confrontati
 * come stringhe tramite `strcmp`.
 *
 * @param id1 Puntatore alla prima spedizione.
 * @param id2 Puntatore alla seconda spedizione.
 * @return < 0 se id1 < id2, 0 se uguali, > 0 se id1 > id2.
 */
int confronta_id(const void* id1,const void* id2){
    return strcmp(((Spedizione*)id1)->p.n, ((Spedizione*)id2)->p.n);
}
