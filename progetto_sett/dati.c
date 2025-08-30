#include "dati.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

    void setNome (char *str, Persona*p){
        strcopy(p->nome,str);
    }

    char *getNome(Persona d){
        
        return d.nome ;
    }


    void setCognome (char *str, Persona*p){
        strcopy(p->cognome,str);
    }
    char *getCognome (Persona d){
        return d.cognome;
    }

    void setTelefono (char *str,Persona*p){
        strcopy(p->telefono,str);
    }

    char *getTelefono(Persona p){
        return p.telefono;

    }


    void setVia(char *str, Persona*p){
        strcopy(p->via,str);
    }
    char *getVia(Persona p){
            return p.via;
    }

    void setCitta(char *str,Persona* p){
        strcopy(p->citta,str);
    }
    char *getCitta(Persona p){
    return p.citta;
    }


    void setProv(char *str, Persona* p){
        strcopy(p->provincia,str);
    }
    char *getProv(Persona p){
        return p.provincia;
    }

    void setCAP (char *str,Persona* p){
        strcopy(p->cap,str);
    }
    char *getCAP(Persona p){
        return p.cap;
    }


    void setMail(char *str, Persona* p){
        strcopy(p->email,str);
    }

    char *getMail(Persona p){
        return p.email;
    }

    // da vedere
    void inserimento_Persona(Persona *p)
    {
       char stringa[100] = {'\0'};

        input_string("Nome: ", stringa, 29);
          setNome(stringa,p);
          strcopy(stringa,"");

        input_string("Cognome: ", stringa, 29);
         setCognome(stringa,p);
         strcopy(stringa,"");

        input_string("Numero di telefono [+00 123 456 7890]: ", stringa, 16);
        setTelefono(stringa,p);
        strcopy(stringa,"");

        input_string("Email: ", stringa, 49);
        setMail(stringa,p);
        strcopy(stringa,"");

        input_string("Indirizzo [via, num. civico]: ", stringa, 99);
        setVia(stringa,p);
         strcopy(stringa,"");


        
    
        input_string("Città: ", stringa, 49);
        setCitta(stringa,p);
        strcopy(stringa,"");

        input_string("Provincia [CC]: ", stringa, 2);
        setProv(stringa,p);
        strcopy(stringa,"");

        input_string("CAP: ", stringa, 5);
        setCAP(stringa,p);
        strcopy(stringa,"");
    }

    
    //stampare le mittente/destinatario fuori
    void stampa_Persona(Persona d)
    {
        printf("%sNome e cognome%s: %s %s \n", WHITE,RESET,getNome(d), getCognome(d));
        printf("%sTelefono%s: %16s, ",WHITE ,RESET,getTelefono(d));
        printf("%sEmail%s: %s\n",WHITE,RESET,getMail(d));
        printf("%sIndirizzo%s: %s, ",WHITE,RESET,getVia(d));
        printf("%sCittà%s: %s, ",WHITE,RESET, getCitta(d));
        printf("%sProvincia%s: %2s, ",WHITE,RESET,getProv(d));
        printf("%sCAP%s: %5s\n",WHITE,RESET,getCAP(d));
    }


    void set_numID(char * str,Pacco*p){
    strcopy(p->n,str);
    }

    char *get_numID(Pacco p){
    return p.n;
    }

    void setPeso(float f,Pacco*p){
        p->peso=f;
    }
    float getPeso(Pacco p){
        return p.peso; 
    }

    void setVolume(float f,Pacco *p){
        p->volume=f;
    }
    float getVolume(Pacco p){
        return p.volume;
    }


    void inserimento_pacco(Pacco *p){
       input_id("", char *dest, int_pos size, int_pos lunghezza);
        set_numID(str,p);
    }
    



    void stampa_pacco(Pacco p)
    {
        printf("%sID Pacco%s: %s \n",WHITE,RESET, p.n);
        printf("%sPeso%s: %.2f grammi, Volume: %.2f cm^3 \n",WHITE,RESET,p.peso, p.volume);
    }




void setPriorita(bool b,Spedizione* s){
    s->priorita=b;
}
bool getPriorita(Spedizione s){
    return s.priorita;
}

void setStato(int i,Spedizione* s){

 while (i<1 || i>5)
 {
    printf("%sErrore%s - Inserisci un valore da 1 a 5.",RED,RESET);
    scanf("%d",&i);
 }
    s->stato=i;
   
}

int getStato(Spedizione s){
   return s.stato;
}
//capire cosa fare per impostare
void setData(const char *prompt, Spedizione*s,bool scelta){
 bool flag = false;
 struct tm *data;
    if(scelta==true){
      data=&s->data_invio;
    }else{
        data=&s->data_consegna;
    }


    do
    {
        printf("%s (formato: gg mm aaaa): ", prompt);
        if (scanf("%d %d %d", &data->tm_mday, &data->tm_mon, &data->tm_year) != 3 ||
            data->tm_mday < 1 || data->tm_mday > 31 ||
            data->tm_mon < 1 || data->tm_mon > 12 ||
            data->tm_year < 1900)
        {
            printf("%sData non valida, riprova.%s\n", RED, RESET);
            flag = true;
        }
        else
        {
            flag = false;

            if (data->tm_year % 4 == 0)
            {
                if (data->tm_mon == 2 && data->tm_mday > 29)
                {
                    printf("%sData non valida, riprova.%s\n", RED, RESET);
                    flag = true;
                }
            }
            else
            {
                if (data->tm_mon == 2 && data->tm_mday > 28)
                {
                    printf("%sData non valida, riprova.%s\n", RED, RESET);
                    flag = true;
                }
            }

            if (data->tm_mon == 4 || data->tm_mon == 6 || data->tm_mon == 9 || data->tm_mon == 11)
            {
                if (data->tm_mday > 30)
                {
                    printf("%sData non valida, riprova.%s\n", RED, RESET);
                    flag = true;
                }
            }
        }

    } while (flag);
 

}

struct tm getData(Spedizione s,bool scelta){
    if(scelta==true){
        return s.data_invio;
    }else{
        return s.data_consegna;
    }
}

void stampa_spedizione(Spedizione s)
{
    puts("<-------------------------------->");

    stampa_pacco(s.p);

    printf("%sPriorità%s: %s\n",WHITE, RESET,s.priorita ? "Alta" : "Normale");

    printf("%sSpedito in data%s: %d/%d/%d \n", WHITE,RESET,s.data_invio.tm_mday, s.data_invio.tm_mon, s.data_invio.tm_year);
    stampa_mittente(s.mittente);

    printf("%sConsegna prevista in data%s: %d/%d/%d \n", WHITE,RESET,s.data_consegna.tm_mday, s.data_consegna.tm_mon, s.data_consegna.tm_year);
    stampa_destinatario(s.destinatario);

    printf("%sStato della spedizione%s: ",WHITE,RESET);
    switch (s.stato)
    {
    case 1:
        puts("Ordinato");
        break;
    case 2:
        puts("Spedito");
        break;
    case 3:
        puts("In consegna");
        break;
    case 4:
        puts("Consegnato");
        break;
    case 5:
        puts("Annullato");
        break;
    default:
        puts("Stato sconosciuto");
    }
}