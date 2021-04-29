#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

//Funcion que transforma un numero binario a decimal.
int binTOdec(long long bin){
    int dec=0,count=0,res;

    while(bin!=0){

        res=bin%10;
        bin/=10;
        dec+=res*pow(2,count);
        count++;
    }

    return dec;
}

//Funcion que recibe una cadena (string), la transforma a binario y retorna el conjunto de bits.
string toBin(string cadena){
    int sizeIn = cadena.length()-1;
    string bit,string1,stringF;
    for(int i=0;i<=sizeIn;i++){
        int n=cadena[i];
        for(int j=0;j<=7;j++){
            bit=to_string(n%2);
            string1+=bit;
            n/=2;
        }
        int sizeOut = string1.length()-1;
        for(int i=0;i<=sizeOut;i++){
            stringF+=string1[sizeOut-i];
        }
        string1.erase(0,8);
    }
    return stringF;
}

//Funcion que separa una cadena (string) en grupos de "sep" elementos.
void sepBin(string cadBin, string *cadAlmac, int sep, int lim){
    int var=0, st=0;
    for(int i=0;i<lim;i++){
        cadAlmac[var]+=cadBin[i];
        if(i==(st+(sep-1))){
            var++;
            st+=sep;
        }
    }
}

//Funcion que codifica una cadena (string) de bits segun el primer metodo.
void code1m(string in,string *modArr,int arrSize,int eTam,int bits){

    string binary,array[arrSize];

    binary = toBin(in);
    sepBin(binary,array,eTam,bits);

    for(int i=0;i<(arrSize-1);i++){

        string arrElem1 = array[i], arrElem2 = array[i+1];

        if(i==0){
            int toModSize=arrElem1.length();
            for(int count=0;count<toModSize;count++){
                if(arrElem1[count]=='0') modArr[i]+='1';
                else if(arrElem1[count]=='1') modArr[i]+='0';
            }
        }

        int zeros=0,ones=0,countLim=arrElem1.length();
        for(int count=0;count<countLim;count++){
            if(arrElem1[count]=='0') zeros++;
            else if(arrElem1[count]=='1') ones++;
        }

        if(zeros==ones){
            int toModSize=arrElem2.length();
            for(int count=0;count<toModSize;count++){
                if(arrElem2[count]=='0') modArr[i+1]+='1';
                else if(arrElem2[count]=='1') modArr[i+1]+='0';
            }
        }
        else if(zeros>ones){
            int toModSize=arrElem2.length();
            for(int count=0;count<toModSize;count++){
                if(count%2==1){
                    if(arrElem2[count]=='0') modArr[i+1]+='1';
                    else if(arrElem2[count]=='1') modArr[i+1]+='0';
                }
                else{
                    if(arrElem2[count]=='0') modArr[i+1]+='0';
                    else if(arrElem2[count]=='1') modArr[i+1]+='1';
                }
            }
        }
        else{
            int toModSize=arrElem2.length(), cond=2;
            for(int count=0;count<toModSize;count++){
                if(count==cond){
                    cond+=3;
                    if(arrElem2[count]=='0') modArr[i+1]+='1';
                    else if(arrElem2[count]=='1') modArr[i+1]+='0';
                }
                else{
                    if(arrElem2[count]=='0') modArr[i+1]+='0';
                    else if(arrElem2[count]=='1') modArr[i+1]+='1';
                }
            }
        }
    }
}

//Funcion que codifica una cadena (string) de bits segun el segundo metodo.
void code2m(string in,string *modArr,int arrSize,int eTam,int bits){

    string binary,array[arrSize];

    binary = toBin(in);
    sepBin(binary,array,eTam,bits);

    for(int i=0;i<arrSize;i++){

        string arrElem = array[i];

        int toModSize=arrElem.length();

        for(int count=(toModSize-1);count>=0;count--){

            if(count<(toModSize-1)) modArr[i] += arrElem[(toModSize-2)-count];
            else modArr[i] += arrElem[count];

        }
    }
}

//Funcion que decodifica una cadena (string) de bits segun el primer metodo.
string decode1m(string in,int arrSize,int eTam,int bits){

    string cadenaF,array[arrSize],modArr[arrSize],bytesArr[bits/8],unify;

    sepBin(in,array,eTam,bits);

    for(int i=0;i<(arrSize-1);i++){

        string arrElem1 = array[i], arrElem2 = array[i+1];

        if(i==0){
            arrElem1 = array[i], arrElem2 = array[i+1];
            int toModSize=arrElem1.length();
            for(int count=0;count<toModSize;count++){
                if(arrElem1[count]=='0') modArr[i]+='1';
                else if(arrElem1[count]=='1') modArr[i]+='0';
            }
        }

        int zeros=0,ones=0,countLim=arrElem1.length();
        arrElem1 = modArr[i], arrElem2 = array[i+1];
        for(int count=0;count<countLim;count++){
            if(arrElem1[count]=='0') zeros++;
            else if(arrElem1[count]=='1') ones++;
        }

        if(zeros==ones){
            int toModSize=arrElem2.length();
            for(int count=0;count<toModSize;count++){
                if(arrElem2[count]=='0') modArr[i+1]+='1';
                else if(arrElem2[count]=='1') modArr[i+1]+='0';
            }
        }
        else if(zeros>ones){
            int toModSize=arrElem2.length();
            for(int count=0;count<toModSize;count++){
                if(count%2==1){
                    if(arrElem2[count]=='0') modArr[i+1]+='1';
                    else if(arrElem2[count]=='1') modArr[i+1]+='0';
                }
                else{
                    if(arrElem2[count]=='0') modArr[i+1]+='0';
                    else if(arrElem2[count]=='1') modArr[i+1]+='1';
                }
            }
        }
        else{
            int toModSize=arrElem2.length(), cond=2;
            for(int count=0;count<toModSize;count++){
                if(count==cond){
                    cond+=3;
                    if(arrElem2[count]=='0') modArr[i+1]+='1';
                    else if(arrElem2[count]=='1') modArr[i+1]+='0';
                }
                else{
                    if(arrElem2[count]=='0') modArr[i+1]+='0';
                    else if(arrElem2[count]=='1') modArr[i+1]+='1';
                }
            }
        }
    }

    for(int h=0;h<arrSize;h++){
        unify+=modArr[h];
    }
    sepBin(unify,bytesArr,8,bits);

    for(int count=0;count<(bits/8);count++){
        int num=binTOdec(stoi(bytesArr[count]));
        cadenaF+=static_cast<char>(num);
    }

    return cadenaF;
}

//Funcion que decodifica una cadena (string) de bits segun el segundo metodo.
string decode2m(string in,int arrSize,int eTam,int bits){

    string cadenaF,array[arrSize],modArr[arrSize],bytesArr[bits/8],unify;

    sepBin(in,array,eTam,bits);

    for(int i=0;i<arrSize;i++){
        int lim = array[i].length();
        for(int j=0;j<lim;j++){
            if(j==(lim-1)) modArr[i]+=array[i][0];
            else modArr[i]+=array[i][j+1];
        }
    }

    for(int h=0;h<arrSize;h++){
        unify+=modArr[h];
    }
    sepBin(unify,bytesArr,8,bits);

    for(int count=0;count<(bits/8);count++){
        int num=binTOdec(stoi(bytesArr[count]));
        cadenaF+=static_cast<char>(num);
    }

    return cadenaF;
}

#endif // FUNCIONES_H
