



typedef struct {

    int id;
    char direccion[128];
    char tipo[32];
    char nombre[32];
    int isEmpy;




}Pantalla;

int pant_cargarPrimerIndiceVacio(Pantalla* pBuffer,int limite);

int pant_inicializarArray(Pantalla* pBuffer,int limite);

int pant_menu(Pantalla* pBuffer,int limite);

int pant_modificarPantalla(Pantalla* pBuffer);

int pant_menu(Pantalla* pBuffer,int limite);
