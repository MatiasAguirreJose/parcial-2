#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Elibro.h"
#include "eEditorial.h"
#include "inputs.h"
#include "Controller.h"
#include "Parser.h"


void menu (void){
				 puts("1- Cargar los datos de los libros  \n");
		    	 puts("2- Cargar los datos de las editoriales \n");
		    	 puts("3- Ordenar los datos\n");
		    	 puts("4- Mostrar los datos \n");
		    	 puts("5- Mostrar los libros de la editorial MINOTAURO\n");
		    	 puts("6- Salir\n");
		         puts("----------------------------------------------------------------------------------");

}




int controllerElibro_loadFromText(char* path , LinkedList* pArrayListLibro)
{
    int retorno = -1;
    FILE* pArchivo;
       if(path!= NULL && pArrayListLibro != NULL){

    	pArchivo = fopen(path,"r");

       	if(pArchivo!=NULL && parser_ElibroFromText(pArchivo, pArrayListLibro) == 0){
       		retorno = 0;
       	}
       fclose(pArchivo);


       }
       return retorno;

}

int controllerEditorial_loadFromText(char* path , LinkedList* pArrayListEditorial)
{
    int retorno = -1;
    FILE* pArchivo;
       if(path!= NULL && pArrayListEditorial != NULL){

    	pArchivo = fopen(path,"r");

       	if(pArchivo!=NULL && parser_EditorialFromText(pArchivo ,  pArrayListEditorial) == 0){
       		retorno = 0;
       	}
       fclose(pArchivo);
       }

       return retorno;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_ListElibro(LinkedList* pArrayListLibros,LinkedList* pArrayListEditorial )
{
	eLibro* libros;


	int len;

	int retorno = -1;
	char titulo	[128];
	char autor [128];
	float precio;
	int ideditorial;
	char nombre [128];
	int id;

	len = ll_len(pArrayListLibros);
	if(pArrayListLibros != NULL && len > 0){

	retorno = 0;

	for(int i = 0; i<len ; i++){

		libros = ll_get(pArrayListLibros , i);
		eLibro_getId(libros,&id);
		eLibro_getTitulo(libros, titulo);
		eLibro_getAutor(libros, autor);
		eLibro_getPrecio(libros,&precio);
		eLibro_getIdEditorial(libros, &ideditorial);



		MostrarEditorial(pArrayListEditorial , ideditorial, nombre);


		printf("-----------------------\n %d,    %s,      %s,     %f,      %s   \n",id,titulo,autor,precio,nombre);



	}
	}

    return retorno;
}

int MostrarEditorial(LinkedList* ListaEditorial, int idEditorial, char* nombre){

	eEditorial* editorial;
	int id;
	int retorno = -1;
	if(ListaEditorial != NULL  && nombre != NULL){

		for(int i=0; i<ll_len(ListaEditorial); i++){
			editorial = ll_get(ListaEditorial,i);
			eEditorial_getIdEditorial(editorial,&id);

			if(idEditorial == id){

				eEditorial_getNombre(editorial,nombre);
				retorno = 0;


			}
		}
	}

return retorno;


}





int controller_sortElibro(LinkedList* pArrayListLibro ,LinkedList* pArrayListEditorial )
{

	int option = -1;
	eLibro* aux;



	char titulo	[128];
	char autor [128];
	char nombre[128];
	float precio;
	int ideditorial;

	int id;
	int len = ll_len(pArrayListLibro);

	if( pArrayListLibro != NULL && len>0){


		option = 0;

		puts("!!¡¡Ordenado por AUTOR!!¡¡");
		puts("Aguarde, Cargando Archivo...");

		for(int i = 0;i<len; i++){
		ll_sort(pArrayListLibro,  eLibro_CompareByAutor, 1);
		aux = (eLibro*) ll_get(pArrayListLibro,i);
		eLibro_getId(aux,&id);
		eLibro_getTitulo(aux, titulo);
		eLibro_getAutor(aux, autor);
		eLibro_getPrecio(aux,&precio);
		eLibro_getIdEditorial(aux, &ideditorial);

		MostrarEditorial(pArrayListEditorial , ideditorial, nombre);

		printf("-----------------------\n %d,    %s, %s,    %f,      %s \n",id,titulo,autor,precio,nombre);

		}

	}



    return option;
}


int buscarPosicion( void* element ){

	eLibro* nuevalista;
	int retorno = -1;

	if(element != NULL){
	   nuevalista = element;

	   	 if( nuevalista != NULL ){

		    if(nuevalista->idEditorial == 4){
			  retorno = 0;



		    }
	   	 }
	}
	return retorno;
}


int buscarContador( void* element ){

	eLibro* nuevalista;
	int retorno = -1;

	if(element != NULL){
	   nuevalista = element;
	   retorno = 0;

	   	 if( nuevalista != NULL ){

		    if(nuevalista->idEditorial == 4){
			  retorno = 1;



		    }
	   	 }
	}
	return retorno;
}
int controller_minotauro(LinkedList* pArrayListLibro, LinkedList* pArrayListEditorial){

	LinkedList* ListaNueva;
	int retorno = -1;
	if(pArrayListLibro != NULL && pArrayListEditorial != NULL){

	  	  ListaNueva = ll_newLinkedList();
	  	  ListaNueva = ll_filter(pArrayListLibro, buscarPosicion);

	  	  	  if(ListaNueva != NULL){
	  	  		  retorno = controller_ListElibro( ListaNueva,pArrayListEditorial);
	  	  	  }

	}
	return retorno;
}

void* buscarPosicionDescuento( void* element ){

	eLibro* nuevalista;




	if(element != NULL){
	   nuevalista = element;

	   	 if( nuevalista != NULL ){

		    if(nuevalista->idEditorial == 1 && nuevalista->precio>300){

		    	nuevalista->precio  = nuevalista->precio - (nuevalista->precio)*20/100;





		    }else{

		   if(nuevalista->idEditorial == 2 && nuevalista->precio<=200){
			   nuevalista->precio  =  nuevalista->precio - (nuevalista->precio)*10/100;

		   	   	 }

		   }
	   	 }
	}
	return nuevalista;
}







int controller_saveAsText(char* path, LinkedList* pArrayListLibro){
        FILE* pArchivo;
        eLibro* aux;

        int retorno = -1;
        int id;
        int i;
        char titulo[128];
        char autor[128];
        float precio;
        int idEditorial;

        if(path != NULL && pArrayListLibro != NULL && ll_isEmpty(pArrayListLibro) == 0){

            pArchivo = fopen(path, "w");

            fprintf(pArchivo,"id,titulo,autor,precio,idEditorial\n");}
            for(i=0; i< ll_len(pArrayListLibro); i++) {
            	aux = ll_get(pArrayListLibro,i);
                if(aux == NULL){
                    break;
                }
                eLibro_getId(aux,&id);
                eLibro_getTitulo(aux, titulo);
                eLibro_getAutor(aux, autor);
                eLibro_getPrecio(aux,&precio);
                eLibro_getIdEditorial(aux, &idEditorial);
                fprintf(pArchivo,"%d,%s,%s,%f,%d\n",id,autor,titulo,precio,idEditorial);
            }

            fclose(pArchivo);
            if(ll_len(pArrayListLibro) == i ){
                retorno = 0;
            }
        return retorno;
}






void menuOpciones (LinkedList* pArrayListLibro, LinkedList* pArrayListEditorial){

	int respuesta;
	char LibroArchivo [128];
	char EditorialArchivo [128];
	do{

	getNumeroConMinyMax(&respuesta, "Ingrese Una Opcion",1,6);

	switch(respuesta){

		case 1:
			GetString("ingrese el nombre del archivo","esta mal",LibroArchivo, 11);
			if(controllerElibro_loadFromText(LibroArchivo, pArrayListLibro)!=0){
				puts("No se pudo cargar");
			};

			break;

		case 2:
			GetString("ingrese el nombre del archivo","esta mal",EditorialArchivo, 128);
			if(controllerEditorial_loadFromText(EditorialArchivo, pArrayListEditorial)!=0){
				puts("No se pudo cargar");
			};

			break;


		case 3:
			if(controller_sortElibro(pArrayListLibro,pArrayListEditorial)!=0){
				puts("No se pudo cargar");
			};

				break;

		case 4:
			if(controller_ListElibro(pArrayListLibro,pArrayListEditorial)!=0){
			puts("No se pudo cargar");
			};

			break;
		case 5:
			if(controller_minotauro(pArrayListLibro,pArrayListEditorial)!=0){
				puts("No se pudo cargar");
			}

			break;





	}
	}while(respuesta != 6);



}




