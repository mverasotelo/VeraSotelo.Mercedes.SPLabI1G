#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veraSotelo.h"

int menuOpciones()
{
    int opcion;
    printf("\n     PAISES AFECTADOS VIRUS COVID-19\n   ___________________________________\n\n");
    printf("1. Cargar archivo\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar estadisticas\n");
    printf("4. Filtrar por paises exitosos\n");
    printf("5. Filtrar por paises en el horno\n");
    printf("6. Ordenar por nivel de vacunacion\n");
    printf("7. Mostrar mas castigado\n");
    printf("8. Salir\n\n");
    opcion = getOption(1,8);
    return opcion;
}

int getOption(int min, int max)
{
	int opcion;
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion < min || opcion > max)
    {
        printf("Opcion invalida. Ingrese nuevamente: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    printf("\n");
    return opcion;
}

int getPath(char* path, int maxLen)
{
    int retorno = 0;
    char aux[maxLen + 5];
    if(path!=NULL && maxLen > 0 && maxLen < maxLen + 5)
    {
        printf("Ingrese path: ");
        fflush(stdin);
        fgets(aux,maxLen+5,stdin);
        while(strlen(aux) > maxLen)
        {
            printf("El maximo numero de caracteres permitidos es %d. Reingrese nombre: ",maxLen);
            fflush(stdin);
            fgets(aux,maxLen+5,stdin);
        }
        aux[strlen(aux)-1]='\0';
        strcpy(path, aux);
        retorno=1;
    }
    return retorno;
}
