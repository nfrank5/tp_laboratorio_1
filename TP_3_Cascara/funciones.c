#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "utn.h"

/** \brief funcion que carga los datos de una pelicula en la estructura EMovie
 *
 * \param puntero a la estructura
 * \return 0 si fue exitoso de lo contrario -1
 *
 */

int cargarPeliculaEstructura(EMovie* movie)
{
    int retorno=-1;
    if(movie!=NULL)
    {
        while(getString(movie->titulo,"Ingrese el titulo de la pelicula: ","Error, intente nuevamente",1,51)==-1);
        while(getString(movie->genero,"Ingrese el genero de la pelicula: ","Error, intente nuevamente",1,21)==-1);
        while(getInt(&movie->duracion,"Ingrese la duracion de la pelicula: ","Error, intente nuevamente[1-600]",1,600)==-1);
        while(getString(movie->descripcion,"Ingrese la descripcion de la pelicula: ","Error, intente nuevamente",1,512)==-1);
        while(getInt(&movie->puntaje,"Ingrese el puntaje de la pelicula: ","Error, intente nuevamente[1-100]",1,100)==-1);
        while(getString(movie->linkImagen,"Ingrese el link de la imagen de la pelicula: ","Error, intente nuevamente",1,151)==-1);
        movie->status=1;
        retorno=0;

    }
    else
    {
        printf("Error, No cargo la estructura\n");
    }

    return retorno;
}


/**
 *  \brief Agrega una pelicula al archivo binario
 *  \param movie la estructura a ser agregada al archivo
 *  \return retorna -1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie * movie)
{
    system("@cls||clear");
    int retorno=-1;
    FILE * peliculasArchivo;
    if(movie!=NULL)
    {
        if((peliculasArchivo = fopen("peliculasArchivo.dat","ab"))==NULL)
        {
            printf("El archivo no puede ser abierto");
            return retorno;
        }
        fwrite(movie,sizeof(EMovie),1,peliculasArchivo);
        if(fclose(peliculasArchivo)==-1)
        {
            printf("No se pudo cerrar el archivo\n");
        }
        else
        {
            printf("El archivo se cerro exitosamente\n");
            retorno=0;
        }
    }
    else
    {
        printf("Error, No cargo la estructura\n");
    }
    return retorno;
}



/**
 *  Borra una pelicula del archivo binario
 *  \param movie la estructura a ser eliminada al archivo
 *  \return retorna -1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie * movie)
{
    system("@cls||clear");
    int retorno=-1;
    int flagEncontrado=0;
    char auxSearchMovie[51];
    FILE * auxPeliculas;
    if(movie!=NULL)
    {
        if((auxPeliculas = fopen("peliculasArchivo.dat","r+b"))==NULL)
        {
            printf("El archivo no puede ser abierto");
            exit(1);
        }
        while(getString(auxSearchMovie,"Ingrese el titulo de la pelicula: ","Error, intente nuevamente",1,51)==-1);
        rewind(auxPeliculas);
        while(fread(movie,sizeof(EMovie),1,auxPeliculas)!=0)
        {
            if(movie->status==1)
            {
                if(strcmp(movie->titulo,auxSearchMovie)==0)
                {
                    movie->status=0;
                    fseek(auxPeliculas,-sizeof(EMovie),SEEK_CUR);
                    fwrite(movie,sizeof(EMovie),1,auxPeliculas);
                    printf("Pelicula eliminada\n");
                    flagEncontrado=1;
                    retorno=0;
                }

            }
        }
        if(flagEncontrado==0)
        {
            printf("La pelicula no existe\n");
        }
    }
    return retorno;
}


/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  \param estructura EMovie para cargar la pelicula
 *  \param nombre el nombre para el archivo.
 */
