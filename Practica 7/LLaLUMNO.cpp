#include <stdlib.h>
#include <stdio.h>

enum {FALSE = 0, TRUE = !FALSE};
typedef unsigned int Bool;

//Estructura para los nodos
struct Node_Type
{
	int semestre;
	struct Node_Type* next;
};
typedef struct Node_Type Node;

//Estructura para la lista
struct LinkedList_Type
{
	Node* first;
	Node* last;
};
typedef struct LinkedList_Type LinkedList;

//Operacion para pedir memoria para objeto nodo
static Node* newNode(int val)
{
	Node* n = (Node *) malloc (sizeof (Node));
	
	if(n){
		n->semestre = val;
		n->next = NULL;	
	}
	return n;
}

//Operacion para remover un nodo
static void deleteNode (Node *n)
{
	if(n){
		free(n);
	}
}



//Operacion para pedir memoria para objeto lista
LinkedList* LinkedList_Create()
{
	LinkedList* n = (LinkedList *) malloc (sizeof(LinkedList));
	if(n){
		n->first = NULL;
		n->last = NULL;
	}
	return n;
}

//Operacion para insertar un nuevo valor a la lista
Bool LinkedList_Insert(LinkedList* this, int val)
{
	//Se crear el nuevo nodo
	Node* n = newNode(val);
	
	//Si hubo problema al reservar memoria devuelve FALSE
	if(!n) { return FALSE; }

	//La lista NO esta vacia
	if(this->last != NULL){
		this->last->next = n;

		//n->next=NULL;
		//NO es necesario next ya viene como NULL

		this->last = n;
	}

	// si la lista esta vacia
	else{
		this->first = this->last = n;
	}

	return TRUE;
}


Bool LinkedList_Remove (LinkedList* this, int *val)
{
 	//Esta vacia si
	if (this->first ==  NULL) {return FALSE;}
	
	//SI la lista tiene un solo elemento
	if (this->first == this->last){
		//copiamos la porcion de datos
		*val = this->first->info;

		//Borramos el nodo
		deleteNode (this->first);

		//Hacemos que first y last no queden "volando"
		this->first = this->last = NULL;
	}

	//Si la lista tiene dos o mas nodos
	else {
		//Copiamos la porcio de datos
		*val = this->first->info;

		//Copiamos la direccion del nodo a la derecha
		Node* tmp = this->first->next;

		//Borramos el nodo al que apunta first
		deleteNode(this->first);

		//First apunta al que ahora es el primer nodo
		this->first = tmp;
	}

	return TRUE;
}

//Destruye los nodos uno por uno
void  LinkedList_Destroy (LinkedList* this)
{
	//Destruye nodos de izquierda derecha
	while(this->first != NULL){
		Node* tmp = this->first->next;
		deleteNode(this->first);
		this->first = tmp;
	}	
	free(this);
}

//Encuentra un valor en los nodos 
Bool LinkedList_FindIf (LinkedList* this, int val)
{
	//No podemos perder a first !!
	//IT = Iterador
	Node* it = this->first;
		
	//Mientras it no haya recorrido toda la lista	
	while(it != NULL){
		if(it->info == val) {return TRUE;}

		//Nos movemos al siguiente nodo
		it = it->next;
	}
return FALSE;
	
}


Bool LinkedList_Empty(LinkedList* this)
{
		//Si esta vacía devuelve TRUE
		if (this->first ==  NULL) {return TRUE;}	
		else
		{
			return FALSE;
		}
}


Node* LinkedList_Search (LinkedList* this, int val)
{
	//No podemos perder a first !!
	//IT = Iterador
	Node* it = this->first;
		
	//Mientras it no haya recorrido toda la lista	
	while(it != NULL){
		if(it->info == val) 
		{
		return it->info;
		}

		//Nos movemos al siguiente nodo
		it = it->next;
	}
return NULL;
		
}

/*-----------------------------------------------------------------------------
 *                           MenÃº
 *-----------------------------------------------------------------------------*/

int menu()
{
	int opcion = 0;

	do {
		printf (	"\n"
					"1 -- Insert\n"
					"2 -- Remove\n"
					"3 -- FindIf\n"	
					"4 -- Delete a Node\n"	
					"5 -- Is Empty\n"
					"6 -- Search\n"							
					"0 -- Finish\n"
					"Su opcion> ");

		scanf ("%d", &opcion);
	} while (opcion < 0 || opcion > 6);

	printf ("\n");
	return opcion;
}

/*-----------------------------------------------------------------------------
 *                           Driver program
 *-----------------------------------------------------------------------------*/
int main()
{
	int num, val;
	
	//Crea ua nueva lista
	LinkedList* miLista = LinkedList_Create();
	
//	if(LinkedList_Insert(miLista, 5) == FALSE){
//		printf("Error insertando\n");	
//	}

while (1)
	{
		int opcion = menu ();
		int val;

		switch (opcion) {
			case 0:
				printf ("Terminando ...\n");
				return 0;

			case 1:
				printf ("Ingresa el valor:\n");
				scanf("%d", &val);
				
				if(LinkedList_Insert(miLista, val) == FALSE){
						printf("Error insertando\n");	
					}
				
				break;

		//	case 2:
		//		printf ("Retirando el valor:\n");
		//		printf ("El valor es: %d",LinkedList_Remove(miLista, val));
		//		break;

			case 3:
				printf("Ingresa el numero que deseas encontrar: \n");
				scanf("%d", &num);
					if(LinkedList_FindIf(miLista, num) == TRUE){
						printf("\nEl numero ya se encuentra en la lista\n");
					}
					else {
					printf("\nEl numero aun no se encuentra en la lista\n");
					}
				break;
				
				case 4:
					printf("\n\tDestruyendo el ultimo nodo\n");
					LinkedList_Remove(miLista, val);	
				break;
				
				case 5:
					if(LinkedList_Empty(miLista) == TRUE){
						printf("\n\tLa lista esta vacia\n");
					}
					else{
						printf("\n\tLa lista contiene elementos\n");
					}
				break;
				
			//	case 6:
			//		printf("Ingresa el numero que deseas encontrar: \n");
			//		scanf("%d", &num);
			//		Node* puntero;
			//	   puntero = LinkedListed_Search(miLista, val);
			//	break;
				
				
			default:
				printf ("Operacion no valida!\n");
				break;
		}
	}


	LinkedList_Destroy (miLista);

	return 0;
}



