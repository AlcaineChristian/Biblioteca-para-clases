#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"


static int getInt(int* pResultado);//static sirve para que sea privada de este archivo utn.c

int utn_getEntero(int* pNumero,int intentos, char* mensaje, char* mensajeError,int max, int min)
{
    int retorno =-1;
    int auxiliar;
    int i=0;
    while(i<intentos)
    {

        printf("%s\n",mensaje);
        if(getInt(&auxiliar) == 0)
        {
            if(auxiliar >= min && auxiliar <= max)
            {
                *pNumero = auxiliar;
                retorno = 0;
                break;
            }
            else
            {
                printf(mensajeError);
                i++;

            }
        }else
        {
            printf(mensajeError);
            __fpurge(stdin);
            i++;
            printf("%d",i);

        }

    }


    return retorno;

}

static int getInt(int* pResultado)
{
    int retorno = -1;
    int auxResultado;
    int valorScanf;


    valorScanf=scanf("%d",&auxResultado);
    if(valorScanf==1)
    {

        *pResultado=auxResultado;
        retorno=0;
    }

    return retorno;
}

int utn_getFlotante(float* pNumero,int intentos , char* mensajeOk , char* mensajeError, int max, int min)
{
    float auxFloat;
    int resultadoScanf;
    int retorno = -1;

    do
      {
         printf("\nIngrese el numero");
         resultadoScanf=scanf("%f",&auxFloat);

         if(resultadoScanf==1)
         {
             if(auxFloat<max&&auxFloat>min)
             {
                 *pNumero=auxFloat;
                 retorno=0;
                 printf("\n%s",mensajeOk);
                 break;
             }
         }
         else
         {
             printf(mensajeError);
             fflush(stdin);
             intentos--;
         }

       }while(intentos>0);

       return retorno;

}


int mostrarArray(int* pArray, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("\nIndex: %d - Value: %d - Add: %p",i,pArray[i],&pArray[i]);

    }

return 0;

}

int mostrarArrayMaximo(int* pArray, int limite)
{
    int i;
    int iMax;
    int maximo=pArray[0];

    for(i=0;i<limite;i++)
    {
        if(pArray[i]>maximo)
        {
            iMax=i;
        }
    }


printf("\nMAXIMO\nIndex: %d - Value: %d - Add: %p",iMax,pArray[iMax],&pArray[iMax]);



return 0;

}
