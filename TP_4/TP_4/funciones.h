#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct{
    char title[51];
    char nationality[51];
    int year;
    char director[51];
    int id;
}E_Movie;

E_Movie* newMovie(void);
int compareMovie(void* pMovieA,void* pMovieB);
void printEMovie(E_Movie* p);
void printArrayListMovie(ArrayList* lista);
E_Movie* findId(ArrayList* lista);
int setMovieId(ArrayList* lista, E_Movie* oneMovie);
int setMovieYear(E_Movie* oneMovie);
int setMovieTitle(E_Movie* oneMovie);
int setMovieDirector(E_Movie* oneMovie);
int setMovieNationality(E_Movie* oneMovie);
int modifyMovie(ArrayList* movies,E_Movie* oneMovie);
int addMoviesToFile(ArrayList* lista, E_Movie* oneMovie, ArrayList* sublistMovies);
E_Movie* hardCodeMovie(char title[51],char country[51],int year, char director[51], int id);
int ManageFavoriteMovies(ArrayList* movies, E_Movie* oneMovie, ArrayList* sublistMovies);



#endif // FUNCIONES_H_INCLUDED
