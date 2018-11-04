#include <stdio.h>
#include <unistd.h>








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

Reloj *Reloj_New(int _horas, int _minutos);

void Reloj_Delete (Reloj *this);

int Reloj_Diff(Reloj *this, Reloj * other);
//funcion para calcular la diferencia de horas

float Determina_fraccion(int diferencia);

float Calcular(int diferencia);

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

//Calcula la diferencia de minutos
int Reloj_Diff(Reloj *this, Reloj *other)
{
    int horas;
    int minutos;

    horas = (other->horas - this->horas) * 60;
    //Calcula la diferencia entre horas y las convierte
    //a minutos
    minutos = (other->minutos - this->minutos) + horas;
    //Calcula la diferencia en minutos y le suma la diferencia
    //de horas en minutos

return minutos;
}


float Determina_fraccion(int diferencia)
{
    int fracc;

return fracc = (diferencia) /15;

}


float Calcular(int diferencia)
{
    float a_pagar;
    float fraccion;

    if(diferencia <= 120)
    {
        a_pagar=5;
    }
        else
        {
            a_pagar=5;
            diferencia = diferencia -120;
            fraccion = Determina_fraccion(diferencia);
            a_pagar= a_pagar +(5.00 * fraccion);
        }

return a_pagar;
}

/*-----------------------------------------------------------------------------
 *                           Driver program
 *-----------------------------------------------------------------------------*/
int main(int argc, const char *argv[])
{
	Reloj *entrada = Reloj_New(16,00);   //Memoria que se pide al final se debe destruir
	Reloj *salida = Reloj_New(19,45);
	int diferencia;

	if (entrada == NULL){
		printf("Error al asignar memmoria\n");
		return 1;
	}

	if (salida == NULL){
		printf("Error al asignar memoria\n");
		return 1;
	}

	Reloj_Print (entrada);
	Reloj_Print (salida);

//-------------Arriba se encuentra lo principal de memoria dinamica---------------------

    printf("\nLa diferencia es: %d", Reloj_Diff(entrada, salida));

    diferencia = Reloj_Diff(entrada, salida);
    printf("\nEl total a pagar es: %.2f", Calcular(diferencia));



	Reloj_Delete (entrada); //Destruye la memoria asignada a casio
    Reloj_Delete (salida); //Destruye la memoria asignada a casio

	return 0;
}
