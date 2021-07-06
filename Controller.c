#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Controller.h"


int controller_loadFromText(char* path , LinkedList* pLinkedList)
{
    int retorno = 0;

    if(pLinkedList != NULL)
    {
        FILE* f = fopen(path, "r");
        if(f != NULL)
        {
            if(parser_FromText(f, pLinkedList))
            {
                retorno = 1;
            }
        }
        fclose(f);
    }
    return retorno;
}


int controller_List(LinkedList* pLinkedList)
{
    int retorno=0;
    ePais* aux = NULL;
    int tam = ll_len(pLinkedList);

    printf("   ID             NOMBRE             1 DOSIS        2 DOSIS      SIN VACUNAR\n\n");
    if(pLinkedList != NULL )
    {
        if(tam > 0)
        {
            for(int i=0;i<tam;i++)
            {
                aux = ll_get(pLinkedList,i);
                mostrarPais(aux);
            }
            printf("\n\n");
        }
        else
        {
            printf("No hay elementos para mostrar\n\n");
        }
        retorno = 1;
    }
    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pLinkedList)
{
    int retorno=0;
    int tam;
    int cant;
    ePais * aux = NULL;

    FILE* f = fopen(path, "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        if(pLinkedList != NULL)
        {
            tam = ll_len(pLinkedList);
            for(int i=0;i<tam;i++)
            {
                aux = ll_get(pLinkedList, i);
                if(aux != NULL){
                    cant = fprintf(f,"%d, %s, %d, %d, %d\n",aux->id, aux->nombre, aux->vac1dosis, aux->vac2dosis, aux->sinVacunar);
                    if(cant < 4)
                    {
                        break;
                    }
                }
                retorno = 1;
            }
        }
    }
    fclose(f);
    return retorno;
}

LinkedList* controller_filterPaisesExitosos(LinkedList * lista)
{
    LinkedList* listaFiltrada = NULL;

    if(lista != NULL)
    {
        listaFiltrada = ll_filter(lista,filterPaisesExitosos);
        if(listaFiltrada != NULL)
        {
            controller_List(listaFiltrada);
            if(!controller_saveAsText("paisesExitosos.csv",listaFiltrada))
            {
                ll_deleteLinkedList(listaFiltrada);
            }
        }
    }
    return listaFiltrada;
}

LinkedList* controller_filterPaisesHorno(LinkedList * lista)
{
    LinkedList* listaFiltrada = NULL;

    if(lista != NULL)
    {
        listaFiltrada = ll_filter(lista,filterPaisesEnElHorno);
        if(listaFiltrada != NULL)
        {
            controller_List(listaFiltrada);
            if(!controller_saveAsText("paisesHorno.csv",listaFiltrada))
            {
                ll_deleteLinkedList(listaFiltrada);
            }
        }
    }
    return listaFiltrada;
}


int controller_paisesMasCastigados(LinkedList * lista)
{
    int retorno = 0;
    ePais * aux = NULL;
    int menorVacunados = 0;

    if(lista != NULL)
    {
        if(!ll_sort(lista,compareSinVacunar,0))
        {
            aux = ll_get(lista,0);

            getSinVacunar(aux, &menorVacunados);
            for(int i=0;i<ll_len(lista);i++)
            {
                aux = ll_get(lista,i);
                if(aux->sinVacunar == menorVacunados)
                {
                    printf(" - %s   %d %% de la poblacion sin vacunar\n\n", aux->nombre, aux->sinVacunar);
                }
            }
        }
        retorno = 1;
    }
    return retorno;
}
