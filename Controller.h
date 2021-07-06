#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED
#include "LinkedList.h"
#include "pais.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pLinkedList LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_loadFromText(char* path , LinkedList* pLinkedList);


/** \brief Listar empleados
 *
 * \param path char*
 * \param pLinkedList LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_List(LinkedList* pLinkedList);


/** \brief asigna estadisticas aleatoriamente a los campos vac1dosis, vac2dosis y sin vacunar de un pais
 *
 * \param lista LinkedList* lista de pais
 * \return LinkedList* retorna lista con los valores asignados
 *
 */
LinkedList* controller_asignarEstadisticas(LinkedList * lista);


/** \brief Guarda los datos de los empleados en un archivo (modo texto).
 *
 * \param path char*
 * \param pLinkedList LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_saveAsText(char* path , LinkedList* pLinkedList);


/** \brief Filtra una lista por paises exitosos (países cuya población este vacunada con dos dosis en un porcentaje mayor al 30%)
 *
 * \param lista LinkedList* lista a filtrar
 * \return LinkedList* devuelve la lista si salio todo bien NULL si hay algun error
 *
 */
LinkedList* controller_filterPaisesExitosos(LinkedList * lista);


/** \brief Filtra una lista por paises en el horno (países donde la cantidad de no vacunados sea mayor a la de vacunados)
 *
 * \param lista LinkedList* lista a filtrar
 * \return LinkedList* devuelve la lista si salio todo bien NULL si hay algun error
 *
 */
LinkedList* controller_filterPaisesHorno(LinkedList * lista);


/** \brief informa el o los (en caso de haber empate) paises mas castigados (con mayor porcentaje de poblacion sin vacunar)
 *
 * \param lista LinkedList* lista a analizar
 * \return int devuelve 1 si salio todo bien y 0 si hubo algun error
 *
 */
int controller_paisesMasCastigados(LinkedList * lista);

#endif // controller_H_INCLUDED
