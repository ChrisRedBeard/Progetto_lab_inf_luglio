#include "pacco.h"
#include "utils.h"
#include <string.h>

void inserimento_pacco(Pacco *p){
    
    input_string("ID Pacco [IT1234567]: ", p->n, sizeof(p->n));
    // se l'id pacco non ha esattamente 9 caratteri non è valido
    
    if (strlen(p->n) != 9 ) {
        puts("ID Pacco non valido.");
        return;
    }

    printf("Peso del pacco (in grammi): ");
    if (scanf("%f", &(p->peso)) != 1 || p->peso <= 0) {
        puts("Peso non valido.");
        while(getchar() != '\n');
        return;
    }

    printf("Volume del pacco (in centimetri cubi): ");
    if (scanf("%f", &(p->volume)) != 1 || p->volume <= 0) {
        puts("Volume non valido.");
        while(getchar() != '\n');
        return;
    }
}

void stampa_pacco(Pacco p){
    printf("ID Pacco: %s \n", p.n);
    printf("Peso: %.2f grammi, Volume: %.2f cm^3 \n", p.peso, p.volume);
}