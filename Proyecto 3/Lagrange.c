#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <validations.h>


#define MAX 100

int menu();

int leerVectores(float vectorX[MAX], float vectorY[MAX]);
void lagrange(float vectorX[MAX], float vectorY[MAX], int n);
void imprimirProceso(int flag, float x, float vectorX[MAX], float vectorY[MAX], int n);

int main() {
	system("color f0");
	int option, n;
	
	welcome();
	
	float vectorX[MAX], vectorY[MAX];
	int flag = 0;
	do {
		option = menu();
		switch(option) {
			case 1:
				flag = 1;
				n = leerVectores(vectorX, vectorY);
				break;
			case 2:				
				if(flag != 0) {
					clear();
					lagrange(vectorX, vectorY, n);
				} else {
					printf("\n\n --PRIMERO DEBES INGRESAR UNA TABLA DE PARES (X, Y)--");
					pause();
					clear();
				}
				break;
			case 3:
				break;
		}
	}while(option != 3);
	
	bye();
	return 0;
}

int menu (){
	char str[MAX];
	int option;

	do{
		system("cls");
		printf("\n\n\t INTERPOLACI%cN DE LAGRANGE: \n", 162);
		printf("\n 1. Ingresar tabla de pares (X, Y).");
		printf("\n 2. Estimar un valor.");
		printf("\n 3. Salir.\n");
		
		do {
			printf("\n Seleccione una opci%cn: ", 162);
			in(str);
			option = atoi(str);
		}while(option != 1 && option != 2 && option != 3 || !isInteger(str));
		clear();	
	}while(option < 0);
	return option;
}

int leerVectores(float vectorX[MAX], float vectorY[MAX]){
	int n, option;
	char str[MAX];
	
	do {
		clear();
		printf("\n\n\t INGRESANDO TABLA DE VALORES\n");
		do {
			printf(" \n Ingrese la cantidad de pares(X, Y) en la tabla: ");
			in(str);
			n = atoi(str);
		} while(n < 2 || !isInteger(str));
		
		clear();
		int i;
		
		printf("\n\n\t INGRESANDO VALORES DE X\n");
		
    	for(i = 0 ; i < n ; i++){
            do{
    		    printf("\n x%d: ",i);
				in(str);
				vectorX[i] = atof(str);
			}while(!isFloat(str));
		}
		clear();
		printf("\n\n\t INGRESANDO VALORES DE Y\n");
		
		
		for(i = 0 ; i < n ; i++){
            do{
    		    printf("\n y%d: ",i);
				in(str);
				vectorY[i] = atof(str);
			}while(!isFloat(str));
		}

		clear();
		
		printf("\n\n %cSu tabla es la siguiente?\n\n",168);
        /*Imprimo la matriz que forman los coeficientes de la ecuacion*/
        printf(" X");
		for(i = 0 ; i < n ; i++){
			printf("\t %f", vectorX[i]);
		}
		printf("\n Y");
		for(i = 0 ; i < n ; i++){
			printf("\t %f", vectorY[i]);
		}
		printf("\n");
		do{
            printf("\n [1.Si 2.No]: ");
			in(str);
			option = atoi(str);
		}while(option!=1 && option!=2 || !isInteger(str));

	}while(option != 1);
	return n;
	
}

void lagrange(float vectorX[MAX], float vectorY[MAX], int n) {
	float x, y, numerador[MAX], denominador[MAX];
	char str[MAX];
	int i, j;
	
	imprimirProceso(0, 0, vectorX, vectorY, n);
	
	do {
		printf("\n\n Ingrese el valor de X a estimar en y(X): ");
		in(str);
		x = atof(str);
	} while(!isFloat(str));
	
	clear();
	
	//Inicializar
	for(i = 0; i < n; i++) {
		numerador[i] = 1;
		denominador[i] = 1;
	}
	
	//Numerador
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(i != j) {
				numerador[i] = numerador[i] * (x - vectorX[j]);
			}
		}
	}
	
	//Denominador
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(i != j) {
				denominador[i] = denominador[i] * (vectorX[i] - vectorX[j]);
			}
		}
	}
	
	//y(X)
	y = 0;
	for(i = 0; i < n; i++) {
		y = y + (vectorY[i] * numerador[i]) / denominador[i];
	}
	
	
	
	printf("\n\n\t VALOR ESTIMADO A TRAVES DE INTERPOLACI%cN DE LAGRANGE.", 162);
	imprimirProceso(1, x, vectorX, vectorY, n);
	printf("\n\n RESULTADO\n\n y(%.2f) = %f\n\n", x, y);
	pause();
}

void imprimirProceso(int flag, float x, float vectorX[MAX], float vectorY[MAX], int n) {
	int i, j;
	
	printf("\n\n");
	
	if(flag == 1) {
		printf(" y(%.2f) = \n\n", x);
	}else {
		printf(" y(X) = \n\n");
	}
	
	for(i = 0; i < n; i ++) {
		printf(" +\t %.2f\t", vectorY[i]);
		for(j = 0; j < n; j++){
			if(i != j) {
				if(flag == 1) {
					printf("(%.2f -\t %.2f)\t", x, vectorX[j]);
				} else {
					printf("(X   -\t %.2f)\t", vectorX[j]);
				}				
			}
		}
		printf("\n                ");
		for(j = 0; j < (n-1) * 2; j++) {
			printf("________");
		}
		
		printf("\n");
		printf(" \t\t", vectorY[i]);
		for(j = 0; j < n; j++){
			if(i != j) {
				printf("(%.2f -\t %.2f)\t", vectorX[i], vectorX[j]);
			}
		}
		printf("\n\n");
	}

}
