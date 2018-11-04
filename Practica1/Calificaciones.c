//Tabla de conversion
//Practica1

#include<stdio.h>
#define tam 5

int califFinales(float arre1[],int arre2[]){
    int  tabla[tam]={6,7.2,7.8,8.4,8.9};
    float elem;
	int i;


    for(i=0; i<tam; i++){
	printf("Ingresa la calicacion %d:", i);
	scanf("%f", &elem);
	arre1[i] = elem;
	}

	for(i=0; i<tam; i++){
        if (arre1[i]< tabla[0])
            arre2[i]=5;
        else if (arre1[i]<tabla[1])
            arre2[i]=6;
        else if (arre1[i]<tabla[2])
            arre2[i]=7;
        else if(arre1[i]<tabla[3])
            arre2[i]=8;
        else if(arre1[i]<tabla[4])
            arre2[i]=9;
        else
            arre2[i]=10;
	}
return arre2;
}

main(){
	float calif[tam];
	int acta[tam];
	int i;

	califFinales(calif, acta);

 printf("\n\n");
	for (i=0; i<tam; ++i){
		printf("La calificacion final %d es: %d \n", i, acta[i]);
	}

}
