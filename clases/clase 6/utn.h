#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/**
    utn_getEntero : pide un numero al usuario
    @param pNumero: puntero al entero
    @param intentos : cuantos intentos tiene el usuario para agregar el numero
    @param mensaje: el mensaje mostrado en caso de que el usuario haya ingresado un numero valido
    @param mensajeError: el mensaje mostrado en caso de que el usuario no haya ingresado un numero valido
    @param max: el valor maximo permitido del numero ingresado por el usuario
    @param min: el valor minimo del numero ingresado por el usuario
    @return 0 en caso de que se haya bien ingresado / -1 en caso de que se haya ingresado mal


*/

int utn_getEntero(int* ,int , char* , char* ,int ,int );

/**
    utn_getFlotante : pide un numero al usuario
    @param pNumero: puntero al
    @param intentos : cuantos intentos tiene el usuario para agregar el numero
    @param mensaje: el mensaje mostrado en caso de que el usuario haya ingresado un numero valido
    @param mensajeError: el mensaje mostrado en caso de que el usuario no haya ingresado un numero valido
    @param max: el valor maximo permitido del numero ingresado por el usuario
    @param min: el valor minimo del numero ingresado por el usuario
    @return 0 en caso de que se haya bien ingresado / -1 en caso de que se haya ingresado mal


*/
int utn_getFlotante(float* ,int , char* , char*, int , int);

int mostrarArray(int* pArray, int limite);
int mostrarArrayMaximo(int* pArray, int limite);
void fun(char pA[],int lim);

#endif
