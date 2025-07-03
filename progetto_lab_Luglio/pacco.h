

typedef struct 
{ 
char provincia[2]; 
int numero; 
} codice_identificativo; 


typedef struct 
{ 
        // Email del mittente o destinatario 
        codice_identificativo n; // codice identificativo del pacco 
        float peso; // in grammi 
        float volume; // in centimetri cubi 
} Pacco;
