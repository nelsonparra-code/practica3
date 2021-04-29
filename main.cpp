#include <iostream>
#include <fstream>
#include <funciones.h>

using namespace std;

int main()
{

    int n,method;
    string infileN, outfileN, procedure;

    cout<<"Ingrese nombre del archivo de entrada (junto con su extension): ";
    cin>>infileN;
    cout<<"Ingrese nombre del archivo de salida (junto con su extension): ";
    cin>>outfileN;
    cout<<"Para codificar un archivo, ingrese la palabra: code."<<endl;
    cout<<"Para decodificar un archivo, ingrese la palabra: decode."<<endl;
    cout<<"Escriba el procedimiento a seguir: ";
    cin>>procedure;
    cout<<"Ingrese semilla para codificar: ";
    cin>>n;
    cout<<"Ingrese metodo de codificacion: ";
    cin>>method;

    string datos;

    ifstream rFile;
    rFile.open("../sesion1/BD/"+infileN);
    if (!rFile.is_open())
       {
         cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    rFile>>datos;
    rFile.close();

    if(procedure=="code"){
        int strlength=datos.length()*8, tamArr=strlength/n, res = strlength%n;
        if(res!=0) tamArr++;
        string codifiedArray[tamArr];

        if(method==1) code1m(datos,codifiedArray,tamArr,n,strlength);
        else if(method==2) code2m(datos,codifiedArray,tamArr,n,strlength);


        ofstream wFile;
        wFile.open("../sesion1/BD/"+outfileN);
        for(int i=0;i<tamArr;i++){
            wFile<<codifiedArray[i];
        }
        wFile.close();

        cout<<"Archivo codificado satisfactoriamente."<<endl;
    }
    else if(procedure=="decode"){
        int strlength=datos.length(), tamArr=strlength/n, res = strlength%n;
        if(res!=0) tamArr++;

        string menDecodif;
        if(method==1) menDecodif = decode1m(datos,tamArr,n,strlength);
        else if(method==2) menDecodif = decode2m(datos,tamArr,n,strlength);


        ofstream wFile;
        wFile.open("../sesion1/BD/"+outfileN);
        wFile<<menDecodif;
        wFile.close();

        cout<<"Archivo decodificado satisfactoriamente."<<endl;
    }

    return 0;
}
