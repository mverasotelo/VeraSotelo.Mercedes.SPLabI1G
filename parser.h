#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "LinkedList.h"
#include "pais.h"

/** \brief Parsea los datos desde el archivo de texto
 *
 * \param path char*
 * \param pLinkedList LinkedList*
 * \return int devuelve 1 si esta todo OK y 0 si algo salio mal
 *
 */
int parser_FromText(FILE* pFile , LinkedList* pLinkedList);


#endif // PARSER_H_INCLUDED
