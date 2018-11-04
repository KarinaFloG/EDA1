#include<assert.h>

#include<stdio.h>

#include<stdlib.h>

#define MAX_TAM 3

#include<string.h>

typedef enum { FALSE = 0, TRUE = !FALSE } Bool;

struct ListaDoble_Type
{
 	int * lista; 
 	int front;
 	int rear;
 	int it;
 	int tmp;
 	int max; 
 	Bool empty;
}; typedef struct ListaDoble_Type LD;

//**------------------------------------------------------------------------------**//
LD * LD_Ctor (int max, int min) 
{
	int Max = max-min;
	LD * newLD = (LD *) malloc (sizeof (LD)); 
	// crea a un nuevo objeto Stack en el heap
 
	//assert (newStack);
 
	newLD->lista = (int *) malloc (Max * sizeof (int)); 
	// crea a un nuevo contenedor (el arreglo) de double's en el heap
 
	assert (newLD->lista);
 
	newLD->front = 0;
	newLD->rear=0;
	newLD->it=0;
	newLD->tmp=0;
	newLD->max = Max;
	newLD->empty = FALSE; 
    
 	return newLD;
}

//**------------------------------------------------------------------------------**//
void LD_Dtor (LD * this) 
{
  	assert (this);
  
  	free (this->lista);
  	 // devuelve la memoria del arreglo
   
 	 free (this);
  	 // devuelve la memoria del objeto
}
//**------------------------------------------------------------------------------**//
Conjunto * Conjunto_Ctor (int max)
{
	Conjunto * newConjunto=(Conjunto *) malloc (sizeof(Conjunto));
	//Reserva memoria para la estructura conjunto
	
	//Reserva memoria para la lista
	
	newConjunto->ap1=0;
	newConjunto->ap2=0;
}
//**------------------------------------------------------------------------------**//
void Conjunto_Dtor(Conjunto * this)
{
	assert(this);
	
	//free(this->lista->lista); //Lista doble 
	//free(this->lista); //Estruc lista
	free(this); // Estruc Conjunto
}

//**------------------------------------------------------------------------------**//
Bool LD_Pertenece (int MAX, int MIN, int val)
{
	if(val>MAX ||val<MIN)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}
//**------------------------------------------------------------------------------**//
//**-------------------------------------------------------------------------------------**//
//Indica si ya se encuentra un elemento en la lista
Bool LD_FindIf (LD* this, int val)
{
	//No se debe perder first   (it = iterador)
	this->it = this->front;

	while (this -> it <= this->rear)
	{
		if (this -> lista[this->it] == val) {return TRUE;}

		//Se mueve al Nodo siguiente
		++this->it;
	}

	return FALSE;
}



//**------------------------------------------------------------------------------**//
void LD_InsertBack (LD * this, int newVal) 
{
 	if (this->front == 0) { assert (0); }
	this->lista[this->front] = newVal;
 	--this->front;
}
//**------------------------------------------------------------------------------**//
 LD_InsertFront(LD * this, int newVal, int MAX, int MIN) 
{
	if(LD_Pertenece(MAX,MIN, newVal) == FALSE) {assert (0);}
	else if (LD_FindIf(this, newVal) == TRUE) { assert(0);}
	else{
 	if (this->rear == MAX_TAM) { assert (0); }
	this->lista[this->rear] = newVal;
 	++this->rear;
 	}
}
//**------------------------------------------------------------------------------**//
int LD_RemoveFront (LD * this)
{
	int newVal = 0;
	if (this->front == this->rear) { assert (0); }
	newVal = this->lista[this->front];
	++this->front;
	return (newVal);
}
//**------------------------------------------------------------------------------**//
int LD_RemoveBack (LD * this)
{
	int newVal = 0;
	if (this->rear == this->front) { assert (0); }
	newVal = this->lista[--this->rear];
	//this->rear;
	return (newVal);
}
//**------------------------------------------------------------------------------**//
//Quita los espacios de en medio al remover en X posición
void LD_Refresh (LD * this)
{
	this -> tmp = this -> it;
	while (this -> tmp != this -> rear)
	{
		++this -> tmp;
		this -> lista[this->it] = this -> lista[this->tmp];
		++this -> it;
		
	}
	--this ->rear;
}



