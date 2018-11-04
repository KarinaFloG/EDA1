#include<assert.h>

#include<stdio.h>

#include<stdlib.h>

#define MAX_TAM 5

#include<string.h>

typedef enum { FALSE = 0, TRUE = !FALSE } Bool;

struct Tail_Type
{
 	int * tail; 
 	int first;
 	int last;
 	int max; 

	int con;	

}; typedef struct Tail_Type Tail;



Tail * Tail_Ctor (int max) 
{
	Tail * newTail = (Tail *) malloc (sizeof (Tail)); 
	// crea a un nuevo objeto Stack en el heap
 
	//assert (newTail);
 
	newTail->tail = (int *) malloc (max * sizeof (int)); 
	// crea a un nuevo contenedor (el arreglo) de double's en el heap
 
	assert (newTail->tail);
 
	newTail->first = 0;
	newTail->last = 0;
	newTail->max = max; 
	
	newTail-> con = 0;
    
 	return newTail;
}


void Tail_Dtor (Tail * this) 
{
  	assert (this);
  
  	free (this->tail);
  	 // devuelve la memoria del arreglo
   
 	 free (this);
  	 // devuelve la memoria del objeto
}

//  igual que antes

void Tail_Insert (Tail * this, int newVal) 
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

int Tail_Remove (Tail * this)
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


/*-----------------------------------------------------------------------------
 *                           Menú
 *-----------------------------------------------------------------------------*/

int menu()
{
	int opcion = 0;

	do {
		printf (	"\n"
					"1 -- Insertar \n"
					"2 -- Extraer\n"					
					"0 -- Terminar\n"
					"Su opcion> ");

		scanf ("%d", &opcion);
	} while (opcion < 0 || opcion > 2);

	printf ("\n");
	return opcion;
}





/*-----------------------------------------------------------------------------
 *                           Driver program
 *-----------------------------------------------------------------------------*/

int main() 
{
	
	Tail * miCC = Tail_Ctor(MAX_TAM);
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
				Tail_Insert(miCC, val);
				break;

			case 2:
				printf ("Retirando el valor:\n");
				printf ("El valor es: %d",Tail_Remove(miCC));
				break;

			default:
				printf ("Operacion no valida!\n");
				break;
		}
	}

	
	Tail_Dtor (miCC); 
	// llamar al destructor
 
	return 0;
}