void generarPagina(EMovie * movie,char nombre[])
{
    system("@cls||clear");
    char ch;
    FILE * auxPeliculas,* HTML,* parteUno,* parteDos;
    if(movie!=NULL)
    {
        if((auxPeliculas = fopen("peliculasArchivo.dat","r+b"))==NULL)
        {
            printf("El archivo no puede ser abierto");
            exit(1);
        }
        if((HTML = fopen(nombre,"w"))==NULL)
        {
            printf("El archivo no puede ser abierto");
            exit(1);
        }
        if((parteUno = fopen("parte_uno.txt","r+"))==NULL)
        {
            printf("El archivo no puede ser abierto");
            exit(1);
        }
        if((parteDos = fopen("parte_dos.txt","r+"))==NULL)
        {
            printf("El archivo no puede ser abierto");
            exit(1);
        }
        while (1)
        {
            ch = fgetc(parteUno);
            if (ch == EOF)
            {
                break;
            }
            else
            {
                putc(ch, HTML);
            }
        }
        while(fread(movie,sizeof(EMovie),1,auxPeliculas)!=0)
        {
            if(movie->status==1)
            {
                fprintf(HTML,"<article class='col-md-4 article-intro'><a href='#'>");
                fprintf(HTML,"<img class='img-responsive img-rounded' src='%s' alt=''>\n",movie->linkImagen);
                fprintf(HTML,"</a><h3><a href='#'>%s</a>",movie->titulo);
                fprintf(HTML,"</h3><ul><li>Género:%s</li>",movie->genero);
                fprintf(HTML,"<li>Puntaje:%d</li>",movie->puntaje);
                fprintf(HTML,"<li>Duración:%d</li></ul>",movie->duracion);
                fprintf(HTML,"<p>%s</p></article>",movie->descripcion);
            }
        }

        while (1)
        {
            ch = fgetc(parteDos);
            if (ch == EOF)
            {
                break;
            }
            else
            {
                putc(ch, HTML);
            }
        }
        if(fclose(auxPeliculas)!=0||fclose(HTML)!=0||fclose(parteUno)!=0||fclose(parteDos)!=0)
        {
            printf("Hubo un error al cerrar los archivos\n");
        }
        else
        {
            printf("HTML generado con exito\n");
        }
    }
    return;
}



/** \brief funcion que permite modificar los datos de una pelicula
 *
 * \param estructura Emovie
 * \return retorna -1 o 0 de acuerdo a si pudo modificar la pelicula o no
 *
 */
int modificarPelicula(EMovie * movie)
{
    int retorno=-1;
    int opcion;
    int flagSearch=0;
    char continuar='s';
    char auxSearchMovie[51];
    FILE * auxPeliculas;
    if(movie!=NULL)
    {
        if((auxPeliculas = fopen("peliculasArchivo.dat","r+b"))==NULL)
        {
            printf("El archivo no puede ser abierto");
            exit(1);
        }
        while(getString(auxSearchMovie,"Ingrese el titulo de la pelicula: ","Error, intente nuevamente",1,51)==-1);
        rewind(auxPeliculas);
        while(fread(movie,sizeof(EMovie),1,auxPeliculas)!=0)
        {
            if(movie->status==1)
            {
                if(strcmp(movie->titulo,auxSearchMovie)==0)
                {
                    flagSearch=1;
                    while(continuar=='s')
                    {
                        printf("¿Que desea modificar?\n");
                        crearMenu(&opcion,"1-titulo\n2-genero\n3-duracion\n4-descripcion\n5-puntaje\n6-linkImagen\n7-salir\n",1,7);
                        switch(opcion)
                        {
                            case 1:
                                while(getString(movie->titulo,"Ingrese el titulo de la pelicula: ","Error, intente nuevamente",1,51)==-1);
                                break;
                            case 2:
                                 while(getString(movie->genero,"Ingrese el genero de la pelicula: ","Error, intente nuevamente",1,21)==-1);
                                 break;
                            case 3:
                                while(getInt(&movie->duracion,"Ingrese la duracion de la pelicula: ","Error, intente nuevamente[1-600]",1,600)==-1);
                                break;
                            case 4:
                                while(getString(movie->descripcion,"Ingrese la descripcion de la pelicula: ","Error, intente nuevamente",1,512)==-1);
                                break;
                            case 5:
                                while(getInt(&movie->puntaje,"Ingrese el puntaje de la pelicula: ","Error, intente nuevamente[1-100]",1,100)==-1);
                                break;
                            case 6:
                                while(getString(movie->linkImagen,"Ingrese el link de la imagen de la pelicula: ","Error, intente nuevamente",1,151)==-1);
                                break;
                            case 7:
                                continuar='n';
                                break;
                        }
                        fseek(auxPeliculas,-sizeof(EMovie),SEEK_CUR);
                        fwrite(movie,sizeof(EMovie),1,auxPeliculas);
                        printf("Pelicula modificada\n");
                        retorno=0;
                    }
                }
            }
        }
        if(flagSearch==0)
        {
            printf("La pelicula no existe\n");
        }
    }
    return retorno;
}
