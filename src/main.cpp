//
// Created by jotace on 17/3/22.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/calculos.h"
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int FILAS_BASE = 366;
const int COLS_BASE = 4;


/*while (!mesCorrecto(ExtraerMes(mes)){

    cout <<"Mes incorrecto, inserte otro mes"
    cin > mes;

 }*/
int main(int argc, char *argv[])
{
    float M[FILAS_BASE][COLS_BASE];
    float Maux[MAX_FNEW][MAX_CNEW];



    /*cargar valores usando redirección de entrada
    for(int i = 0; i < FILAS_BASE; i++){
        for(int j = 0; j < COLS_BASE; j++){
            cin >> M[i][j];
        }
    }


     //muestro los datos leídos - OPCION 1
    for (int i = 0; i < FILAS_BASE; i++) {
        cout << endl;
        for (int j = 0; j < COLS_BASE; j++)
            cout << M[i][j] << "\t";

    }
    cout << endl;

    //1era funcion:
    float menorValor, mayorValor, diferencia;

    valoresExtremosAnuales(M,mayorValor,menorValor,diferencia);

    cout <<"Mayor valor: "<< mayorValor << "."<<endl;
    cout <<"Menor valor: "<< menorValor << "."<<endl;
    cout <<"Diferencias: "<< diferencia << "."<<endl;

    //2a funcion:
    ExtraeDatos(M,Maux,2);
    for (int i = 0; i <MAX_FNEW; i++){
        for (int j = 0; j < MAX_CNEW; j++){
            cout << Maux[i][j] << "\t";
        }
        cout <<endl;
    }
    //3a funcion:

    //cout <<mediaMensualAjustada(M,Maux,2,"enero")<<endl;
    float suma = 0;
    for (int i = 0; i < MAX_CNEW; i++){

        suma += Maux[1][i];

    }
    suma = suma /31;
    cout << suma<<endl;
    limpiador(Maux);
    cout <<mediaMensualAjustada(M,Maux,2,"febrero")<<endl;


    //4a funcion:
    float tempMax, tempMin;
    limpiador(Maux);
    valoresExtremos(M,Maux,tempMax,tempMin,"enero");
    cout << "Max: "<<tempMax <<". Min: "<<tempMin<<endl;


*/

    //Entrada por fichero:

    ifstream  f(argv[1]);
    for(int i = 0; i<FILAS_BASE; ++i )
    {
        for( int j=0; j<COLS_BASE; ++j )
            f >> M[i][j];
    }

    menu(M,Maux);






    return 0;
    }
