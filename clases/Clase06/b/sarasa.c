#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"


int main()
{
    int edad;
    //if(getEdad(&edad) == 0)
    if(getEntero(&edad,3,"edad?:","error",0,199) == 0)
    {
        printf("La edad es: %d",edad);
    }

    return 0;
}





