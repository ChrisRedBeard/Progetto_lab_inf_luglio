#ifndef FUNZIONI_H
#define FUNZIONI_H

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define WHITE "\033[97m"

/**
 * @typedef int_pos
 * @brief Tipo definito per rappresentare posizioni o dimensioni intere positive.
 */
typedef unsigned short int int_pos;

/**
 * @brief Legge da input una stringa con lunghezza massima specificata.
 *
 * La funzione richiede all'utente di inserire una stringa tramite stdin.
 * L'input viene accettato solo se la stringa è non vuota e non supera la lunghezza massima.
 * Rimuove il carattere di newline se presente.
 * In caso di errore nella lettura o di input non valido, viene richiesto di riprovare.
 *
 * @param prompt Messaggio mostrato all'utente per richiedere l'input.
 * @param dest Buffer dove salvare la stringa inserita.
 * @param size Dimensione massima del buffer (incluso terminatore nullo).
 * @param lunghezza Lunghezza massima accettabile per la stringa (escluso terminatore nullo).
 */
void input_string(const char *prompt, char *dest, int_pos lunghezza);

/**
 * @brief Legge da input un numero in virgola mobile (float) con valore minimo.
 *
 * La funzione richiede all'utente di inserire un valore float tramite stdin.
 * Viene controllato che il valore inserito sia valido e maggiore o uguale al minimo indicato.
 * Se l'input è non valido o minore del minimo, viene chiesto di riprovare.
 *
 * @param prompt Messaggio mostrato all'utente per richiedere l'input.
 * @param dest Puntatore alla variabile float dove salvare il valore inserito.
 * @param min Valore minimo accettabile (incluso).
 */
void input_float(const char *prompt, float *dest, float min);

/**
 * @brief Legge da input uno specifico ID con lunghezza fissa.
 *
 * Questa funzione richiede all'utente di inserire una stringa tramite stdin.
 * L'input viene accettato solo se la stringa ha esattamente la lunghezza richiesta,
 * altrimenti viene chiesta nuovamente.
 * Rimuove il carattere di newline se presente.
 *
 * @param prompt Messaggio mostrato all'utente per richiedere l'input.
 * @param dest Buffer dove salvare la stringa inserita dall'utente.
 * @param size Dimensione massima del buffer (incluso terminatore nullo).
 * @param lunghezza Lunghezza esatta richiesta per l'ID (escluso terminatore nullo).
 */
void input_id(const char *prompt, char *dest, int_pos lunghezza);

/**
 * @brief Stampa un messaggio di uscita con animazione.
 */
void stampa_uscita();

#endif
