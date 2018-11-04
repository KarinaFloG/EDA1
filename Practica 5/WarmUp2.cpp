#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef enum { FALSE = 0, TRUE = !FALSE } Bool;

struct Stack_Type
{
 double * stack; 
 int top;
 int max; 
}; typedef struct Stack_Type Stack;

void Stack_Ctor (Stack * this, double * stack, int max) 
{
 this->stack = stack; 
 this->max = max; 
 this->top = 0;
}

void Stack_Push (Stack * this, double newVal) 
{
 if (this->top >= this->max) { assert (0); }
 this->stack[this->top] = newVal;
 ++this->top;
}

double Stack_Pop (Stack * this) { 
if (this->top == 0) { assert (0); }
--this->top;
return this->stack[this->top];
}

Bool Stack_IsEmpty (Stack * this) 
{
 return (this->top == 0); 
}

Bool Stack_IsFull (Stack * this) 
{
 return (this->top >= this->max); 
}


#define MAX_TAM 3
int main()
{
  Stack miPila; 
  double arreglo[MAX_TAM]; 
  Stack_Ctor (&miPila, arreglo, MAX_TAM);
  
  Stack_Push (&miPila, 2.5);
  Stack_Push (&miPila, 3.5);
  Stack_Push (&miPila, 4.5);
  
  printf ("<%f>\n", Stack_Pop (&miPila)); 
  printf ("<%f>\n", Stack_Pop (&miPila));
  printf ("<%f>\n", Stack_Pop (&miPila));
  
  Stack otraPila;
  double arreglo2[100]; 
  Stack_Ctor (&otraPila, arreglo2, 100);
// como los contenedores son arreglos locales a esta función, entonces NO es necesario liberar ninguna memoria.
return 0;
}
