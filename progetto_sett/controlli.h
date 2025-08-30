#ifndef CONTROLLI_H
#define CONTROLLI_H

#include "dati.h"

/**
 * @brief Controlla che la data di invio sia precedente a quella di consegna.
 *
 * @param data_invio Data di invio del pacco.
 * @param data_consegna Data di consegna del pacco.
 * @return true se le date sono coerenti, false altrimenti.
 */
bool controllo_date(struct tm data_invio, struct tm data_consegna);


#endif // CONTROLLI_H