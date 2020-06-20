
//  main.c
//  Taller 1
//
//  Creado por Grupo 10 el ?/?/20.
//

#ifndef stdlib_h
#define stdlib_h
#include <stdlib.h>
#endif /* stdlid_h */

#include <string.h>
#include <conio.h>

#include <stdio.h>
#include "enterolargo.h"

void main()
{
/*	int numero_ingresado=0;
	EnteroLargo *numero;

	
	printf("ingresa numero  \n");// desde aqui  se comprueba que se ingreso bien el numero crea enterolargoint, pasandole cualquier numero
	scanf("%d",&numero_ingresado);
	
	numero=creaEnteroLargoInt(numero_ingresado);//le paso como parametro el numero dado , retorna puntero numero que referencia uan estructura tipo EnteroLargo
	muestraEnteroLargo(numero);
	eliminaEnteroLargo(numero);
	muestraEnteroLargo(numero);// aqui termina la primera comprobacion*/
	
/*	EnteroLargo *numero,*numero1;
	char *numero_string;// desde aqui se crea un string de tamaño dinamico , luego se pide memoria para crear el string de tamaño  TAM * el tipo de dato char
	numero_string = malloc(sizeof(char)*TAM);
	printf("ingresa numero que se leera como string \n");
	scanf("%s",numero_string);
	numero =creaEnteroLargoStr(numero_string);// se pasa como parametro el string , como es un puntero  al llamar la funcion esta se le debe anteponer *
	
	numero1 =copiaEnteroLargo(numero1,numero);
	
	
	muestraEnteroLargo(numero1);*/
	
	EnteroLargo *numero,*numero2,*numero3,*numero4;//desde aqui
	FILE *fp,*fs,*archivo;
	
	numero =LeeEnteroLargo(fp);//el numero escrito en este archivo
    numero2=copiaEnteroLargo(numero2,numero);
    numero3=LeeEnteroLargo2(fs);// y el numero escrito en este archivo se sumaran y se grabaran en un 3er archivo , aparte de mostrarse en consola
    
    printf("el valor1 de ");
    muestraEnteroLargo(numero);
    printf("\n");
    printf("el valor2 de ");
    muestraEnteroLargo(numero3);
	printf("\n");

/*	numero=sumaEnteroLargo(numero,numero3);
	printf("la suma de ");
	muestraEnteroLargo(numero);
	printf("\n");
	
	escribeEnteroLargo(archivo,numero);// aqui se escribira el resultado de la suma, la suma esta registrada en el puntero numero
	printf("la suma se guardo con exito en el archivo registro_de_digito.txt \n");*/
	
	numero=restaEnteroLargo(numero,numero3);
	escribeEnteroLargo(archivo,numero);
	muestraEnteroLargo(numero);
// esta modificacion solo se ve en rama secundaria
// posteriormente se hara la union de la rama con su rama master
// esta edicion la hice desde computadora 
// otra edicion
	
}

