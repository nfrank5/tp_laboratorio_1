#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAXIMO 5

typedef struct{
    char titulo[51];
    char genero[21];
    int duracion;
    char descripcion[512];
    int puntaje;
    char linkImagen[151];
    int status;
}EMovie;

int cargarPeliculaEstructura(EMovie* movie);
int agregarPelicula(EMovie * movie);
int borrarPelicula(EMovie * movie);
void generarPagina(EMovie * movie,char nombre[]);
int modificarPelicula(EMovie * movie);



#endif // FUNCIONES_H_INCLUDED
