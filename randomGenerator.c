// Declaración de Librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaracion de constantes
#define START_SIZE 30

// Cuerpo principal
int main()
{
    int i, newNumber = 0, positionUpdate, randomNumber = 0, totalRandomNumbers, newTry = 0;

    // Reservando memoria para el array de arranque
    int *startArray = (int *)calloc(START_SIZE, sizeof(int));

    srand(time(NULL));

    do
    {
        // Validacion para el número de entrada
        do
        {
            printf("¿Cuantos números aleatorios desea generar?: ");
            scanf("%d", &totalRandomNumbers);
            if (totalRandomNumbers < 0)
            {
                printf("Error, debe ingresar un numero >= 0. Vuelva a intentarlo.\n");
            }
        } while (totalRandomNumbers < 0);

        // Generando el array de arranque
        for (i = 0; i < START_SIZE; i++)
        {
            startArray[i] = rand();
        };

        // Generando los numeros aleatorio
        for (i = 0; i < totalRandomNumbers; i++)
        {
            newNumber = rand();
            positionUpdate = newNumber % START_SIZE;
            randomNumber = startArray[positionUpdate];

            // Actualiando el numero aleatorio de arranque
            startArray[positionUpdate] = newNumber;

            if (totalRandomNumbers == 1)
            {
                printf("Numero aleatorio: %d\n", randomNumber);
            }
            else
            {
                printf("Numero aleatorio %d: %d\n", (i + 1), randomNumber);
            }
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
    printf("\nHasta luego...");
    return 0;
}