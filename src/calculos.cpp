

//if (año%100 = 0 and año %4 = 0)
//  es_bisiesto = true;
// Created by jotace on 17/3/22.
//

#include "../include/calculos.h"
#include <iostream>
using namespace std;
float mayorTemperatura(const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], bool original, int mes){
    float resultado;
    if (original){

    int j = 2;
    resultado = anio [0][j];
    for (int i = 0; i < MAX_F; i++){

        if (anio[i][j] > resultado){

            resultado = anio[i][j];

        }

    }
    }
    else{
        resultado = M[mes][0];
        for (int i = 0; i < MAX_CNEW; i++ ){

            if (anio[mes][i] > resultado){

                resultado = anio[mes][i];

            }

        }

    }

    return resultado;

}
float menorTemperatura(const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], bool original, int mes){

    float resultado;

    if (original) {
        int j = 3;
        resultado = anio[0][j];
        for (int i = 0; i < MAX_F; i++) {

            if (anio[i][j] < resultado) {

                resultado = anio[i][j];

            }

        }
    }   else{
        resultado = M[mes][0];
        for (int i = 0; i < MAX_CNEW; i++ ){

            if (anio[mes][i] < resultado){

                resultado = anio[mes][i];

            }

        }

    }


    return resultado;
}

float amplitudTermica(const float anio[MAX_F][MAX_C]){


    float resultado = (anio[0][2] - anio[0][3]);

    for (int i = 0; i < MAX_F; i++){

        if ((anio[i][2] - anio[i][3]) > resultado){

            resultado = (anio[i][2] - anio[i][3]);

        }

    }

    return resultado;

}


void valoresExtremosAnuales (const float anio[MAX_F][MAX_C], float &warm_day, float &cold_day, float &difference){

    warm_day = mayorTemperatura(anio, 0, true, -1);
    cold_day = menorTemperatura(anio, 0, true, -1);
    difference = amplitudTermica(anio);

}
void ExtraeDatos(const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], int col){

    int contador = 0;
    float mostrG,mostrP,mostrD;
    bool mesPeque;

    for (int i = 0; i < MAX_FNEW; i++){
        mesPeque = false;
        for (int j = 0; j <MAX_CNEW &&!mesPeque; j++){

            if ((anio[contador][0] == MAX_CNEW - 2 or anio[contador][0] == MAX_CNEW - 1)  and anio [contador+1][0] == 1){
                if (anio[contador][0] == MAX_CNEW - 2){

                    M[i][j] = anio[contador][col];
                    mostrP = M[i][j];
                    M[i][j+1] = MARCA_FIN;
                    mostrP = M[i][j+1];
                    M[i][j+2] = MARCA_FIN;
                    mostrP = M[i][j+2];
                    contador++;
                    mesPeque = true;


                }
                else if (anio[contador][0] == MAX_CNEW -1 and !mesPeque){
                    M[i][j] = anio[contador][col];
                    mostrP = M[i][j];
                    M[i][j+1] = MARCA_FIN;
                    mostrP = M[i][j];
                    contador++;
                    mesPeque = true;
                }

            }
            else{

            M[i][j] = anio[contador][col];

            contador++;
            }
        }
    }
}
float mediaMensualAjustada (const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], int tipoTemperatura, string mes){

    float suma = 0;
    float media;
    int MostrM;
    MostrM = extraerMes(mes);
    ExtraeDatos(anio,M, tipoTemperatura);
    for (int i = 0; i < MAX_CNEW; i++){

        suma += M[extraerMes(mes)][i];
    }
    media = suma/MAX_CNEW;
    return media;
}
int extraerMes(string mes){

    int resultado;
    pasarAMinuscula(mes);
    if(mes == "enero"){
        resultado = 0;
    }
    else if(mes == "febrero"){
        resultado = 1;
    }else if(mes == "marzo"){
        resultado = 2;
    }else if(mes == "abril"){
        resultado = 3;
    }else if(mes == "mayo"){
        resultado = 4;
    }else if(mes == "junio"){
        resultado = 5;
    }else if(mes == "julio"){
        resultado = 6;
    }else if(mes == "agosto"){
        resultado = 7;
    }else if(mes == "septiembre"){
        resultado = 8;
    }else if(mes == "octubre"){
        resultado = 9;
    }else if(mes == "noviembre"){
        resultado = 10;
    }else if(mes == "diciembre"){
        resultado = 11;
    }
    else
        resultado = -1;
    return resultado;
}

