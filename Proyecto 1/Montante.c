#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <validations.h>


#define MAX 100

int menu();
int leerMatriz(float matrizI[MAX][MAX], float matrizA[MAX][MAX], float igualdad[MAX]);
int metodoMontante(float matrizI[MAX][MAX], float matrizA[MAX][MAX], float igualdad[MAX], int n);
float opCruz(int n, int pivAnt, int x, int i, int j, float matrizI[MAX][MAX], float matrizA[MAX][MAX]);

int main() {
	system("color f0");
	int option, n, aux;

	welcome();
	
	float matrizI[MAX][MAX], matrizA[MAX][MAX], igualdad[MAX];
	do {
		option = menu();
		switch(option) {
			case 1:
				n = leerMatriz(matrizI, matrizA, igualdad);
				aux = metodoMontante(matrizI, matrizA, igualdad, n);
				if(aux == 1) {
					pause();
				} else {
					printf("\n\n El sistema NO TIENE SOLUCI%cN\n det = 0", 162);
					pause();
				}
				break;
			case 2:
				
				break;
	}
	}while(option != 2);
	
	bye();
	return 0;
}

int menu (){
	char str[MAX];
	int option;

	do{
		system("cls");
		printf("\n\n\t MENU: \n");
		printf("\n 1. M%ctodo montante.", 130);
		printf("\n 2. Salir.\n");
		
		do {
			printf("\n Seleccione una opci%cn: ", 162);
			in(str);
			option = valInt(str);
		}while(option != 1 && option != 2);
		clear();	
	}while(option < 0);
	return option;
}

int leerMatriz(float matrizI[MAX][MAX], float matrizA[MAX][MAX], float igualdad[MAX]){
	int n, option;
	char str[MAX];
	
	do {
		
		clear();
		printf("\n\n\tMETODO MONTANTE\n");
		do {
			printf(" \nIngrese la cantidad de ecuaciones: ");
			in(str);
			n = valInt(str);
		} while(n < 2);
		
		clear();
		int i, j;
		
		printf("\n\n\t Ingrese los coeficientes de las ecuaciones");
		for(i = 0 ; i < n ; i++){
			printf("\n\n\t Ecuaci%cn %d\n", 162,i+1);
    	    for(j = 0 ; j < n ; j++){
     	       do{
      		        printf(" x%d: ",j+1);
					in(str);
					//printf("%f", valFloat(str));
					matrizI[i][j] = valFloat(str);
				}while(!isNumber(str));
			}
			/*Leo las igualdades de cada ecuacion*/
			
			do {
				printf(" = ");
				in(str);
				igualdad[i] = valFloat(str);
			}while(!isNumber(str));
			
		}
		
		clear();
		
		printf("\n\n %cSu sistema de ecuaciones es el siguiente?\n\n",168);
        /*Imprimo la matriz que forman los coeficientes de la ecuacion*/
		for(i = 0 ; i < n ; i++){
        	for(j = 0 ; j < n ; j++){
            	if(j==n-1) printf(" %0.2f x%d = ",matrizI[i][j],j+1);
            	else printf(" %0.2f x%d + ",matrizI[i][j],j+1);
			}
			/*Imprimo el vector solucion */
			printf("%0.2f\n",igualdad[i]);
		}
		do{
            printf("\n\n [1.Si 2.No]: ");
			in(str);
			option = valInt(str);
		}while(option!=1 && option!=2);

	}while(option != 1);
	return n;
}

int metodoMontante(float matrizI[MAX][MAX], float matrizA[MAX][MAX], float igualdad[MAX], int n) {
	int i, j;
	system("cls");
	printf("\n\n SOLUCION DEL SISTEMA POR EL METODO MONTANTE\n\n");
	/*Inicializo la matriz identidad de dimension nxn*/
	for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if(i==j) matrizA[i][j]=1.0;
            else matrizA[i][j]=0.0;
		}
	}
	/*Imprimo la matriz asociada al sistema con la identidad que extiende*/
	printf(" Estado inicial:\n\n");
	for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            printf(" %0.2f\t",matrizI[i][j]);
		}
		printf("|\t");
		for(j = 0 ; j < n ; j++){
            printf(" %0.2f\t",matrizA[i][j]);
		}
		printf("\n");
	}
	
	float pivAnt=1, pivAct;
	int k;
	for(k = 0 ; k < n ; k++){
        pivAct=matrizI[k][k];
		/*operaciones cruzadas para obtener numeros en la fila diferente a la del pivote*/
        for(i = 0 ; i < n ; i++){
        	for(j = 0 ; j < 2*n ; j++){
                if(i!=k && j!=k){
					if(j<n){
						matrizI[i][j]=opCruz(n,pivAnt,k,i,j,matrizI,matrizA);
					} else matrizA[i][j-n]=opCruz(n,pivAnt,k,i,j,matrizI,matrizA);
				}
			}
		}
		
		/*Imprimo la corrida en la que voy, el metodo consta de n corridas*/
		printf("\n\n Corrida %d:\n",k+1);
        for(i = 0 ; i < n ; i++){
        	for(j = 0 ; j < n ; j++){
            	if(j==k && i!=k) matrizI[i][j]=0;
            	printf(" %0.2f\t",matrizI[i][j]);
			}
			printf("|\t");
			for(j = 0 ; j < n ; j++){
            	printf(" %0.2f\t",matrizA[i][j]);
			}
			printf("\n");
		}
		pivAnt=pivAct;
		if(pivAnt==0.0) {
			return 0;
		}
	}
	//system("color 0A");
	/*Imprimo los resultados obtenidos Det, Mt, M-1 y solucion.*/
	printf("\n\n ############# RESULTADOS OBTENIDOS #############\n\n");
	if(matrizI[0][0]!=0){
		printf(" det= %0.2f",matrizI[0][0]);
	}
	
	printf("\n\n Matriz traspuesta del sistema:\n",k+1);
        for(i = 0 ; i < n ; i++){
        	for(j = 0 ; j < n ; j++){
            	printf(" %0.2f\t",matrizA[i][j]);
			}
			printf("\n");
		}

	printf("\n\n Matriz Inversa del sistema:\n",k+1);
        for(i = 0 ; i < n ; i++){
        	for(j = 0 ; j < n ; j++){
            	matrizA[i][j] = matrizA[i][j]/matrizI[0][0];
            	printf(" %0.2f\t",matrizA[i][j]);
			}
			printf("\n");
		}

	printf("\n\n **SOLUCION DEL SISTEMA**:\n");
	float solucion[' '];
	for(i = 0 ; i < n ; i++){
		solucion[i]=0;
       	for(j = 0 ; j < n ; j++){
           	solucion[i] = solucion[i] + igualdad[j]*matrizA[i][j];
		}
		printf(" x%d = %f\n",i+1,solucion[i]);
	}
	
	return 1;
}

float opCruz(int n, int pivAnt, int x, int i, int j, float matrizI[MAX][MAX], float matrizA[MAX][MAX]) {
	float resultado=0.0;

    if(j<n){
		resultado = (matrizI[x][x]*matrizI[i][j]-matrizI[x][j]*matrizI[i][x])/pivAnt;
	} else {
        resultado = (matrizI[x][x]*matrizA[i][j-n]-matrizA[x][j-n]*matrizI[i][x])/pivAnt;
	}

	return resultado;
}
