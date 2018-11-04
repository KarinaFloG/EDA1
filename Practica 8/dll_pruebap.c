 #include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

enum {FALSE = 0, TRUE = !FALSE};
typedef unsigned int Bool;

//**-----------------------------------------------------------------------**//

struct Alumno_Type
{
	char nombre[32];
	int semestre;
	float promedio;
};
typedef struct Alumno_Type Alumno;
//**-------------------------------------------------------------------------**//
struct Node_Type
{
	Alumno alumno;

	struct Node_Type* next;
	struct Node_Type* prev;
};
typedef struct Node_Type Node;
//*----------------------------------------------------**//

struct DLL_Type
{
	Node* first;
	Node* last;
	Bool empty;
};
typedef struct DLL_Type DLL;

//*----------------------------------------------------**//

void Alumno_SetNombre (Alumno* this, char* nombre)
 {
 	strcpy(this->nombre, nombre);
 }
//**----------------------------------------------------**//
void Alumno_SetPromedio (Alumno* this, float promedio )
{
	this->promedio = promedio;
}
//**----------------------------------------------------**//
void Alumno_SetSemestre (Alumno* this, int semestre)
{
	this->semestre = semestre;
}
//**-----------------------------------------------------**//
char Alumno_GetNombre (Alumno* this)
{
	return this->nombre;
}
//**-----------------------------------------------------**//
float Alumno_GetPromedio (Alumno *this)
{
	return this->promedio;
}
//**-----------------------------------------------------**//
int Alumno_GetSemestre (Alumno *this)
{
	return this->semestre;
}

//**--------------------------------------------------------------------------------**//
Node* newNode (Alumno* alumno)
{
	Node* n = (Node*) malloc (sizeof (Node));
	if(n){
		char* nombre = Alumno_GetNombre (alumno);
		int* semestre = Alumno_GetSemestre (alumno);
		float* promedio = Alumno_GetPromedio (alumno);

		Alumno_SetNombre (&n->alumno, nombre);
		Alumno_SetSemestre (&n->alumno, semestre);
		Alumno_SetPromedio (&n->alumno, promedio);

		n->next = n->prev = NULL;
		}
		return n;
}


//*----------------------------------------------------**//

void deleteNode(Node* n)
{
	if (n) {free (n); }
}

//*----------------------------------------------------**//

DLL* DLL_Create()
{
	DLL* lista = (DLL*) malloc (sizeof (DLL));


	if (lista){
		lista->first = lista->last = NULL;
		lista->empty = TRUE;
	}
	return lista;
}

 //*----------------------------------------------------**//

Bool DLL_Insert (DLL* this, Alumno* alumno)
{
	Node* n = newNode (alumno);

	if (!n) {return FALSE;}

	if(this->empty){
		this->first = this->last = n;
		this->empty = FALSE;
	}
	else{
		this->last->next = n;
		n->prev = this->last;
		this->last = n;
	}
	return TRUE;
}

 //*----------------------------------------------------**//

void DLL_Destroy (DLL* this)
{
	if (this){
			while(this->first){
					Node* tmp = this->first->next;
					deleteNode(this->first);
					this->first = tmp;
			}
			//BORA LA LISTA
			free(this);
	}
}

 //*----------------------------------------------------**//

Bool DLL_Remove (DLL* this, Alumno* alumno)
{
	if(this->first != this->last){
		Alumno_Assign(alumno, &this->first->alumno);

		Node * tmp = this->first->next;
		deleteNode(this->first);
		this->first = tmp;
		this->first->prev = NULL;
		return TRUE;
	}
	else if(this->empty == FALSE){
		Alumno_Assign(alumno, &this->first->alumno);
		deleteNode(this->first);
		this->first = this->last = NULL;
		this->empty = TRUE;
		return TRUE;
	}
	else {
		return FALSE;
	}
}
//**-----------------------------------------------------------------**//
void Alumno_Assign (Alumno* this, Alumno* other)
{
	strcpy(this->nombre, other->nombre);
	this->semestre = other->semestre;
	this->promedio = other->promedio;
}
//**----------------------------------------------------**//
//**--------------Driver Program------------------------**//
//**----------------------------------------------------**//

int main(void)
{
	DLL * miLista = DLL_Create();
	assert (miLista);

	Alumno unAlumno;

	Alumno_SetNombre(&unAlumno, "FCO");
	Alumno_SetPromedio(&unAlumno, "10.0");
	Alumno_SetSemestre(&unAlumno, "2");
	Alumno_Print(&unAlumno);

	DLL_Insert (miLista, &unAlumno);

	Alumno_SetNombre(&unAlumno, "F");
	Alumno_SetPromedio(&unAlumno, "5.0");
	Alumno_SetSemestre(&unAlumno, "1");

	DLL_Remove(miLista, &unAlumno);
	Alumno_Print(&unAlumno);

	DLL_Destroy(miLista);

	return 0;
}
