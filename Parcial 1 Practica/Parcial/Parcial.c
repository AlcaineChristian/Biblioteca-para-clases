#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Parcial.h"
#define CANTIDAD_DE_PANTALLAS 100

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

int pant_inicializarArray(Pantalla* pBuffer,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        pBuffer[i].isEmpy=1;
    }
    return 0;
}

int pant_cargarPrimerIndiceVacio(Pantalla* pBuffer,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        if(pBuffer[i].isEmpy==1)
        {

            pBuffer[i].id=i;
            printf("\nIngrese nombre\n");
            getString(pBuffer[i].nombre,32);
            printf("\nIngrese direccion\n");
            getString(pBuffer[i].direccion,128);
            printf("\nIngrese tipo\n");
            getString(pBuffer[i].tipo,32);
            pBuffer[i].isEmpy=0;
            break;
        }

    }
    return 0;

}

int pant_modificarPantalla(Pantalla* pBuffer)
{
    int i;
    printf("\nIngese id de pantalla a modificar\n");
    getInt( i);
    printf("\nIngrese nombre\n");
    getString(pBuffer[i].nombre,32);
    printf("\nIngrese direccion\n");
    getString(pBuffer[i].direccion,128);
    printf("\nIngrese tipo\n");
    getString(pBuffer[i].tipo,32);
    pBuffer[i].isEmpy=0;

    return 0;
}

int pant_menu(Pantalla* pBuffer,int limite)
{

    int aux;
    menu:
    printf("\n\n1-Alta de pantalla\n2-Modificar datos de pantalla\n3-Baja de pantalla\n");
    __fpurge(stdin);
    scanf("%d",&aux);
    switch(aux)
    {
        case 1:
            pant_cargarPrimerIndiceVacio(pBuffer,limite);
            goto menu;
            break;
        case 2:
            pant_modificarPantalla(pBuffer);
            goto menu;
            break;
        case 3:
            break;
        default:
            printf("Opcion no valida, ingrese opcion valida");
            goto menu;
            break;

    }


    return 0;
}
