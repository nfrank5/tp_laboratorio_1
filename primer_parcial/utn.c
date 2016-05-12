#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/** \brief Funcion para tomar un entero del usuario
 *
 * \param puntero para el retorno del entero ingresado
 * \param Mensaje para pedirle al usuario que ingrese un numero
 * \param Mensaje de error
 * \param numero minimo a aceptar
 * \param numero maximo a aceptar
 * \return 0 si se ingreso el numero correctamento -1 si hubo un error
 *
 */
int getInt(int* retorno, char msg[], char errormsg[], int minimo,int maximo)
{
    char aux[1024];
    int valor=0;
    printf("%s\n",msg);
    scanf(" %s%*[^\n]",aux);
    if(strcmp(aux,"0\0")==0)
    {
        valor=0.00;
    }
    else if((valor=atoi(aux))==0||(valor<minimo||valor>maximo))
    {
        printf("%s",errormsg);
        return -1;
    }
    *retorno=valor;
    return 0;

}

/** \brief Funcion para tomar un numero  float del usuario
 *
 * \param puntero para el retorno del float ingresado
 * \param Mensaje para pedirle al usuario que ingrese un numero
 * \param Mensaje de error
 * \param numero minimo a aceptar
 * \param numero maximo a aceptar
 * \return 0 si se ingreso el numero correctamento -1 si hubo un error
 *
 */
int getFloat(float* retorno, char msg[], char errormsg[], int minimo,int maximo)
{
    char aux[1024];
    float valor=0.00;
    //int flag=0;
    printf("%s\n",msg);
    scanf(" %s%*[^\n]",aux);
    if(strcmp(aux,"0\0")==0)
    {
        valor=0.00;
        //flag=1;
    }
    else if((valor=atof(aux))==0||(valor<minimo||valor>maximo))
    {
        printf("%s",errormsg);
        return -1;
    }
    *retorno=valor;
    return 0;

}

/**
 * \brief Solicita un caracter al usuario y lo valida
 * \param input Se carga el caracter ingresado
 * \param msg Es el mensaje a ser mostrado
 * \param errorMsg Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return Si obtuvo el caracter [0] si no [-1]
 *
 */
int getChar(char* input,char msg[],char errorMsg[], char lowLimit, char hiLimit)
{
    char aux;
    printf("%s", msg);
    scanf(" %c%*[^\n]", &aux);
    aux=tolower(aux);
    lowLimit=tolower(lowLimit);
    hiLimit=tolower(hiLimit);
    if(aux<lowLimit||aux>hiLimit)
    {
        printf("%s",errorMsg);
        return -1;
    }
    *input=aux;
    return 0;
}

/**
 * \brief Solicita una cadena al usuario y lo valida
 * \param input Se carga la cadena ingresada
 * \param msg Es el mensaje a ser mostrado
 * \param errorMsg Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return Si obtuvo el caracter [0] si no [-1]
 *
 */
int getString(char* input,char msg[],char errorMsg[],int lowLimit,int hiLimit)
{
    char aux[1024];
    printf("%s",msg);
    scanf(" %[^\n]s",aux);
    if(strlen(aux)<lowLimit||strlen(aux)>hiLimit)
    {
        printf("%s",errorMsg);
        return -1;
    }
    strcpy(input,aux);
    return 0;
}

/** \brief Funcion para validar S o N en la seleccion de continuar o no.
 * \return 0
 *
 */
int validarS_N(char* input)
{
    char*respuesta;
    respuesta=input;
    while(getChar(respuesta,"¿Continuar S/N?\n","Error, vuelva a ingresar",'N','S')==-1);
    return 0;
}

/** \brief crear un menu
 *
 * \param retorno por puntero
 * \param El texto del menu
 * \param numero de opcion minimo
 * \param numero de opcion maximo
 * \return retorna un 0
 *
 */
int crearMenu(int* retorno,char items[], int desde, int hasta)
 {
    do
    {
        printf("%s", items);
        *retorno=0;
        getInt(retorno,"Ingrese una opcion","Error, intente nuevamente\n", desde,hasta);
    }while(*retorno<desde||*retorno>hasta);
    return 0;
}

/** \brief Funcion para tomar un entero largo positivo del usuario
 *
 * \param puntero para el retorno del entero ingresado
 * \param Mensaje para pedirle al usuario que ingrese un numero
 * \param Mensaje de error
 * \param numero minimo a aceptar
 * \param numero maximo a aceptar
 * \return 0 si se ingreso el numero correctamento -1 si hubo un error
 *
 */
int getUnsignedLongInt(unsigned long int* retorno, char msg[], char errormsg[], int minimo,int maximo)
{
    char aux[1024];
    unsigned long int valor=0;
    printf("%s\n",msg);
    scanf(" %s%*[^\n]",aux);
    if(strcmp(aux,"0\0")==0)
    {
        valor=0.00;
    }
    else if((valor=atoi(aux))==0||(valor<minimo||valor>maximo))
    {
        printf("%s",errormsg);
        return -1;
    }
    *retorno=valor;
    return 0;

}




/** \brief verificar si lo que se ingreso es un numero
 *
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numerico 0 si no lo es
 *
 */
int esNumerico(char str[])
{
	int i =0;
	while(str[i]!='\0')
	{
		if(str[i]<'0'||str[i]>'9')
		{
			return 0;
		}
		i++;
	}
	return 1;
}

/** \brief verificar si lo que se ingreso son solo letras
 *
 * \param str Array con la cadena a ser analizada
 * \return 1 si son solo letras 0 si no lo son
 *
 */
int esSoloLetras(char str[])
{
	int i =0;
	while(str[i]!='\0')
	{
		if((str[i]!=' ')&&(str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z'))
		{
			return 0;
		}
		i++;
	}
	return 1;
}

/** \brief verificar si lo que se ingreso es un telefono
 *
 * \param str Array con la cadena a ser analizada
 * \return 1 si es telefono 0 si no lo es
 *
 */
int esTelefono(char str[])
{
	int i =0;
	int contadorGuiones=0;
	while(str[i]!='\0')
	{
		if((str[i]!=' ')&&(str[i]<'0'||str[i]>'9')&&(str[i]!='-')&&(str[i]!='+'))
		{
			return 0;
		}
		if(str[i]=='-')
        {
            contadorGuiones++;
        }
		i++;
	}
	if(contadorGuiones==1) //Un solo guion
    {
        return 1;
    }
	return 0;
}

/** \brief verificar si lo que se ingreso es alfanumerico
 *
 * \param str Array con la cadena a ser analizada
 * \return 1 si es alfanumerico 0 si no lo es
 *
 */
int esAlfanumerico(char str[])
{
	int i =0;
	while(str[i]!='\0')
	{
		if((str[i]!=' ')&&(str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z')&&(str[i]<'0'||str[i]>'9'))
		{
			return 0;
		}
		i++;
	}
	return 1;
}

