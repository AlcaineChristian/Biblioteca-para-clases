#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#define CANTIDAD_EMPLEADOS 5
#define DATO_INVALIDO -1
#define false 0
#define true 1


/*int main()
{


    int edad;
    //if(getEdad(&edad) == 0)
    if(utn_getEntero(&edad,3,"edad?:","error",0,199) == 0)
    {
        printf("La edad es: %d",edad);
    }



    return 0;
}*/

int main()
{
    int array[4];
    int i;

    for(i=0;i<4;i++)
    {
        printf("ingrese valor \n ");
        scanf("%d\n",&array[i]);

        printf("%d \n",array[i]);
    }


}




