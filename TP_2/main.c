#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../miLib/misFunciones.h"
#include "funciones.h"
#define MAXIMO 20

/** \brief Funcion con Altas y bajas de personas que puede listar ordenado alfabeticamente e imprimir un grafico de las personas ordenado por grupos de edad
 *
 * \param No se ingresan parametros
 * \return No se devuelven parametros
 *
 */
int main()
{
    char seguir='s';
    int opcion=0;
    int i=0;
    EPersona persona[MAXIMO];
    inicializarEstado(persona,MAXIMO); //Inicializo el estado de todo el array como libre;
    while(seguir=='s')
    {
        crearMenu(&opcion,"1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por nombre \n4- Imprimir grafico de edades\n5- Salir\n",1,5);
        switch(opcion)
        {
            case 1:
                if(obtenerEspacioLibre(persona,&i,MAXIMO)==0) //busco espacio libre para agregar persona
                {
                    agregarPersona(persona,&i,MAXIMO); //agrego persona
                }
                break;
            case 2:
                if(buscarPorDni(persona,&i,MAXIMO)==0) //busco por DNI para hacer la baja
                {
                    borrarPersona(persona,&i,MAXIMO); //borro a la persona
                }
                break;
            case 3:
                if(imprimirLista(persona,MAXIMO)==0); //Imprimo la lista ordenada alfabeticamente
                break;
            case 4:
                imprimirGrafico(persona,MAXIMO); //Imprimo un asterisco por persona en cada grupo
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
