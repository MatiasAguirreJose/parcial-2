/*
 * eEditorial.h
 *
 *  Created on: 21 nov. 2021
 *      Author: Matias
 */

#ifndef EEDITORIAL_H_
#define EEDITORIAL_H_


#include "LinkedList.h"




typedef struct
{
    int idEditorial;
    char Nombre[128];

}eEditorial;


eEditorial* eEditorial_new();


eEditorial* eEditorial_newParametros(char* idEditorialStr, char* NombreStr);



int employee_setIdEditorial(eEditorial* this,int idEditorial);
int employee_getIdEditorial(eEditorial* this,int* Editorial);
int eEditorial_setIdEditorial(eEditorial* this,int idEditorial);
int eEditorial_getIdEditorial(eEditorial* this,int* Editorial);
int eEditorial_setNombre(eEditorial* this,char* Nombre);
int eEditorial_getNombre(eEditorial* this,char* Nombre);



void menu (void);




#endif /* EEDITORIAL_H_ */
