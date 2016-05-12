#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAX_USER 200
#define MAX_COMMENT 1000

typedef struct
{
    char nickname[51];
    char name[51];
    char eMail[51];
    int password;
    int status;
} EUser;

typedef struct
{
    char nickname[51];
    int commentId;
    int likesCounter;
    char commentText[51];
    int status;
} EComments;




int initializeUserArrayStatus(EUser lista[],int length);
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



/*
int findCommentById(EUser book[], EComments author[], int userArrayLenght, int authorArrayLenght, int auxSearch);
int ordenarLista(EUser lista[],int length);
int printBookList(EUser lista[],int length);
int printAuthorList(EComments lista[],int length);
int imprimirGrafico(EUser lista[],int length);
int menorMayor(EUser lista[],int length);
int crearMenu(int* retorno,char items[], int desde, int hasta);
*/
#endif // FUNCIONES_H_INCLUDED
