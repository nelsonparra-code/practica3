#include <iostream>
#include <funciones.h>

using namespace std;

/* El programa requiere estar ubicado dentro de un directorio llamado 'sesion1'.
 *
 * Los archivos dentro de lectura (bases de dato) en un directorio llamado 'BD' dentro de 'sesion1'.
 *
 * La aplicacion tiene la condicion de que solo se codifica o decodifica la primera linea (sin espacios) de un archivo.
 *
 * En la carpeta BD hay unos archivos de prueba, por ejemplo: A.txt (original), codedA.txt (archivo codificado con la aplicacion)
 * y decodedA.txt (decodificacion con la aplicacion).
 *
 * El formato de codificacion de los archivos (archivo,metodo,semilla), cumple con:
 * (A.txt,1,3),(B.txt,2,7),(C.txt,2,6),(D.txt,1,9),(E.txt,2,2)*/

int main()
{
    /*La variable n debe ser un numero menor al tamano de la cadena de texto multiplicado por 8: "<(tamanocadena*8)".
    O, menor al tamano de la cadena binaria.*/
    int semilla;
    int method;
    int procedure;
    string infileN;
    string outfileN;

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

    if(procedure==1){
        codeFile(semilla,method,infileN,outfileN);
    }

    else if(procedure==0){
        decodeFile(semilla,method,infileN,outfileN);
    }
    else cout<<"Opcion invalida."<<endl;

    system("PAUSE");
    return 0;
}
