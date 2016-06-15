#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "utn.h"
#include "funciones.h"
#include <string.h>

/** \brief crea en forma dinamica la variable E_Movie
 *
 * \return int Return (NULL) if Error [NULL pointer] - (E_MOVIE*) if Ok
 *
 */
E_Movie* newMovie(void)
{
    E_Movie* returnAux = NULL;
    E_Movie* oneMovie = malloc(sizeof(E_Movie));
    if(oneMovie!= NULL)
    {
        strcpy(oneMovie->director," - ");
        oneMovie->id = -1;
        strcpy(oneMovie->nationality," - ");
        strcpy(oneMovie->title," - ");
        oneMovie->year = 0;
        returnAux = oneMovie;
    }
    return returnAux;
}


/** \brief Funcion para determinar mayor o menor estructura de acuerdo al año
 *
 * \param puntero a un elemento E_movie
 * \param puntero a otro elemento E_movie
 * \return devuelve 1 si pMovieA es mayor y -1 si pMovieB es mayor y o si hubo un error o las peliculas sondel mismo año
 *
 */
int compareMovie(void* pMovieA,void* pMovieB)
{
    int retorno = 0;
    if(pMovieA!=NULL&&pMovieB!=NULL)
    {
        if(((E_Movie*)pMovieA)->year > ((E_Movie*)pMovieB)->year)
        {
            retorno = 1;
        }
        if(((E_Movie*)pMovieA)->year < ((E_Movie*)pMovieB)->year)
        {
            retorno = -1;
        }

    }
    return retorno;


}

/** \brief Imprime una estructura E_Movie
 *
 * \param puntero al elemento a imprimir
 */

void printEMovie(E_Movie* p)
{
    printf("%17s\t\t%d\t%12s\t\t%26s\t\t%d\n",p->director,p->id,p->nationality,p->title,p->year);
}


/** \brief imprime todas las peliculas del arraylist
 *
 * \param puntero al arraylist
 */
void printArrayListMovie(ArrayList* lista)
{
  int i=0;
  printf("Director\t\t\tID\t\tNationality\t\tTitle\t\t\t\tYear\n");
  for(i=0;i<lista->len(lista);i++)
  {
      E_Movie* pAux = lista->get(lista,i);
      printEMovie(pAux);
  }
}

/** \brief busca a una pelicula por el ID
 *
 * \param El array de la estructura
 * \return 1 encontrado NULL no se encontro
 *
 */
E_Movie* findId(ArrayList* lista)
{
    E_Movie* retorno = NULL;
    int scanId, i, flagEncontrado=0;
    E_Movie* auxMovie;
    while(getInt(&scanId,"Ingrese ID pelicula: ","Error, intente nuevamente[0-110]\n",0,999)==-1);

    if(lista!=NULL)
    {
        for(i=0;i<lista->len(lista);i++)
        {
            auxMovie=lista->get(lista,i);
            if(auxMovie->id==scanId)
            {
                flagEncontrado=1;
                retorno=auxMovie;
                return retorno;
            }
        }
        if(flagEncontrado==0)
        {
            system("clear");
            printf("No se encontró el ID\n");
        }
    }
    return retorno;
}


int setMovieId(ArrayList* lista, E_Movie* oneMovie)
{
    int returnAux = -1;
    int idAux, i;
    E_Movie* auxMovie;
    while(getInt(&idAux,"Ingrese ID pelicula: ","Error, intente nuevamente[0-999]\n",0,999)==-1);
    if(lista!=NULL)
    {
        for(i=0;i<lista->len(lista);i++)
        {
            auxMovie=lista->get(lista,i);
            if(auxMovie->id==idAux)
            {
                return returnAux;
            }
        }
    }
    if(oneMovie!= NULL)
    {
        oneMovie->id = idAux;
        returnAux = 0;
    }
    return returnAux;
}


int setMovieYear(E_Movie* oneMovie)
{
    int returnAux = -1;
    int yearAux;
    while(getInt(&yearAux,"Ingrese el año de la pelicula: ","Error, intente nuevamente[1850-2016]\n",1890,2016)==-1);
    if(oneMovie!= NULL)
    {
        oneMovie->year = yearAux;
        returnAux = 0;
    }
    return returnAux;
}


