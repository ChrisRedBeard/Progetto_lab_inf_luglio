#include "dati.h"
#include "utils.h"

void setNome (char *str, Persona*p){

    strcopy(p->nome,str);

}

char *getNome(Persona d){
    
    return d.nome ;
}


void setCognome (char *str, Persona*p){
      strcopy(p->cognome,str);
}
char *getCognome (Persona d){
    return d.cognome;
}

void setTelefono (char *str,Persona*p){
      strcopy(p->telefono,str);
}

char *getTelefono(Persona p){
    return p.telefono;

}


void setVia(char *str, Persona*p){
    strcopy(p->via,str);
}
char *getVia(Persona p){
        return p.via;
}

void setCitta(char *str,Persona* p){
     strcopy(p->citta,str);
}
char *getCitta(Persona p){
 return p.citta;
}


void setProv(char *str, Persona* p){
    strcopy(p->provincia,str);
}
char *getProv(Persona p){
    return p.provincia;
}

void setCAP (char *str,Persona* p){
    strcopy(p->cap,str);
}
char *getCAP(Persona p){
    return p.cap;
}


void setMail(char *str, Persona* p){
    strcopy(p->email,str);
}

char *getMail(Persona p){
    return p.email;
}

// da vedere
void inserimento_Persona(Persona *p)
{
    input_string("Nome: ", p->nome, sizeof(p->nome), 29);
    input_string("Cognome: ", p->cognome, sizeof(p->cognome), 29);
    input_string("Numero di telefono [+00 123 456 7890]: ", p->telefono, sizeof(p->telefono), 16);
    input_string("Email: ", p->email, sizeof(p->email), 49);
    input_string("Indirizzo [via, num. civico]: ", p->via, sizeof(p->via), 99);
    input_string("Città: ", p->citta, sizeof(p->citta), 49);
    input_string("Provincia [CC]: ", p->provincia, sizeof(p->provincia), 2);
    input_string("CAP: ", p->cap, sizeof(p->cap), 5);
}

//NON LO SO DEVO METTERNE 2?
void stampa_destinatario(Destinatario d)
{
    printf("%sDestinatario%s: %s %s \n", WHITE,RESET,d.nome, d.cognome);
    printf("%sTelefono%s: %16s, ",WHITE ,RESET,d.telefono);
    printf("%sEmail%s: %s\n",WHITE,RESET,d.email);
    printf("%sIndirizzo%s: %s, ",WHITE,RESET,d.via);
    printf("%sCittà%s: %s, ",WHITE,RESET, d.citta);
    printf("%sProvincia%s: %2s, ",WHITE,RESET,d.provincia);
    printf("%sCAP%s: %5s\n",WHITE,RESET,d.cap);
}

void stampa_Mittente(Mittente d)
{
    printf("%sMittente%s: %s %s \n", WHITE,RESET,d.nome, d.cognome);
    printf("%sTelefono%s: %16s, ",WHITE ,RESET,d.telefono);
    printf("%sEmail%s: %s\n",WHITE,RESET,d.email);
    printf("%sIndirizzo%s: %s, ",WHITE,RESET,d.via);
    printf("%sCittà%s: %s, ",WHITE,RESET, d.citta);
    printf("%sProvincia%s: %2s, ",WHITE,RESET,d.provincia);
    printf("%sCAP%s: %5s\n",WHITE,RESET,d.cap);
}


void set_numID(char * str,Pacco*p){
 strcopy(p->n,str);
}

char *get_numID(Pacco p){
 return p.n;
}

void setPeso(float f,Pacco*p){
    p->peso=f;
}
float getPeso(Pacco p){
    return p.peso; 
}

void setVolume(float f,Pacco *p){
    p->volume=f;
}
float getVolume(Pacco p){
    return p.volume;
}







void stampa_pacco(Pacco p)
{
    printf("%sID Pacco%s: %s \n",WHITE,RESET, p.n);
    printf("%sPeso%s: %.2f grammi, Volume: %.2f cm^3 \n",WHITE,RESET,p.peso, p.volume);
}
