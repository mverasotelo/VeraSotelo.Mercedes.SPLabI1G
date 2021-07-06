#include <stdio.h>
#include <stdlib.h>
#include "parser.h"


int parser_FromText(FILE* pFile , LinkedList* pLinkedList)
{
    int retorno = 0;
    char buffer[4][20];
    int cant;
    ePais * aux = NULL;

    if(pLinkedList != NULL && pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
        do
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            if(cant == 5)
            {
                aux = newpaisParam(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
                if(aux!=NULL)
                {
                    ll_add(pLinkedList,aux);
                    aux=NULL;
                }
                else
                {
                    printf("No se pudo cargar el elemento\n");
                }
                retorno=1;
            }
            else
            {
                printf("Ha ocurrido un error al leer los datos\n");
            }
        }
        while(!feof(pFile));
    }
    return retorno;
}
