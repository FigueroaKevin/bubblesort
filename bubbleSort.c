/*
*Intitution: Intituto Politecnico Nacional
*Section: Escuela Superior de Computo
*Course: N/A
*Author: Figueroa Rivera Kevin
*Data: Septiembre 2022
*Description: Basic implementation of bubble sort algorithm in c
*/

#include<stdio.h> //E/S
#include<stdlib.h> //rand
#include<stdbool.h> //booleanos
#define TAM 1000

/*This funtion inserts random numbers in an array
*@param {*int} arre [array of numbers]
*@param {int} tam [array size]
*/
void numeros_aleatorios(int arre[], int tam)
{
    int i=0;
    for(i=0; i<tam; i++)
    {
        //genera numeros aleatorios entre 0 y n+1
        arre[i] = rand() % (tam+1);
    }
}

/*This funtion print an array, without return
*@param {*int} arre [array of numbers]
*@param {int} tam [array size]
*/ 
void imprime_arreglo(int arre[], int tam)
{
    int i=0;
    for(i=0; i<tam; i++)
    {
        printf("%d, ",arre[i]);
    }
    putchar('\n');
}

/*This funtion inserts random numbers in an array
*@param {*int} arre [array of numbers]
*@param {int} tam [array size]
*/
void bubble_sort(int arre[], int tam)
{
    int i = 0, j = 0, contador = 0, temp = 0;
    bool flag = true;
    while (flag)
    {
        flag = false; 
        contador = contador + 1;
        for(j=0; j<tam-contador; j++)
        {
            if(arre[j] > arre[j+1])
            {
            //Permutation block
            temp = arre[j];
            arre[j] = arre[j+1];
            arre[j+1] = temp;
            flag = true;
            }
        }
    }
}

void principal()
{
    int arre[TAM], tam;
    //int tam = 10; Este va ser dado por el ususario
    printf("\nIntroduce el tamaño del arreglo\n");
    scanf("%d", &tam);
    printf("Arreglo no ordenado\n");
    numeros_aleatorios(arre, tam);
    imprime_arreglo(arre, tam);
    printf("Arreglo ordenado\n");
    bubble_sort(arre, tam);
    imprime_arreglo(arre, tam);
}

int main(int argc, char *argv[])
{
    principal();
    return 0;
}


//Este es un nuevo comentario para probar git 
//Este es para prbar el commit 