#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"
#include "utn.h"

int main()
{
    E_Movie* p0 = hardCodeMovie("La Guerra de las Galaxias", "EEUU", 1977, "George Lucas" ,1);
    E_Movie* p1 = hardCodeMovie("Volver al futuro", "EEUU", 1985, "Steven Spielberg" ,2);
    E_Movie* p2 = hardCodeMovie("En busca del arca perdida", "EEUU", 1981, "Steven Spielberg" ,3);
    E_Movie* p3 = hardCodeMovie("Brazil", "Reino Unido", 1985, "Terry Gilliam" ,4);
    E_Movie* p4 = hardCodeMovie("Fargo", "EEUU", 1996, "Hermanos Coen" ,5);
    ArrayList* movies = (ArrayList*)al_newArrayList();

    movies->add(movies,p0);
    movies->add(movies,p1);
    movies->add(movies,p2);
    movies->add(movies,p3);
    movies->add(movies,p4);


    ArrayList* sublistMovies = (ArrayList*)al_newArrayList();
    ArrayList* sortMovies = (ArrayList*)al_newArrayList();
    E_Movie* oneMovie;
    int mainMenuOption;
    char seguir='s',c;
    while(seguir=='s')
    {

        crearMenu(&mainMenuOption,"1-Altas peliculas\n2-Modificar datos de una pelicula\n3-Baja de una pelicula\n4-Imprimir todas las peliculas\n5-Ordena por año e imprime peliculas\n6-Exportar a .txt\n7-Top 3 Favoritas\n8-Salir\n",1,9);
        switch(mainMenuOption)
        {
            case 1:
                system("@cls||clear");
                if((oneMovie=newMovie())!=NULL)
                {
                    if(setMovieId(movies, oneMovie)!=0)
                    {
                        printf("ID repetida\n");
                        break;
                    }
                    if(setMovieDirector(oneMovie)!=0) printf("Error carga Director");
                    if(setMovieNationality(oneMovie)!=0) printf("Error carga nacionalidad");
                    if(setMovieTitle(oneMovie)!=0) printf("Error carga titulo");
                    if(setMovieYear(oneMovie)!=0) printf("Error carga año");
                    if(movies->add(movies,oneMovie)!=0) printf("Error carga en arraylist");
                }
                break;
            case 2:
                system("@cls||clear");
                if(movies->isEmpty(movies)==0)  //Si no esta vacio
                {
                    oneMovie = findId(movies);
                    if(oneMovie!=NULL) // si la funcion findId no encuentre el ID devuelve un puntero NULL
                    {
                        if(modifyMovie(movies,oneMovie)!=0)
                        {
                            printf("Hubo un error en la modificacion");
                        }
                    }
                }
                else
                {
                    printf("No hay peliculas cargadas\n");
                }
                break;
            case 3:
                system("@cls||clear");
                if(movies->isEmpty(movies)==0) //Si no esta vacio
                {
                    oneMovie = findId(movies);
                    if(oneMovie!=NULL) // si la funcion findId no encuentre el ID devuelve un puntero NULL aca se verifica
                    {
                        printf("Pelicula eliminada: ");
                        printEMovie(oneMovie);
                        movies->remove(movies,movies->indexOf(movies,oneMovie));

                    }
                }
                else
                {
                    printf("No hay peliculas cargadas\n");
                }
                break;
            case 4:
                system("@cls||clear");
                if(movies->isEmpty(movies)==0)
                {
                    printArrayListMovie(movies);
                }
                else
                {
                    printf("No hay peliculas cargadas\n");
                }
                break;
            case 5:
                system("@cls||clear");
                if(movies->len(movies)>=2)
                {
                    sortMovies =  movies->clone(movies);
                    if(movies->containsAll(movies,sortMovies)==1)
                    {
                        sortMovies->sort(sortMovies,compareMovie,0);
                        printArrayListMovie(sortMovies);
                    }
                }
                else
                {
                    printf("No hay peliculas suficientes\n");
                }
                break;
            case 6:
                system("@cls||clear");
                if(movies->isEmpty(movies)==0)  //Si no esta vacio
                {
                    addMoviesToFile(movies, oneMovie,sublistMovies);
                }
                else
                {
                    printf("No hay peliculas cargadas\n");
                }
                break;
            case 7:
                system("@cls||clear");
                if(movies->isEmpty(movies)==0)  //Si no esta vacio
                {
                    ManageFavoriteMovies(movies,oneMovie,sublistMovies);
                }
                else
                {
                    printf("No hay peliculas cargadas\n");
                }
                break;
            case 8:
                seguir = 'n';
                movies->deleteArrayList(movies);
                sublistMovies->deleteArrayList(sublistMovies);
                sortMovies->deleteArrayList(sortMovies);
                while((c = getchar()) != '\n' && c != EOF);
                break;
        }
    }

    return 0;
}
