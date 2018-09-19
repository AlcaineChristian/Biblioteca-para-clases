#include <stdio_ext.h>
#include <stdlib.h>
#include "producto.h"
#define CANTIDAD 200

int main()
{
    Producto productos[CANTIDAD];
    inicializarArray(productos,CANTIDAD);
    imprimirArray(productos,CANTIDAD);
    cargaProducto(productos,6);


    return 0;
}
