
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "Elibro.h"

int eLibro_setId(eLibro* this,int id){

	int retorno = -1;
	if(this != NULL){

		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int eLibro_setTitulo(eLibro* this,char* Titulo){

	int retorno = -1;
	if(this != NULL){

		strcpy(this->titulo, Titulo);
		retorno = 0;
	}

	return retorno;
}
int eLibro_setAutor(eLibro* this,char* Autor){
	int retorno = -1;
		if(this != NULL){

			strcpy(this->autor, Autor);
			retorno = 0;
		}

		return retorno;

}

int eLibro_setPrecio(eLibro* this,float precio){
	int retorno = -1;
	if(this != NULL){

		this->precio = precio;
		retorno = 0;
	}

	return retorno;


}

int eLibro_setIdEditorial(eLibro* this,int idEditorial){

	int retorno = -1;
	if(this != NULL){

		this->idEditorial = idEditorial;
		retorno = 0;
	}

	return retorno;

}





int eLibro_getId(eLibro* this,int* id){
	int retorno = -1;
		if(this != NULL && id != NULL){

			*id = this->id;
			retorno = 0;
		}

		return retorno;

}


int eLibro_getTitulo(eLibro* this,char* Titulo){
	int retorno = -1;
		if(this != NULL && Titulo != NULL){

			strcpy( Titulo, this->titulo);
			retorno = 0;
		}

		return retorno;

}




int eLibro_getAutor(eLibro* this,char* Autor){
	int retorno = -1;
		if(this != NULL && Autor != NULL){

			strcpy( Autor, this->autor);

			retorno = 0;
		}

		return retorno;

}




int eLibro_getPrecio(eLibro* this,float* precio){
	int retorno = -1;
		if(this != NULL && precio != NULL){

			*precio = this->precio;
			retorno = 0;
		}

		return retorno;

}

int eLibro_getIdEditorial(eLibro* this,int* Editorial){
	int retorno = -1;
			if(this != NULL && Editorial != NULL){

				*Editorial = this->idEditorial;
				retorno = 0;
			}

			return retorno;

}




eLibro* eLibro_new()
{
		eLibro* newLibro;
		newLibro = (eLibro*)malloc(sizeof(eLibro));

	    if(newLibro != NULL)
	    {
	    	newLibro->id = 0;
	        strcpy(newLibro->titulo, " ");
	        strcpy(newLibro->autor, " ");
	        newLibro->precio = 0;
	        newLibro->idEditorial = 0;
	    }

	    return newLibro;
	}




eLibro* eLibro_newParametros(char* idStr, char* tituloStr, char* autorStr,char* precioStr, char* idEditorialStr)
{
    eLibro* newLibro;
    newLibro = eLibro_new();

    int id;

    int precio;
	int idEditorial;

    if(idStr != NULL && tituloStr != NULL && autorStr != NULL && idEditorialStr != NULL && precioStr != NULL &&  newLibro != NULL  ){

		id= atoi(idStr);
		precio = atoi(precioStr);
		idEditorial = atoi(idEditorialStr);


    	eLibro_setId(newLibro, id);
    	eLibro_setTitulo(newLibro,tituloStr);
    	eLibro_setAutor(newLibro,autorStr);
    	eLibro_setPrecio(newLibro,precio);
    	eLibro_setIdEditorial(newLibro,idEditorial);

    }

    return newLibro;
}



int eLibro_CompareByTitulo(void* e1,void* e2){
	int retorno;

	eLibro* PrimerLibro;
	eLibro* SegundoLibro;

	PrimerLibro = (eLibro*) e1;
	SegundoLibro = (eLibro*) e2;

	retorno = strcmp(PrimerLibro->titulo,  SegundoLibro->titulo);

	return retorno;
}

int eLibro_CompareById(void* e1,void* e2){
	int retorno;

	eLibro* PrimerLibro;
	eLibro* SegundoLibro;

	PrimerLibro = (eLibro*) e1;
	SegundoLibro = (eLibro*) e2;

	if(PrimerLibro->id>SegundoLibro->id){
		retorno = 0;
	}

	return retorno;
}

int eLibro_CompareByAutor(void* e1,void* e2){

	int retorno;

	eLibro* PrimerLibro;
	eLibro* SegundoLibro;

	PrimerLibro = (eLibro*) e1;
	SegundoLibro = (eLibro*) e2;

	retorno = strcmp(PrimerLibro->autor, SegundoLibro->autor);

	return retorno;
}
int employee_CompareByPrecio(void* e1,void* e2){
	int retorno;

	eLibro* PrimerLibro;
	eLibro* SegundoLibro;

	PrimerLibro = (eLibro*) e1;
	SegundoLibro = (eLibro*) e2;


	if(PrimerLibro->precio>SegundoLibro->precio){
		retorno = 0;
	}

	return retorno;
}


int employee_CompareByEditorial(void* e1,void* e2){

	int retorno;

	eLibro* PrimerLibro;
	eLibro* SegundoLibro;

	PrimerLibro = (eLibro*) e1;
	SegundoLibro = (eLibro*) e2;


	if(PrimerLibro->idEditorial>SegundoLibro->idEditorial){
		retorno = 0;
	}


	return retorno;
}



