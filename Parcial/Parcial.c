#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Parcial.h"
#define CLIENTES 100
#define VENTAS 1000
#define INTVACIO -1
#define CHARVACIO "vacio"


static int getString(char* bufferString,int limite);
static int getInt(int*pBuffer);
static int isInt(char *pBuffer);

static int isInt(char *pBuffer){
    int retorno=-1;
    int i=0;
    do{
        if(*(pBuffer+i)<48||*(pBuffer+i)>57){
                break;
        }
        i++;
    }while (i<strlen(pBuffer));
    if(i==strlen(pBuffer)){
        retorno=0;
    }
    return retorno;
}

static int getInt(int* pBuffer){
    char bufferString[200];
    int retorno =-1;
    if(getString(bufferString,200)==0 && isInt(bufferString)==0){
        *pBuffer=atoi(bufferString);
        retorno=0;
    }
    return retorno;
}

static int getString(char* pBuffer,int limite){
    char bufferString[4096];
    int retorno =-1;
    if (pBuffer != NULL && limite >0){
        __fpurge(stdin);
        fgets(bufferString,sizeof(bufferString),stdin);
        if (bufferString[strlen(bufferString)-1]=='\n'){
            bufferString[strlen(bufferString)-1]='\0';
        }
        if(strlen(bufferString)<= limite){
            strncpy(pBuffer,bufferString,limite);
            retorno=0;
        }
    }
    return retorno;
}

int getCuit(char* pBuffer)
{
    int reintentos=0;
    getString(pBuffer,16);
    while(sizeof(pBuffer)!=8 && isInt(pBuffer)==-1 && reintentos<3)
    {
        printf("Cuit invalido, ingerese cuit valido");
        getString(pBuffer,16);
        reintentos++;
    }

    return 0;
}

int parcial_inicializarCliente(Cliente* pBuffer,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        strncpy(pBuffer[i].nombre,CHARVACIO,32);
        strncpy(pBuffer[i].apellido,CHARVACIO,32);
        pBuffer[i].cuit=-1;
        pBuffer[i].isEmpy=1;

    }
    return 0;
}

int parcial_inicializarVenta(Venta* pBuffer,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        strncpy(pBuffer[i].nombreArchivo,CHARVACIO,32);
        strncpy(pBuffer[i].zona,CHARVACIO,16);
        pBuffer[i].estado=0;
        pBuffer[i].cantidadAfiches=-1;
        pBuffer[i].isEmpy=1;
        pBuffer[i].idCliente=-1;
        pBuffer[i].estado=0;
    }
    return 0;
}
int parcial_altaCliente(Cliente* pBuffer,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        if(pBuffer[i].isEmpy==1)
        {

            pBuffer[i].id=i;
            printf("\nIngrese nombre\n");
            getString(pBuffer[i].nombre,32);
            printf("\nIngrese apellido\n");
            getString(pBuffer[i].apellido,32);
            printf("\nIngrese cuit\n");
            getInt(&pBuffer[i].cuit);
            pBuffer[i].isEmpy=0;
            printf("\nId de cliente %d",i);
            break;
        }

    }
    return 0;

}

int parcial_altaVenta(Venta* pBuffer,Cliente* pBufferCLiente,int limite)
{
    int i;
    int aux;
    int opcion;
    for(i=0;i<limite;i++)
    {
        if(pBuffer[i].isEmpy==1)
        {
            printf("\nIngrese ID del cliente \n");
            getInt(&aux);
            if(pBufferCLiente[aux].isEmpy==0)
            {
                pBuffer[i].id=i;
                pBuffer[i].idCliente=aux;
                printf("\nIngrese cantidad de afiches\n");
                getInt(&pBuffer[i].cantidadAfiches);
                printf("\nIngrese nombre del archivo \n");
                getString(pBuffer[i].nombreArchivo,32);
                printf("\nIngrese cuit\n1-CABA\n2-Zona sur\n3-Zona oeste\n");
                opciones:
                getInt(&opcion);
                switch(opcion)
                {
                    case 1:
                        strncpy(pBuffer[i].zona,"CABA",16);
                        break;
                    case 2:
                        strncpy(pBuffer[i].zona,"Zona sur",16);
                        break;
                    case 3:
                        strncpy(pBuffer[i].zona,"Zona norte",16);
                        break;
                    default:
                        printf("Esa no es opcion");
                        goto opciones;
                        break;
                }
                printf("\nID de la venta ");
                printf("%d",i);
                pBuffer[i].isEmpy=0;
                pBuffer[i].estado=0;

                break;
            }else{
            printf("Ese cliente no existe");
            }

        }

    }
    return 0;

}

int parcial_bajaCliente(Cliente* pBuffer,int limite)
{
    int i;
    printf("\nIngese id de cliente a dar de baja\n");
    getInt(&i);
    if(pBuffer[i].isEmpy==0)
    {
        strncpy(pBuffer[i].nombre,CHARVACIO,32);
        strncpy(pBuffer[i].apellido,CHARVACIO,32);
        pBuffer[i].cuit=-1;
        pBuffer[i].isEmpy=1;
    }else{
    printf("ID vacio, elija un id dado de alta");
    }


    return 0;


}

int parcial_ventaCobrada(Venta* pBuffer,int limite)
{
    int i;
    printf("\nIngese id de venta a cobrar \n");
    getInt(&i);
    if(pBuffer[i].isEmpy==0)
    {
        pBuffer[i].estado=1;
    }else{
    printf("ID vacio, elija un id dado de alta");
    }


    return 0;


}


