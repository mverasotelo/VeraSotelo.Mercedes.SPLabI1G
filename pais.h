#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct{
    int id;
    char nombre[25];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
}ePais;


#endif // PAIS_H_INCLUDED


//PROTOTIPOS

//Constructores

/** \brief Devuelve un nuevo puntero a la estructura con todos sus campos inicializados en cero
 *
 * \return ePais* puntero a la nueva estructura
 *
 */
ePais* newPais();


/** \brief Devuelve un nuevo puntero a la estructura con todos los campos inicializados segun valores pasados por parametros, correctamente parseados
 *
 * \param idStr char* Campo ID pasado como cadena
 * \param nombreStr char* Campo nombre pasado como cadena
 * \param vac1dosisStr char* Campo vacunados 1 dosis pasado como cadena
 * \param vac2dosisStr char*  Campo vacunados 2 dosis pasado como cadena
 * \param sinVacunarStr char* Campo sin vacunar pasado como cadena
 * \return ePais* Devuelve el puntero al elemento creado, si hubo algun error devuelve NULL.
 *
 */
ePais* newpaisParam(char* idStr, char* nombreStr, char* vac1dosisStr, char* vac2dosisStr, char* sinVacunarStr);


/** \brief Muestra la informacion de un pais
 *
 * \param this ePais* Puntero al pais a a mostrar
 * \return int devuelve 1 si salio todo bien y 0 si el puntero apunta NULL
 *
 */
int mostrarPais(ePais * this);


/** \brief Borra un elemento
 *
 * \param this ePais* puntero al elemento a borrar
 * \return void
 *
 */
void deletePais(ePais* this);


//Getters

/** \brief obtiene el contenido del campo ID del elemento
 *
 * \param this ePais* puntero al elemento
 * \param id int* direccion de memoria donde guardar el contenido del campo
 * \return int devuelve 1 si salio todo bien y 0 si algun puntero apunta NULL
 *
 */
int getId(ePais* this, int * id);


/** \brief obtiene el contenido del campo nombre del elemento
 *
 * \param this ePais* puntero al elemento
 * \param nombre char* direccion de memoria donde guardar el contenido del campo
 * \return int devuelve 1 si salio todo bien y 0 si algun puntero apunta NULL
 *
 */
int getNombre(ePais* this, char * nombre);


/** \brief obtiene el contenido del campo vac1dosis del elemento
 *
 * \param this ePais* puntero al elemento
 * \param vac1dosis int* direccion de memoria donde guardar el contenido del campo
 * \return int devuelve 1 si salio todo bien y 0 si algun puntero apunta NULL
 *
 */
int getVac1dosis(ePais* this, int * vac1dosis);


/** \brief obtiene el contenido del campo vac2dosis del elemento
 *
 * \param this ePais* puntero al elemento
 * \param vac2dosis int* direccion de memoria donde guardar el contenido del campo
 * \return int devuelve 1 si salio todo bien y 0 si algun puntero apunta NULL
 *
 */
int getVac2dosis(ePais* this, int * vac2dosis);


/** \brief obtiene el contenido del campo sin vacunar del elemento
 *
 * \param this ePais* puntero al elemento
 * \param sinVacunar int* direccion de memoria donde guardar el contenido del campo
 * \return int devuelve 1 si salio todo bien y 0 si algun puntero apunta NULL
 *
 */
int getSinVacunar(ePais* this, int * sinVacunar);


//Setters

/** \brief Setea el campo ID de un elemento
 *
 * \param this ePais* puntero al elemento
 * \param id int valor a asignarle al campo
 * \return int devuelve 1 si salio todo bien y 0 si el puntero apunta NULL o no se pudo validar el dato
 *
 */
int setId(ePais* this, int id);


/** \brief Setea el campo nombre de un elemento
 *
 * \param this ePais* puntero al elemento
 * \param nombre char* valor a asignarle al campo
 * \return int devuelve 1 si salio todo bien y 0 si el puntero apunta NULL o no se pudo validar el dato
 *
 */
int setNombre(ePais* this, char* nombre);


/** \brief Setea el campo vac1dosis de un elemento
 *
 * \param this ePais* puntero al elemento
 * \param tipo int valor a asignarle al campo
 * \return int devuelve  1 si salio todo bien y 0 si el puntero apunta NULL o no se pudo validar el dato
 *
 */
int setVac1dosis(ePais* this, int vac1dosis);


/** \brief Setea el campo vac2dosis de un elemento
 *
 * \param this ePais* puntero al elemento
 * \param vac2dosis int valor a asignarle al campo
 * \return int devuelve 1 si salio todo bien y 0 si el puntero apunta NULL o no se pudo validar el dato
 *
 */
int setVac2dosis(ePais* this,int vac2dosis);


/** \brief Setea el campo sin vacunar de un elemento
 *
 * \param this ePais* puntero al elemento
 * \param sinVacunar int valor a asignarle al campo
 * \return int devuelve 1 si salio todo bien y 0 si el puntero apunta NULL o no se pudo validar el dato
 *
 */
int setSinVacunar(ePais* this,int sinVacunar);


/** \brief Setea un elemento con campos aleatorios
 *
 * \param a void* puntero al elemento
 * \return void* elemento con sus campos modificados
 *
 */
void* setValoresRandom(void* a);


/** \brief chequea si un pais esta en el horno o no
 *
 * \param p void* puntero al pais
 * \return int devuelve 1 si esta al horno y 0 si no esta
 *
 */
int filterPaisesEnElHorno(void* p);


/** \brief chequea si un pais es exitoso o no
 *
 * \param p void* puntero al pais
 * \return int devuelve 1 si es exitoso y 0 si no
 *
 */
int filterPaisesExitosos(void* p);


//Comparison
/** \brief Compara el porcentaje de vacunacion de 1 dosis entre 2 paises
 *
 * \param a void* puntero al pais A
 * \param b void* puntero al pais B
 * \return int devuelve 1 si el porcentaje del primer pais es mayor, -1 si es menor y 0 si alguno de los punteros apunta a NULL
 *
 */
int compareVac1dosis(void* a,void* b);


/** \brief Compara el porcentaje de no vacunados entre 2 paises
 *
 * \param a void* puntero al pais A
 * \param b void* puntero al pais B
 * \return int devuelve 1 si el porcentaje del primer pais es mayor, -1 si es menor y 0 si alguno de los punteros apunta a NULL
 *
 */
int compareSinVacunar(void* a,void* b);
