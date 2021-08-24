#include <funciones.h>

using namespace std;

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

void sepBin(string cadBin, string *cadAlmac, int sep, int lim){
    int var=0, st=0;
    /*En este ciclo, se va concatenando, cada elemento
     * de la cadena de binarios, a la posicion 'var' del arreglo cadAlmac*/
    for(int i=0;i<lim;i++){
        cadAlmac[var]+=cadBin[i];
        if(i==(st+(sep-1))){
            var++;
            st+=sep;
        }
    }
}

string readInFile(string toReadFile){
    string data;

    ifstream rFile;
    rFile.open("C:/Users/Usuario/infoii/practica3/sesion1/BD/"+toReadFile);
    if (!rFile.is_open())
       {
         cout << "Error abriendo el archivo." << endl;
         exit(1);
       }
    rFile>>data;
    rFile.close();

    return data;
}

void writeInFile(string toWriteFile, string content, string operation){
    ofstream wFile;
    wFile.open("C:/Users/Usuario/infoii/practica3/sesion1/BD/"+toWriteFile);
    if (!wFile.is_open())
       {
         cout << "Error abriendo el archivo." << endl;
         exit(1);
       }
    wFile<<content;
    wFile.close();

    if(operation=="code") cout<<"Archivo codificado satisfactoriamente."<<endl;
    else cout<<"Archivo decodificado satisfactoriamente."<<endl;

}

void codeFile(int seed, int codeMethod, string inputFile, string outputFile){

    /*Se invoca a la funcion readInFile() para leer el contenido del archivo "inputFile",
     * y almacenarlo en la variable "datos"*/
    string datos = readInFile(inputFile);

    /*Se realizan calculos para determinar la cantidad de "bits" que ocupa "datos".
     * Luego, con "arrSize" se determina el tamaño del arreglo que contendra
     * los grupos de "seed" bits codificados. Y, el calculo del residuo es empleado
     * cuando los bits no son divisibles entre "seed", entonces se suma una posicion para completar.*/
    int bits=datos.length()*8, arrSize=bits/seed, res = bits%seed;
    if(res!=0) arrSize++;
    string modArr[arrSize];
    string codedMessage;

    /*Se verifica el metodo de codificacion.*/
    if(codeMethod==1){
        /*Variable binary almacena el contenido del archivo en binario.
         * separatedArray almacena el arreglo de los grupos de "seed" bits sin codificar.
         *
         * Ejemplo: binary = 1111, seed = 2, separatedArray = {"11", "11"}*/
        string binary = toBin(datos), separatedArray[arrSize];
        sepBin(binary,separatedArray,seed,bits);

        for(int i=0;i<(arrSize-1);i++){

            string arrElem1 = separatedArray[i], arrElem2 = separatedArray[i+1];

            /*Al ser la primera operacion, simplemente se cambian los 1s por 0s y viceversa.*/
            if(i==0){
                int toModSize=arrElem1.length();
                for(int count=0;count<toModSize;count++){
                    if(arrElem1[count]=='0') modArr[i]+='1';
                    else if(arrElem1[count]=='1') modArr[i]+='0';
                }
            }

            /*Se cuentan de 1s y 0s de la cadena de los primeros n bits.*/
            int zeros=0,ones=0,countLim=arrElem1.length();
            for(int count=0;count<countLim;count++){
                if(arrElem1[count]=='0') zeros++;
                else if(arrElem1[count]=='1') ones++;
            }

            /*Se establecen condicionales para realizar alguna operacion segun sea el caso.*/
            if(zeros==ones){
                int toModSize=arrElem2.length();
                /*Se utiliza el for para recorrer los n bits y asi cambiar el valor de 1 por 0, y viceversa,
                 * y concatenarlo a la posicion 'i+1' del arreglo modArr. Es la posicion 'i+1' dado que
                 * el conteo esta retrasado en uno a causa de la primera modificacion. (cuando i==0)*/
                for(int count=0;count<toModSize;count++){
                    if(arrElem2[count]=='0') modArr[i+1]+='1';
                    else if(arrElem2[count]=='1') modArr[i+1]+='0';
                }
            }
            else if(zeros>ones){
                int toModSize=arrElem2.length();
                /*Se utiliza el for para recorrer los n bits y asi cambiar el valor de 1 por 0, y viceversa,
                 * cada 2 bits (es la razon del condicional adicional 'count%2==1',
                 * tomando en cuenta que cada 2 bits las posiciones con impares)
                 * y concatenarlo a la posicion 'i+1' del arreglo modArr.*/
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
                /*Se utiliza el for para recorrer los n bits y asi cambiar el valor de 1 por 0, y viceversa,
                 * cada 3 bits (es la razon del condicional adicional 'count==cond' y la operacion 'cond+=3',
                 * siendo 'cond' una variable auxiliar que ayuda a saber cual es la posicion al cumplirse los 3 bits)
                 * y concatenarlo a la posicion 'i+1' del arreglo modArr.*/
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

    else if(codeMethod==2){
        /*Variable binary almacena el contenido del archivo en binario.
         * separatedArray almacena el arreglo de los grupos de "seed" bits sin codificar.
         *
         * Ejemplo: binary = 1111, seed = 2, separatedArray = {"11", "11"}*/
        string binary = toBin(datos),separatedArray[arrSize];
        sepBin(binary,separatedArray,seed,bits);

        for(int i=0;i<arrSize;i++){

            string arrElem = separatedArray[i];

            int toModSize=arrElem.length();

            for(int count=(toModSize-1);count>=0;count--){

                if(count<(toModSize-1)) modArr[i] += arrElem[(toModSize-2)-count];
                else modArr[i] += arrElem[count];

            }
        }
    }
    for(int i=0;i<arrSize;i++){
        codedMessage+=modArr[i];
    }
    writeInFile(outputFile,codedMessage,"code");
}

void decodeFile(int seed, int codeMethod, string inputFile, string outputFile){

    /*Se invoca a la funcion readInFile() para leer el contenido del archivo "inputFile",
     * y almacenarlo en la variable "datos"*/
    string datos = readInFile(inputFile);

    /*Se realizan calculos para determinar la cantidad de "bits" que ocupa "datos".
     * Luego, con "arrSize" se determina el tamaño del arreglo que contendra
     * los grupos de "seed" bits codificados. Y, el calculo del residuo es empleado
     * cuando los bits no son divisibles entre "seed", entonces se suma una posicion para completar.*/
    int bits=datos.length(), arrSize=bits/seed, res = bits%seed;
    if(res!=0) arrSize++;

    string cadenaF,array[arrSize],modArr[arrSize],bytesArr[bits/8],unify;
    sepBin(datos,array,seed,bits);


    if(codeMethod==1){

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
    }
    else if(codeMethod==2){
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

            /*Un conjunto de bits es transformado a decimal.*/
            int num=binTOdec(stoi(bytesArr[count]));

            /*El decimal es transformado a caracter.*/
            cadenaF+=static_cast<char>(num);
        }
    }
    writeInFile(outputFile,cadenaF,"decode");
}
