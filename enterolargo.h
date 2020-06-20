
#define TAM 50
typedef struct arreglo
{
	char signo;
	int cantidad_de_digitos;
	int *array;
}EnteroLargo;
///////////////////////////////////////////
EnteroLargo *creaEnteroLargo()
{
	EnteroLargo *Enterolargo=malloc(sizeof(EnteroLargo));
	Enterolargo->signo='+';
	Enterolargo->cantidad_de_digitos=1;
	Enterolargo->array=malloc(sizeof(int)*TAM);

	return Enterolargo;
}
//////////////////////////////////////////
EnteroLargo *creaEnteroLargoInt(int numero)
{
	EnteroLargo *aux=malloc(sizeof(EnteroLargo));
	int resto=0,cantidad_de_digitos=0,k=0;
	aux->array=malloc(sizeof(int)*TAM);
	
	while(k<TAM)
	{
		aux->array[k]=0;
		k++;
	}
	
	if(numero>0)
	{
		aux->signo= '+';
	}
	else
	{
		aux->signo= '-';
	}
	
	int i=0;
	while(numero!=0)
	{
		resto=numero%10;
		aux->array[i]=resto;
		numero=numero/10;
		cantidad_de_digitos=i++;	
	}
	aux->cantidad_de_digitos=cantidad_de_digitos+1;

	return aux;// se devuelve arreglo que contiene el numero en una arreglo , en cada posicion contiene un numero del digito ingresado.
}		
/////////////////////////////////////////////////
int conversion(int numero)//convierte caracter de numero a numero int
{
	int i =0;
		if(numero==48){ return 0;}
		if(numero==49){ return 1;}
		if(numero==50){ return 2;}
		if(numero==51){ return 3;}
		if(numero==52){ return 4;}
		if(numero==53){ return 5;}
		if(numero==54){ return 6;}
		if(numero==55){ return 7;}
		if(numero==56){ return 8;}
		if(numero==57){ return 9;}
		
	//	printf("error\n");
		return 1000;
}
////////////////////////////////////////////////