int setMovieTitle(E_Movie* oneMovie)
{
    int returnAux = -1;
    char titleAux[51];
    while(getString(titleAux,"Ingrese el titulo de la pelicula: ","Error, intente nuevamente",1,51)==-1);
    if(oneMovie!= NULL)
    {
        strcpy(oneMovie->title,titleAux);
        returnAux = 0;
    }
    return returnAux;
}



int setMovieNationality(E_Movie* oneMovie)
{
    int returnAux = -1;
    char nationalityAux[51];
    while(getString(nationalityAux,"Ingrese la nacionalidad de la pelicula: ","Error, intente nuevamente",1,51)==-1);
    if(oneMovie!= NULL)
    {
        strcpy(oneMovie->nationality,nationalityAux);
        returnAux = 0;
    }
    return returnAux;
}


int setMovieDirector(E_Movie* oneMovie)
{
    int returnAux = -1;
    char directorAux[51];
    while(getString(directorAux,"Ingrese el director de la pelicula: ","Error, intente nuevamente",1,51)==-1);
    if(oneMovie!= NULL)
    {
        strcpy(oneMovie->director,directorAux);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int modifyMovie(ArrayList* movies, E_Movie* oneMovie)
{
    int returnAux = -1;
    int modifyMenuOption;
    char seguir='s';
    if(movies!=NULL&&oneMovie!=NULL)
    {
        while(seguir=='s')
        {
            crearMenu(&modifyMenuOption,"1-Modificar director\n2-Modificar Año\n3-Modificar Nacionalidad\n4-Modificar Titulo\n5-Menu principal\n",1,6);
            switch(modifyMenuOption)
            {
                case 1:
                    setMovieDirector(oneMovie);
                    break;
                case 2:
                    setMovieYear(oneMovie);
                    break;
                case 3:
                    setMovieNationality(oneMovie);
                    break;
                case 4:
                    setMovieTitle(oneMovie);
                    break;
                case 5:
                    seguir = 'n';
                    returnAux=0;
                    break;
            }
        }
    }
    return returnAux;
}



/**
 *  \brief Agrega una pelicula a un archivo de texto
 *  \param movie la estructura a ser agregada al archivo
 *  \return retorna -1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int addMoviesToFile(ArrayList* lista, E_Movie* oneMovie, ArrayList* sublistMovies)
{
    //system("@cls||clear");
    int retorno=-1;
    int i;
    FILE * peliculasArchivo;
    if(lista!=NULL&&oneMovie!=NULL&&sublistMovies!=NULL)
    {
        if((peliculasArchivo = fopen("peliculasArchivo.txt","w"))==NULL)
        {
            printf("El archivo no puede ser abierto");
            return retorno;
        }
        fprintf(peliculasArchivo,"Director\t\t\tID\t\tNationality\t\tTitle\t\t\t\tYear\n");
        for(i=0;i<lista->len(lista);i++)
        {
            oneMovie = lista->get(lista,i);
            fprintf(peliculasArchivo,"%17s\t\t%d\t%12s\t\t%26s\t\t%d\n",oneMovie->director,oneMovie->id,oneMovie->nationality,oneMovie->title,oneMovie->year);

        }
        fprintf(peliculasArchivo,"Favoritas\n");
        for(i=0;i<sublistMovies->len(sublistMovies);i++)
        {
            fprintf(peliculasArchivo,"Puesto %d\n",i+1);
            oneMovie = sublistMovies->get(sublistMovies,i);
            fprintf(peliculasArchivo,"%17s\t\t%d\t%12s\t\t%26s\t\t%d\n",oneMovie->director,oneMovie->id,oneMovie->nationality,oneMovie->title,oneMovie->year);
        }
        if(fclose(peliculasArchivo)!=0)
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
        printf("Error, No cargo el puntero\n");
    }
    return retorno;
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
E_Movie* hardCodeMovie(char title[51],char country[51],int year, char director[51], int id)
{
    E_Movie* returnAux = NULL;
    E_Movie* pMovie = malloc(sizeof(E_Movie));

    if(pMovie != NULL)
    {

        pMovie->id = id;
        strcpy(pMovie->title,title);
        strcpy(pMovie->nationality,country);
        pMovie->year = year;
        strcpy(pMovie->director,director);
        returnAux = pMovie;
    }

    return returnAux;

}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int ManageFavoriteMovies(ArrayList* movies, E_Movie* oneMovie,ArrayList* sublistMovies)
{
    int retorno = -1;
    char seguir = 's';
    int manageMenuOption,i;
    if(movies!=NULL&&oneMovie!=NULL&&sublistMovies!=NULL)
    {
        while(seguir=='s')
        {
            crearMenu(&manageMenuOption,"1-Agregar favorita\n2-Reemplazar pelicula\n3-Imprimir favoritos\n4-Menu principal\n",1,4);
            switch(manageMenuOption)
            {
                case 1:
                    system("@cls||clear");
                    oneMovie = findId(movies); // Busco la pelicula por ID y la asigno a oneMovie
                    if(oneMovie!=NULL) // si la funcion findId no encuentre el ID devuelve un puntero NULL
                    {
                        while(getInt(&i,"Ingrese el puesto en el que quiere ingresar la pelicula: ","Error, intente nuevamente[1-3]\n",1,3)==-1);
                        if(i>sublistMovies->len(sublistMovies)+1)
                        {
                            printf("No hay suficientes peliculas para ese puesto\n"); //el indice es superior a la cantidad de peliculas favoritas
                        }
                        else
                        {
                            //auxMovie = movies->get(movies,movies->indexOf(movies,oneMovie));
                            if(sublistMovies->contains(sublistMovies,oneMovie)==0) //contains retorna cero si no se encontro el elemento
                            {
                                sublistMovies->push(sublistMovies,i-1,oneMovie); //la primera pelicula pasa al segundo puesto
                                printf("Pelicula cargada a favoritos\n");
                            }
                            else
                            {
                                printf("Ya existe esa pelicula en favoritos");
                            }
                            if(sublistMovies->len(sublistMovies)>3)
                            {
                                printf("Se elimino del top 3 a: \n");
                                oneMovie = sublistMovies->pop(sublistMovies,3); //semuestra i elimina la pelicula que cae del tercer puesto
                                printEMovie(oneMovie);
                            }
                        }
                    }
                    break;
                case 2:
                    system("@cls||clear");
                    if(sublistMovies->isEmpty(sublistMovies)==0)
                    {
                        oneMovie = findId(movies); // Busco la pelicula por ID y la asigno a oneMovie
                        if(oneMovie!=NULL) // si la funcion findId no encuentre el ID devuelve un puntero NULL y si el sublist esta vacio no se puede reemplazar nada
                        {
                            while(getInt(&i,"Ingrese el puesto de la pelicula que quiere reemplazar: ","Error, intente nuevamente[1-3]\n",1,3)==-1);
                            if(i>sublistMovies->len(sublistMovies)+1)
                            {
                                printf("No hay suficientes peliculas para reemplazar ese puesto\n"); //el indice es superior a la cantidad de peliculas favoritas
                            }
                            else
                            {
                                //auxMovie = movies->get(movies,movies->indexOf(movies,oneMovie));
                                if(sublistMovies->contains(sublistMovies,oneMovie)==0)
                                {
                                    sublistMovies->set(sublistMovies,i-1,oneMovie); //la primera pelicula pasa al segundo puesto
                                    printf("Se reemplazo la pelicula\n");
                                }
                                else
                                {
                                    printf("La pelicula ya esta en favoritos\n");
                                }
                            }

                        }
                        else
                        {
                            printf("Error, no es encontro el ID\n");
                        }
                    }
                    else
                    {
                        printf("No hay peliculas favoritas para reemplazar\n");
                    }
                    break;
                case 3:
                    system("@cls||clear");
                    if(sublistMovies->isEmpty(sublistMovies)==0)
                    {
                        printArrayListMovie(sublistMovies);
                    }
                    break;
                case 4:
                    system("@cls||clear");
                    seguir = 'n';
                    retorno=0;
                    break;
            }
        }
    }
    return retorno;
}


