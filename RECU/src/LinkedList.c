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
	LinkedList* this;//= NULL;
	this = (LinkedList*)malloc(sizeof(LinkedList));
	if(this != NULL){
		this->pFirstNode = NULL;
		this->size = 0;
	}
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
    	returnAux = this->size; //depende de que todas las demás funciones seteen bien este parámetro. Podría hacerse con un contador.
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
	Node* retorno = NULL;
	if(this != NULL && nodeIndex>=0 && ll_len(this)>nodeIndex){// el index arranca a contar en cero, por eso el último node está en len-1
		retorno = this->pFirstNode;
		for(int i = 0; i<nodeIndex;i++){
				retorno = retorno->pNextNode;
		}
	}
	return retorno;
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
	int retorno = -1;

	Node* newNode = NULL;
	Node* auxNode = NULL;

	if(this != NULL && nodeIndex>=0 && nodeIndex <= ll_len(this)){
		newNode = (Node*)malloc(sizeof(Node));
		if(newNode != NULL){
			newNode->pElement = pElement; //Lo entregué con esta linea arriba del if.
			if(nodeIndex==0){ //Caso agrego en posicion 0: el nuevo nodo debe apuntar al primero de la linked. Y convertirse en el nuevo primero.
				newNode->pNextNode = this->pFirstNode;
				this->pFirstNode = newNode;
			}else{ //Demás casos. Me traigo el nodo anterior al index de inserción. El "pNextNode" de mi nodo nuevo va a apuntar adonde apuntaba el anterior (el ahora siguiente al nuevo)
				auxNode = getNode(this,nodeIndex-1); //Luego el anterior, apuntará al nodo nuevo.
				if(auxNode!=NULL){
					newNode->pNextNode = auxNode->pNextNode; //Ej, new en posicion 5. Tomo el 4, le saco su nextNode y se lo pongo a mi nuevo.
					auxNode->pNextNode = newNode; //Y luego el 4 lo apunto a mi nuevo nodo (que ahora es el nuevo 5)
				}
			}
			this->size++;
			retorno = 0;
		}
	}
	return retorno;
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

    if(this!=NULL){
    	returnAux = addNode(this,ll_len(this),pElement); //ejecuta un addNode en la última posición de la linked.
   		}
    return returnAux;
}

/** \brief Permite ...
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
    Node* auxNode = NULL;

    if(this != NULL && index >=0 && index <ll_len(this)){
    	auxNode = getNode(this, index); //Simplemente llamar a la función getNode previa, pero devolver el puntero al ELEMENTO al que apunta.
    	if(auxNode != NULL){
    		returnAux = auxNode->pElement;
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
    int returnAux = -1;
    Node* auxNode = NULL;

    if(this != NULL && index >=0){
    	auxNode = getNode(this, index);
    	if(auxNode != NULL){
    		auxNode->pElement = pElement; //Usar getNode, e igualar el elemento previo con el nuevo provisto por parámetro
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
	int retorno = -1;

	Node* auxNodePrev = NULL;
	Node* auxNode = NULL; //el nodo a remover
	Node* auxNodeNext = NULL;

	if(this != NULL && index>=0 && index < ll_len(this)){ //de nuevo, recordar que cuenta desde index=0
		auxNode = getNode(this, index); //obtengo el nodo a borrar
		if(auxNode != NULL){
			if(index==0){//CASO PRIMERA POSICION
				auxNodeNext = auxNode->pNextNode; //NodeNext ahora apunta a donde solía apuntar el nodo a borrar
				this->pFirstNode = auxNodeNext; //Convierto a NodeNext en el primer nodo de la LL a Next
			}else{ //CASO RESTO
				auxNodePrev = getNode(this,index-1); //Tomo el nodo anterior al que se quiere borrar
				if(auxNodePrev!=NULL){
					auxNodePrev->pNextNode = auxNode->pNextNode;//Lo apunto adonde solía apuntar el nodo a borrar
										//Se perdió la referencia al nodo a borrar. Fin.
				}
			}
			free(auxNode);
			retorno = 0;
			this->size--;
		}
	}
	return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
/*
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
    	this->pFirstNode = NULL; //Y con esta linea, se perdieron todas las direcciones a nodos que pudieran haber. El primero es el último.
    	this->size = 0;
    	returnAux = 0;
    }
    return returnAux;
}
*/

int ll_clear(LinkedList* this)
{
	int i;
    int returnAux = -1;
    if(this!=NULL){
    	for(i=(ll_len(this)-1);i>=0;i--){
    		ll_remove(this,i);
    	}
    	// Remove desde el último al primero, remove ya reduce el size.
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
    if(this!=NULL){
    	free(this); //Se libera el espacio de memoria al que apunta el puntero a la LinkedList provisto por parámetro.
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
    int i;
    if(this!=NULL){
    	Node* auxNode = this->pFirstNode;
    	for(i=0;i<ll_len(this);i++){ //Recorre la LL y solo corta cuando encuentra coincidencia con el elemento provisto y el apuntado. Retorna posición.
    		if(auxNode->pElement == pElement){
    			returnAux = i;
    			break;
    		}else{
    			auxNode = auxNode->pNextNode;
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
    if(this!=NULL && index>=0 && index <= ll_len(this)){
    	if(!addNode(this, index, pElement)){
    		returnAux = 0;
    	}
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
    if(this!=NULL && index>=0 && index<=ll_len(this)){
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
    }
    return returnAux;
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
    int i;
    if(this!=NULL){
    	returnAux = 0;
    	Node* auxNode = this->pFirstNode;
    	for(i=0;i<ll_len(this);i++){
    		if(auxNode->pElement == pElement){
    			returnAux = 1;
    			break;
    		}else{
    			auxNode = auxNode->pNextNode;
    		}
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
    if(this!=NULL && this2!=NULL){
    	returnAux = 1;
    	void* auxElement = NULL;
    	for(int i = 0;i<ll_len(this2);i++){
    		auxElement = ll_get(this2, i);
    		if(!ll_contains(this, auxElement)){ //significa que contains dio 0 (no contiene) en todos los casos
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
    LinkedList* cloneArray = NULL;
    if(this!=NULL && from<to && from>=0 && to<=ll_len(this)){
    	cloneArray = ll_newLinkedList();
    	void* auxElement = NULL;
    	if(cloneArray!=NULL){
    		for(int i = from; i<to ; i++){
    			auxElement = ll_get(this, i);
    			if(!ll_add(cloneArray, auxElement)){
    				continue;
    			}
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
    if(this!=NULL){
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
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int retornoAux = -1;
	void *auxElemento1 = NULL;
	void *auxElemento2 = NULL;

	if (this != NULL && (order == 1 || order == 0) && pFunc != NULL) {
		for (int i = 0; i < ll_len(this) - 1; i++) {
			for (int j = i + 1; j < ll_len(this); j++) {
				auxElemento1 = ll_get(this, i);
				auxElemento2 = ll_get(this, j);
				if (order == 1 && pFunc(auxElemento1, auxElemento2) > 0) { //Caso contrario, no intercambiar
					ll_set(this, i, auxElemento2);
					ll_set(this, j, auxElemento1);
				}
				if (order == 0 && pFunc(auxElemento1, auxElemento2) < 0) { //Caso contrario, no intercambiar
					ll_set(this, i, auxElemento2);
					ll_set(this, j, auxElemento1);
				}
			}
			retornoAux = 0;
		}
	}
	return retornoAux;
}

