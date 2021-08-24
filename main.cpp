#include <iostream>
#include <fstream>
#include <funciones.h>

using namespace std;

int main()
{

    //funcion(semilla, metodo, archivoEntrada, archivoSalida)
    //El control si es codificacion o decodificacion, se hace en el main

    /*La variable n es un numero menor al tamano de la cadena de texto multiplicado por 8: "<(tamanocadena*8)".
    O, menor al tamano de la cadena binaria.*/
    int n,method;
    string infileN, outfileN, procedure;

    cout<<"Ingrese nombre del archivo de entrada (junto con su extension): ";
    //cin>>infileN;
    infileN="sm.txt";

    cout<<"Ingrese nombre del archivo de salida (junto con su extension): ";
    //cin>>outfileN;
    outfileN="dsmTEST.txt";

    cout<<"Para codificar un archivo, ingrese 1"<<endl;
    cout<<"Para decodificar un archivo, ingrese 0"<<endl;
    cout<<"Escriba el procedimiento a seguir: ";
    //cin>>procedure;
    procedure="0";

    cout<<"Ingrese semilla para codificar: ";
    //cin>>n;
    n=4;

    cout<<"Ingrese metodo de codificacion (1 o 2): ";
    //cin>>method;
    method=2;

    if(procedure=="1"){
        codeFile(n,method,infileN,outfileN);
    }

    else if(procedure=="0"){
        decodeFile(n,method,infileN,outfileN);
    }
    else cout<<"Opcion invalida."<<endl;

    system("PAUSE");
    return 0;
}
