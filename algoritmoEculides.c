/*
 *Institution: Instituto Politecnico Nacional 
 *Section: Escuela Superior de Computo
 *Course: Analisis de Algoritmos 
 *Author: Figueroa Rivera Kevin 
 *Data: Septiembre 2022
 *Description:Implementation of Euclides algorithm
 */


#include<stdio.h>
#include<stdlib.h>
#define TAM 1000

/*Find the greatest common factor (Euclides algorithm)
*@param {*int} cont [executed steps counter ]
*@param {int} a [a number]
*@param {int} b [a number]
*@return {int} a [GCD of a and b]
*/
int mcdEuclides(int a, int b, int *cont)
{
    int temp; (*cont)++; 
    while(b != 0)
    {
        (*cont)++; 

        temp = b; (*cont)++; 
        
        b = a % b; (*cont)++;
        
        a = temp; (*cont)++;
    
    }
    (*cont)++; 
    (*cont)++; 
    return a;
}


/* Generate a random array of a numbers
*@param {int} tam [number of elements in the sequence]
*@param {int[]} arre2 [array of random numbers]
*/
void caso_aleatorio(int tam, int *arre2)
{
    int i = 0;
    for(i = 0; i<tam; i++)
    {
        //LLena el arreglo con numeros aleatorios entre 0 y 100
        arre2[i] = rand() % (tam+1);
        
    }
}



/* Generate a fibonacci sequence
*@param {int} num [number of elements in the sequence]
*@return {int} [The recursive sequence]
*/
int fibonacci(int num)
{
  if (num > 2)
    return fibonacci(num - 1) + fibonacci(num - 2);
  else if (num == 2)
    return 1;
  else if (num == 1)       
    return 1;
  else if (num == 0)
    return 0;
}


/* Generate a array with the fibonacci sequence
*@param {int} tam [number of elements in the sequence]
@param {int[]} arre1 [array of fibonacci sequence]
*/
void peorCaso(int tam, int*arr1)
{   
    int i = 0;
    for(i = 0; i<=tam; i++)
    {
        arr1[i] = fibonacci(i);
        //printf("%d ,",arr1[i]);
    }

    
}



void genera_archivo(int *contador, int *array, int tam)
{
    int i = 0;
    FILE *flujo = fopen("mi_prueba_archivo.txt", "w+"); //abre archivo, modo escritura, si no existe lo creea.
    //Modulo para validar si se abre el archivo
    if (flujo == NULL)
    {
        perror("Error al abrir el archivo\n");
        //return 1;
    }
    else
    {
        for(i=0; i<tam; i++)
        {
            fprintf(flujo, "%d  %d\n", array[i], contador[i]);
        }
    }
    fflush(flujo);
    fclose(flujo);
}


void main_menu()
{
    int n1 = 0, n2 = 0, cont = 0, arre1[TAM], arre2[TAM], ct[TAM], num = 0, n, opcion, i = 0;
    int tam = 30; //Es el tamaño del arreglo, numero de elementos en la secuenacia
    do
    {
        printf( "\n 1. Caso propuesto");
        printf( "\n 2. Peor caso");
        printf( "\n 3. Caso aleatorio");
        printf( "\n 4. Salir");
        printf( "\n Introduzca opcion: \n");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("\nIngresa los numeros a y b, separados por una coma\n");
                scanf("%d, %d", &n1, &n2);
                printf("El M.C.D para los numero %d, %d es: %d\n",mcdEuclides(n1,n2,&cont));
                printf("Ct = %d\n",cont);  
                break;
            case 2:
                peorCaso(tam, arre1);
                for(i=0; i<tam; i++)
                {
                    printf("\nEl M.C.D del peor caso para los numero %d, %d es: %d\n",arre1[i], arre1[i+1], mcdEuclides(arre1[i], arre1[i+1], &cont));
                    printf("Ct = %d\n",cont); 
                    ct[i] = cont;
 
                }
                genera_archivo(ct, arre1, tam);
                
                break;
            case 3:
                caso_aleatorio(tam, arre2);
                for(i=0; i<tam; i++)
                {
                    printf("\nEl M.C.D del caso aleatorio para los numero %d, %d es: %d\n",arre2[i], arre2[i+1], mcdEuclides(arre2[i], arre2[i+1], &cont));
                    printf("Ct = %d\n",cont);
                    ct[i] = cont;
                }
                genera_archivo(ct, arre2, tam);
                break;

        }
    }while(opcion != 4);
    
}


int main()
{   
    main_menu();
    return 0;
}




