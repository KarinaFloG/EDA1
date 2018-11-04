//Tabla de conversion
//Practica1

#include<stdio.h>
#define tam 5

main(){
	float calif[tam];
	int  tabla[tam]={6,7.2,7.8,8.4,8.9};
	int  acta[tam];
	float elem;
	int i,j,k;

	for(i=0; i<tam; i++){
	printf("Ingresa la calicacion %d:", i);
	scanf("%f", &elem);
	calif[i] = elem;
	}

	for(i=0; i<tam; i++){
		if(calif[i] < tabla[0])
			acta[i]=5;
		else if(calif[i] < tabla[1])
			acta[i]=6;
		else if(calif[i] < tabla[2])
			acta[j]=7;
		else if(calif[i] < tabla[3])
			acta[j]=8;
		else if(calif[i] < tabla[4])
			acta[i]=9;
		else
			acta[i]=10;
	}

	printf("\n\n");
	for (i=0; i<tam; ++i){
		printf("La calificacion final %d es: %d \n", i, acta[i]);
	}
}
