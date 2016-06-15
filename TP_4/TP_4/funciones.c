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


/** \brief Funcion para determinar si es mayor o menor  una estructura de acuerdo al año
 *
 * \param puntero a un elemento E_movie
 * \param puntero a otro elemento E_movie
 * \return devuelve 1 si pMovieA es mayor y -1 si pMovieB es mayor y 0 si hubo un error o las peliculas son del mismo año
 *
 */
int compareMovie(void* pMovieA,void* pMovieB)
{
    int retorno = 0;
    if(pMovieA!=NULL&&pMovieB!=NULL) //si los punteros son nulos retorna cero y la funcion sort no ordena nada
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

/** \brief Carga el ID de una pelicula en un auxiliar verificando que el ID no se repita con otros que existen en la estructura
 *
 * \param puntero del arraylist
 * \param puntero a una estructura E_Movie
 * \return -1 si hubo un error o si el ID esta repetido y 0 si no esta repetido
 *
 */
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
                return returnAux; // devuelve -1 si esta repetida
            }
        }
    }
    if(oneMovie!= NULL)
    {
        oneMovie->id = idAux; // seteo el ID de la pelicula
        returnAux = 0;
    }
    return returnAux;
}



/** \brief Carga el año de una pelicula en un auxiliar
 *
 * \param el puntero al auxiliar de E_Movie
 * \return -1 si hubo un error y 0 si la carga fue exitosa
 *
 */
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

/** \brief Carga el titulo de una pelicula en un auxiliar
 *
 * \param el puntero al auxiliar de E_Movie
 * \return -1 si hubo un error y 0 si la carga fue exitosa
 *
 */
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

/** \brief Carga el pais de origen de una pelicula en un auxiliar
 *
 * \param el puntero al auxiliar de E_Movie
 * \return -1 si hubo un error y 0 si la carga fue exitosa
 *
 */
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

/** \brief Carga el director de una pelicula en un auxiliar
 *
 * \param el puntero al auxiliar de E_Movie
 * \return -1 si hubo un error y 0 si la carga fue exitosa
 *
 */
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

/** \brief mediante un menu permite hacer modificaciones en una elemento del arraylist
 *
 * \param el puntero al array list
 * \param una estructura E_Movie auxiliar
 * \return -1 si hubo un error y 0 si la modificacion fue exitosa
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
                    if(setMovieDirector(oneMovie)!=0)
                    {
                        return returnAux;
                    }
                    break;
                case 2:
                    if(setMovieYear(oneMovie)!=0)
                    {
                        return returnAux;
                    }
                    break;
                case 3:
                    if(setMovieNationality(oneMovie)!=0)
                    {
                        return returnAux;
                    }
                    break;
                case 4:
                    if(setMovieTitle(oneMovie)!=0)
                    {
                        return returnAux;
                    }
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
 *  \param arraylist de las peliculas
 *  \param E_Movie auxiliar
 *  \param arraylist de favoritas
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

/** \brief carga los datos harcodeados a un arraylist
 *
 * \param title[] char
 * \param country[] char
 * \param year int
 * \param director[] char
 * \param id int
 * \return int Return if Error [NULL pointer] -  if Ok el puntero para
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

/** \brief submenu para manejar las opciones de favoritos
 *
 * \param arraylist de peliculas
 * \param E_Movie Auxiliar
 * \return arraylist de favoritos
 *
 */
int ManageFavoriteMovies(ArrayList* movies, E_Movie* oneMovie,ArrayList* sublistMovies)
{
    int retorno = -1;
    char seguir = 's';
    int manageMenuOption;
    if(movies!=NULL&&oneMovie!=NULL&&sublistMovies!=NULL)
    {
        while(seguir=='s')
        {
            crearMenu(&manageMenuOption,"1-Agregar favorita\n2-Reemplazar pelicula\n3-Imprimir favoritos\n4-Menu principal\n",1,4);
            switch(manageMenuOption)
            {
                case 1:
                    system("@cls||clear");
                    addFavorite(movies,oneMovie,sublistMovies); //Hay que ingresar primero la pelicula en el puesto uno luego dos y luego tres en orden
                    break;
                case 2:
                    system("@cls||clear");
                    replaceFavorite(movies,oneMovie,sublistMovies); //No se reemplazar si no existe una pelicula antes en ese puesto
                    break;
                case 3:
                    system("@cls||clear");
                    if(sublistMovies->isEmpty(sublistMovies)==0) //No se puede imprimir si no hay altas
                    {
                        printArrayListMovie(sublistMovies);
                    }
                    else
                    {
                        printf("No hay favoritas para imprimir\n");
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


/** \brief  agrega una pelicula a favoritos
 *
 * \param arraylist de E_Movie
 * \param un auxiliar de E_Movie
 * \param  un arraylist de favoritos de E_Movie
 * \return -1 si hay un error 0 si carga Ok
 *
 */
int addFavorite(ArrayList* movies, E_Movie* oneMovie,ArrayList* sublistMovies)
{
    int retorno=-1;
    int i;
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
                printf("Pelicula cargada con exito a favoritos\n");
            }
            else
            {
                printf("Error, Ya existe esa pelicula en favoritos");
            }
            if(sublistMovies->len(sublistMovies)>3)
            {
                printf("Se elimino del top 3 a: \n");
                oneMovie = sublistMovies->pop(sublistMovies,3); //se muestra y elimina la pelicula que cae del tercer puesto
                printEMovie(oneMovie);
            }
        }
        retorno=0;
    }
    return retorno;
}


/** \brief  reemplaza una pelicula de favoritos
 *
 * \param arraylist de E_Movie
 * \param un auxiliar de E_Movie
 * \param  un arraylist de favoritos de E_Movie
 * \return -1 si hay un error 0 si carga Ok
 *
 */
int replaceFavorite(ArrayList* movies, E_Movie* oneMovie,ArrayList* sublistMovies)
{
    int auxretorno=-1;
    int i;
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
                    auxretorno = 0;
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
    return auxretorno;

}