/////////////////////////////////////////////////
EnteroLargo *creaEnteroLargoStr(char *string)// se recibe un arreglo que en cada posicion contiene un string
{
	EnteroLargo *Enterolargo= malloc(sizeof(char)*TAM);
	Enterolargo->array=malloc(sizeof(char)*TAM);
 	int cantidad_de_digitos=0,restar_caracter=0;
	char caracter='1';
	
	int k=0;
	while(k<TAM)
	{
		Enterolargo->array[k]=0;
		k++;
	}

 Enterolargo->signo=' ';
	 while(caracter!='\0')//se lee string, si encuentra caracter'\0' significa que hallo el fin del numero y debe dejar de contar cantidad de digitos
 	{
 		caracter=string[cantidad_de_digitos]; 
 		if((caracter=='+')||(caracter=='-'))//si encuentra + o - se asigna a valor ese signo
 		{
 			restar_caracter++;
 			
 			if(string[cantidad_de_digitos]=='+')
 	    	 {
 	   			    Enterolargo->signo='+';
			 }
			 
			 if(string[cantidad_de_digitos]=='-')
			 {
				 	Enterolargo->signo='-';
		 	 }
 			
		 }
 		cantidad_de_digitos++;
 	}
 	cantidad_de_digitos=cantidad_de_digitos-restar_caracter;// se corrige cantidad de digitos quitandole el signo
 	Enterolargo->cantidad_de_digitos=cantidad_de_digitos-1;// se guarda dato de cantidad de digitos	
 	
 	int j=0,numero1=12;
 	while(cantidad_de_digitos>=0)
 	{
 		if((string[cantidad_de_digitos]=='\0')||(string[cantidad_de_digitos]=='+')||(string[cantidad_de_digitos]=='-'))
 	   	 {
 			cantidad_de_digitos--;
		 }
		 else
		 {	//asignacion
		    numero1=string[cantidad_de_digitos];
		    numero1=conversion(numero1);
		
			if(Enterolargo->signo=='-')
			{
				numero1=numero1*-1;		
			}
 			Enterolargo->array[j]=numero1;//string[cantidad_de_digitos];
 	 		cantidad_de_digitos--;j++;
 	     }
	}
	
	if(Enterolargo->signo==' ')//si el numero que se esta leyendo no tiene signo , se entendera que es un numero positivo
	{
		Enterolargo->signo='+';
	}
	 return Enterolargo;
}
/////////////////////////////////////////////////
EnteroLargo *copiaEnteroLargo(EnteroLargo *destino,EnteroLargo *fuente)
{
	
	int cantidad_de_digitos=0;
	cantidad_de_digitos=fuente->cantidad_de_digitos;
	
	EnteroLargo *destino2= malloc(sizeof(int)*TAM);
	destino2->array=malloc(sizeof(int)*TAM);
	
	int k=0;
	while(k<TAM)
	{
		destino2->array[k]=0;
		k++;
	}
	
	destino2->cantidad_de_digitos=fuente->cantidad_de_digitos;
	destino2->signo=fuente->signo;
	cantidad_de_digitos--;
 	while(cantidad_de_digitos>=0)
 	{	//asignacion
		
			destino2->array[cantidad_de_digitos]=fuente->array[cantidad_de_digitos];
			cantidad_de_digitos--;
	}
	return destino2;
}
/////////////////////////////////////////////////
EnteroLargo *inversion(EnteroLargo *fuente)
{
	EnteroLargo *numero1;//se crea variable tipo entero largo y se copia catidad de datos y signo de fuente, luego se asigna inversamente sus valores
	numero1=malloc(sizeof(numero1)*TAM);
	numero1->array=malloc(sizeof(int)*TAM);
	
	int k=0;
	while(k<TAM)
	{
		numero1->array[k]=0;
		k++;
	}

	numero1->cantidad_de_digitos=fuente->cantidad_de_digitos;
	numero1->signo=fuente->signo;

	int cantidad_de_digitos=fuente->cantidad_de_digitos;
	cantidad_de_digitos--;
	
	int i=0,num=0;
	if(fuente->signo=='-')
	{
		while(i<fuente->cantidad_de_digitos)
		{
			num=fuente->array[i];
			num=num*-1;
			fuente->array[i]=num;
			i++;
		}
	}

	 i=0;
	while(i<fuente->cantidad_de_digitos)
	{
		numero1->array[i]=fuente->array[cantidad_de_digitos];
		i++;
		cantidad_de_digitos--;
	}
	return (numero1);
}
/////////////////////////////////////////////////
void muestraEnteroLargo(EnteroLargo *EnteroLargo)
{
    int	 i=EnteroLargo->cantidad_de_digitos-1;
	
	if(EnteroLargo==NULL)
	{
		printf("no existen datos \n");
	}
	else
	{
		printf("EnteroLargo es:  %c",EnteroLargo->signo);
		while(i>=0)
		{
			if(EnteroLargo->signo=='-')
			{	
				printf("%d",EnteroLargo->array[i]*-1);
			
			}
			else
			{
				printf("%d",EnteroLargo->array[i]);
			}
		 	i--;
		}
	}
	printf("\n");
}
/////////////////////////////////////////////////
void eliminaEnteroLargo(EnteroLargo *Enterolargo)
{
	free(Enterolargo->array);//vacio el espacio ocupado del arreglo
//	Enterolargo->cantidad_de_digitos=0;
	free(Enterolargo);// vacio la memoria pedida para crear estructura
}
///////////////////////////////////////////////////
void signo(char caracter, EnteroLargo *enterolargo)
{	
	if(caracter=='-')
	{
		enterolargo->signo='-';
	}
	else
	{
		enterolargo->signo='+';
	}		
}
//////////////////////////////////////////////////
EnteroLargo *LeeEnteroLargo(FILE *archivo)
{
	int digitos=0;
	 EnteroLargo *Enterolargo;
	 Enterolargo=malloc(sizeof(EnteroLargo)*TAM);
	 Enterolargo->array=malloc(sizeof(int)*TAM);
	 int k=0;
	 while(k<TAM)
	 {
	 	Enterolargo->array[k]=0;k++;
	 }	  
	 archivo= fopen("numeros_en_archivo.txt","rb");

		int numero=0;char caracter;
		while(!feof(archivo))//mientras no se llegue a final de archivo vamos a leer archivo
		{
				if((caracter==' ')||(caracter=='\0')||(caracter=='+')||(caracter=='-')||(caracter==10))//mientras se detecte un espacio , se omitira hasta encontrar otro numero 
				{ 
					while((caracter==' ')||(caracter=='+')||(caracter=='\0')||(caracter=='-')||(caracter==13)||(caracter==10))
					{
						signo(caracter, Enterolargo);
						caracter=fgetc(archivo);	
					}
					numero=conversion(caracter);	
					
					if(numero==1000)
					{
						Enterolargo->cantidad_de_digitos=digitos;
						Enterolargo =inversion(Enterolargo);
							fclose(archivo);
						return(Enterolargo);
					}					
				}
				Enterolargo->array[digitos]=numero;//asignacion
				
				digitos++;
			
				caracter=fgetc(archivo);//se lee caracter a caracter y se asigna a caracter
				numero=conversion(caracter);
					if(numero==1000)
					{
							Enterolargo->cantidad_de_digitos=digitos;
							Enterolargo =inversion(Enterolargo);
								fclose(archivo);
							return(Enterolargo);
					}
		}
	fclose(archivo);
	Enterolargo->cantidad_de_digitos=digitos;

	return (Enterolargo);
}
//////////////////////////////////////////////////////
EnteroLargo *LeeEnteroLargo2(FILE *archivo)
{
	int digitos=0;
	 EnteroLargo *Enterolargo2;
	 Enterolargo2=malloc(sizeof(EnteroLargo)*TAM);
	 Enterolargo2->array=malloc(sizeof(int)*TAM);
	 int k=0;
	 while(k<TAM)
	 {
	 	Enterolargo2->array[k]=0;k++;
	 }
		 archivo= fopen("numeros_en_archivo2.txt","rb");

		int numero=0;char caracter;
		while(!feof(archivo))//mientras no se llegue a final de archivo vamos a leer archivo
		{
				if((caracter==' ')||(caracter=='\0')||(caracter=='+')||(caracter=='-')||(caracter==10))//mientras se detecte un espacio , se omitira hasta encontrar otro numero 
				{ 
					while((caracter==' ')||(caracter=='+')||(caracter=='\0')||(caracter=='-')||(caracter==13)||(caracter==10))
					{
						signo(caracter, Enterolargo2);
						caracter=fgetc(archivo);	
					}
					numero=conversion(caracter);	
					
					if(numero==1000)
					{
						Enterolargo2->cantidad_de_digitos=digitos;
						Enterolargo2 =inversion(Enterolargo2);
							fclose(archivo);
						return(Enterolargo2);
					}					
				}
				Enterolargo2->array[digitos]=numero;//asignacion
				
				digitos++;
			
				caracter=fgetc(archivo);//se lee caracter a caracter y se asigna a caracter
				numero=conversion(caracter);
					if(numero==1000)
					{
							Enterolargo2->cantidad_de_digitos=digitos;
							Enterolargo2 =inversion(Enterolargo2);
								fclose(archivo);
							return(Enterolargo2);
					}
		}
	
	fclose(archivo);
	Enterolargo2->cantidad_de_digitos=digitos;

	return (Enterolargo2);
}
//////////////////////////////////////////////////////
void escribeEnteroLargo(FILE *archivo ,EnteroLargo *numero)
{
	//escribe entero largo guardado anteriormente en numero , y lo escribe un archivo de texto 
	archivo=fopen("registo_de_digito.txt","w");
	if(archivo==NULL)
	{
		printf("ERROR: archivo no  a sido creado con exito \n");
	}
	else
	{
		int i=0;int caracter=0,posicion=numero->cantidad_de_digitos;
		posicion--;
		while(i<numero->cantidad_de_digitos)
		{
			caracter=numero->array[posicion--];
		    fprintf(archivo, "%d",caracter);
			i++;
		}
	}
	fclose(archivo);
}
///////////////////////////////////////////////                               \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//////////////////////////////////////////////<OPERACIONES ARITMETICAS BASICAS>\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
/////////////////////////////////////////////                                   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\                       

