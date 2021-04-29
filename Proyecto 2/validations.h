#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX 100

void welcome();
void bye();
void in(char string[MAX]);
int valInt(char aux[MAX]);
float valFloat(char aux[' ']);
void pause();
int isEmpty(char cinta[MAX]);
void clear();
int isNumber();

void welcome() {
	printf("\n\n\n\n");
	printf("\n\n\t\t\t    BIENVENIDO \n\n\n\t\t");
	printf(" PRESIONE UNA TECLA PARA INICIAR: ");
	getch();
	system("cls");
}

void bye() {
	printf("\n\n\n\n");
	printf("\n\n\t\t\t FIN DEL PROGRAMA \n\n\n\t\t");
	printf(" PRESIONE UNA TECLA PARA SALIR: ");
	getch();
	system("cls");
}

void in(char string[MAX]) {
	fflush(stdin);
	gets(string);
	return;
}

int valInt(char aux[MAX]) {
	int i, n, lon, flag=1;
	lon=strlen(aux);
	for(i=0;i<lon;i++)
	{
		if(isdigit(aux[i]))
			flag=1;
		else
			flag=0;
		if(flag==0)
			break;
	}
	if (lon==0)
		flag=0;
	if(flag==1)
		n=atoi(aux);
	else if(flag==0)
		n=-9999;
	return n;
}

float valFloat(char aux[MAX]) {
	int i, lon, flag, punto=0;
	float n;
	lon=strlen(aux);
	for(i=0;i<lon;i++)
	{
		if(isdigit(aux[i])||aux[i]=='.')
		{
			flag=1;
			if(aux[i]=='.')
				punto++;
		}
		else
			flag=0;
		if(flag==0||punto>1)
		{
			flag=0;
			break;
		}
	}
	if(lon==0)
		flag==0;
	if(flag==1)
		n=atof(aux);
	else if(flag==0)
		n=-9999;
	return n;
}


void pause() {
	printf("\n\n PRESIONE UNA TECLA PARA CONTINUAR: ");
	getch();
	fflush(stdin);
}

int isEmpty(char cinta[MAX]) {
	int i, empty;
	empty = 1;
	for(i = 0; i < strlen(cinta); i++) {
		if(cinta[i] != ' ') {
			empty = 0;
			break;
		}
	}
	return empty;
}

void clear(){
	system("cls");
}

int isNumber(char aux[MAX]) {
	int i, lon, flag, punto=0;
	float n;
	lon=strlen(aux);
	for(i=0;i<lon;i++)
	{
		if(isdigit(aux[i])||aux[i]=='.')
		{
			flag=1;
			if(aux[i]=='.')
				punto++;
		}
		else
			flag=0;
		if(flag==0||punto>1)
		{
			flag=0;
			break;
		}
	}
	if(lon==0)
		flag==0;

	return flag;
}
