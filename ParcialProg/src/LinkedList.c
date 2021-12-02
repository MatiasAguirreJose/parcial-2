#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this= (LinkedList*) malloc (sizeof(LinkedList));
    this->size = 0;
    this->pFirstNode = NULL;


    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{

	Node* pNodeAux = NULL;
	int len = ll_len(this);
	if(this != NULL && nodeIndex>=0 && nodeIndex<len){

		pNodeAux = this->pFirstNode;



		for(int i = 0;  i<nodeIndex; i++){

			pNodeAux = pNodeAux->pNextNode;


		}


	}

    return pNodeAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= len ){

    		Node* NewNode =  (Node*)malloc(sizeof(Node));
    	    Node* NodePrew = getNode( this, nodeIndex-1);

			if(NewNode != NULL){
				NewNode->pElement = pElement;
				NewNode->pNextNode = NULL;


				if( NodePrew == NULL ){
					 NewNode->pNextNode  = this->pFirstNode;
					 this->pFirstNode =  NewNode;


				}else{

					  NewNode->pNextNode = NodePrew->pNextNode;
					  NodePrew->pNextNode = NewNode;


				 }
				returnAux = 0;
				this->size++;
			}

    }



    	 return returnAux;
    }




/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if (this != NULL){

    	Node* NewNode=(Node*) malloc(sizeof(Node));
    	if(NewNode != NULL){

    	NewNode->pElement = pElement;
    	NewNode->pNextNode = NULL;

    	Node* PrevNode = getNode(this,ll_len(this)-1);


    	if(PrevNode == NULL){
    		this->pFirstNode = NewNode;

    	}else{

    		PrevNode->pNextNode = NewNode;

    	}


    	}
    	returnAux = 0;
    	 this->size++;


    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* NodeAux;
    if (this != NULL && index>=0 && index< ll_len(this)){
    NodeAux= getNode( this, index);
    if (NodeAux != NULL){

    	returnAux = NodeAux->pElement;
    }





    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux ;
    returnAux =  -1;

    Node* NodeAux;
    if (this != NULL && index>=0 && index< ll_len(this)){
    NodeAux= getNode( this, index);
    if (NodeAux != NULL){

    	NodeAux->pElement = pElement ;
    	returnAux = 0;
    }





    }

    return returnAux;

}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this)){
    	    Node* NodeAux = getNode( this, index);

     if (NodeAux != NULL ){
    	   Node* NodePrew = getNode( this, index-1);
    	 if (NodePrew == NULL){


    			 this->pFirstNode = NodeAux->pNextNode;

    		 }
    		 else{

    			 NodePrew->pNextNode = NodeAux->pNextNode;

    			}

    	 free(NodeAux);

    	 this->size --;
    	 returnAux = 0;

 }

     }





    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{

    int returnAux = -1;
    if(this != NULL ){
    Node* NodeAux;
    for (int i = 0; i<ll_len(this); i++ ){
    	NodeAux = getNode(this, i);
    	free(NodeAux);

    	 this->size --;
    }

    returnAux = 0;

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){

    ll_clear( this);
    free(this);
    returnAux = 0;

    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if (this != NULL){

    	for(int i = 0 ; i< ll_len(this); i++){
    		if( pElement == ll_get(this,i)){

    			 returnAux = i;
    		}


    	}


    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){



    	if(ll_len(this)==0){
    		returnAux = 1;

    	}else{


    		returnAux = 0;
    	}




    }


    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
if(this != NULL && index>=0 && index<=ll_len(this)){
    addNode(this, index,pElement);
    returnAux = 0;
}
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{

    void* returnAux = NULL;
    if(this != NULL && index>=0 && index<=ll_len(this)){

    	returnAux =  ll_get( this, index);
    	ll_remove(this, index);


    }
    return  returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL ){

    	if(ll_indexOf(this,  pElement) != -1 ){
    		returnAux = 1;
    	}else{
    		returnAux = 0;
    	}



    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    if(this != NULL && this2 != NULL ){


    		returnAux = 1;
    		Node* NodeAux2;
    		Node* NodeAux1;

    		for(int i = 0; i< ll_len(this2); i++){
    			NodeAux2 = ll_get(this2, i);
    			NodeAux1 = ll_get(this, i);

    			if(NodeAux1->pElement != NodeAux2->pElement){

    				 returnAux = 0;
    				 break;

    			}



    	}


    	}

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL ;

    if(this != NULL && from>=0 && from <= ll_len(this)  && to <= ll_len(this) ){

    	cloneArray  = ll_newLinkedList();

    	if (cloneArray != NULL){
    		void* eLement = NULL;

    		for(int i = from; i<to; i++){
    			eLement	= ll_get( this,i);
    			ll_add( cloneArray,eLement);

    		}

    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL){


    	cloneArray = ll_subList(this,0,ll_len(this));



    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{

	void* pSwaper1;
	void* pSwaper2;

	int Flag = 0;
	int condicion;
    int returnAux =-1;
    int len;
    len = ll_len(this);

    if(this!= NULL && (order == 1 || order == 0) && len > 0 && pFunc != NULL){

    	do{

    	Flag = 0;
    	for(int i = 0; i<len-1;i++){


			pSwaper1 = ll_get( this, i);
			pSwaper2 = ll_get( this, i+1);

			condicion = pFunc(pSwaper1 ,pSwaper2);

			if((order == 0 && condicion < 0) || (order == 1 && condicion > 0)){


				ll_set(this,i,pSwaper2);
				ll_set(this,i+1,pSwaper1);
				Flag = 1;

			}

    	}




    	len--;
    	}while(Flag);

     returnAux = 0;
    }

    return returnAux;

}
/** \brief filtra los elementos de la editorial
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param void element  Indica la posicion del elemento
 * \return  Retorna la nuevalsita
  */
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element)){
	  void* elementNew;
	  LinkedList* NuevaLista;
	  NuevaLista = ll_newLinkedList();
	  int len = ll_len(this);
	  int i;



	   if(NuevaLista != NULL  && this != NULL){

	       for(i = 0; i< len; i++){

	    	   elementNew = ll_get(this, i);

	            if(elementNew !=NULL && fn(elementNew) != -1 ){

	            	ll_add(NuevaLista, elementNew);

	          }
	       }
	  }


	    return NuevaLista;

}


int ll_count(LinkedList* this, int (*fn)(void* element)){

	  void* elementNew;
	  int contador = 0;


	  int len = ll_len(this);
	  int i;



	   if(this != NULL){

	       for(i = 0; i< len; i++){

	    	   elementNew = ll_get(this, i);

	            if(elementNew !=NULL  ){

	            	contador+=fn(elementNew);




	          }
	       }

	  }


	    return contador;

}



LinkedList* ll_map(LinkedList* this, void* (*fn)(void* element)){

	void* elementNew;

	LinkedList* NuevaLista;
	NuevaLista = ll_newLinkedList();

	 if(this != NULL){

		       for(int i = 0; i< ll_len(this); i++){

		    	   elementNew = ll_get(this, i);

		            if(elementNew !=NULL ){




		            	ll_add(NuevaLista, fn(elementNew));



		          }


		       }
		  }

	 return NuevaLista;
}

void* ll_declareMax(LinkedList* this, int (*pFunc) (void* ,void*)) //devuelve un elemento
{
	void* pElement1 = NULL;
	void* pElement2 = NULL;
	void* max = NULL;

	if(this != NULL && pFunc != NULL)
	{
		for(int i = 0; i < ll_len(this); i++)
		{
			for(int j = i + 1; j < ll_len(this); j++)
			{
				pElement1 = ll_get(this, i);
				pElement2 = ll_get(this, j);

				if(pFunc(pElement1, pElement2) > 0)
				{
					max = pElement1;
				}
				else if(pFunc(pElement1, pElement2) < 0)
				{
					max = pElement2;
				}
			}
		}//for
	}//if null
	return max;
}
