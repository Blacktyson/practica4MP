//
// Created by jotace on 17/3/22.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/calculos.h"
#include <iomanip>
using namespace std;

const int FILAS_BASE = 366;
const int COLS_BASE = 4;


/*while (!mesCorrecto(ExtraerMes(mes)){

    cout <<"Mes incorrecto, inserte otro mes"
    cin > mes;

 }*/
int main()
{
    float M[FILAS_BASE][COLS_BASE];

    // cargar valores usando redirección de entrada
    for(int i = 0; i < FILAS_BASE; i++){
        for(int j = 0; j < COLS_BASE; j++){
            cin >> M[i][j];
        }
    }

    // muestro los datos leídos - OPCION 1

    for (int i = 0; i < FILAS_BASE; i++) {
        cout << endl;
        for (int j = 0; j < COLS_BASE; j++)
            cout << M[i][j] << "\t";

    }
    cout << endl;


    //1era funcion:
    /*int menorValor, mayorValor, diferencia;

    valoresExtremosAnuales(M,mayorValor,menorValor,diferencia);

    cout <<"Mayor valor: "<< mayorValor << "."<<endl;
    cout <<"Menor valor: "<< menorValor << "."<<endl;
    cout <<"Diferencias: "<< diferencia << "."<<endl;
*/

}
