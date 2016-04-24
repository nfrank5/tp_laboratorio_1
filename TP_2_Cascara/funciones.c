#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "../../miLib/misFunciones.h"
#include <string.h>





/**
 * Obtiene el primer indice libre del array.
 * /param listint obtenerEspacioLibre(EPersona lista[])a el array se pasa como parametro.
 * /return el primer indice disponible
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
 * \return
 *
 */
int agregarPersona(EPersona lista[],int*aux)
{
    system("clear");
    while(getInt(&lista[*aux].edad,"Ingrese edad: ","Error, intente nuevamente[0-110]\n",0,110)==-1);
    while(getUnsignedLongInt(&lista[*aux].dni,"Ingrese dni: ","Error, intente nuevamente[1-900]\n",1,60000000)==-1);
    while(getString(lista[*aux].nombre,"Ingrese su nombre: ","Error, intente nuevamente",1,50)==-1);
    lista[*aux].estado=1;

    return 1;
}


/** \brief
 *
 * \param
 * \param
 * \return
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
        if(auxDNI==lista[i].dni)
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

int imprimirLista(EPersona persona[])
{
    int i,j;
    EPersona auxPersona;
    for(i=0;i<MAXIMO-1;i++)
    {
        for(j=i+1;j<MAXIMO;j++)
        {
            if(strcmp(persona[i].nombre,persona[j].nombre)>0)
            {
                auxPersona=persona[i];
                persona[i]=persona[j];
                persona[j]=auxPersona;
            }
        }
    }
    system("clear");
    printf("DNI\t\tNombre\t\tEdad\n");
    for(i=0;i<MAXIMO;i++)
    {
        if(persona[i].estado==1)
        {
            printf("%lu\t\t",persona[i].dni);
            printf("%s\t\t",persona[i].nombre);
            printf("%d\n",persona[i].edad);
        }
    }

    return 1;
}

int inicializarEstado(EPersona persona[])
{
    int i;
    for(i=0;i<MAXIMO;i++) //inicializo flag de estado
    {
        persona[i].estado=0;
    }
    return 1;
}


int borrarPersona(EPersona lista[],int*aux)
{
    char auxBorrado='n';
    printf("¿Quiere eliminar a %s?(s/n)\n",lista[*aux].nombre);
    scanf(" %c",&auxBorrado);
    if(auxBorrado=='s')
    {
        lista[*aux].estado=0;
        printf("Persona eliminada\n");
    }
    return 1;
}


int imprimirGrafico(EPersona lista[])
{
    char grafico[MAXIMO-1][2];
    //int z=(sizeof(char));
    int i,j,contador18Menos=0,contador19A35=0,contador35Mas=0;
    for(i=0;i<MAXIMO;i++)
    {
        if(lista[i].edad<=18)
        {
            contador18Menos++;

        }
        else if(lista[i].edad>18&&lista[i].edad<=35)
        {
            contador19A35++;
        }
        else if(lista[i].edad>35)
        {
            contador35Mas++;
        }


    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<MAXIMO;j++)
        {
            if(j>(MAXIMO-contador18Menos))
            {
                grafico[i][j]='*';
            }
        }
    }

    for(i=0;i<2;i++)
    {
        for(j=0;j<MAXIMO;j++)
        {
            printf("%c\t",grafico[i][j]);


        }

    }

    return 1;


}
