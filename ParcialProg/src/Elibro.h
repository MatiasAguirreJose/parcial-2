#ifndef ELIBRO_H_INCLUDED
#define ELIBRO_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char titulo[128];
    char autor[128];
    int precio;
    int idEditorial;

}eLibro;



eLibro* eLibro_new();

eLibro* eLibro_newParametros(char* idStr, char* tituloStr, char* autorStr,char* precioStr, char* idEditorialStr);




int eLibro_setId(eLibro* this,int id);
int eLibro_getId(eLibro* this,int* id);

int eLibro_setTitulo(eLibro* this,char* Titulo);
int eLibro_getTitulo(eLibro* this,char* Titulo);

int eLibro_setAutor(eLibro* this,char* Autor);
int eLibro_getAutor(eLibro* this,char* Autor);

int eLibro_setPrecio(eLibro* this,float precio);
int eLibro_getPrecio(eLibro* this,float* precio);

int eLibro_setIdEditorial(eLibro* this,int idEditorial);
int eLibro_getIdEditorial(eLibro* this,int* Editorial);

int eLibro_CompareByTitulo(void* e1,void* e2);
int eLibro_CompareById(void* e1,void* e2);
int eLibro_CompareByAutor(void* e1,void* e2);
int employee_CompareByPrecio(void* e1,void* e2);
int employee_CompareByEditorial(void* e1,void* e2);



void menu (void);

#endif // employee_H_INCLUDED
