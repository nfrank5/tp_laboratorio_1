#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"

int main()
{
    EMovie auxMovie;
    char seguir='s';
    int opcion=0;
    while(seguir=='s')
    {
        crearMenu(&opcion, "1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar Pelicula\n4- Generar pagina web\n5- Salir\n",1,5);

        switch(opcion)
        {
            case 1:
                system("@cls||clear");
                if(cargarPeliculaEstructura(&auxMovie)==0)
                {
                    agregarPelicula(&auxMovie);
                }
                break;
            case 2:
                system("@cls||clear");
                borrarPelicula(&auxMovie);
                break;
            case 3:
                system("@cls||clear");
                modificarPelicula(&auxMovie);
                break;
            case 4:
                system("@cls||clear");
                generarPagina(&auxMovie,"index.html");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
