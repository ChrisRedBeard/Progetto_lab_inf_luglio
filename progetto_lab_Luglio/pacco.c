#include "pacco.h"
#include "utils.h"

void inserimento_pacco(Pacco *p)
{
    input_id("ID Pacco [IT1234567]: ", p->n, sizeof(p->n), 9);
  /*
  
    int pos = ricerca_spedizione_per_id(p->n, &trovata);
            if (pos != -1)
            {
                printf("%sSpedizione trovata!%s ID: %s\n", GREEN, RESET, trovata.p.n);
                stampa_spedizione(trovata);
            }
            else
            {
                printf("%sSpedizione non trovata.%s\n", RED, RESET);
            }*/
     
   
    input_float("Peso del pacco (in grammi): ", &(p->peso), 0.0);

    input_float("Volume del pacco (in centimetri cubi): ", &(p->volume), 0.0);
}

void stampa_pacco(Pacco p)
{
    printf("ID Pacco: %s \n", p.n);
    printf("Peso: %.2f grammi, Volume: %.2f cm^3 \n", p.peso, p.volume);
}