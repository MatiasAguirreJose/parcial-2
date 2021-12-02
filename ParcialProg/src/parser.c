#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "LinkedList.h"
#include "Elibro.h"
#include "eEditorial.h"
#include "Parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ElibroFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int retorno = -1;

	eLibro* libro;

		char id[128];
		char titulo[128];
		char autor[128];
		char precio[128];
		char idEditorial[128];


		if(pFile != NULL &&  pArrayListEmployee!= NULL){

				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,], %[^\n]\n", id, titulo, autor, precio, idEditorial);



			while(!feof(pFile)){

				fscanf(pFile, "%[^,], %[^,], %[^,],%[^,], %[^\n]\n", id, titulo, autor, precio, idEditorial);
				printf("%s - %s - %s - %s - %s\n", id, titulo, autor, precio, idEditorial);
				libro = eLibro_newParametros(id, titulo, autor, precio, idEditorial);

				if(libro != NULL){
					if(ll_add(pArrayListEmployee, libro) == -1){
						puts("Error");

					}else{
						retorno = 0;
					}
				}
			}
		}
		return retorno;
}

int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int retorno = -1;

		eEditorial* editorial;

		char id[128];
		char nombre[128];



		if(pFile != NULL &&  pArrayListEmployee!= NULL){

				fscanf(pFile, "%[^,], %[^\n]\n", id,nombre);



			while(!feof(pFile)){

				fscanf(pFile, "%[^,],  %[^\n]\n", id,  nombre);
				printf("%s - %s \n", id, nombre);
				editorial = eEditorial_newParametros(id, nombre);

				if(editorial != NULL){
					if(ll_add(pArrayListEmployee, editorial) == -1){
						puts("Error");

					}else{
						retorno = 0;
					}
				}
			}
		}
		return retorno;
}





