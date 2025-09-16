#ifndef DATI_H
#define DATI_H

#include <stdbool.h>
#include <time.h>


/**
 * @file dati.h
 * @brief Definizione delle strutture e funzioni per la gestione dei dati relativi alle spedizioni.
 *
 * Questo modulo include le strutture per rappresentare persone, pacchi, spedizioni e code di spedizione,
 * oltre alle funzioni per la loro inizializzazione, modifica, visualizzazione e gestione.
 */

 
/**
 * @struct Persona
 * @brief Definisce una persona con i dati necessari per una spedizione.
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


/**
 * @brief Funzione per settare il nome di una struct Persona.
 * @param str Stringa contenente il nome.
 * @param p Puntatore alla struttura Persona.
 */
void setNome(char *, Persona *);

/**
 * @brief Funzione per ottenere il nome da una struct Persona.
 * @param p Puntatore alla struttura Persona.
 * @return nome come stringa.
 */
char *getNome(Persona *);

/**
 * @brief Funzione per settare il cognome di una struct Persona.
 * @param str Stringa contenente il cognome.
 * @param p Puntatore alla struttura Persona.
 */
void setCognome(char *str, Persona *);



/**
 * @brief Funzione per ottenere il cognome da una struct Persona.
 * @param p Puntatore alla struttura Persona.
 * @return Cognome come stringa.
 */

char *getCognome(Persona *);


/**
 * @brief Funzione per settare il numero di telefono di una struct Persona.
 * @param str Stringa contenente il numero di telefono.
 * @param p Puntatore alla struttura Persona.
 */

void setTelefono(char *str, Persona *);


/**
 * @brief Funzione per ottenere il numero di telefono da una struct Persona.
 * @param p Puntatore alla struttura Persona.
 * @return Numero di telefono come stringa.
 */
char *getTelefono(Persona *);


/**
 * @brief Funzione per settare l'indirizzo (via) di una struct Persona.
 * @param str Stringa contenente l'indirizzo.
 * @param p Puntatore alla struttura Persona.
 */
void setVia(char *str, Persona *);


/**
 * @brief Funzione per ottenere l'indirizzo (via) da una struct Persona.
 * @param p Puntatore alla struttura Persona.
 * @return Indirizzo come stringa.
 */
char *getVia(Persona *);


/**
 * @brief Funzione per settare la città di una struct Persona.
 * @param str Stringa contenente la città.
 * @param p Puntatore alla struttura Persona.
 */
void setCitta(char *str, Persona *);


/**
 * @brief Funzione per ottenere la città da una struct Persona.
 * @param p Puntatore alla struttura Persona.
 * @return Città come stringa.
 */
char *getCitta(Persona *);


/**
 * @brief Funzione per settare la provincia di una struct Persona.
 * @param str Stringa contenente la provincia.
 * @param p Puntatore alla struttura Persona.
 */
void setProv(char *str, Persona *);


/**
 * @brief Funzione per ottenere la provincia da una struct Persona.
 * @param p Puntatore alla struttura Persona.
 * @return Provincia come stringa.
 */
char *getProv(Persona *);


/**
 * @brief Funzione per settare il CAP di una struct Persona.
 * @param str Stringa contenente il CAP.
 * @param p Puntatore alla struttura Persona.
 */
void setCAP(char *str, Persona *);



/**
 * @brief Funzione per ottenere il CAP da una struct Persona.
 * @param p Puntatore alla struttura Persona.
 * @return CAP come stringa.
 */
char *getCAP(Persona *);


/**
 * @brief Funzione per settare l'email di una struct Persona.
 * @param str Stringa contenente l'email.
 * @param p Puntatore alla struttura Persona.
 */
void setMail(char *str, Persona *);


/**
 * @brief Funzione per ottenere l'email da una struct Persona.
 * @param p Puntatore alla struttura Persona.
 * @return Email come stringa.
 */
char *getMail(Persona *);



