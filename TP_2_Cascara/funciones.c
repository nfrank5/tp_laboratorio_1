#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "../../miLib/misFunciones.h"
#include <string.h>
#include <ctype.h>
/**
 * Obtiene el primer indice libre del array.
 * /param el array de la estructura
 * /param puntero para indicar el indice del espacio libre
 * /return 1 si hay espacio libre -1 si no lo hay
 */
int obtenerEspacioLibre(EPersona lista[],int*aux)
{
    int i;
    int flagEncontrado=0;
    for(i=0;i<MAXIMO;i++)
    {
        if(lista[i].estado==0)
        {
            *aux=i;
            flagEncontrado=1;
        }
    }
    if(flagEncontrado==0)
    {
        system("clear");
        printf("No hay espacio libre\n");
        return -1;
    }
    else
    {
        return 1;
    }


}

/** \brief Agregar una persona
 *
 * \param el array de la estructura
 * \param el puntero del indice del array
 * \return 1 si se agrego la persona -1 si el DNI es duplicado
 *
 */
int agregarPersona(EPersona lista[],int*aux)
{
    system("clear");
    int i;
    unsigned long int auxDni;
    while(getInt(&lista[*aux].edad,"Ingrese edad: ","Error, intente nuevamente[0-110]\n",0,110)==-1);
    while(getUnsignedLongInt(&auxDni,"Ingrese dni: ","Error, intente nuevamente [10Millones-60Millones]\n",10000000,99000000)==-1);
    for(i=0;i<MAXIMO;i++)
    {
        if(auxDni==lista[i].dni&&lista[i].estado==1)
        {
            printf("DNI duplicado\n");
            return -1;
        }
        else
        {
            lista[*aux].dni=auxDni;
        }

    }
    while(getString(lista[*aux].nombre,"Ingrese su nombre: ","Error, intente nuevamente",1,51)==-1);
    lista[*aux].estado=1;

    return 1;
}

/** \brief busca a una persona por el DNI
 *
 * \param El array de la estructura
 * \param un puntero para retornar el indica de la persona
 * \return 1 encontrado -1 no se encontro
 *
 */
int buscarPorDni(EPersona lista[],int*aux)
{
    unsigned long int auxDNI;
    int i, flagEncontrado=0;
    printf("Ingrese el DNI\n");
    scanf("%lu",&auxDNI);
    for(i=0;i<MAXIMO;i++)
    {
        if((auxDNI==lista[i].dni)&&lista[i].estado==1)
        {
            flagEncontrado=1;
            *aux=i;
            system("clear");
            return  1;
        }
    }
    if(flagEncontrado==0)
    {
        system("clear");
        printf("No se encontró el DNI\n");
    }
    return -1;
}

/** \brief Imprimi una lista de todas la personas ordenado por su nombre
 *
 * \param el array de la estructura
 * \return 1
 *
 */
int imprimirLista(EPersona persona[])
{
    int i,j,t,largo1,largo2;
    char auxNombreUno[51],auxNombreDos[51];
    EPersona auxPersona;
    for(i=0;i<MAXIMO-1;i++)
    {
        for(j=i+1;j<MAXIMO;j++)
        {
            if(persona[i].estado==1&&persona[j].estado==1)
            {
                strcpy(auxNombreUno,persona[i].nombre);
                strcpy(auxNombreDos,persona[j].nombre);
                largo1=strlen(auxNombreUno);
                largo2=strlen(auxNombreDos);
                for(t=0;t<largo1; t++)
                {
                    auxNombreUno[t] = tolower(auxNombreUno[t]);
                }
                for(t=0;t<largo2; t++)
                {
                    auxNombreDos[t] = tolower(auxNombreDos[t]);
                }
                if(strcmp(auxNombreUno,auxNombreDos)>0)
                {
                    auxPersona=persona[i];
                    persona[i]=persona[j];
                    persona[j]=auxPersona;
                }
            }

        }
    }
    system("clear");
    printf("Edad\t\tDNI\t\tNombre\n");
    for(i=0;i<MAXIMO;i++)
    {
        if(persona[i].estado==1)
        {
            printf("%d\t\t",persona[i].edad);
            printf("%lu\t",persona[i].dni);
            printf("%s\n",persona[i].nombre);
        }
    }

    return 1;
}

/** \brief inicializa el estado en todos los indices del array de la estructura
 *
 * \param el array de la estructura
 * \return 1
 *
 */
int inicializarEstado(EPersona persona[])
{
    int i;
    for(i=0;i<MAXIMO;i++) //inicializo flag de estado
    {
        persona[i].estado=0;
    }
    return 1;
}

/** \brief borra a la persona seleccionada por el usuario
 *
 * \param el array de la estructura
 * \param un puntero con el indice de la persona elegida para ser borrado
 * \return 0 si fue eliminada -1 si no lo fue
 *
 */
int borrarPersona(EPersona lista[],int*aux)
{
    char auxBorrado='n';
    if(lista[*aux].estado==1)
    {
        printf("Usted va a eliminar a %s.\n",lista[*aux].nombre);
        validarS_N(&auxBorrado);
        if(auxBorrado=='s')
        {
            lista[*aux].estado=0;
            printf("Persona eliminada\n");
            return 0;
        }
    }
    else
    {
        printf("Error, no existe la persona\n");
    }
    return -1;
}

/** \brief imprime un grafico con un asterisco por persona en cada rango de edad
 *
 * \param el array de la estructura
 * \return 1
 *
 */
int imprimirGrafico(EPersona lista[])
{
    int i,j,contador18Menos=0,contador19A35=0,contador35Mas=0;
    system("clear");
    for(i=0;i<MAXIMO;i++) //creo contadores de cada rango de edad
    {
        if(lista[i].edad<=18&&lista[i].edad>=0&&lista[i].estado==1)
        {
            contador18Menos++;
        }
        else if(lista[i].edad>18&&lista[i].edad<=35&&lista[i].estado==1)
        {
            contador19A35++;
        }
        else if(lista[i].edad>35&&lista[i].edad<=110&&lista[i].estado==1)
        {
            contador35Mas++;
        }
    }
    for(i=0;i<MAXIMO;i++) //imprimo
    {
        for(j=0;j<3;j++)
        {
            if(j==0)
            {
                if(i>=(MAXIMO-contador18Menos))
                {
                    printf(" * \t");
                }
                else
                {
                    printf("   \t");
                }
            }
            if(j==1)
            {
                if(i>=(MAXIMO-contador19A35))
                {
                    printf(" * \t");
                }
                else
                {
                    printf("   \t");
                }

            }
            if(j==2)
            {
                if(i>=(MAXIMO-contador35Mas))
                {
                    printf(" * \n");
                }
                else
                {
                    printf("   \n");
                }
            }
        }
    }

    printf("<18\t19-35\t>35\t\n");
    return 1;
}
