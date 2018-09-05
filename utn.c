#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */

float utn_getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

/**
* \brief Realiza una suma con dos numeros antes pedidos
* \param mensaje Es el mensaje a mostrar
* \param numeroUno Es uno de los numeros a utilizar
* \param numeroDos Es el otro numero a utilizar
* \return La suma de ambos numeros
*
*/

float utn_getSuma(float numeroUno,float numeroDos)
{
    float suma;
    suma = numeroUno + numeroDos;
    return suma;
}
/**
* \brief Realiza una resta con dos numeros antes pedidos
* \param mensaje Es el mensaje a mostrar
* \param numeroUno Es uno de los numeros a utilizar
* \param numeroDos Es el otro numero a utilizar
* \return La resta de ambos numeros
*
*/

float utn_getResta(float numeroUno,float numeroDos)
{
    float resta;
    resta = numeroUno - numeroDos;
    return resta;
}
/**
* \brief Realiza una multiplicacion con dos numeros antes pedidos
* \param mensaje Es el mensaje a mostrar
* \param numeroUno Es uno de los numeros a utilizar
* \param numeroDos Es el otro numero a utilizar
* \return La multiplicacion de ambos numeros
*
*/

float utn_getMultiplicacion(float numeroUno,float numeroDos)
{
    float multiplicacion;
    multiplicacion = numeroUno * numeroDos;
    return multiplicacion;
}
/**
* \brief Realiza una division con dos numeros antes pedidos
* \param mensaje Es el mensaje a mostrar
* \param numeroUno Es uno de los numeros a utilizar
* \param numeroDos Es el otro numero a utilizar
* \return La division de ambos numeros
*
*/

float utn_getDivision(float numeroUno,float numeroDos)
{
    float division;
    division = numeroUno / numeroDos;
    return division;
}
/**
* \brief Realiza una factorizacion con un numero antes pedido
* \param mensaje Es el mensaje a mostrar
* \param numero Es el numero a utilizar
* \return La factorizacion del numero
*
*/

float utn_getFactorial(float numero)
{
    float factorial;
    float i;
    factorial = 1;
    for (i=1;i<=numero;i++)
    {
        factorial = factorial * i;
    }
    return factorial;
}
