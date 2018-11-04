/Tabla de conversion
//Practica1

#include<stdio.h>
#define tam 5

main(){
	float calif[tam];
	int  tabla[tam]={6,7.2,7.8,8.4,8.9};
	int  acta[tam];
	float elem;

	for(size_t i=0; i<tam; i++){
	printf("Ingresa la calicacion %d:", i);
	scanf("%f", &elem);
	calif[i] = elem;
	}

	for(size_t j=0; j<tam; j++){
		if(calif[j] < tabla[0])
			acta[j]=5;
		else if(calif[j] < tabla[1])
			acta[j]=6;
		else if(calif[j] < tabla[2])
			acta[j]=7;
		else if(calif[j] < tabla[3])
			acta[j]=8;
		else if(calif[j] < tabla[4])
			acta[j]=9;
		else
			acta[j]=10;
	}

	printf("\n\n");
	for (size_t k=0; k<tam; ++k){
		printf("La calificacion final %d es: %d \n", k, acta[k]);
	}
}
