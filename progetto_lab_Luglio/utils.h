/**
 * @file utils.h
 * @brief Definizione di funzioni di utilità generali per input e colori terminale.
 *
 * Questo file contiene definizioni di costanti per la colorazione del testo nel terminale
 * e dichiarazioni di funzioni per l'acquisizione sicura di input da tastiera.
 */
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

/**
 * @def BLACK
 * @brief Sequenza ANSI per il colore nero del testo.
 */
#define BLACK "\033[30m"

/**
 * @def RED
 * @brief Sequenza ANSI per il colore rosso del testo.
 */
 #define RED "\033[31m"
/**
 * @def GREEN
 * @brief Sequenza ANSI per il colore verde del testo.
 */

 #define GREEN "\033[32m"
/**
 * @def YELLOW
 * @brief Sequenza ANSI per il colore giallo del testo.
 */
  #define YELLOW "\033[33m"
/**
 * @def BLUE
 * @brief Sequenza ANSI per il colore blu del testo.
 */

 #define BLUE "\033[34m"
/**
 * @def RESET
 * @brief Sequenza ANSI per resettare il colore del testo.
 */
 #define RESET "\033[0m"


/**
 * @typedef int_pos
 * @brief Tipo definito per rappresentare posizioni o dimensioni intere positive.
 */
typedef unsigned short int int_pos;

/**
 * @brief Acquisisce una stringa dall'utente con lunghezza controllata.
 *
 * La funzione stampa il prompt, legge l'input da tastiera e lo memorizza
 * nella variabile `dest`, limitando la lunghezza.
 *
 * @param prompt Testo da mostrare all'utente.
 * @param dest Puntatore al buffer di destinazione.
 * @param size Dimensione massima del buffer (compreso '\0').
 * @param lunghezza Lunghezza massima consentita (escluso '\0').
 */
void input_string(const char *prompt, char *dest, int_pos size, int_pos lunghezza);


/**
 * @brief Acquisisce un numero float dall'utente, con un valore minimo ammesso.
 *
 * @param prompt Testo da mostrare all'utente.
 * @param dest Puntatore alla variabile dove salvare il numero.
 * @param min Valore minimo accettabile (incluso).
 */
void input_float(const char *prompt, float *dest, float min);


/**
 * @brief Acquisisce un ID in formato stringa con lunghezza controllata.
 *
 * @param prompt Testo da mostrare all'utente.
 * @param dest Puntatore al buffer in cui salvare l'ID.
 * @param size Dimensione massima del buffer.
 * @param lunghezza Lunghezza massima consentita dell'ID (escluso '\0').
 */
void input_id(const char *prompt, char *dest, int_pos size, int_pos lunghezza);

#endif