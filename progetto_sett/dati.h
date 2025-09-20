#ifndef DATI_H
#define DATI_H

#include <stdbool.h>
#include <time.h>

/**
 * @file dati.h
 * @brief Dichiarazioni delle strutture dati e delle funzioni per la gestione di persone, pacchi, spedizioni e code di spedizioni.
 *
 * Questo header contiene le dichiarazioni delle strutture dati principali (Persona, Pacco, Spedizione, NodoSpedizione, CodaSpedizione)
 * e delle funzioni per la creazione, modifica, accesso e gestione delle spedizioni e delle relative code.
 */

/**
 * @brief Struttura che rappresenta una persona.
 */
typedef struct _persona Persona;

/**
 * @brief Struttura che rappresenta un pacco.
 */
typedef struct _pacco Pacco;

/**
 * @brief Struttura che rappresenta una spedizione.
 */
typedef struct _spedizione Spedizione;

/**
 * @brief Nodo della lista/coda delle spedizioni.
 */
typedef struct _nodo_spedizione NodoSpedizione;

/**
 * @brief Struttura che rappresenta una coda di spedizioni.
 */
typedef struct _coda_spedizione CodaSpedizione;

// --- Funzioni crea ---


/**
 * @brief Crea una nuova istanza di Spedizione.
 * @return Puntatore alla nuova Spedizione allocata.
 */
Spedizione *creaSpedizione();



/**
 * @brief Crea una nuova coda di spedizioni.
 * @return Puntatore alla nuova CodaSpedizione allocata.
 */
CodaSpedizione *creaCoda();

// --- Funzioni set ---
/**
 * @brief Imposta il nome della Persona.
 * @param str Nome da impostare.
 * @param p Puntatore alla Persona.
 */
void setNome(char *str, Persona *p);

/**
 * @brief Imposta il cognome della Persona.
 * @param str Cognome da impostare.
 * @param p Puntatore alla Persona.
 */
void setCognome(char *str, Persona *p);

/**
 * @brief Imposta il telefono della Persona.
 * @param str Numero di telefono.
 * @param p Puntatore alla Persona.
 */
void setTelefono(char *str, Persona *p);

/**
 * @brief Imposta la via della Persona.
 * @param str Via da impostare.
 * @param p Puntatore alla Persona.
 */
void setVia(char *str, Persona *p);

/**
 * @brief Imposta la città della Persona.
 * @param str Città da impostare.
 * @param p Puntatore alla Persona.
 */
void setCitta(char *str, Persona *p);

/**
 * @brief Imposta la provincia della Persona.
 * @param str Provincia da impostare.
 * @param p Puntatore alla Persona.
 */
void setProv(char *str, Persona *p);

/**
 * @brief Imposta il CAP della Persona.
 * @param str CAP da impostare.
 * @param p Puntatore alla Persona.
 */
void setCAP(char *str, Persona *p);

/**
 * @brief Imposta la mail della Persona.
 * @param str Indirizzo email.
 * @param p Puntatore alla Persona.
 */
void setMail(char *str, Persona *p);

/**
 * @brief Imposta il numero identificativo del Pacco.
 * @param str Numero identificativo.
 * @param p Puntatore al Pacco.
 */
void set_numID(char *str, Pacco *p);

/**
 * @brief Imposta il peso del Pacco.
 * @param peso Peso da impostare.
 * @param p Puntatore al Pacco.
 */
void setPeso(float peso, Pacco *p);

/**
 * @brief Imposta il volume del Pacco.
 * @param volume Volume da impostare.
 * @param p Puntatore al Pacco.
 */
void setVolume(float volume, Pacco *p);

/**
 * @brief Imposta la Persona associata alla Spedizione.
 * @param s Puntatore alla Spedizione.
 * @param p Puntatore alla Persona.
 * @param tipo true per destinatario, false per mittente.
 */
void setPersona(Spedizione *s, Persona *p, bool tipo);

/**
 * @brief Imposta la priorità della Spedizione.
 * @param priorita true se prioritaria, false altrimenti.
 * @param s Puntatore alla Spedizione.
 */
void setPriorita(bool priorita, Spedizione *s);

/**
 * @brief Imposta lo stato della Spedizione.
 * @param i Stato da impostare.
 * @param s Puntatore alla Spedizione.
 */
void setStato(int i, Spedizione *s);


/**
 * @brief Imposta il prossimo nodo nella lista.
 * @param n1 Puntatore al NodoSpedizione corrente.
 * @param n2 Puntatore al prossimo NodoSpedizione.
 */
void setProssimoNodo(NodoSpedizione *n1, NodoSpedizione *n2);



// --- Funzioni get ---
/**
 * @brief Restituisce il nome della Persona.
 * @param p Puntatore alla Persona.
 * @return Puntatore alla stringa del nome.
 */
char *getNome(Persona *p);

/**
 * @brief Restituisce il cognome della Persona.
 * @param p Puntatore alla Persona.
 * @return Puntatore alla stringa del cognome.
 */
char *getCognome(Persona *p);

/**
 * @brief Restituisce il telefono della Persona.
 * @param p Puntatore alla Persona.
 * @return Puntatore alla stringa del telefono.
 */
char *getTelefono(Persona *p);

