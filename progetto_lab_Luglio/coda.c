
/**
 * @file coda.c
 * @brief Gestione della coda delle spedizioni.
 *
 * Questo file contiene le implementazioni delle funzioni per gestire la coda delle spedizioni,
 * inclusi enqueue, dequeue, stampa e convalida.
 */

#include "coda.h"
#include "spedizione.h"
#include "utils.h"
#include "gestione_file.h"

#include <stdlib.h>

/**
 * @brief Inizializza la coda impostando i puntatori a NULL.
 * 
 * @param coda Puntatore alla coda da inizializzare.
 */
void coda_init(Coda *coda)
{
    coda->headPtr = NULL; // Inizializza il puntatore front a NULL
    coda->tailPtr = NULL; // Inizializza il puntatore rear a NULL
}

/**
 * @brief Stampa la coda delle spedizioni su file.
 * 
 * @param c Coda da stampare.
 */
void printQueue(Coda c)
{

    /* Se la coda è vuota  */
    if (isEmpty(c)==1)
    {
        printf("%sLa coda è vuota.%s\n",YELLOW,RESET);
    }
    else
    {
        while (c.headPtr != NULL)
        {
            /*inserimento_file_spedizioni(Spedizione s)*/
            inserimento_file_spedizioni(c.headPtr->sp_nodo); // Inserisce la spedizione nel file delle spedizioni
            c.headPtr = c.headPtr->nextPtr;                 // spostamento al nodo successivo
        }
    }
}

/**
 * @brief Verifica se la coda è vuota.
 * 
 * @param c Coda da controllare.
 * @return int Ritorna 1 se la coda è vuota, altrimenti 0.
 */
int isEmpty(Coda c)
{
    return (c.headPtr) == NULL; // ritorna 1 se la coda è vuota, altrimenti ritorna 0
}

/**
 * @brief Rimuove e restituisce la spedizione in testa alla coda.
 * 
 * @param c Puntatore alla coda.
 * @return Spedizione* Puntatore alla spedizione rimossa.
 */
Spedizione* dequeue(Coda *c)
{

    Spedizione *s=(Spedizione*)malloc(sizeof(Spedizione));
    QueueNodePtr tempPtr; // puntatore al nodo da rimuovere

    *s = (c->headPtr)->sp_nodo; // recupero la spedizione dal nodo da rimuovere
    tempPtr = c->headPtr;
    c->headPtr = c->headPtr->nextPtr;

    /*Se la coda è vuota   */
    if (c->headPtr == NULL)
    {
        c->tailPtr = NULL; // se la coda è vuota, il puntatore alla coda viene impostato a NULL
    }

    free(tempPtr); // rilascio la memoria del nodo rimosso

   return s;
}

/**
 * @brief Inserisce una spedizione alla fine della coda.
 * 
 * @param c Puntatore alla coda.
 * @param s Spedizione da inserire.
 */
void enqueue(Coda *c, Spedizione s)
{

    QueueNodePtr newPtr;                // puntatore al nuovo nodo
    newPtr = malloc(sizeof(QueueNode)); // allocazione memoria per il nuovo nodo

    // se c'è memoria disponibile
    if (newPtr != NULL)
    {
        newPtr->sp_nodo = s; // inserimento della spedizione nel nodo
        newPtr->nextPtr = NULL;

        if (isEmpty(*c))
        {
            c->headPtr = newPtr; // se è vuota, il nuovo nodo diventa la testa della coda
        }
        else
        {
            (c->tailPtr)->nextPtr = newPtr; // altrimenti il nuovo nodo viene inserito alla fine della coda
        }

        c->tailPtr = newPtr; // il nuovo nodo diventa la coda della coda
    }
    else
    {

        printf("\n%sLa spedizione con id: %s non è stata inserita nella coda, poiché non c'è memoria disponibile!!\n",RED,s.p.n,RESET);

    }
}


/**
 * @brief Inserisce una nuova spedizione, decidendo se inserirla nel file o nella coda.
 * 
 * @param c Puntatore alla coda.
 */

void inserimento_spedizione(Coda *c)
{
    Spedizione nuova_sped = {0};

    puts("Inserisci i dati della spedizione:");

    inserimento_pacco(&nuova_sped.p);

    do
    {
        printf("Priorità (1 per alta, 0 per normale): ");
        if (scanf("%d", &nuova_sped.priorita) != 1 || (nuova_sped.priorita != 0 && nuova_sped.priorita != 1))
        {
            printf("%sPriorità non valida.%s\n", RED, RESET);
        }
    } while (nuova_sped.priorita != 0 && nuova_sped.priorita != 1);

    do
    {
        inserimento_data("Data di invio", &nuova_sped.data_invio);
        inserimento_data("Data di consegna prevista", &nuova_sped.data_consegna);

    } while (!controllo_date(nuova_sped.data_invio, nuova_sped.data_consegna));

    puts("<--Dati del mittente-->");
    inserimento_mittente(&nuova_sped.mittente);

    puts("<--Dati del destinatario-->");
    inserimento_destinatario(&nuova_sped.destinatario);

    do
    {
        puts("Inserire lo stato della spedizione (1 per ordinato, 2 per spedito, 3 per in consegna, 4 per consegnato, 5 per annullato): ");
        if (scanf("%d", &nuova_sped.stato) != 1 || nuova_sped.stato < 1 || nuova_sped.stato > 5)
        {
            printf("%s", RED);
            puts("Stato non valido.");
            printf("%s", RESET);
            while (getchar() != '\n')
                ;
        }
    } while (nuova_sped.stato < 1 || nuova_sped.stato > 5);

    if (nuova_sped.stato == 1)
    {
        // Se il pacco è "ordinato", viene inserito in una coda
        printf("Pacco con ID %s inserito in coda.\n", nuova_sped.p.n);
        enqueue(c, nuova_sped);
    }
    else
    {
        // Altrimenti, viene inserito nel file delle spedizioni
        inserimento_file_spedizioni(nuova_sped);
    }
}

/**
 * @brief Convalida le spedizioni nella coda chiedendo all’utente conferma.
 * 
 * Se l’utente conferma, la spedizione viene scritta su file e marcata come “spedita”.
 * Altrimenti può essere reinserita in coda o eliminata.
 * 
 * @param c Puntatore alla coda da processare.
 */
void convalida_spedizioni(Coda *c)
{

    int_pos convalida = 0;
    int_pos scelta;
    Spedizione *s;

    while (!isEmpty(*c))
    {
        stampa_spedizione(c->headPtr->sp_nodo);

       s = dequeue(c);

       stampa_spedizione(*s); //stampa sul terminale e poi chiede all'utente se vuole convalidarlo o meno

        printf("Vuoi convalidare il pacco? (1=>Si 0=>No) : ");
        scanf("%hd", &convalida);
        if (convalida == 1)
        {
            // lo tolgo dalla coda e poi gli cambio lo stato per stamparlo nel file

            s->stato= spedito;
            inserimento_file_spedizioni(*s);

        }
        else
        {
                puts("Vuoi eliminare la spedizione? (1=>Si 0=>No)");
                scanf("%hd",&scelta);
                if(scelta==0){
                     enqueue(c, *s);
                }else{
                    printf("%sSpedizione eliminata dalla coda degli ordini%s",BLUE,RESET);
                }


        }
    }

}
