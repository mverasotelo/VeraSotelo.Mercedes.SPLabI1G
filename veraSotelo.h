#ifndef VUELOS_H_INCLUDED
#define VUELOS_H_INCLUDED

/** \brief menu de opciones
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int menuOpciones();


/** \brief pide y valida una opcion
 *
 * \param min int opcion minima
 * \param max int opcion maxima
 *
 */
int getOption(int min, int max);


/** \brief Pide el nombre de archivo al usuario y lo valida
 *
 * \param nombre char* path
 * \param maxLen int maximo de caracteres permitidos
 * \return int devuelve 1 si esta todo OK y 0 si algo salio mal
 *
 */
int getPath(char *path, int maxLen);

#endif // VUELOS_H_INCLUDED
