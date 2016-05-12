#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAXIMO 5

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int status;
}EMovie;

int initializeMovierArrayStatus(EMovie lista[],int length);



/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);


/*
int initializeCommentArrayStatus(EComments lista[],int length);
int obtenerEspacioLibre(EUser lista[],int*i,int length);
int addItem(EUser lista[],EComments commentArray[],int*aux,int length,int lengthComment);
int findUserByNick(EUser lista[],int*aux,int length);
int deleteUser(EUser lista[],int*aux,int length);
int modifyUser(EUser lista[],EComments commentArray[],int*aux,int length,int lengthComment);


int obtenerEspacioLibreComments(EComments lista[],int*aux,int length);
int newComment(EUser lista[],EComments commentArray[],int*aux,int length,int lengthComment);
int newLike(EComments lista[],int length,EUser userArray[],int lengthUser);

int printInformar(EComments lista[],int length);
int printUserCommentList(EUser userArray[],EComments commentArray[],int authorArrayLenght,int userArrayLenght);




int findCommentById(EUser book[], EComments author[], int userArrayLenght, int authorArrayLenght, int auxSearch);
int ordenarLista(EUser lista[],int length);
int printBookList(EUser lista[],int length);
int printAuthorList(EComments lista[],int length);
int imprimirGrafico(EUser lista[],int length);
int menorMayor(EUser lista[],int length);
int crearMenu(int* retorno,char items[], int desde, int hasta);
*/

#endif // FUNCIONES_H_INCLUDED
