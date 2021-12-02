
/** \brief menu de opciones
 * \param pList LinkedList* Puntero a libro
 * \param  pList LinkedList* Puntero a editorial
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return  void

 */
void menuOpciones (LinkedList* pArrayListLibro, LinkedList* pArrayListEditorial);
int controller_loadFromText(char* path , LinkedList* pArrayListLibro);
int controller_ListElibro(LinkedList* pArrayListLibros,LinkedList* pArrayListEditorial );
int controller_sortElibro(LinkedList* pArrayListLibro ,LinkedList* pArrayListEditorial );
int controllerEditorial_loadFromText(char* path , LinkedList* pArrayListEditorial);
int controllerElibro_loadFromText(char* path , LinkedList* pArrayListEditorial);
int controller_minotauro(LinkedList* pArrayListLibro, LinkedList* pArrayListEditorial);
int MostrarEditorial(LinkedList* pArrayListEditorial, int idEditorial, char* nombre);
void* buscarPosicionDescuento( void* element );
int controller_saveAsText(char* path, LinkedList* pArrayListLibro);
int controller_minotauroContador(LinkedList* pArrayListLibro);




