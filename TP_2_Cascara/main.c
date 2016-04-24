#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include "../../miLib/misFunciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int i=0;
    EPersona persona[MAXIMO];
    inicializarEstado(persona);
    while(seguir=='s')
    {
        crearMenu(&opcion,"1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por nombre \n4- Imprimir grafico de edades\n5- Salir\n\n",1,5);
        switch(opcion)
        {
            case 1:
                if(obtenerEspacioLibre(persona,&i)==1)
                {
                    agregarPersona(persona,&i);
                }
                break;
            case 2:
                if(buscarPorDni(persona,&i)==1)
                {
                    borrarPersona(persona,&i);
                }
                break;
            case 3:
                imprimirLista(persona);
                break;
            case 4:
                imprimirGrafico(persona);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