EnteroLargo *sumaEnteroLargo(EnteroLargo *numero1,EnteroLargo *numero2)// si los dos signos son iguales hablamos de suma 
{// si uno de los signos es diferente hablamos de resta
	EnteroLargo *suma;
	suma=malloc(sizeof(suma)*TAM);
	suma->array=malloc(sizeof(int)*TAM);
	
	int k=0;
	while(k<TAM)
	{
		suma->array[k]=0;
		k++;
	}
	suma->signo='?';
	int largo_numero1=numero1->cantidad_de_digitos;
	int largo_numero2=numero2->cantidad_de_digitos,i=0,valor1=0,valor2=0;
	int recordar=0,num=0,suma_temporal=0,resta=0,valor_absoluto=0;

	if(numero1->array[largo_numero1-1]>numero2->array[largo_numero2-1])//desde aqui
	{
			suma->signo=numero1->signo;
	}
	else
	{
			suma->signo=numero2->signo;
	}//hasta aqui es para reconocer signo que debe tener la suma de estos digitos*/

	while(((i<largo_numero1)||(i<largo_numero2)))//mientras no se recorra ambos numeros completo hacer esto
	{
					suma_temporal=numero1->array[i]+numero2->array[i];
					valor_absoluto=abs(suma_temporal);

					if(((valor_absoluto>10))&&(recordar==0))// si la suma de los digitos en esa posicion es inferior a 10 siemplemente asignar la suma en esa posicion
					{
						suma->array[i]=valor_absoluto;
						recordar=0;
					}
					else
					{
							resta=valor_absoluto-10;
							suma->array[i]=resta+recordar;
							recordar=1;
					}	
		i++;
		suma->cantidad_de_digitos=i;
	}
	if(recordar==1)//si aunque se recorrio los 2 arreglo quedo algun exceso
	{
		suma->cantidad_de_digitos=largo_numero1+1;
		suma->array[i]=1; 
	}
	
	int l=0,num1=0;
	if(suma->signo=='-')
	{
		while(l<suma->cantidad_de_digitos)
		{
			num1=suma->array[l];
			suma->array[l]=num1*(-1);
			l++;
		}
	}
		return suma;
}
//////////////////////////////////////////////////////////////////////////////
EnteroLargo *numero_mayor()
{
	EnteroLargo *numero_mayor;
	numero_mayor=malloc(sizeof(numero_mayor)*TAM);
	numero_mayor->array=malloc(sizeof(int)*TAM);
	return numero_mayor;
}