/**
 * @brief Restituisce la via della Persona.
 * @param p Puntatore alla Persona.
 * @return Puntatore alla stringa della via.
 */
char *getVia(Persona *p);

/**
 * @brief Restituisce la città della Persona.
 * @param p Puntatore alla Persona.
 * @return Puntatore alla stringa della città.
 */
char *getCitta(Persona *p);

/**
 * @brief Restituisce la provincia della Persona.
 * @param p Puntatore alla Persona.
 * @return Puntatore alla stringa della provincia.
 */
char *getProv(Persona *p);

/**
 * @brief Restituisce il CAP della Persona.
 * @param p Puntatore alla Persona.
 * @return Puntatore alla stringa del CAP.
 */
char *getCAP(Persona *p);

/**
 * @brief Restituisce la mail della Persona.
 * @param p Puntatore alla Persona.
 * @return Puntatore alla stringa della mail.
 */
char *getMail(Persona *p);

/**
 * @brief Restituisce il numero identificativo del Pacco.
 * @param p Puntatore al Pacco.
 * @return Puntatore alla stringa del numero identificativo.
 */
char *get_numID(Pacco *p);

/**
 * @brief Restituisce il peso del Pacco.
 * @param p Puntatore al Pacco.
 * @return Peso del pacco.
 */
float getPeso(Pacco *p);

/**
 * @brief Restituisce il volume del Pacco.
 * @param p Puntatore al Pacco.
 * @return Volume del pacco.
 */
float getVolume(Pacco *p);

/**
 * @brief Restituisce la Persona associata alla Spedizione.
 * @param s Puntatore alla Spedizione.
 * @param tipo true per destinatario, false per mittente.
 * @return Puntatore alla Persona.
 */
Persona *getPersona(Spedizione *s, bool tipo);

/**
 * @brief Restituisce la priorità della Spedizione.
 * @param s Puntatore alla Spedizione.
 * @return true se prioritaria, false altrimenti.
 */
bool getPriorita(Spedizione *s);

/**
 * @brief Restituisce lo stato della Spedizione.
 * @param s Puntatore alla Spedizione.
 * @return Stato della spedizione.
 */
int getStato(Spedizione *s);

/**
 * @brief Restituisce il giorno dalla struttura tm.
 * @param data Struttura tm.
 * @return Giorno.
 */
int getGiorno(struct tm data);

/**
 * @brief Restituisce il mese dalla struttura tm.
 * @param data Struttura tm.
 * @return Mese.
 */
int getMese(struct tm data);

/**
 * @brief Restituisce l'anno dalla struttura tm.
 * @param data Struttura tm.
 * @return Anno.
 */
int getAnno(struct tm data);

/**
 * @brief Restituisce la data associata alla Spedizione.
 * @param s Puntatore alla Spedizione.
 * @param tipo true per data di consegna, false per spedizione.
 * @return Puntatore alla struttura tm.
 */
struct tm *getData(Spedizione *s, bool tipo);

/**
 * @brief Restituisce il Pacco associato alla Spedizione.
 * @param s Puntatore alla Spedizione.
 * @return Puntatore al Pacco.
 */
Pacco *getPacco(Spedizione *s);


/**
 * @brief Restituisce il prossimo nodo della lista.
 * @param n Puntatore al NodoSpedizione corrente.
 * @return Puntatore al prossimo NodoSpedizione.
 */
NodoSpedizione *getProssimoNodo(NodoSpedizione *n);

/**
 * @brief Restituisce la Spedizione associata al nodo.
 * @param n Puntatore al NodoSpedizione.
 * @return Puntatore alla Spedizione.
 */
Spedizione *getSpedDaNodo(NodoSpedizione *n);

/**
 * @brief Restituisce il nodo testa della CodaSpedizione.
 * @param c Puntatore alla CodaSpedizione.
 * @return Puntatore al NodoSpedizione testa.
 */
NodoSpedizione *getNodoTesta(CodaSpedizione *c);

// --- Funzioni inserimento ---


/**
 * @brief Inserisce i dati di una Spedizione.
 * @param s Puntatore alla Spedizione da inserire.
 */
void inserimento_spedizione(Spedizione *s);



// --- Funzioni gestione coda e spedizioni ---
/**
 * @brief Verifica se la coda è vuota.
 * @param c Puntatore alla CodaSpedizione.
 * @return 1 se vuota, 0 altrimenti.
 */
int isEmpty(CodaSpedizione *c);

/**
 * @brief Inserisce una spedizione nella coda.
 * @param coda Puntatore alla CodaSpedizione.
 * @param sped Puntatore alla Spedizione da inserire.
 */
void enqueue(CodaSpedizione *coda, Spedizione *sped);

/**
 * @brief Estrae una spedizione dalla coda.
 * @param coda Puntatore alla CodaSpedizione.
 * @return Puntatore alla Spedizione estratta.
 */
Spedizione *dequeue(CodaSpedizione *coda);

/**
 * @brief Elimina una spedizione dalla coda.
 * @param coda Puntatore al puntatore della CodaSpedizione.
 */
void elimina_spedizione(CodaSpedizione **coda);

/**
 * @brief Modifica una spedizione nella coda.
 * @param coda Puntatore al puntatore della CodaSpedizione.
 */
void modifica_spedizione(CodaSpedizione **coda);

#endif // DATI_H
