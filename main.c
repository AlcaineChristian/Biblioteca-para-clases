#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    float operandoUno;
    float operandoDos;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    float factorialUno;
    float factorialDos;
    int opcion;

    operandoUno = utn_getFloat("Ingrese A \n");
    operandoDos = utn_getFloat("Ingrese B \n");

    printf("Ingrese el numero de opcion(cualquier numero para salir)\n1-Suma\n2-Resta\n3-Division\n4-Multiplicacion\n5-Factorial de A y de B\n\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
        case 1:
            suma = utn_getSuma(operandoUno,operandoDos);
            printf("\nEl resultado de A+B es:%.2f",suma);
            break;
        case 2:
            resta = utn_getResta(operandoUno,operandoDos);
            printf("\n“El resultado de A-B es:%.2f",resta);
            break;
        case 3:
            division = utn_getDivision(operandoUno,operandoDos);
            printf("\nEl resultado de A/B es:%.2f",division);
            break;
        case 4:
            multiplicacion = utn_getMultiplicacion(operandoUno,operandoDos);
            printf("\nEl resultado de A*B es:%.2f",multiplicacion);
            break;
        case 5:
            factorialUno = utn_getFactorial(operandoUno);
            factorialDos = utn_getFactorial(operandoDos);
            printf("\nEl factorial de A es: %.2f y El factorial de B es: %.2f",factorialUno,factorialDos);
            break;
        default:
            break;

    }

    return 0;
}
