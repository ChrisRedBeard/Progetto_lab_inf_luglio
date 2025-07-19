#ifndef PACCO_H
#define PACCO_H

typedef struct
{
    char n[10];   // codice identificativo del pacco, ad esempio "IT1234567"
    float peso;   // in grammi
    float volume; // in centimetri cubi
} Pacco;

void inserimento_pacco(Pacco *p);
void stampa_pacco(Pacco p);

#endif // PACCO_H
