#include <stdio.h>
#include <stdlib.h>
#include "utn.h" //nunca incluyo un .c , solo los .h
#define CANTIDAD_EMPLEADOS 5

int main()
{
    int edades[CANTIDAD_EMPLEADOS];
    int i;

    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        if(utn_getEntero(&edades[i],2,"\nEdad?","\nError\n",1000,0) == -1)
        {

            edades[i] = 0;

        }

    }
    mostrarArray(edades,CANTIDAD_EMPLEADOS);
    mostrarArrayMaximo(edades, CANTIDAD_EMPLEADOS);


    return 0;
}