//**------------------------------------------------------------------------------**//
int LD_RemoveAT (LD * this, int val)
{
	int newVal;
	
	if (this -> front ==  this -> it) //Si es el primer valor 
	{	
		return LD_RemoveFront (this); //LD * 
	}
	else if (this -> rear == this -> it) //el valor
	{
		return LD_RemoveBack (this); //LD * 
	}
	else
	{	
		this -> it = 0;
		while (this -> lista[this->it] != val)
		{
			++this -> it;
		}
		newVal = this -> lista[this->it];
		LD_Refresh(this);
		return (newVal);
	}
}
//**--------------------------------------------------------------------------**//
int LD_Cardinalidad(int MAX, int MIN)
{
	int card;
	card = MAX-MIN;
	return card;
}
/*-----------------------------------------------------------------------------
 *                           Menú
 *-----------------------------------------------------------------------------*/

int menu()
{
	int opcion = 0;

	do {
		printf (	"\n"
					"1 -- Insertar\n"
					"2 -- Remover\n"
					"3 -- Insertar Atras\n"
					"4 -- Remover Atras\n"
					"5 -- Find if\n"
					"6 -- Remover at\n"
					"7 -- Pertenece \n"
					"8 -- Cardinalidad\n"
					"0 -- Terminar\n"
					"Su opcion> ");

		scanf ("%d", &opcion);
	} while (opcion < 0 || opcion > 8);

	printf ("\n");
	return opcion;
}


/*-----------------------------------------------------------------------------
 *                           Driver program
 *-----------------------------------------------------------------------------*/

int main() 
{
	int max1, max2, min1, min2;
//	LD * miLista = LD_Ctor(LD_Cardinalidad(max,min));
//	LD * miLista2 = LD_Ctor(LD_Cardinalidad(max,min));
//	Conjunto * miConj = Conjunto_Ctor();
	printf("\nIngresa el valor max del primer conjunto:\n");
	scanf("%d", &max1);
	printf("\nIngresa el valor min del primer conjunto:\n");
	scanf("%d", &min1);
	LD * miLista = LD_Ctor(max1,min1);
	
	printf("\nIngresa el valor max del segundo conjunto:\n");
	scanf("%d", &max2);
	printf("\nIngresa el valor min del segundo conjunto:\n");
	scanf("%d", &min2);
	LD * miLista2 = LD_Ctor(max2,min2);
	
while (1)
	{
		int opcion = menu ();
		int val;

		switch (opcion) {
			case 0:
				printf ("\n\tTerminando ...\n");
				return 0;

			case 1:
				printf ("\nIngresa el valor:\n");
				scanf("%d", &val);
				LD_InsertFront(miLista, val, max1, min1);
				break;

			case 2:
				printf ("\n\tRetirando el valor:\n");
				printf ("\n\tEl valor es: %d\n",LD_RemoveFront(miLista));
				break;
				
			case 3:
				printf ("\nInserta el valor:\n");
				scanf("%d", &val);
				LD_InsertBack(miLista, val);
				break;

			case 4:
				printf ("\n\tRetirando el valor\n");				
				printf ("\n\tEl valor es: %d\n",LD_RemoveBack(miLista));
				break;
				
			case 5:
				printf("\nQue valor deseas encontrar?:\n");
				scanf("%d", &val);
				if (LD_FindIf (miLista,val) == TRUE)
				{
					printf("\n\tEl valor se encuentra en la lista\n");
				}
				else
				{
					printf("\n\tEl valor aun NO se encuentra en la lista\n");
				}
				break;
			
			case 6:
				printf("\nQue valor deseas remover?:\n");
				scanf("%d", &val);
				LD_RemoveAT (miLista,val);
				printf("\n\tRemoviendo valor...\n");
				break;
				
			case 7:
				printf("\nIngresa el valor: \n");
				scanf("%d",&val);
				if (LD_Pertenece(max1, min1, val) == FALSE)
				{
					printf("\n\tEl valor NO pertenece al conjunto\n");
				}
				else
				{
					printf("\n\tEl valor pertenece al conjunto\n");
				}
				break;
			
			case 8:
				printf("\nLa cardinalidad del conjunto es: ");
				printf("%d\n", LD_Cardinalidad(max1,min1));
			break;
			
			default:
				printf ("\n\tOperacion no valida!\n");
				break;
		}
	}

	
	LD_Dtor (miLista); 
	// llamar al destructor
 
	return 0;
}
