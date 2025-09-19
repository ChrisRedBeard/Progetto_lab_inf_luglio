#ifndef FUNZIONI_H
#define FUNZIONI_H

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define WHITE "\033[97m"

#include "dati.h"

typedef unsigned short int int_pos;

// --- Funzioni input ---
void input_string(const char *prompt, char *dest, int_pos lunghezza);
void input_float(const char *prompt, float *dest, float min);
void input_id(const char *prompt, char *dest, int_pos lunghezza);

// --- Funzioni stampa ---
void stampa_uscita();
void stampa_spedizione(Spedizione *s);
void stampa_coda_spedizioni(CodaSpedizione *coda);

// --- Funzioni confronto ---
int confronta_spedizioni(Spedizione *s1, Spedizione *s2);
int confronta_id(char * id1,char * id2);

// --- Funzioni gestione coda ---
bool rimuovi_doppioni_coda(CodaSpedizione *coda);
void inserisciOrdinato(CodaSpedizione *ordinata, Spedizione *nuova);
void ordinaCodaSpedizioni(CodaSpedizione *originale);

#endif // FUNZIONI_H