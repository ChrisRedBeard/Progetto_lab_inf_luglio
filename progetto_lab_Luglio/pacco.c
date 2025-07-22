/**
 * @file pacco.c
 * @brief Implementazione delle funzioni di gestione della struttura Pacco.
 *
 * Questo file contiene l'implementazione delle funzioni per inserire e stampare
 * le informazioni relative a un pacco.
 */
#include "pacco.h"
#include "utils.h"
#include "spedizione.h"
#include <stdbool.h>
#include "gestione_file.h"


/**
 * @brief Inserisce i dati relativi a un pacco, assicurandosi che l'ID non sia già presente.
 *
 * Viene richiesto all'utente di inserire un ID pacco univoco, il peso e il volume.
 * Se l'ID è già presente nel file delle spedizioni, verrà richiesto di inserirne uno nuovo.
 *
 * @param[out] p Puntatore alla struttura Pacco da riempire.
 */
void inserimento_pacco(Pacco *p)
{
    Spedizione s;
    bool trovato=false;
    do{
        input_id("ID Pacco [IT1234567]: ", p->n, sizeof(p->n), 9);

          int pos = ricerca_spedizione_per_id(p->n,&s);
            if (pos != -1)
            {
              trovato=true;
              printf("%sL'id che stai cercando di inserire è già presente%s\n",YELLOW,RESET);
            }else{
                trovato=false;
            }


    }while (trovato==true);
    input_float("Peso del pacco (in grammi): ", &(p->peso), 0.0);

    input_float("Volume del pacco (in centimetri cubi): ", &(p->volume), 0.0);
}

/**
 * @brief Stampa a video le informazioni di un pacco.
 *
 * @param[in] p Struttura Pacco da stampare.
 */
void stampa_pacco(Pacco p)
{
    printf("%sID Pacco%s: %s \n",WHITE,RESET, p.n);
    printf("%sPeso%s: %.2f grammi, Volume: %.2f cm^3 \n",WHITE,RESET,p.peso, p.volume);
}
