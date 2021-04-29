#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <validations.h>

#define MAX 100

int menu ();
int leerVector(float vector[MAX]);
void imprimirVector(float vector[MAX], int n);
int metodoBige(float vector[MAX],int n);

int main() {
	system("color f0");
	int option, n, flag;
	welcome();
	float polinomio[MAX];
	do {
		option = menu();
		switch(option) {
			case 1:
				n = leerVector(polinomio);
				flag = metodoBige(polinomio, n);				
				if(flag==1) printf("\n\n Metodo Bige - Vieta aplicado correctamente.\n\n");
				if(flag==0) printf("\n\n *No es posible continual con el metodo Bige - Vieta, intente obtener raices con otro metodo.");
				if(flag==-1) printf("\n\n *No es posible aplicar el metodo Bige - Vieta.\n\n");
				pause();
				break;
			case 2:
				break;
		}
	}while(option != 2);
	bye();
	return 0;
}


int menu () {
	char str[MAX];
	int option;

	do{
		system("cls");
		printf("\n\n\t MENU: \n");
		printf("\n 1. M%ctodo Bige - Vieta.", 130);
		printf("\n 2. Salir.\n");	
		do {
			printf("\n Seleccione una opci%cn: ", 162);
			in(str);
			option = atoi(str);
		}while(option != 1 && option != 2 || !isInteger(str));
		clear();	
	}while(option < 0);
	return option;
}

int metodoBige(float polinomio[MAX],int n) {
	float x, polinomio1[n+1], mult1[n+1], polinomio2[n+1], mult2[n+1], polinomio3[n+1], solucion[n];
	int i, j, iteracion;
	int raicesRest;
	raicesRest = n;
	clear();
	//copiar polinomio
	for(i = 0 ; i < n + 1; i++){
		polinomio2[i] = polinomio[i];
		//printf("%f", polinomio2[i]);
	}
	printf("\n Procedimiento de Bige - Vieta:\n\n");
	for(i = 0 ; i < n; i++){
		printf("**************************  RAIZ    %d  **************************\n\n", i+1);
		for(j = 0 ; j < raicesRest + 1; j++){
			polinomio1[j] = polinomio2[j];
			//printf("%f", polinomio1[j]);
		}
		//Valor de x
		if(polinomio1[raicesRest - 1] != 0){
			x = (-1.0)*polinomio1[raicesRest]/polinomio1[raicesRest - 1];
		} else return -1;
		//Inicializar variables
		for(j = 0; j < raicesRest + 1; j++) {
			mult1[j] = 0;
			polinomio2[j] = 0;
			mult2[j] = 0;
			polinomio3[j] = 0;
		}
		//Repetir mientras el resto de la division sintetica sea != 0	
		iteracion = 0;
		do {
			printf(" X%d = %.4f\t", iteracion, x);
			for(j = 0; j < raicesRest + 1; j++) {
				if(j == 0) {
					polinomio2[j] = polinomio1[j];
				} else {
					mult1[j] = polinomio2[j-1] * x;
					polinomio2[j] = polinomio1[j] + mult1[j];
				}
			}
			for(j = 0; j < raicesRest; j++) {
				if(j == 0 && j < raicesRest - 1) {
					polinomio3[j] = polinomio2[j];
				} else {
					mult2[j] = polinomio3[j - 1] * x;
					polinomio3[j] = polinomio2[j] + mult2[j];
				}
			}
			for(j = 0;j < raicesRest + 1; j++) {
				printf(" %.2f", polinomio1[j]);
			}
			printf("\n\t\t");
			for(j = 0;j < raicesRest + 1; j++) {
				printf(" %.2f", mult1[j]);
			}
			printf("\n\t\t");
			for(j = 0;j < raicesRest + 1; j++) {
				printf("_______");
			}
			printf("\n\t\t");
			for(j = 0;j < raicesRest + 1; j++) {
				printf(" %.2f", polinomio2[j]);
			}
			printf("\n\t\t");
			for(j = 0;j < raicesRest; j++) {
				printf(" %.2f", mult2[j]);
			}
			printf("\n\t\t");
			for(j = 0;j < raicesRest + 1; j++) {
				printf("_______");
			}
			printf("\n\t\t");
			for(j = 0;j < raicesRest; j++) {
				printf(" %.2f", polinomio3[j]);
			}
			printf("\n\n\n");
			x = x - polinomio2[raicesRest]/polinomio3[raicesRest - 1]; 
			iteracion++;
			if(iteracion == 100) return 0;
		}while(polinomio2[raicesRest] != 0 || polinomio2[raicesRest] != -0);
		solucion[i] = x;
		raicesRest--;			
	}
	printf("*****************************************************************\n\n");
	//solucion[n - 1] = ((-1) * polinomio2[1]) / polinomio[0];
	printf("\n\n          Ecuacion: \n\n");
	imprimirVector(polinomio, n);
	printf("\n\n          SOLUCIONES: \n\n");
	for(i = 0; i < n; i++) {
		printf("\n X%d = %.6f", i+1, solucion[i]);
	}
}

int leerVector(float vector[MAX]) {
	int n, option;
	char str[MAX];
	
	do {
		clear();
		printf("\n\n\tMETODO BIGE - VIETA\n");
		do {
			printf(" \n Ingrese el grado de su ecuacion: ");
			in(str);
			n = atoi(str);
		} while(n < 2 || !isNumber(str));
		
		clear();
		int i;
		
		printf("\n\n\t Ingrese los coeficientes de cada termino");
		
    	for(i = 0 ; i <= n ; i++){
            do{
    		    printf("\n x^%i: ",n-i);
				in(str);
				vector[i] = atof(str);
			}while(!isFloat(str));
		}

		clear();
		
		printf("\n\n %cSu ecuacione es la siguiente?\n\n",168);
        /*Imprimo la matriz que forman los coeficientes de la ecuacion*/
		imprimirVector(vector, n);
		do{
            printf("\n [1.Si 2.No]: ");
			in(str);
			option = atoi(str);
		}while(option!=1 && option!=2 || !isInteger(str));

	}while(option != 1);
	return n;
	
}

void imprimirVector(float vector[MAX], int n) {
	int i;
	for(i = 0 ; i <= n ; i++){
		if(vector[i]<0) printf(" - ");
		else printf(" + ");
		
		if(i==n) {
           	if(vector[i]<0) printf(" %0.2f = 0\n",vector[i]*(-1));
           	else printf(" %0.2f = 0\n",vector[i]);
		}
           else {
           	if(vector[i]<0) printf("%0.2f x^%i",vector[i]*(-1),n-i);
           	else printf("%0.2f x^%i",vector[i],n-i);
		}
	}
}