/////////////////////////////////////////////////////////////////////////////
EnteroLargo *restaEnteroLargo(EnteroLargo *numero1 , EnteroLargo *numero2)
{
	EnteroLargo *resultado;//se considera resta cuadno los dos signos son diferentes
	resultado= malloc(sizeof(EnteroLargo)*TAM);
	resultado->array=malloc(sizeof(int)*TAM);
	int i=0,resta_temporal=0,recordar=0,largo1=numero1->cantidad_de_digitos,largo2=numero2->cantidad_de_digitos,valor_absoluto=0;
	while(i<TAM)
	{
		resultado->array[i]=0;
		i++;
	}

	
	if(numero1->array[largo1-1]>numero2->array[largo2-1])//desde aqui
	{
			resultado->signo=numero1->signo;
		//	EnteroLargo *numero_mayor=numero_mayor();
	}
	else
	{
			resultado->signo=numero2->signo;
	}//hasta aqui es para reconocer signo que debe tener la suma de estos digitos*/
	
	

	
	///////// 999-1,995-8,99988-99
	i=0;
	
	while((i<numero1->cantidad_de_digitos)||(i<numero2->cantidad_de_digitos))//mientras no se recorra ambos numeros se restara
	{
		resta_temporal=abs(numero1->array[i])-abs(numero2->array[i]);
	//	printf("numero 1: %d ,numero 2: %d \n ",numero1->array[i],numero2->array[i]);
	//	printf("resta temporal : %d \n",resta_temporal);
		
		
		if(((resta_temporal)>=0))
		{
			if(resta_temporal-recordar<0)
			{
				resultado->array[i]=abs(numero1->array[i])-1;
				recordar=0;	
			}
			else
			{
				resultado->array[i]=resta_temporal-recordar;
				recordar=0;
			}
		}
		else
		{
			resta_temporal=10+abs(numero1->array[i])-abs(numero2->array[i]);
			resultado->array[i]=resta_temporal-recordar;
			recordar=1;
		}
		i++;
		resultado->cantidad_de_digitos=i;
	}
	


	
	if((numero1->signo=='-')&&(numero2->signo=='-'))
	{
	
		int j=0,num=0;
		while(j<TAM)
		{
			num=resultado->array[j];
			resultado->array[j]=num*-1;
			j++;
		}
	}
	
	
	return resultado;
}
