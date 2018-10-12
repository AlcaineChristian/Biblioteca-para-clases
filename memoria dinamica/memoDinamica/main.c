#include <stdio.h>
#include <stdlib.h>

int* newArray(int size)
{
    int* ret = NULL;
    int* auxInt;
    if(size>0)
    {
        auxInt = malloc(sizeof(int)*size);
        if(auxInt != NULL)
        {
            ret = auxInt;
        }
    }
    return ret;
}
int initArray(int* arrayInt,int limite,int valor)
{
    int ret=-1;
    int i;
    if(arrayInt != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            *(arrayInt+i)=valor;
        }
        ret=0;
    }
    return ret;


}
int showArray(int* arrayInt,int limite)
{
    int ret=-1;
    int i;
    if(arrayInt != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            printf("\n%p - [%d] - %d\n",(arrayInt+i),i,*(arrayInt+i));
        }
        ret=0;
    }
    return ret;

}
int deleteArray(int* arrayInt,int size)
{
    int ret=-1;
    if(arrayInt != NULL)
    {
        free(arrayInt);
        ret=0;
    }
    return ret;

}

int main()
{
    int* arrayEnteros;
    arrayEnteros = newArray(100);
    initArray(arrayEnteros,100,1024);
    showArray(arrayEnteros,100);
    deleteArray(arrayEnteros,100);



    return 0;
}
