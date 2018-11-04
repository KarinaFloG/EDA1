#include<assert.h>

#include<stdio.h>

#include<stdlib.h>

#define MAX_TAM 5

#include<string.h>

typedef enum { FALSE = 0, TRUE = !FALSE } Bool;


struct DL_Char
{
 	char * stack; 
 	int front;
 	int rear;
 	int max; 
}; typedef struct DL_Char DL;



DL* DL_Ctor (int max) 
{
	DL * newDL = (DL *) malloc (sizeof (DL)); 
	// crea a un nuevo objeto Stack en el heap
 
	//assert (newStack);
 
	newDL->stack = (char *) malloc (max * sizeof (char)); 
	// crea a un nuevo contenedor (el arreglo) de double's en el heap
 
	assert (newDL->stack);
 
	newDL->front = 0;
	newDL->rear=0;
	newDL->max = max; 
    
 	return newDL;
}


void DL_Dtor (DL * this) 
{
  	assert (this);
  
  	free (this->stack);
  	 // devuelve la memoria del arreglo
   
 	 free (this);
  	 // devuelve la memoria del objeto
}

//  igual que antes


void DL_InsertFront(DL * this, char newVal) 
{
 	if (this->rear == MAX_TAM) { assert (0); }
 	//++this->rear;
	this->stack[this->rear] = newVal;
 	++this->rear;
 	
}


char DL_RemoveFront (DL * this)
{
	char newVal;
	if (this->front == this->rear) { assert (0); }
	//++this->front;
	newVal = this->stack[this->front];
	++this->front;
	return (newVal);
}


void DL_InsertBack (DL * this, char newVal) 
{
 	if (this->front == 0) { assert (0); }
 //	this->front=--this->front;
 	this->stack[this->front] = newVal;
	--this->front;
}


char DL_RemoveBack (DL * this)
{
	char newVal;
	//int newVal = 0;
	if (this->rear == this->front) { assert (0); }
	--this->rear;
	newVal = this->stack[this->rear];
//	--this->rear;
	return (newVal);
}


Bool DL_IsEmpty(DL * this)
{
	if (this->front == this->rear)
	{
		printf("\tLa lista esta vacia\n");
		return(TRUE);
	}
	
		else
		{
			printf("\tLa lista contiene elementos o esta llena\n");
			return(FALSE);
		 } 	
}

Bool DL_IsFull(DL * this)
{
	if(this->rear > MAX_TAM && this->front > MAX_TAM )
	{
		printf("\tLa lista esta llena\n");
		return(TRUE);
	}
	
		else
		{
			printf("\tLa lista esta vacia o aun no se llena\n");
			return(FALSE);
		}
}

void DL_Clear(DL * this)
{
	this->front=0;
	this->rear=0;
}
/*-----------------------------------------------------------------------------
 *                          Menú
 *-----------------------------------------------------------------------------*/

int menu()
{
	int opcion = 0;

	do {
		printf (	"\n"
					"1 -- Insert Front (rear-izq)\n"
					"2 -- Remove Front (front-der)\n"
					"3 -- Insert Back (front-1 - der)\n"
					"4 -- Remove Back (rear-1 - izq)\n"
					"5 -- Empty\n"
					"6 -- Full\n"
					"7 -- Clear\n"
					"0 -- Finish\n"
					"Su opcion> ");

		scanf ("%d", &opcion);
	} while (opcion < 0 || opcion > 7);

	printf ("\n");
	return opcion;
}


