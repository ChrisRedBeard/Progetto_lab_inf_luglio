#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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


/**
 * Verifica che s sia esattamente "+39 123 456 7890", formato italiano
 * - s[0] = '+'
 * - s[1]='3', s[2]='9'
 * - s[3]=' '
 * - s[4..6] = cifre
 * - s[7]=' '
 * - s[8..10] = cifre
 * - s[11]=' '
 * - s[12..15] = cifre
 * - s[16] = '\\0'
 */
bool check_phone_format(const char *s) {
    if (!s) 
        return false;
    if (s[0] != '+' || !isdigit((unsigned char)s[1]) || !isdigit((unsigned char)s[2]) || s[3] != ' ')
        return false;

    // blocco 1 (3 cifre)
    for (int i = 4; i <= 6; i++)
        if (!isdigit((unsigned char)s[i]))
            return false;
    if (s[7] != ' ')
        return false;

    // blocco 2 (3 cifre)
    for (int i = 8; i <= 10; i++)
        if (!isdigit((unsigned char)s[i]))
            return false;
    if (s[11] != ' ')
        return false;

    // blocco 3 (4 cifre)
    for (int i = 12; i <= 15; i++)
        if (!isdigit((unsigned char)s[i]))
            return false;

    // fine stringa
    return s[16] == '\0';
}


bool check_email_format(const char *email) {
    // 1. Presenza e posizionamento della chiocciola
    const char *at = strchr(email, '@');
    if (!at || at == email) {
        return false;
    }

    // 2. Validazione della parte locale (prima della '@')
    const char *local = email;
    // controllo caratteri ammessi e punti non consecutivi
    for (const char *p = local; p < at; ++p) {
        char c = *p;
        if (!(isalnum(c) || c == '.' || c == '_' || c == '-' || c == '+')) {
            return false;
        }
        if (p > local && p[-1] == '.' && c == '.') {
            return false;
        }
    }
    // la parte locale non inizia o finisce con '.'
    if (local[0] == '.' || at[-1] == '.') {
        return false;
    }

    // 3. Validazione del dominio (dopo la '@')
    const char *domain = at + 1;
    size_t domain_len = strlen(domain);
    // non vuoto, non inizia o finisce con '.', e contiene almeno un punto
    if (domain_len == 0 || domain[0] == '.' || domain[domain_len-1] == '.' || !strchr(domain, '.')) {
        return false;
    }

    // controllo etichette di dominio (alphanumeric e '-'), no doppio '-', no label vuota
    const char *label = domain;
    for (const char *p = domain; ; ++p) {
        if (*p == '.' || *p == '\0') {
            // etichetta vuota
            if (p == label) {
                return false;
            }
            // non inizia o finisce con '-'
            if (label[0] == '-' || p[-1] == '-') {
                return false;
            }
            if (*p == '\0') {
                break;
            }
            label = p + 1;
        } else if (!(isalnum(*p) || *p == '-')) {
            return false;
        }
    }

    return true;
}

bool check_provincia(const char *id) {
    if (!id) 
        return false;

    // i primi due caratteri devono essere lettere maiuscole
    if (!isupper((unsigned char)id[0]) || !isupper((unsigned char)id[1]))
        return false;

    // compongo una stringa "XX\0" per il confronto
    char code[3] = { id[0], id[1], '\0' };

    // confronto con tutti i codici noti
    for (size_t i = 0; i < province_count; ++i) {
        if (strcmp(code, province[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool check_Id(const char *id){
 
    if (!id || strlen(id) != 9)    // 2 lettere + 7 cifre
        return false;

    if (!check_provincia(id))      // controlla i primi 2 caratteri
        return false;

    // verifica che i restanti 7 siano cifre
    for (int i = 2; i < 9; ++i) {
        if (!isdigit((unsigned char)id[i]))
            return false;
    }

    return true;
}