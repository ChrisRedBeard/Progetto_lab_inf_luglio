#ifndef CONTROLLI_H
#define CONTROLLI_H

#include <stdbool.h>
#include <time.h>

/**
 * @brief Controlla che la data di invio sia precedente a quella di consegna.
 *
 * @param data_invio Data di invio del pacco.
 * @param data_consegna Data di consegna del pacco.
 * @return true se le date sono coerenti, false altrimenti.
 */
bool controllo_date(struct tm data_invio, struct tm data_consegna);

/**
 * @brief Controlla che il numero di telefono sia nel formato corretto e italiano.
 *  
 * */
bool check_phone_format(const char *s);

/**
 * @brief Controlla che la stringa della mail sia nel formato corretto.
 *  
 * */
bool check_email_format(const char *email);

// Elenco (parziale) dei codici di provincia italiani
static const char *province[] = {
    "AG","AL","AN","AO","AR","AP","AQ","AT","AV","BA","BG","BI","BN","BO",
    "BR","BS","BT","BZ","CA","CB","CE","CH","CL","CN","CO","CR","CS","CT",
    "CZ","EN","FC","FE","FG","FI","FM","FR","GE","GO","GR","IM","IS","KR",
    "LC","LE","LI","LO","LT","LU","MB","MC","ME","MI","MN","MO","MS","MT",
    "NA","NO","NU","OR","PA","PC","PD","PE","PG","PI","PN","PO","PR","PT",
    "PV","PZ","RA","RC","RE","RG","RI","RM","RN","RO","SA","SI","SO","SP",
    "SR","SS","SV","TA","TE","TN","TO","TP","TR","TS","TV","VA","VB","VC",
    "VE","VI","VT","VV"
};

bool check_provincia(const char *email);

//TODO
bool check_Id(const char *email);



static const size_t province_count = sizeof(province)/sizeof(province[0]);




#endif // CONTROLLI_H