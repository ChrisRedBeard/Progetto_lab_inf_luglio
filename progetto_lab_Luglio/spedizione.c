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



void mod_stato_sped(Spedizione *s){
    int scelta;
    while(scelta < 1 || scelta > 5) {
        puts("Modifica stato della spedizione:");
        puts("1. Ordinato");
        puts("2. Spedito");
        puts("3. In consegna");
        puts("4. Consegnato");
        puts("5. Annullato");
        printf("Inserisci la tua scelta (1-5): ");
        scanf("%d", &scelta);
        
    switch (scelta) {
        case 1:
            s->stato = ordinato; // Modifica lo stato della spedizione a "ordinato"
            break;
        case 2:
            s->stato = spedito; // Modifica lo stato della spedizione a "spedito"
            break;
        case 3:
            s->stato = in_consegna; // Modifica lo stato della spedizione a "in_consegna"
            break;
        case 4:
            s->stato = consegnato; // Modifica lo stato della spedizione a "consegnato"
            break;
        case 5:
            s->stato = annullato; // Modifica lo stato della spedizione a "annullato"
            break;
        default:
            puts("Scelta non valida.");
        
    }
   }


}