/**
 * @brief Inserisce i dati di una persona tramite input da tastiera.
 * @param d Puntatore alla struttura Persona da riempire.
 */
void inserimento_Persona(Persona *);


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

/**
 * @brief Funzione per settare il codice identificativo di un pacco.
 * @param str Stringa contenente il codice identificativo.
 * @param p Puntatore alla struttura Pacco.
 */
void set_numID(char *str, Pacco *p);

/**
 * @brief Funzione per ottenere il codice identificativo di un pacco.
 * @param p Puntatore alla struttura Pacco.
 * @return Codice identificativo come stringa.
 */
char *get_numID(Pacco *p);

/**
 * @brief Funzione per settare il peso di un pacco.
 * @param peso Valore del peso in grammi.
 * @param p Puntatore alla struttura Pacco.
 */
void setPeso(float peso, Pacco *p);

/**
 * @brief Funzione per ottenere il peso di un pacco.
 * @param p Struttura Pacco.
 * @return Peso in grammi.
 */
float getPeso(Pacco p);

/**
 * @brief Funzione per settare il volume di un pacco.
 * @param volume Valore del volume in centimetri cubi.
 * @param p Puntatore alla struttura Pacco.
 */
void setVolume(float volume, Pacco *p);

/**
 * @brief Funzione per ottenere il volume di un pacco.
 * @param p Struttura Pacco.
 * @return Volume in centimetri cubi.
 */
float getVolume(Pacco p);


/**
 * @brief Inserisce i dati del pacco tramite input da tastiera.
 * @param p Puntatore alla struttura Pacco da riempire.
 */
void inserimento_pacco(Pacco *p);



/**
 * @brief Stampa le informazioni del pacco.
 * @param p Pacco da stampare.
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


/**
 * @struct Spedizione
 * @brief Rappresenta una spedizione completa con pacco, mittente, destinatario e stato.
 */

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


/**
 * @brief Imposta il mittente o il destinatario di una spedizione.
 * @param s Puntatore alla spedizione.
 * @param p Puntatore alla persona da assegnare.
 * @param tipo true per mittente, false per destinatario.
 */
void setPersona(Spedizione *s, Persona *p, bool tipo);


/**
 * @brief Restituisce il mittente o il destinatario di una spedizione.
 * @param s Puntatore alla spedizione.
 * @param tipo true per mittente, false per destinatario.
 * @return Struttura Persona corrispondente.
 */
Persona* getPersona(Spedizione *s, bool tipo);
/**
 * @struct NodoSpedizione
 * @brief Nodo di una lista collegata contenente una spedizione.
 */

typedef struct NodoSpedizione
{
    Spedizione sped;
    struct NodoSpedizione *nextPtr;
} NodoSpedizione;



/**
 * @struct CodaSpedizione
 * @brief Coda FIFO di spedizioni.
 */
typedef struct
{
    NodoSpedizione *testaPtr;
    NodoSpedizione *codaPtr;
} CodaSpedizione;

/**
 * @brief Inizializza una coda di spedizioni vuota.
 * @param coda Puntatore alla struttura CodaSpedizione da inizializzare.
 */
void initCoda(CodaSpedizione *coda);

/**
 * @brief Verifica se la coda di spedizioni è vuota.
 * @param coda La coda da controllare.
 * @return true Se la coda è vuota.
 * @return false Se la coda contiene almeno una spedizione.
 */
int isEmpty(CodaSpedizione c);

/**
 * @brief Inserisce una spedizione nella coda (enqueue).
 * @param coda Puntatore alla coda in cui inserire la spedizione.
 * @param sped La spedizione da inserire.
 */
void enqueue(CodaSpedizione *coda, Spedizione sped);

/**
 * @brief Estrae la prima spedizione dalla coda (dequeue).
 * @param coda Puntatore alla coda da cui estrarre.
 * @return Puntatore alla spedizione estratta, oppure NULL se la coda è vuota.
 */
