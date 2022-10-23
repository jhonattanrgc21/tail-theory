// Declaración de Librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaracion de constantes
#define START_SIZE 30
#define SAMPLE_SIZE 1000000

// Definicion de funciones
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void readAB(int *min, int *max)
{
    // Validacion para el número de entrada
    do
    {
        printf("¿Valor minimo de la distribucion?: ");
        scanf("%d", min);
        if (min < 0)
        {
            printf("Error, debe ingresar un numero >= 0. Vuelva a intentarlo.\n");
        }
    } while (min < 0);

    // Validacion para el número de entrada
    do
    {
        printf("Valor maximo de la distribucion: ");
        scanf("%d", max);
        if (max < 0)
        {
            printf("Error, debe ingresar un numero >= 0. Vuelva a intentarlo.\n");
        }
    } while (max < 0);

    if (min > max)
    {
        swap(min, max);
    }
}

void uniformDistribution(int startArray[], float sampleList[], int min, int max)
{
    int i, newNumber = 0, positionUpdate, randomNumber = 0;

    // Generando los numeros aleatorio
    for (i = 0; i < SAMPLE_SIZE; i++)
    {
        newNumber = rand();
        positionUpdate = newNumber % START_SIZE;
        randomNumber = startArray[positionUpdate];

        // Actualiando el numero aleatorio de arranque
        startArray[positionUpdate] = newNumber;

        sampleList[i] = ((float)randomNumber / RAND_MAX) * (max - min) + min;
    }
}

// Cuerpo principal
int main()
{
    int i, min = 0, max = 0, newNumber = 0, positionUpdate, randomNumber = 0, totalRandomNumbers, newTry = 0;

    // Reservando memoria para el array de arranque
    int *startArray = (int *)calloc(START_SIZE, sizeof(int));
    float *sampleList = (float *)calloc(SAMPLE_SIZE, sizeof(float));

    srand(time(NULL));

    do
    {
        // Generando el array de arranque
        for (i = 0; i < START_SIZE; i++)
        {
            startArray[i] = rand();
        };

        printf("GENERADOR DISTRIBUCION UNIFORME \n");
        readAB(&min, &max);

        // Generando los numeros aleatorio
        uniformDistribution(startArray, sampleList, min, max);
        for (i = 0; i < SAMPLE_SIZE; i++)
        {
            printf("Numero aleatorio %d: %f\n", (i + 1), sampleList[i]);
        }

        // Validacion para repetir el proceso
        do
        {
            printf("\n¿Desea volver a intentar? (1: Si, 2: No): ");
            scanf("%d", &newTry);
            if (newTry < 1 || newTry > 2)
            {
                printf("Error, debe ingresar un numero entre [1, 2]. Vuelva a intentarlo.\n");
            }
        } while (newTry < 1 || newTry > 2);

        if (newTry == 1)
        {
            printf("\n");
        }
    } while (newTry == 1);

    // Liberando la memoria del arreglo de arranque
    free(startArray);
    free(sampleList);
    printf("\nHasta luego...");
    return 0;
}