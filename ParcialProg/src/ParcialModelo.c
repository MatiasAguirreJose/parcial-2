/*
 ============================================================================
 Name        : ParcialModelo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Elibro.h"
#include "eEditorial.h"
#include "inputs.h"

int main(void) {
	setbuf(stdout,NULL);
	LinkedList* listaLibros = ll_newLinkedList();
	LinkedList* listaEditorial = ll_newLinkedList();

	menu();
	menuOpciones(listaLibros, listaEditorial);


	return EXIT_SUCCESS;
}
