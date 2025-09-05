/**
 * @file controlli.h
 * @brief Funzioni di validazione per dati relativi a spedizioni, contatti e identificativi.
 *
 * Questo modulo contiene funzioni per il controllo della validità di:
 * - date di invio/consegna
 * - numeri di telefono
 * - indirizzi email
 * - codici di provincia italiani
 * - identificativi univoci
 */

#ifndef CONTROLLI_H
#define CONTROLLI_H

#include <stdbool.h>
#include <time.h>

/**
 * @brief Verifica che la data di invio sia precedente o uguale alla data di consegna.
 *
 * Confronta anno, mese e giorno tra le due date. Se la data di invio è successiva
 * alla data di consegna, la funzione restituisce false.
 *
 * @param data_invio Data di invio del pacco.
 * @param data_consegna Data di consegna prevista del pacco.
 * @return true Se la data di invio è antecedente o uguale a quella di consegna.
 * @return false Se la data di invio è successiva alla data di consegna.
 */
bool controllo_date(struct tm data_invio, struct tm data_consegna);

/**
 * @brief Verifica se una stringa rappresenta un numero di telefono italiano valido.
 *
 * Il formato previsto è: +XX XXX XXX XXXX (totale 16 caratteri).
 * Controlla la presenza del prefisso internazionale, spazi e blocchi numerici.
 *
 * @param s Puntatore alla stringa del numero di telefono.
 * @return true Se il formato è valido.
 * @return false Se il formato è errato.
 */
bool check_phone_format(const char *s);

/**
 * @brief Verifica se una stringa è un indirizzo email valido.
 *
 * Controlla la presenza della chiocciola '@', la validità della parte locale e del dominio.
 * La parte locale può contenere lettere, numeri, '.', '_', '-', '+', ma non punti consecutivi.
 * Il dominio deve contenere almeno un punto, non iniziare o finire con '.', e avere etichette valide.
 *
 * @param email Puntatore alla stringa dell'indirizzo email.
 * @return true Se l'indirizzo email è valido.
 * @return false Se l'indirizzo email è invalido.
 */
bool check_email_format(const char *email);

/**
 * @brief Elenco dei codici di provincia italiani.
 *
 * Array statico contenente i codici delle province italiane (es. "MI", "RM", "TO", ecc.).
 */
static const char *province[] = {
    "AG", "AL", "AN", "AO", "AR", "AP", "AQ", "AT", "AV", "BA", "BG", "BI", "BN", "BO",
    "BR", "BS", "BT", "BZ", "CA", "CB", "CE", "CH", "CL", "CN", "CO", "CR", "CS", "CT",
    "CZ", "EN", "FC", "FE", "FG", "FI", "FM", "FR", "GE", "GO", "GR", "IM", "IS", "KR",
    "LC", "LE", "LI", "LO", "LT", "LU", "MB", "MC", "ME", "MI", "MN", "MO", "MS", "MT",
    "NA", "NO", "NU", "OR", "PA", "PC", "PD", "PE", "PG", "PI", "PN", "PO", "PR", "PT",
    "PV", "PZ", "RA", "RC", "RE", "RG", "RI", "RM", "RN", "RO", "SA", "SI", "SO", "SP",
    "SR", "SS", "SV", "TA", "TE", "TN", "TO", "TP", "TR", "TS", "TV", "VA", "VB", "VC",
    "VE", "VI", "VT", "VV"};

/**
 * @brief Verifica se i primi due caratteri di una stringa rappresentano un codice di provincia italiano valido.
 *
 * I codici validi sono confrontati con una lista di province note.
 * I primi due caratteri devono essere lettere maiuscole.
 *
 * @param id Puntatore alla stringa contenente il codice identificativo.
 * @return true Se il codice di provincia è valido.
 * @return false Se il codice non è valido o non è presente.
 */
bool check_provincia(const char *email);

/**
 * @brief Verifica se un identificativo è valido secondo il formato: 2 lettere + 7 cifre.
 *
 * Controlla che i primi due caratteri siano lettere maiuscole (codice provincia)
 * e che i successivi 7 caratteri siano cifre.
 *
 * @param id Puntatore alla stringa dell'identificativo.
 * @return true Se l'identificativo è valido.
 * @return false Se l'identificativo non è valido.
 */

bool check_Id(const char *email);

/**
 * @brief Numero totale di codici di provincia presenti nell'array `province`.
 */

static const size_t province_count = sizeof(province) / sizeof(province[0]);

#endif // CONTROLLI_H