#include <stdio.h>
#include <unistd.h>



/*-----------------------------------------------------------------------------
 *  Definicion del ADT: cheque.h
 *-----------------------------------------------------------------------------*/
struct Cheque_Type
{
	char beneficiario[80];
	float cantidad;
	int day, month, year;
};

typedef struct Cheque_Type Cheque;


//void Cheque_Llenar(Cheque *this,char beneficiario, float cantidad, int day, month, year );

//void Cheque_See(Cheque *this,char bene[80], float cantidad, int day, month, year);

//////void Cheque_Save();

//void Cheque_Editar(Cheque *this, char bene[80], float cantidad, int day,month,year);

//void Cheque_Print();

//void Cheque_Cancel();


/*-----------------------------------------------------------------------------
 *  Implementacion del ADT reloj: reloj.c
 *-----------------------------------------------------------------------------*/

void Cheque_Llenar(Cheque * this)
{
	this->beneficiario = "karina" ;
	this->cantidad = 800;
	this->day = 02;
	this->month = 05;
	this->year = 03;
}

void Cheque_See(Cheque * this)
{
	printf("Beneficiario: %c", this->beneficiario);
	printf("Cantidad: %.2f", this->cantidad);
	printf("Fecha: %d/%d/%d", this->day,this->month,this->year);

}

void Cheque_Save(){
	printf("'\n******Guardando en la base de datos******");
}

//void Cheque_Editar(Cheque *this, char bene[80], float cantidad, int day,month,year);

void Cheque_Print()
{
	printf("Imprimiendo el cheque...");
}

void Cheque_Cancel(){
	printf("\n*****Cancelando******");

}



/*-----------------------------------------------------------------------------
 *                           Driver program
 *-----------------------------------------------------------------------------*/
 int menu(){
 	int opcion = 0;

	do {
 
 	printf("\n******BIENVENIDO AL SISTEMA******\n");
	printf("\tElija una opcion\n");
	printf("\t1. Llenar\n");
	printf("\t2. Ver\n");
	printf("\t3. Guardar\n");
	printf("\t4. Editar\n");
	printf("\t5. Imprimir\n");
	printf("\t6. Cancelar\n");
	printf("\t0. Terminar\n");
	
		scanf ("%d", &opcion);
	} while (opcion < 0 || opcion > 6);

	printf ("\n");
		return opcion;
}




int main(){

//	Cheque nombre[80];
//	Cheque cantidad;
//	Cheque day, month, year;
	Cheque cheque;
	
	
	while (1)
	{
		int opcion = menu ();

		switch (opcion) {
			case 0:
				printf ("Terminando ...\n");
				return 0;

			case 1:
				Cheque_Llenar(&cheque);
	
				
				break;

			case 2:
				Cheque_See (&cheque);
				break;

			case 3:
				Cheque_Save();
				break;

			case 4:
				printf ("Avanza la hora 30 minutos ...\n");
				break;

			case 5:
				Cheque_Print();
				break;
			
			case 6:
				Cheque_Cancel();
				break;
				
				
			default:
				printf ("Operacion no valida!\n");
				break;
		}
	}
return 0;	
	
}//principal

