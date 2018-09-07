#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#define CANTIDAD_EMPLEADOS 5
#define DATO_INVALIDO -1
#define false 0
#define true 1


static int getInt(int* pResultado);



int funcion(void)
{
    static int i=9;

    i++;
    return i;
}



int utn_getEntero(int* pEdad,int reintentos,char* msg,char*msgErr,int min, int max)
{



    int retorno = -1;
    int auxiliarEdad;

    for(;reintentos > 0;reintentos--)
    {
        printf(msg);

        //if(scanf("%d",&auxiliarEdad) == 1)
        if(getInt(&auxiliarEdad) == 0)
        {
            if(auxiliarEdad >= min && auxiliarEdad < max)
            {
                *pEdad = auxiliarEdad;
                retorno = 0;
                break;
            }
            else
            {
                printf(msgErr);
            }
        }
        else
        {
            printf(msgErr);
            __fpurge(stdin);
        }
    }
    return retorno;
}

static int esNumero(char pSimbolo[])
{
    int ret=1;
    int i=0;
    int aux;

    aux=pSimbolo[i];
    while(aux!=0)
    {
        if(aux>57 || aux<48)
            {
                ret=0;
                break;
            }
            i++;
            aux=pSimbolo[i];

    }

    return ret;

}





static int getInt(int* pResultado)
{

    int aux;
    char cadena[64];
    int ret=-1;


    scanf("%s",cadena);
    //validar

        if(esNumero(cadena)==1)
        {
            aux = atoi(cadena);
            *pResultado = aux;


            ret=0;
        }else
        {
            ret=-1;
        }



    return ret;
/*
    int aux;
    int ret=-1;
    if(scanf("%d",&aux) == 1)
    {
        *pResultado = aux;
        ret=0; // ok
    }
    return ret;
    */
}


int ordenarArrayMenorMayor(int* pArray, int limite)
{
    int i;
    int aux;
    int flag=1;


    if(pArray != NULL && limite > 0)
    {
        while(flag==1)
        {
            flag=0;
            for(i=0;i<(limite-1);i++)
            {
                if(pArray[i] > pArray[i+1])
                {
                    aux=pArray[i];
                    pArray[i]=pArray[i+1];
                    pArray[i+1]=aux;
                    flag=1;
                }
            }
        }


    }
    return 0;
}

int mostrarArray(int* pArray, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("\nIndex:%d - Value:%d - Add: %p",i,pArray[i],&pArray[i]);

    }
    return 0;
}

int initArray(int* pArray, int limite, int valor)
{
    int retorno=-1;
    int i;
    if(pArray != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            pArray[i] = valor;
        }
        retorno = 0;
    }
    return retorno;
}