void pasarAMinuscula(string &mes){
    for (int i = 0; i < mes.size(); i++){
        mes[i] = tolower(mes[i]);
    }
}

bool mesCorrecto(int numMes){

    bool correcto = false;

    if (numMes !=-1){

        correcto = true;

    }
    return correcto;
}

void valoresExtremos(const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], float& valorMax, float& valorMin, string mes){

    extraerMes(mes);

    ExtraeDatos(anio,M, 2);
    limpiador(M);
    ExtraeDatos(anio, M, 3);

    valorMax = mayorTemperatura(anio,M,false, extraerMes(mes));
    valorMin = menorTemperatura(anio, M, false, extraerMes(mes));

}

void limpiador(float M[MAX_FNEW][MAX_CNEW]){
    for (int i = 0; i < MAX_FNEW; i++){
        for (int j = 0; j < MAX_CNEW; j++){
            M[i][j] = 0;
        }
    }
}

void menu(const float anio[MAX_F][MAX_C], float Maux[MAX_FNEW][MAX_CNEW]){

    char enter;
    int valorIntroducido;
    string separator = "=================================================================================";

    cout << "BIENVENIDO/A AL MENÚ DE LA PRÁCTICA DE MATRICES"<<endl<<"Realizado por Montes Ronda Juan Carlos 1ºD3"<<endl<<"A continuación se le mostrarán las opciones.";

    cout << endl<<separator<<endl;

    cout << "1. Leer matriz anual."<<endl;
    cout << "2. Generar matriz por temperaturas."<<endl;
    cout << "3. Obtener los valores mayores, menores y la mayor amplitud anual"<<endl;
    cout << "4. Obtener la media de las temperaturas de un mes"<<endl;
    cout << "5. Obtener valores minimos y maximos de un mes";
    cout << endl<<separator<<endl;
    cout << "0. Salir del menú y cerrar el programa"<<endl;
    cout << separator<<endl;
    cout << "Inserte el número equivalente a la opción deseada: "<<endl;
    cin >> valorIntroducido;
    while (!valorIntroducidoCorrecto(valorIntroducido)){

        cout << "La opcion pedida no corresponde a ninguna opcion"<<endl;
        cin >> valorIntroducido;

    }

    cout << "ok";

    opcionesSwitcher(valorIntroducido,anio,Maux);

}
bool valorIntroducidoCorrecto(int valor){
    bool incorrecto = false;
    if (valor!=0 or valor!=1 or valor!=2 or valor!=3 or valor!=4 or valor!=5){

        incorrecto = true;

    }
    return incorrecto;
}
void opcionesSwitcher(int valor,const float anio[MAX_F][MAX_C], float Maux[MAX_FNEW][MAX_CNEW]){

    bool anual;

    switch (valor) {

        case 1:
            anual = true;
            lectorMatriz(anio,Maux,anual,0);



    }


}
void lectorMatriz(const float anio[MAX_F][MAX_C], float Maux[MAX_FNEW][MAX_CNEW], bool anual, int col){

    if (anual){

        for (int i = 0; i < MAX_F; i++) {
            cout << endl;
            for (int j = 0; j < MAX_C; j++)
                cout << anio[i][j] << "\t";

        }
        cout << endl;

    }
    else
        ExtraeDatos(anio, Maux, col);
        for (int i = 0; i <MAX_FNEW; i++){
            for (int j = 0; j < MAX_CNEW; j++){
              cout << Maux[i][j] << "\t";
            }
            cout <<endl;
        }



}