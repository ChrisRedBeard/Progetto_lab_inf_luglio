#ifndef DATI_H
#define DATI_H

#include <stdbool.h>
#include <time.h>

typedef struct _persona Persona;
typedef struct _pacco Pacco;
typedef struct _spedizione Spedizione;
typedef struct _nodo_spedizione NodoSpedizione;
typedef struct _coda_spedizione CodaSpedizione;

// --- Funzioni crea ---
Persona* creaPersona();
Pacco* creaPacco();

Spedizione* creaSpedizione(void);

NodoSpedizione* creaNodoSpedizione();
CodaSpedizione* creaCoda();



// --- Funzioni set ---
void setNome(char *, Persona *);
void setCognome(char *str, Persona *);
void setTelefono(char *str, Persona *);
void setVia(char *str, Persona *);
void setCitta(char *str, Persona *);
void setProv(char *str, Persona *);
void setCAP(char *str, Persona *);
void setMail(char *str, Persona *);
void set_numID(char *str, Pacco *p);
void setPeso(float peso, Pacco *p);
void setVolume(float volume, Pacco *p);
void setPersona(Spedizione *s, Persona *p, bool tipo);
void setPriorita(bool priorita, Spedizione *s);
void setStato(int i, Spedizione *s);


// --- Funzioni get ---
char *getNome(Persona *);
char *getCognome(Persona *);
char *getTelefono(Persona *);
char *getVia(Persona *);
char *getCitta(Persona *);
char *getProv(Persona *);
char *getCAP(Persona *);
char *getMail(Persona *);
char *get_numID(Pacco *p);
float getPeso(Pacco *p);
float getVolume(Pacco *p);
Persona *getPersona(Spedizione *s, bool tipo);
bool getPriorita(Spedizione *s);
int getStato(Spedizione *s);
int getGiorno(struct tm);
int getMese(struct tm);
int getAnno(struct tm);
struct tm *getData(Spedizione *s, bool tipo);
Pacco *getPacco(Spedizione *s);
NodoSpedizione* getCodaNodo(CodaSpedizione *c);
NodoSpedizione* getProssimoNodo(NodoSpedizione *n);
Spedizione* getSpedDaNodo(NodoSpedizione *n);
NodoSpedizione* getNodoTesta(CodaSpedizione *c);


void setSpedDaNodo(NodoSpedizione *n,Spedizione* sped);
void setProssimoNodo(NodoSpedizione* n1,NodoSpedizione* n2);
void setCodaPtr(CodaSpedizione*c);
void setNodoTesta(CodaSpedizione*,NodoSpedizione*);
void setCodaNodo(CodaSpedizione*,NodoSpedizione*);

// --- Funzioni inserimento ---
void inserimento_Persona(Persona *);
void inserimento_pacco(Pacco *p);
void inserimento_spedizione(Spedizione *s);
void inserimentoData(const char *prompt, Spedizione *s, bool tipo);

// --- Funzioni gestione coda e spedizioni ---
int isEmpty(CodaSpedizione *c);
void enqueue(CodaSpedizione *coda, Spedizione *sped);
Spedizione *dequeue(CodaSpedizione *coda);
void elimina_spedizione(CodaSpedizione **coda);
void modifica_spedizione(CodaSpedizione **coda);

#endif // DATI_H