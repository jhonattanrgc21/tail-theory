// Declaración de Librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Declaracion de constantes
#define START_SIZE 30
//#define SAMPLE_SIZE 1000000
#define SAMPLE_SIZE 10

/* CK define el numero de datos que se suman para obtener
la distribucion normal */
#define CK 1000

// Definicion de funciones
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void readMinMax(int *min, int *max)
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

void readMeanVariance(float *mean, float *variance)
{
    // Validacion para el número de entrada
    do
    {
        printf("¿Valor de la media de la distribucion: ");
        scanf("%f", mean);
        if (mean < 0)
        {
            printf("Error, debe ingresar un numero >= 0. Vuelva a intentarlo.\n");
        }
    } while (mean < 0);

    // Validacion para el número de entrada
    do
    {
        printf("Valor de la varianza de la distribucion: ");
        scanf("%f", variance);
        if (variance < 0)
        {
            printf("Error, debe ingresar un numero >= 0. Vuelva a intentarlo.\n");
        }
    } while (variance < 0);
}

void normalDistribution(int startArray[], float sampleList[], float mean, float variance)
{
    int i, k, newNumber = 0, positionUpdate, randomNumber = 0;
    ;
    float desv = 0.0, aux = 0.0;

    desv = sqrt(variance);
    for (i = 0; i < SAMPLE_SIZE; i++)
    {
        aux = 0;

        for (k = 0; k < CK; k++)
        {
            // Generando el nuevo numero aleatorio
            newNumber = rand();
            positionUpdate = newNumber % START_SIZE;
            randomNumber = startArray[positionUpdate];

            // Actualiando el numero aleatorio de arranque
            startArray[positionUpdate] = newNumber;

            aux = aux + (float)randomNumber / RAND_MAX;
        }
        sampleList[i] = desv * sqrt((float)12 / CK) * (aux - (float)CK / 2) + mean;
    }
}

// Cuerpo principal
int main()
{
    int i, min = 0, max = 0, newNumber = 0, positionUpdate, randomNumber = 0, totalRandomNumbers, newTry = 0;
    float mean = 0.0, variance = 0.0;

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

        /* Operacion para la distribucion uniforme */
        printf("GENERADOR DISTRIBUCION UNIFORME \n");
        readMinMax(&min, &max);
        uniformDistribution(startArray, sampleList, min, max);
        for (i = 0; i < SAMPLE_SIZE; i++)
        {
            printf("Numero aleatorio uniforme %d: %f\n", (i + 1), sampleList[i]);
        }

        /* Operacion para la distribucion normal */
        printf("\n\nGENERADOR DISTRIBUCION NORMAL \n");
        readMeanVariance(&mean, &variance);
        normalDistribution(startArray, sampleList, mean, variance);
        for (i = 0; i < SAMPLE_SIZE; i++)
        {
            printf("%f\n", sampleList[i]);
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