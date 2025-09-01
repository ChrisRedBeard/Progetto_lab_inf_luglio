
#include <stdbool.h>
#include <stdio.h>
#include "dati.h"

bool salva_coda_su_file(CodaSpedizione *coda, char *nomeFile){
    FILE *file = fopen(nomeFile, "wb");
    if (file == NULL) {
        return false; // Errore nell'apertura del file
    }

    NodoSpedizione *corrente = coda->testaPtr;
    while (corrente != NULL) {
        fwrite(&corrente->sped, sizeof(Spedizione), 1, file);
        corrente = corrente->nextPtr;
    }

    fclose(file);
    return true; // Salvataggio riuscito
}

bool carica_coda_da_file(CodaSpedizione *coda, char *nomeFile){
    FILE *file = fopen(nomeFile, "rb");
    if (file == NULL) {
        return false; // Errore nell'apertura del file
    }

    Spedizione s;
    while (fread(&s, sizeof(Spedizione), 1, file) == 1) {
        enqueue(coda, s);
    }

    fclose(file);
    return true; // Caricamento riuscito
}