Spedizione* dequeue(CodaSpedizione *coda);

/**
 * @brief Stampa tutte le spedizioni presenti nella coda.
 *
 * Visualizza su stdout le informazioni di ogni spedizione contenuta nella coda,
 * in ordine FIFO (First-In, First-Out).
 *
 * @param coda Puntatore alla coda da stampare.
 */
void stampa_coda_spedizioni(CodaSpedizione *coda);

/**
 * @brief Elimina una spedizione dalla coda.
 *
 * Permette all'utente di selezionare e rimuovere una spedizione dalla coda.
 *
 * @param coda Puntatore alla coda da cui eliminare la spedizione.
 */
void elimina_spedizione(CodaSpedizione *coda);

/**
 * @brief Modifica i dati di una spedizione presente nella coda.
 *
 * Consente all'utente di aggiornare le informazioni di una spedizione esistente.
 *
 * @param coda Puntatore alla coda contenente la spedizione da modificare.
 */
void modifica_spedizione(CodaSpedizione *coda);


/**
 * @brief Imposta la priorità di una spedizione.
 * @param priorita true se la spedizione è prioritaria, false altrimenti.
 * @param s Puntatore alla struttura Spedizione da modificare.
 */
void setPriorita(bool priorita, Spedizione *s);

/**
 * @brief Restituisce la priorità di una spedizione.
 * @param s La spedizione da controllare.
 * @return true Se la spedizione è prioritaria.
 * @return false Se la spedizione non è prioritaria.
 */
bool getPriorita(Spedizione s);

/**
 * @brief Imposta lo stato di una spedizione.
 * @param i Intero corrispondente allo stato (vedi enum Stati).
 * @param s Puntatore alla struttura Spedizione da modificare.
 */
void setStato(int i, Spedizione *s);

/**
 * @brief Restituisce lo stato attuale di una spedizione.
 * @param s La spedizione da controllare.
 * @return Intero corrispondente allo stato (vedi enum Stati).
 */
int getStato(Spedizione s);

/**
 * @brief Imposta la data di invio o di consegna di una spedizione.
 * @param prompt Messaggio da visualizzare per l'input.
 * @param s Puntatore alla struttura Spedizione da modificare.
 * @param tipo true per data di invio, false per data di consegna.
 */
void setData(const char *prompt, Spedizione *s, bool tipo);

/**
 * @brief Restituisce la data di invio o di consegna di una spedizione.
 * @param s La spedizione da cui estrarre la data.
 * @param tipo true per data di invio, false per data di consegna.
 * @return struct tm La data selezionata.
 */
struct tm getData(Spedizione s, bool tipo);

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
 * @brief Inserisce una nuova spedizione (con eventuale richiesta all'utente).
 * @param c Puntatore alla coda.
 */
void inserimento_spedizione(Spedizione *s);

/**
 * @brief Restituisce il pacco di una spedizione.
 * @param s La spedizione da cui estrarre il pacco.
 *
 */
Pacco* getPacco(Spedizione *s);

/**
 * @brief Inizializza una struttura Persona impostando i campi a valori predefiniti.
 * @param p Puntatore alla struttura Persona da inizializzare.
 */
void initPersona(Persona *p);

/**
 * @brief Inizializza una struttura Pacco impostando i campi a valori predefiniti.
 * @param p Puntatore alla struttura Pacco da inizializzare.
 */
void initPacco(Pacco *p);

/**
 * @brief Inizializza una struttura Spedizione impostando i campi a valori predefiniti.
 * @param s Puntatore alla struttura Spedizione da inizializzare.
 */
void initSpedizione(Spedizione *s);

/**
 * @brief Inizializza un nodo della coda di spedizioni.
 * @param n Puntatore alla struttura NodoSpedizione da inizializzare.
 */
void initNodoSpedizione(NodoSpedizione *n);


#endif // DATI_H
