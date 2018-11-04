#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

enum {FALSE = 0, TRUE = !0};
typedef unsigned int Bool;


struct Reloj_Type
{
	int minutos;
	int horas;
};

typedef struct Reloj_Type Reloj;

void Reloj_Set (Reloj * this, int horas, int minutos);

void Reloj_IncHoras (Reloj * this);

void Reloj_IncMinutos (Reloj * this);

void Reloj_Print (Reloj * this);

void Reloj_Tick (Reloj * this);

Bool Reloj_IsEqual (Reloj * this, Reloj * other);

Bool Reloj_IsGreater (Reloj * this, Reloj * other);

Reloj *Reloj_New(int _horas, int _minutos);

void Reloj_Delete (Reloj *this);


void Reloj_Set (Reloj * this, int horas, int minutos)
{
	this->minutos = minutos;
	this->horas = horas;
}

void Reloj_IncHoras (Reloj * this)
{
	++this->horas;
	if (this->horas > 23 ) {
		this->horas = 0;
	}
}

void Reloj_IncMinutos (Reloj * this)
{
	++this->minutos;
	if (this->minutos > 59 ) {
		this->minutos = 0;
	}
}

void Reloj_Print (Reloj * this)
{
	printf ("%02d : %02d\n", this->horas, this->minutos);
}

void Reloj_Tick (Reloj * this)
{
	++this->minutos;
	if (this->minutos > 59) {
		this->minutos = 0;

		++this->horas;
		if (this->horas > 23) {
			this->horas = 0;
		}
	}
}

Bool Reloj_IsEqual (Reloj * this, Reloj * other)
{
	if (this -> horas == other -> horas){
		if  ( this -> minutos == other -> minutos){
			return TRUE;
		}
		else {
			return FALSE;
		}
	}
	else {
		return FALSE;
	}
}

Bool Reloj_IsGreater (Reloj * this, Reloj * other)
{
	if (this-> horas > other -> horas){
		return TRUE;
	}
	else if (this-> horas == other -> horas){
		if (this-> minutos > other -> minutos){
			return TRUE;
		}
		else{
			return FALSE;
		}
	}
	else {
		return FALSE;
	}
}

Reloj *Reloj_New(int _horas, int _minutos)
{
	if (_horas > 23) {_horas = 23; }
	if (_horas < 0) { _horas = 0; }

	if (_minutos > 59) {_minutos = 59; }
	if (_minutos < 0) {_minutos = 0; }
	
	Reloj *p = (Reloj *) malloc (sizeof(Reloj));
	if (p !=NULL){
		p->horas = _horas;
		p->minutos = _minutos;
	}
	return p;
}

void Reloj_Delete (Reloj *this)
{
	if (this != NULL){
		free (this);
		this = NULL;
	}
}



int menu()
{
	int opcion = 0;

	do {
		printf (	"\n"
					"1 -- Muestra la hora\n"
					"2 -- Incrementa las horas\n"
					"3 -- Incrementa los minutos\n"
					"4 -- Avanza al reloj 30 minutos\n"
					"0 -- Terminar\n"
					"Su opción> ");

		scanf ("%d", &opcion);
	} while (opcion < 0 || opcion > 4);

	printf ("\n");
	return opcion;
}

/*-----------------------------------------------------------------------------
 *                           Driver program
 *-----------------------------------------------------------------------------*/
int main(int argc, const char *argv[])
{
	Reloj *casio = Reloj_New(12,00);   //Memoria que se pide al final se debe destruir 
	
	if (casio == NULL){
		printf("Error al asignar memmoria\n");
		return 1;
	}
//#if 0
	//Reloj_Print (casio);

	//for (int i = 0; i < 90; ++i){
	//	Reloj_Tick(casio);
	//}
//#endif

	Reloj_Print (casio);

//-------------Arriba se encuentra lo principal de memoria dinamica---------------------

//#if 0
	
	//Reloj_Set (casio, 22, 50);

	Reloj swatch;

	Reloj_Set (&swatch, 12, 30);

	if (Reloj_IsGreater (casio, &swatch) == TRUE){
		printf ("La hora en casio es MAYOR que swatch\n");
	}
	else {
		printf ("La hora en casio en MENOR que swatch\n");
	}


	if (Reloj_IsEqual (casio, &swatch) == TRUE){
		printf ("Las horas son iguales\n");
	}
	else {
		printf ("Las horas No son iguales\n");
	} 
//#endif

//#if 1
	while (1)
	{
		int opcion = menu ();

		switch (opcion) {
			case 0:
				printf ("Terminando ...\n");
				return 0;

			case 1:
				printf ("Muestra la hora ... \n");
				Reloj_Print (casio);
				break;

			case 2:
				printf ("Incrementa las horas ...\n");
				Reloj_IncHoras (casio);
				break;

			case 3:
				printf ("Incrementa los minutos ...\n");
				Reloj_IncMinutos (casio);
				break;

			case 4:
				printf ("Avanza la hora 30 minutos ...\n");

				for (int i = 0; i < 30; ++i) {
					Reloj_Tick (casio);
					sleep (1);
					Reloj_Print (casio);
				}
				break;

			default:
				printf ("Operación no válida!\n");
				break;
		}
	}
//#endif

	Reloj_Delete (casio); //Destruye la memoria asignada a casio 

	return 0;
}
