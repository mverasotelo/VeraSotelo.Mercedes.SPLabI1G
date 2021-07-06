#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

//prototipos funciones estaticas
/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


//funciones publicas
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = (LinkedList*) malloc(sizeof(LinkedList) *1);

    if(this != NULL){
        this->pFirstNode = NULL;
        this->size = 0;
    }
    return this;
}

int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
        returnAux=this->size;
    }
    return returnAux;
}


static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* nodo = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
        nodo = this -> pFirstNode;
        while(nodeIndex > 0){
            nodo = nodo -> pNextNode;
            nodeIndex--;
        }
    }
    return nodo;
}


Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node * newNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){ //valido los parametros
            newNode = (Node*) malloc(sizeof(Node)); //creo un nuevo nodo
            if(newNode!= NULL){ //chequeo que el nuevo nodo no apunte NULL
                newNode->pElement = pElement; //le asigno al nuevo nodo la carga pasada por parametro
                newNode->pNextNode = getNode(this, nodeIndex);  //hago que mi nodo nuevo apunte al nodo en la pos. nodeIndex
                if(nodeIndex != 0){
                    getNode(this, nodeIndex-1)->pNextNode = newNode; //hago que el nodo anterior apunte al nuevo nodo
                }
                else{
                    this->pFirstNode = newNode; //si la posicion es cero hago que la lista apunte al nuevo nodo
                }
            this->size++; //agrando la lista en 1
            returnAux = 0;
        }
    }
    return returnAux;
}


int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


int ll_add(LinkedList* this, void* pElement)
{
    return addNode(this,ll_len(this),pElement);
}


void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodo = getNode(this,index);

    if(nodo != NULL){
        returnAux = nodo->pElement;
    }
    return returnAux;
}


int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodo = getNode(this,index);

    if(nodo != NULL){
        nodo->pElement = pElement;
        returnAux = 0;
    }
    return returnAux;
}


int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node * nodoAnterior = NULL;
    Node * nodoActual = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        nodoActual = getNode(this, index);
        if(index != 0)
        {
            nodoAnterior = getNode(this,index-1);
            if (nodoAnterior != NULL)
            {
                nodoAnterior -> pNextNode = getNode(this,index+1);
            }
        }
        else
        {
            this->pFirstNode = getNode(this,index+1);
        }
        free(nodoActual);
        this->size--;
        returnAux = 0;
    }
    return returnAux;
}


int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        while(!ll_isEmpty(this)){
            ll_remove(this,0);
        }
        returnAux = 0;
    }
    return returnAux;
}


int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(!ll_clear(this))
    {
        free(this);
        returnAux = 0;
    }

    return returnAux;
}


int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        for(int i=0; i<ll_len(this);i++)
        {
            if(ll_get(this,i) == pElement){
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if( this != NULL)
    {
        returnAux = 0;
        if(!ll_len(this))
        {
            returnAux = 1;
        }
    }
    return returnAux;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);
}


void* ll_pop(LinkedList* this, int index)
{
    void* returnAux = NULL;

    returnAux = ll_get(this,index);
    if(ll_remove(this,index))
    {
        returnAux = NULL;
    }

    return returnAux;
}


int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 0;
        if(ll_indexOf(this, pElement) != -1)
        {
            returnAux = 1;
        }
    }

    return returnAux;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int tam;

    if(this != NULL && this2 != NULL)
    {
        tam = ll_len(this2);
        returnAux = 1;
        for(int i=0;i<tam;i++)
        {
            if(!ll_contains(this,ll_get(this2,i)))
            {
                returnAux = 0;
                break;
            }
        }
    }

    return returnAux;
}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int tam;

    if(this != NULL)
    {
        tam=ll_len(this);
        if(from >= 0 && to >= from && to <= tam)
        {
            cloneArray = ll_newLinkedList();
            if(cloneArray != NULL)
            {
                for(int i=from;i<to;i++)
                {
                    ll_add(cloneArray,ll_get(this,i));
                }
            }
        }
    }
    return cloneArray;
}


LinkedList* ll_clone(LinkedList* this)
{
    return ll_subList(this,0,ll_len(this));
}


int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void * element1 = NULL;
    void * element2 = NULL;
    int tam;

    if(this != NULL && pFunc != NULL && (order == 0 || order ==1))
    {
        tam = ll_len(this);
        for(int i=0;i<tam-1;i++)
        {
            for(int j=i+1;j<tam;j++)
            {
                element1 = ll_get(this,i);
                element2 = ll_get(this,j);

                if((!order && pFunc(element1,element2) == -1) || (order && pFunc(element1,element2) == 1))
                {
                    ll_set(this,i, element2);
                    ll_set(this,j, element1);
                }
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*)){

    LinkedList* newList = NULL;
    void* pElement;

    if(this!=NULL && pFunc!=NULL)
    {
        newList = ll_newLinkedList();

        if(newList != NULL)
        {
            for(int i=0;i<ll_len(this);i++)
            {
                pElement=ll_get(this,i);
                if(pFunc(pElement))
                {
                    ll_add(newList,pElement);
                }
            }
        }
    }
    return newList;
}

LinkedList* ll_map (LinkedList* this, void*(*pFunc) (void* element))
{
    LinkedList* newList = NULL;
    void* elemento;
    int len;

    if (this!=NULL && pFunc!=NULL){
        newList = ll_newLinkedList();
        if (newList!=NULL){
            len = ll_len(this);
            for (int i=0;i<len;i++){
                elemento = ll_get(this,i);
                elemento = pFunc(elemento);
                if (elemento!=NULL){
                    ll_add(newList,elemento);
                }

            }
        }
    }
    return newList;
}
