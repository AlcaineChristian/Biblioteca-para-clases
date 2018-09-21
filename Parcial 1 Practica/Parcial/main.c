#include <stdio_ext.h>
#include <stdlib.h>
#include "Parcial.h"
#define CANTIDAD_DE_PANTALLAS 100

int main()
{
    Pantalla pantallas[CANTIDAD_DE_PANTALLAS];
    pant_inicializarArray(pantallas,CANTIDAD_DE_PANTALLAS);
    /*for(i=0;i<100;i++){
        printf("\n%d\n",pantallas[i].isEmpy);

    }*/
    pant_menu(pantallas,CANTIDAD_DE_PANTALLAS);


    return 0;
}
