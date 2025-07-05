#include "spedizione.h"
#include <stdio.h>
#include <stdlib.h>

void inserimento_file_spedizioni(Spedizione s){
    FILE *fp;

    fp = fopen("spedizioni.dat", "ab");
    if (fp == NULL) {
        perror("Errore nell'apertura del file");
        return;
    }

    if (fwrite(&s, sizeof(Spedizione), 1, fp) != 1) {
        perror("Errore nella scrittura nel file");
    } else {
        printf("Spedizione inserita correttamente nel file.\n");
    }

    /*Creare una funzione che riordini il file rispetto alla data di invio*/

    fclose(fp);
}

void stampa_file_spedizioni(){
    FILE *fp;
    Spedizione s;

    fp = fopen("spedizioni.dat", "rb");
    if (fp == NULL) {
        perror("Errore nell'apertura del file");
        return;
    }

    printf("Contenuto del file spedizioni.dat:\n");
    while (fread(&s, sizeof(Spedizione), 1, fp)) {
        puts("<-------------------------------->");
        printf("ID Pacco: %s \n", s.p.n);
        printf("Peso e volume del pacco: %f grammi, %f cm^3 \n", s.p.peso, s.p.volume);
        
        printf("Spedito in data: %d/%d/%d ,", s.data_invio.tm_mday, s.data_invio.tm_mon /*+ 1*/, s.data_invio.tm_year /*+1900*/);
        /*Aggiungere stampa completa per mitt e dest*/
        printf("da: %s \n", s.mittente.nome);       
        printf("Consegna prevista in data: %d/%d/%d ,", s.data_consegna.tm_mday, s.data_consegna.tm_mon /*+ 1*/, s.data_consegna.tm_year /*+1900*/);
        printf("a: %s \n", s.destinatario.nome);

        printf("Stato della spedizione: ");
        switch (s.stato) {
            case ordinato:
                puts("Ordinato");
                break;
            case spedito:
                puts("Spedito");
                break;
            case in_consegna:
                puts("In consegna");
                break;
            case consegnato:
                puts("Consegnato");
                break;
            case annullato:
                puts("Annullato");
                break;
            default:
                puts("Stato sconosciuto");
        }
    }   

    fclose(fp);
}
