#include <stdio_ext.h>
#include <stdlib.h>
#include "Parcial.h"
#define CLIENTES 100
#define VENTAS 1000


int main()
{
    Cliente clientes[CLIENTES];
    Venta ventas[VENTAS];
    parcial_inicializarCliente(clientes,CLIENTES);
    parcial_inicializarVenta(ventas,VENTAS);
    /*for(i=0;i<100;i++){
        printf("\n%d\n",clientes[i].isEmpy);

    }*/
    menu(clientes,ventas,CLIENTES,VENTAS);


    return 0;
}
