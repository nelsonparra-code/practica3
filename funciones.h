#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <cmath>

using namespace std;

//Funcion que transforma un numero binario a decimal.
int binTOdec(long long);

//Funcion que recibe una cadena (string), la transforma a binario y retorna el conjunto de bits.
string toBin(string);

//Funcion que separa una cadena (string) en grupos de "sep" elementos.
void sepBin(string, string, int, int);

/*Funcion que lee el contenido en el archivo toReadFile,
 * en la direccion C:/Users/Usuario/infoii/practica3/sesion1/BD/...
 * y retorna lo leido.*/
string readInFile(string);

//Funcion que escribe en el archivo toWriteFile, el texto content en la direccion C:/Users/Usuario/infoii/practica3/sesion1/BD/...
void writeInFile(string, string, string);

/*Funcion que codifica una cadena (string) de bits segun el primer metodo.
 * seed es la semilla. codeMethod es el metodo de codificacion.
 * inputFile el archivo que se leera.
 * outputFile el archivo que resultara de la codificacion.*/
void codeFile(int, int, string, string);

//Funcion que decodifica una cadena (string) de bits segun el primer metodo.
void decodeFile(int, int, string, string);
#endif // FUNCIONES_H
