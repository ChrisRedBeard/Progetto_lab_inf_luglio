#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "controlli.h"
#include "funzioni.h"

bool controllo_date(struct tm d_invio, struct tm d_cons)
{
    // Se l'anno è maggiore
    if (d_invio.tm_year > d_cons.tm_year)
    {
        printf("%sHai inserito una data di invio con anno superiore a quello di consegna, riprova%s\n", RED, RESET);
        return false;
    }
    // Se l'anno è uguale a quello di consegna ,confronto il mese
    if (d_invio.tm_year == d_cons.tm_year && d_invio.tm_mon > d_cons.tm_mon)
    {
        printf("%sHai inserito una data di invio con mese superiore a quello di consegna, riprova%s\n", RED, RESET);
        return false;
    }
    // Se l'anno e il mese sono uguali a quella di consegna ,confronto il giorno
    if (d_invio.tm_year == d_cons.tm_year && d_invio.tm_mon == d_cons.tm_mon && d_invio.tm_mday > d_cons.tm_mday)
    {
        printf("%sHai inserito una data di invio con giorno superiore a quello di consegna, riprova%s\n", RED, RESET);
        return false;
    }

    return true;
}

bool check_phone_format(const char *s)
{
    if (!s)
        return false;
    if (s[0] != '+' || !isdigit((unsigned char)s[1]) || !isdigit((unsigned char)s[2]) || s[3] != ' ')
        return false;

    // blocco delle prime 3 cifre
    for (int i = 4; i <= 6; i++)
        if (!isdigit((unsigned char)s[i]))
            return false;
    if (s[7] != ' ')
        return false;

    // blocco delle seconde 3 cifre
    for (int i = 8; i <= 10; i++)
        if (!isdigit((unsigned char)s[i]))
            return false;
    if (s[11] != ' ')
        return false;

    // ultimo blocco da 4 cifre
    for (int i = 12; i <= 15; i++)
        if (!isdigit((unsigned char)s[i]))
            return false;

    // fine stringa
    return s[16] == '\0';
}

bool check_email_format(const char *email)
{

    // vado a controllare la presenza e posizionamento della chiocciola
    const char *at = strchr(email, '@');
    if (!at || at == email)
    {
        return false;
    }

    // controllo la parte prima della '@'
    const char *local = email;

    // controllo caratteri ammessi e punti non consecutivi
    for (const char *p = local; p < at; ++p)
    {
        char c = *p;
        if (!(isalnum(c) || c == '.' || c == '_' || c == '-' || c == '+'))
        {
            return false;
        }
        if (p > local && p[-1] == '.' && c == '.')
        {
            return false;
        }
    }
    // la parte locale non inizia o finisce con '.'
    if (local[0] == '.' || at[-1] == '.')
    {
        return false;
    }

    // 3. Validazione del dominio (dopo la '@')
    const char *domain = at + 1;
    size_t domain_len = strlen(domain);
    // non vuoto, non inizia o finisce con '.', e contiene almeno un punto
    if (domain_len == 0 || domain[0] == '.' || domain[domain_len - 1] == '.' || !strchr(domain, '.'))
    {
        return false;
    }

    // controllo etichette di dominio (alphanumeric e '-'), no doppio '-', no label vuota
    const char *label = domain;
    for (const char *p = domain;; ++p)
    {
        if (*p == '.' || *p == '\0')
        {
            // etichetta vuota
            if (p == label)
            {
                return false;
            }
            // non inizia o finisce con '-'
            if (label[0] == '-' || p[-1] == '-')
            {
                return false;
            }
            if (*p == '\0')
            {
                break;
            }
            label = p + 1;
        }
        else if (!(isalnum(*p) || *p == '-'))
        {
            return false;
        }
    }

    return true;
}

bool check_provincia(const char *id)
{
    if (!id)
        return false;

    // i primi due caratteri devono essere lettere maiuscole
    if (!isupper((unsigned char)id[0]) || !isupper((unsigned char)id[1]))
        return false;

    // compongo una stringa "XX\0" per il confronto
    char code[3] = {id[0], id[1], '\0'};

    // confronto con tutti i codici noti
    for (size_t i = 0; i < province_count; ++i)
    {
        if (strcmp(code, province[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

bool check_Id(const char *id)
{

    // 2 lettere della provincia + 7 cifre del codice
    if (!id || strlen(id) != 9)
        return false;
    // vado a controllare i primi 2 caratteri
    if (!check_provincia(id))
        return false;

    // verifica che i restanti 7 siano cifre
    for (int i = 2; i < 9; ++i)
    {
        if (!isdigit((unsigned char)id[i]))
            return false;
    }

    return true;
}