
#ifndef DATI_H
#define DATI_H

#include <stdbool.h>
#include <time.h>

/**
 * @struct Destinatario
 * @brief Definisce la struttura Destinatario con  le relative informazioni per una spedizione.
 */
typedef struct
{
    char nome[30];
    char cognome[30];
    char telefono[17]; // formato: +39 123 456 7890
    char via[100];     // Indirizzo (via, numero civico, ecc.)
    char citta[50];
    char provincia[3];
    char cap[6];
    char email[50];
} Persona;

typedef Persona Mittente;
typedef Persona Destinatario;

void setNome(char *, Persona *);
char *getNome(Persona *);

void setCognome(char *str, Persona *);
char *getCognome(Persona *);

void setTelefono(char *str, Persona *);
char *getTelefono(Persona *);

void setVia(char *str, Persona *);
char *getVia(Persona *);

void setCitta(char *str, Persona *);
char *getCitta(Persona *);

void setProv(char *str, Persona *);
char *getProv(Persona *);

void setCAP(char *str, Persona *);
char *getCAP(Persona *);

void setMail(char *str, Persona *);
char *getMail(Persona *);

/**
 * @brief Permette l'inserimento dei dati del destinatario tramite input da tastiera.
 * @param d Puntatore alla struttura Destinatario da riempire.
 */
void inserimento_Persona(Persona *);

/**
 * @brief Stampa a video le informazioni del destinatario.
 * @param d Struttura Destinatario da stampare.
 */
void stampa_Destinatario(Destinatario d);
/**
 * @brief Stampa a video le informazioni del mittente.
 *
 * Visualizza su stdout i dati contenuti in una struttura Mittente in formato leggibile.
 *
 * @param[in] m Mittente da stampare.
 */
void stampa_mittente(Mittente m);

/**
 * @struct Pacco
 * @brief Definisce un pacco.
 *
 * Contiene informazioni identificative e fisiche del pacco:
 * - codice identificativo (`n`)
 * - peso in grammi
 * - volume in centimetri cubi
 */
typedef struct
{
    char n[10];   // codice identificativo del pacco, ad esempio "IT1234567"
    float peso;   // in grammi
    float volume; // in centimetri cubi
} Pacco;

void set_numID(char *, Pacco *);
char *get_numID(Pacco *);

void setPeso(float, Pacco *);
float getPeso(Pacco);

void setVolume(float, Pacco *);
float getVolume(Pacco);

/**
 * @brief Richiede all'utente i dati del pacco e li inserisce nella struttura.
 *
 * @param[out] p Puntatore alla struttura Pacco da riempire.
 */
void inserimento_pacco(Pacco *p);

/**
 * @brief Stampa a video le informazioni del pacco.
 *
 * @param[in] p La struttura Pacco da visualizzare.
 */
void stampa_pacco(Pacco p);

/**
 * @enum Stati
 * @brief Elenco degli stati possibili di una spedizione.
 */
enum Stati
{
    ordinato = 1,
    spedito,
    in_consegna,
    consegnato,
    annullato
};

typedef struct
{
    Pacco p;
    bool priorita;           // true se il pacco ha priorità, false altrimenti
    struct tm data_invio;    // data di invio del pacco
    struct tm data_consegna; // data di consegna prevista del pacco
    Mittente mittente;
    Destinatario destinatario;
    enum Stati stato;
} Spedizione;

typedef struct NodoSpedizione
{
    Spedizione sped;
    struct NodoSpedizione *nextPtr;
} NodoSpedizione;

typedef struct
{
    NodoSpedizione *testaPtr;
    NodoSpedizione *codaPtr;
} CodaSpedizione;

void initCoda(CodaSpedizione *coda);
void enqueue(CodaSpedizione *coda, Spedizione sped);
int dequeue(CodaSpedizione *coda, Spedizione *sped);

void setPersona(Spedizione *s, Persona *p, bool tipo);
Persona getPersona(Spedizione *s, bool tipo);

void setPriorita(bool, Spedizione *);
bool getPriorita(Spedizione);

void setStato(int, Spedizione *);
int getStato(Spedizione);

void setData(const char *prompt, Spedizione *, bool);
struct tm getData(Spedizione, bool);

/**
 * @brief Stampa i dati completi di una spedizione.
 *
 * @param s La spedizione da stampare.
 */
void stampa_spedizione(Spedizione s);

/**
 * @brief Confronta due ID di pacchi (funzione di confronto per qsort).
 *
 * @param id1 Puntatore al primo elemento (stringa).
 * @param id2 Puntatore al secondo elemento (stringa).
 * @return Valore negativo, zero o positivo se id1 è minore, uguale o maggiore di id2.
 */
int confronta_id(const void *id1, const void *id2);

/**
 * @brief Convalida le spedizioni presenti nella coda.
 * Le spedizioni vengono mostrate all’utente che può decidere se convalidarle, eliminarle o lasciarle nella coda.
 * @param c Puntatore alla coda.
 */
void convalida_spedizioni(CodaSpedizione *c);

/**
 * @brief Inserisce una nuova spedizione (con eventuale richiesta all'utente).
 * @param c Puntatore alla coda.
 */

// void inserimento_spedizione(CodaSpedizione *c);
void inserimento_spedizione(Spedizione *s);

#endif // DATI_H
