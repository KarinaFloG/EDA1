#include<assert.h>
#include<stdio.h>
//para usar las aserciones

#define MAX_TAM 5

int main()
{
	double pila[MAX_TAM];
	int top=0;
	
	if(top>=MAX_TAM){assert(0);}
	pila[top]=2.5;
	++top;
	
	
	if(top>=MAX_TAM){assert(0);}
	pila[top]=3.5;
	++top;
	
	if(top>=MAX_TAM){assert(0);}
	pila[top]=4.5;
	++top;
	
	if(top==0){assert(0);}
	--top;
	printf("<%f>\n", pila[top]);
	
	if(top==0){assert(0);}
	--top;
	printf("<%f>\n", pila[top]);
	
	if(top==0){assert(0);}
	--top;
	printf("<%f>\n", pila[top]);
	
	printf("<%f>\n",pila[top]);
	
	return 0;
}
