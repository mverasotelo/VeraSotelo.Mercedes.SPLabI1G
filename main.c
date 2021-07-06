#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "veraSotelo.h"
#include "pais.h"

int main()
{

    srand(time(NULL));
    char path[20];
    char salir;
    int flagFile = 1;
    int flagEstad = 1;

    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaFiltrada = NULL;

    //Si el linkedlist es NULL salgo del programa
    if(lista == NULL){
        printf("ERROR: No se pudo crear la lista\n");
        exit(EXIT_FAILURE);
    }

    do{
        switch(menuOpciones()){

            case 1: //CARGAR ARCHIVO
                if(flagFile)
                {
                    getPath(path,20);
                    if(controller_loadFromText(path,lista))
                    {
                        printf("\nCarga de datos exitosa\n\n");
                        flagFile = 0;
                    }
                    else
                    {
                    printf("\nERROR: Ha ocurrido un error al cargar el archivo\n\n");
                    }
                }
                else
                {
                    printf("ERROR: Ya se ha cargado un archivo\n\n");
                }
                break;

            case 2: //IMPRIMIR LISTA
                if(!flagFile)
                {
                    controller_List(lista);
                }
                else
                {
                    printf("ERROR: Primero debe cargar el archivo\n\n");
                }
                break;

            case 3: //ASIGNAR ESTADISTICAS
                if(!flagFile && flagEstad)
                {
                    lista = ll_map(lista,setValoresRandom);

                    if(lista != NULL)
                    {
                        controller_List(lista);
                        flagEstad = 0;
                    }
                }
                else
                {
                    printf("ERROR: Primero debe cargar el archivo\n\n");
                }
                break;

            case 4: //FILTRAR POR PAISES EXITOSOS
                if(!flagFile && !flagEstad)
                {
                    listaFiltrada = controller_filterPaisesExitosos(lista);
                    if(listaFiltrada != NULL)
                    {
                        printf("* La lista se ha guardado en paisesExitosos.csv\n\n");
                    }
                    else
                    {
                        printf("ERROR: Ha ocurrido un error al guardar los datos\n\n");
                    }
                }
                else
                {
                    printf("ERROR: Primero debe cargar el archivo y asignar las estadisticas\n\n");
                }
                break;

            case 5: // FILTRAR POR PAISES EN EL HORNO
                if(!flagFile && !flagEstad)
                {
                    listaFiltrada = controller_filterPaisesHorno(lista);
                    if(listaFiltrada != NULL)
                    {
                        printf("* La lista se ha guardado en paisesEnElHorno.csv\n\n");
                    }
                    else
                    {
                        printf("ERROR: Ha ocurrido un error al guardar los datos\n\n");
                    }
                }
                else
                {
                    printf("ERROR: Primero debe cargar el archivo y asignar las estadisticas\n\n");
                }
                break;

            case 6: //ORDENAR POR NIVEL DE VACUNACION
                if(!flagFile && !flagEstad){
                    if(!ll_sort(lista,compareVac1dosis,0)){
                        printf("La lista se ha ordenado exitosamente\n\n");
                    }else{
                        printf("ERROR: Ha ocurrido un problema al ordenar la lista\n\n");
                    }
                }else{
                        printf("ERROR: Primero debe cargar el archivo y asignar las estadisticas\n\n");
                }
                break;

            case 7: //MOSTRAR MAS CASTIGADO
                if(!flagFile && !flagEstad){
                    printf("Pais o paises mas castigados:\n");
                    if(!controller_paisesMasCastigados(lista))
                    {
                        printf("ERROR: Ha ocurrido un problema al calcular los datos\n\n");
                    }
                }else{
                        printf("ERROR: Primero debe cargar el archivo y asignar las estadisticas\n\n");
                }
                break;

            case 8: // Salir
                printf("Esta seguro de que desea salir?\n");
                fflush(stdin);
                salir = getchar();
                printf("\n");
                if(salir == 's'){
                    ll_deleteLinkedList(lista); //elimina la linked list
                    ll_deleteLinkedList(listaFiltrada); //elimina la linked list
                    printf("Programa finalizado\n\n");
                }
                break;
        }
    }while(salir != 's');

    return 0;
}
