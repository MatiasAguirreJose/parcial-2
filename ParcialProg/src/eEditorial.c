
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "eEditorial.h"




int eEditorial_setIdEditorial(eEditorial* this,int idEditorial){


	int retorno = -1;
	if(this != NULL){

		this->idEditorial = idEditorial;
		retorno = 0;
	}

	return retorno;
}

int eEditorial_setNombre(eEditorial* this,char* Nombre){

	int retorno = -1;
	if(this != NULL){

		strcpy(this->Nombre, Nombre);
		retorno = 0;
	}

	return retorno;
}




int eEditorial_getIdEditorial(eEditorial* this,int* Editorial){
	int retorno = -1;
			if(this != NULL && Editorial != NULL){

				*Editorial = this->idEditorial;
				retorno = 0;
			}

			return retorno;

}

int eEditorial_getNombre(eEditorial* this,char* Nombre){

	int retorno = -1;
			if(this != NULL && Nombre != NULL){

				strcpy( Nombre, this->Nombre);

				retorno = 0;
			}

			return retorno;

}



eEditorial* eEditorial_new()
{
		eEditorial* new;
	    new = (eEditorial*)malloc(sizeof(eEditorial));

	    if(new != NULL)
	    {

	        new->idEditorial = 0;
	        strcpy(new->Nombre, " ");


	    }

	    return new;
	}




eEditorial* eEditorial_newParametros(char* idEditorialStr, char* NombreStr)
{
	eEditorial* newEditorial;
	newEditorial = eEditorial_new();

    int idEditorial;



    if(idEditorialStr != NULL && NombreStr != NULL && newEditorial != NULL ){
    	idEditorial = atoi(idEditorialStr);



    	eEditorial_setIdEditorial(newEditorial,idEditorial);
    	eEditorial_setNombre(newEditorial, NombreStr);


    }

    return newEditorial;
}





