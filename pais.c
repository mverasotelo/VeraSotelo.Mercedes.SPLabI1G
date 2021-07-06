#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pais.h"

//CONSTRUCTORES
ePais* newPais()
{
    ePais* newPais = (ePais*) malloc(sizeof(ePais));
    if (newPais != NULL)
    {
        newPais->id=0;
        strcpy(newPais->nombre,"");
        newPais->vac1dosis=0;
        newPais->vac2dosis=0;
        newPais->sinVacunar=0;

    }
    return newPais;
}

ePais* newpaisParam(char* idStr, char* nombreStr, char* vac1dosisStr, char* vac2dosisStr, char* sinVacunarStr)
{
    ePais* pais = newPais();

    if (pais != NULL)
    {
        setId(pais, atoi(idStr));
        setNombre(pais, nombreStr);
        setVac1dosis(pais, atoi(vac1dosisStr));
        setVac2dosis(pais, atoi(vac2dosisStr));
        setSinVacunar(pais, atoi(sinVacunarStr));
    }
    else
    {
        free(pais);
        pais = NULL;
    }
    return pais;
}

void deletePais(ePais* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int mostrarPais(ePais * this){
    int retorno = 0;
    int id;
    char nombre[25];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;

    if(this != NULL){
        getId(this,&id);
        getNombre(this,nombre);
        getVac1dosis(this,&vac1dosis);
        getVac2dosis(this,&vac2dosis);
        getSinVacunar(this,&sinVacunar);
        printf(" %4d  %20s        %7ld %%      %7ld %%       %7d %%\n", id, nombre, vac1dosis, vac2dosis, sinVacunar);
        retorno = 1;
    }
    return retorno;
}


//GETTER Y SETTER ID
int setId(ePais* this, int id)
{
    int retorno=0;
    if(this != NULL && id > 0)
    {
        this->id=id;
        retorno=1;
    }
    return retorno;
}


int getId(ePais* this,int* id)
{
    int retorno=0;
    if( this != NULL && id != NULL)
    {
        *id = this->id;
        retorno=1;
    }
    return retorno;
}

//GETTER Y SETTER NOMBRE
int setNombre(ePais* this, char* nombre)
{
    int retorno=0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno=1;
    }
    return retorno;
}

int getNombre(ePais* this, char* nombre)
{
    int retorno=0;
    if( this != NULL && nombre!=NULL )
    {
        strcpy(nombre, this->nombre);
        retorno=1;
    }
    return retorno;
}

//GETTER Y SETTER VACUNADOS 1 DOSIS
int setVac1dosis(ePais* this, int vac1dosis)
{
    int retorno = 0;
    if(this != NULL && vac1dosis >=0 )
    {
        this->vac1dosis=vac1dosis;
        retorno=1;
    }
    return retorno;
}

int getVac1dosis(ePais* this, int* vac1dosis)
{
    int retorno=0;
    if(this != NULL)
    {
        *vac1dosis = this->vac1dosis;
        retorno=1;
    }
    return retorno;
}

//GETTER Y SETTER VACUNADOS 2 DOSIS
int setVac2dosis(ePais* this, int vac2dosis)
{
    int retorno=0;
    if(this != NULL && vac2dosis >= 0)
    {
        this->vac2dosis = vac2dosis;
        retorno=1;
    }
    return retorno;
}

int getVac2dosis(ePais* this, int* vac2dosis)
{
    int retorno=0;
    if( this != NULL && vac2dosis != NULL)
    {
        *vac2dosis = this->vac2dosis;
        retorno=1;
    }
    return retorno;
}

//GETTER Y SETTER SIN VACUNAR
int setSinVacunar(ePais* this, int sinVacunar)
{
    int retorno=0;
    if(this != NULL && sinVacunar >= 0)
    {
        this->sinVacunar = sinVacunar;
        retorno=1;
    }
    return retorno;
}

int getSinVacunar(ePais* this, int* sinVacunar)
{
    int retorno=0;
    if( this != NULL && sinVacunar != NULL)
    {
        *sinVacunar = this->sinVacunar;
        retorno=1;
    }
    return retorno;
}

void* setValoresRandom(void* a)
{
    ePais* pais = NULL;
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;

    pais = (ePais*) a;

    if( pais != NULL)
    {
    vac1dosis = rand()%(100-0+1)+0; //entre 0 y 100
    vac2dosis = rand()%((100-vac1dosis)-0+1)+0; //entre 0 y el resto
    sinVacunar = 100-(vac1dosis+vac2dosis); //100 menos la suma de los dos anteriores

    pais->vac1dosis = vac1dosis;
    pais->vac2dosis = vac2dosis;
    pais->sinVacunar = sinVacunar;

    }
    return pais;
}

int filterPaisesExitosos(void* p)
{
    int retorno = 0;
    int vac2dosis;
    ePais* pais = NULL;
    pais = (ePais*) p;

    if(pais != NULL){
        getVac2dosis(pais,&vac2dosis);
        if(vac2dosis > 30)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int filterPaisesEnElHorno(void* p)
{
    int retorno = 0;
    int sinVacunar;
    int vac1dosis;
    int vac2dosis;
    int vacunados;
    ePais* pais = (ePais*) p;

    if(pais != NULL){
        getSinVacunar(pais,&sinVacunar);
        getVac1dosis(pais,&vac1dosis);
        getVac2dosis(pais,&vac2dosis);
        vacunados = vac1dosis + vac2dosis;

        if(vacunados < sinVacunar)
        {
            retorno = 1;
        }
    }
    return retorno;
}

//COMPARISON
int compareVac1dosis(void* a,void* b)
{
    int retorno = 0;
    ePais * p1 = (ePais*) a;
    ePais * p2 = (ePais*) b;

    if( p1 != NULL && p2 != NULL)
    {
        if(p1->vac1dosis > p2->vac1dosis)
        {
            retorno = 1;
        }
        else if(p1->vac1dosis < p2->vac1dosis)
        {
            retorno = -1;
        }
    }
    return retorno;
}

int compareSinVacunar(void* a,void* b)
{
    int retorno = 0;
    ePais * p1 = (ePais*) a;
    ePais * p2 = (ePais*) b;

    if( p1 != NULL && p2 != NULL)
    {
        if(p1->sinVacunar > p2->sinVacunar)
        {
            retorno = 1;
        }
        else if(p1->sinVacunar < p2->sinVacunar)
        {
            retorno = -1;
        }
    }
    return retorno;
}