int parcial_modificarCliente(Cliente* pBuffer)
{
    int i;
    printf("\nIngese id de pantalla a modificar\n");
    getInt(&i);
    if(pBuffer[i].isEmpy==0)
    {
        printf("\nIngrese nombre\n");
        getString(pBuffer[i].nombre,32);
        printf("\nIngrese apellido\n");
        getString(pBuffer[i].apellido,32);
        printf("\nIngrese cuit\n");
        getInt(&pBuffer[i].cuit);
    }else{
    printf("ID vacio, elija un id dado de alta");
    }
    return 0;
}

int parcial_modificarVenta(Venta* pBuffer)
{
    int i;
    int opcion;
    printf("\nIngese id de pantalla a modificar\n");
    getInt(&i);
    if(pBuffer[i].isEmpy==0)
    {
      pBuffer[i].id=i;
                printf("\nIngrese cantidad de afiches\n");
                getInt(&pBuffer[i].cantidadAfiches);
                printf("\nIngrese nombre del archivo \n");
                getString(pBuffer[i].nombreArchivo,32);
                printf("\nIngrese cuit\n1-CABA\n2-Zona sur\n3-Zona oeste\n");
                opciones:
                getInt(&opcion);
                switch(opcion)
                {
                    case 1:
                        strncpy(pBuffer[i].zona,"CABA",16);
                        break;
                    case 2:
                        strncpy(pBuffer[i].zona,"Zona sur",16);
                        break;
                    case 3:
                        strncpy(pBuffer[i].zona,"Zona norte",16);
                        break;
                    default:
                        printf("Esa no es opcion");
                        goto opciones;
                        break;
                }
                printf("\nID de la venta ");
                printf("%d",i);
                pBuffer[i].isEmpy=0;

    }else{
    printf("ID vacio, elija un id dado de alta");
    }
    return 0;
}

int mostrar(Cliente* pBuffer,Venta* pBufferSecundario,int limite,int limiteVentas)
{
//    int i;
    int j;
    //for(i=0;i<limite;i++)
    //{
        //if(pBuffer[i].isEmpy==0)
        //{
            //printf("\nNombre %s\n",pBuffer[i].nombre);
            //printf("\nApellido %s\n",pBuffer[i].apellido);
            //printf("\nCuit %d\n",pBuffer[i].cuit);
            for(j=0;j<limiteVentas;j++)
            {
                //if(pBuffer[i].id==pBufferSecundario[j].idCliente)
                if(pBufferSecundario[j].isEmpy==0)
                {
                    printf("\nid %d\n",pBufferSecundario[j].id);
                    printf("\nidCliente %d\n",pBufferSecundario[j].idCliente);
                    printf("\nNombre archivo %s\n",pBufferSecundario[j].nombreArchivo);
                    printf("\ncantidad afiches %d\n",pBufferSecundario[j].cantidadAfiches);
                    printf("\nzona %s\n",pBufferSecundario[j].zona);
                    printf("\nestado ");
                    if(pBufferSecundario[j].estado==1)
                    {
                       printf("cobrada\n");
                    }else
                    {printf("a cobrar\n");}

                }
            //}
        }



    //}

    return 0;
}

int parcial_imprimirClientes(Cliente* pBuffer,Venta* pBufferSecundario,int limite,int limiteVentas)
{
    int i;
    int cantidad=0;
    int j;
    for(i=0;i<limite;i++)
    {
        if(pBuffer[i].isEmpy==0)
        {
            printf("\nNombre %s\n",pBuffer[i].nombre);
            printf("\nApellido %s\n",pBuffer[i].apellido);
            printf("\nCuit %d\n",pBuffer[i].cuit);
            for(j=0;j<limiteVentas;j++)
            {
                if(pBuffer[i].id==pBufferSecundario[j].idCliente)
                {
                    if(pBufferSecundario[j].estado!=1)
                    {
                        cantidad++;
                    }
                }

            }
            printf("\nCantidad de ventas a cobrar %d\n",cantidad);
        }
    }

    return 0;

}

int menu(Cliente* pBuffer,Venta* pBufferSecundario,int limite,int limiteVentas)
{

    int aux;
    int i;
    for(i=0;i<3;i++)
    {
      parcial_altaCliente(pBuffer,limite);
    }
    menu:
    printf("\n\n1-Alta de cliente\n2-Modificar datos de cliente\n3-Baja de cliente\n4-Vender afiche\n5-Editar afiche\n6-Cobrar venta\n7-Imprimir cliente\n99-Salir\n");
    __fpurge(stdin);
    scanf("%d",&aux);
    switch(aux)
    {
        case 1:
            parcial_altaCliente(pBuffer,limite);
            goto menu;
            break;
        case 2:
            parcial_modificarCliente(pBuffer);
            goto menu;
            break;
        case 3:
            parcial_bajaCliente(pBuffer,limite);
            goto menu;
            break;
        case 4:
            parcial_altaVenta(pBufferSecundario,pBuffer,limiteVentas);
            goto menu;
            break;
        case 5:
            parcial_modificarVenta(pBufferSecundario);
            goto menu;
            break;
        case 6:
            parcial_ventaCobrada(pBufferSecundario,limiteVentas);
            goto menu;
            break;
        case 7:
            parcial_imprimirClientes(pBuffer,pBufferSecundario,limite,limiteVentas);
            goto menu;
            break;
        case 99:
            break;
        case 33:
            mostrar(pBuffer,pBufferSecundario,limite,limiteVentas);
            goto menu;
            break;
        default:
            printf("Opcion no valida, ingrese opcion valida");
            goto menu;
            break;

    }


    return 0;
}
