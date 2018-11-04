#include<assert.h>

#include<stdio.h>

#include<stdlib.h>

#define MAX_TAM 5

#include<string.h>

typedef enum { FALSE = 0, TRUE = !FALSE } Bool;

struct CQ_Int
{
 	int * tail; 
 	int first;
 	int last;
 	int max; 

	int con;	

}; typedef struct CQ_Int CQ;



CQ * CQ_Ctor (int max) 
{
	CQ * newCQ = (CQ *) malloc (sizeof (CQ)); 
	// crea a un nuevo objeto Stack en el heap
 
	//assert (newTail);
 
	newCQ->tail = (int *) malloc (max * sizeof (int)); 
	// crea a un nuevo contenedor (el arreglo) de double's en el heap
 
	assert (newCQ->tail);
 
	newCQ->first = 0;
	newCQ->last = 0;
	newCQ->max = max; 
	
	newCQ-> con = 0;
    
 	return newCQ;
}


void CQ_Dtor (CQ * this) 
{
  	assert (this);
  
  	free (this->tail);
  	 // devuelve la memoria del arreglo
   
 	 free (this);
  	 // devuelve la memoria del objeto
}


void CQ_Insert (CQ * this, int newVal) 
{
 	if (this -> con > MAX_TAM ) { assert (0); }
	
	this->tail[this->last] = newVal;
 	++this->last;

	if (this->last == MAX_TAM)
	{
		this->last = 0;
	}
	++this -> con;
}

int CQ_Remove (CQ * this)
{
	int newVal = 0;
	if (this -> con == 0) { assert (0); }

	newVal = this->tail[this->first];
	++this->first;

	if (this->first == MAX_TAM)
	{
		this->first = 0;
	}
	--this -> con;

	return (newVal);
}

void CQ_Clear(CQ * this){
	this->first=0;
	this->last=0;
	this->con=0;
	//limpia la cola regresando los apuntadores a 0
}


Bool CQ_IsFull(CQ *this){
	// si el contador es mayor al tamaño de la cola
	if(this->con >= MAX_TAM){
		printf("La cola esta llena\n");
		return TRUE;
	}
	else{
		printf("La cola aun no esta llena\n");	
		return FALSE;
	}
}

Bool CQ_IsEmpty(CQ * this)
{
	//Si el contador es igual a 0
	if(this->con == 0)
	{
		printf("La cola esta vacia\n");
		return TRUE;
	}
	else{
		printf("La cola contiene elementos o esta llena\n");
		return FALSE;
	}
}

/*-----------------------------------------------------------------------------
 *                           MenÃº
 *-----------------------------------------------------------------------------*/

int menu()
{
	int opcion = 0;

	do {
		printf (	"\n"
					"1 -- Insert \n"
					"2 -- Remove\n"
					"3 -- Clear\n"
					"4 -- Full\n"
					"5 -- Empty\n"									
					"0 -- Finish\n"
					"Su opcion> ");

		scanf ("%d", &opcion);
	} while (opcion < 0 || opcion > 5);

	printf ("\n");
	return opcion;
}





/*-----------------------------------------------------------------------------
 *                           Driver program
 *-----------------------------------------------------------------------------*/

int main() 
{
	
	CQ * ColaC = CQ_Ctor(MAX_TAM);
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
				CQ_Insert(ColaC, val);
				break;

			case 2:
				printf ("Retirando el valor:\n");
				printf ("El valor es: %d",CQ_Remove(ColaC));
				break;

			case 3:
				printf("La cola se ha limpiado\n");
				CQ_Clear(ColaC);
				break;

			case 4: 
				CQ_IsFull(ColaC);
				break;

			case 5:
				CQ_IsEmpty(ColaC);
				break;

			default:
				printf ("Operacion no valida!\n");
				break;
		}
	}

	
	Tail_Dtor (ColaC); 
	// llamar al destructor
 
	return 0;
}
