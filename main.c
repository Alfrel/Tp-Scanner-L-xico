#include <stdio.h>
#include <stdlib.h>
typedef enum {
INICIO, FIN, LEER, ESCRIBIR, ID, CONSTANTE, PARENIZQUIERDO,
PARENDERECHO, PUNTOYCOMA, COMA, ASIGNACION, SUMA, RESTA, FDT, ERROR
} TOKEN;

typedef struct {
    char palabraReservada[11];
}PalabraReservada;

PalabraReservada palabrasReservadas[5]={{"inicio"},{"fin"},{"leer"},{"escribir"}};

const int ESTADO_RECHAZO=14;
TOKEN palabraReserv;
FILE * archivo;
int main()
{
    /*Aca hay que invocar a la funcion scanner.
      Hay que hacer las firmas de los metodos */
    return 0;
}

TOKEN analizadorLexico(int tabla[15][13]){
    int estado=0;
    int i=0;
    char buffer[30];

    do{
        char letra = fgetc(archivo);
        estado=tabla[estado][obtenerColumna(letra)];
        if(letra!=' '){
             buffer[i]=letra;
             i++;
        }

    }while(!esEstadoFinal(estado) && estado!=ESTADO_RECHAZO);

    if(esPalabraReservada(buffer))
        return palabraReservada(buffer);

    else
        return obtenerToken();

}


int esEstadoFinal(int estado){
    int esEstadoFinal=0;
    esEstadoFinal=(estado!=0 && estado!=1 && estado!=3 && estado!=ESTADO_RECHAZO)?1:0;
    return esEstadoFinal;
};


int obtenerColumna(int letra){

if(isalpha(letra))return 0;
if(isdigit(letra))return 1;
if (isspace(letra)) return 11;
switch(letra){
case ('+'): return 2;
case ('-'): return 3;
case ('('): return 4;
case (')'): return 5;
case (','): return 6;
case (';'): return 7;
case (':'): return 8;
case ('='): return 9;
case (EOF): return 10;
default: return 12;

}

}

int esPalabraReservada(char buffer[30]){
    return (strcmp("inicio",buffer)||(strcmp("fin",buffer))||(strcmp("leer",buffer))||(strcmp("escribir",buffer)));
}

int palabraReservada(char buffer[30]){
    if(strcmp("inicio",buffer)) return INICIO;
    if(strcmp("fin",buffer))    return FIN;
    if(strcmp("leer",buffer))   return LEER;
    if(strcmp("escribir",buffer))return ESCRIBIR;
    return 0;

}

int obtenerToken(int estado){
switch(estado){
    case 2: return ID;
    case 4: return CONSTANTE;
    case 5: return PARENIZQUIERDO;
    case 6: return PARENDERECHO;
    case 9: return COMA;
    case 10: return PUNTOYCOMA;
    case 12: return ASIGNACION;
    case 13:return FDT;
    case 14: return ERROR;
    default: return 0;
}
}

TOKEN scanner(){
/*Hay que crear la matriz aca y pasarsela por parametro a la funcion de abajo*/
//analizadorLexico(matriz)


}




