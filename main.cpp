#include <iostream>
#include <funciones.h>

using namespace std;

/* IMPORTANTE:
 * Los archivos seran leidos y guardados en la ruta "C:/Users/Usuario/infoii/practica3/sesion1/BD/"
 * Es posible cambiar esta ruta desde el archivo funciones.cpp en readInFile() y writeInFile()*/

int main()
{
    /*La variable n debe ser un numero menor al tamano de la cadena de texto multiplicado por 8: "<(tamanocadena*8)".
    O, menor al tamano de la cadena binaria.*/
    int semilla,method;
    string infileN, outfileN, procedure;

    cout<<"Para codificar un archivo, ingrese 1"<<endl;
    cout<<"Para decodificar un archivo, ingrese 0"<<endl;
    cout<<"Escriba el procedimiento a seguir: ";
    cin>>procedure;

    cout<<"Ingrese metodo de codificacion (1 o 2): ";
    cin>>method;

    cout<<"Ingrese semilla para codificar: ";
    cin>>semilla;

    cout<<"Ingrese nombre del archivo de entrada (junto con su extension): ";
    cin>>infileN;

    cout<<"Ingrese nombre del archivo de salida (junto con su extension): ";
    cin>>outfileN;

    if(procedure=="1"){
        codeFile(semilla,method,infileN,outfileN);
    }

    else if(procedure=="0"){
        decodeFile(semilla,method,infileN,outfileN);
    }
    else cout<<"Opcion invalida."<<endl;

    system("PAUSE");
    return 0;
}
