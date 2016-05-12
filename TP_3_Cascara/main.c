#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"


int main()
{
    EMovie movie[MAXIMO];
    initializeMovierArrayStatus(movie,MAXIMO);
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        crearMenu(&opcion, "1- Agregar pelicula\n2- Borrar pelicula\n3- Generar pagina web\n4- Salir\n",1,4);

        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
