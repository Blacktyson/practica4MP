//
// Created by Montes Ronda Juan Carlos on 17/3/22.
//

const int MAX_F = 366;
const int MAX_C = 4;
const float MARCA_FIN = 31;
const int MAX_FNEW = 12;
const int MAX_CNEW = 31;
#include <iostream>
using namespace std;

#ifndef PRACTICA4_CALCULOS_H
#define PRACTICA4_CALCULOS_H
/**
 * @brief extrae el menor valor de la matriz elegida
 * @param anio: matriz general
 * @param M: matriz reducida
 * @param original: controla si se trabaja sobre la matriz general o la reducida
 * @param mes: en caso de ser reducida, se elige el mes sobre que se trabaja
 * @pre original controla que matriz usar
 * @return menor valor
 * */
float menorTemperatura(const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], bool original, int mes);
/**
 * @brief extrae el mayor valor de la matriz elegida
 * @param anio: matriz general
 * @param M: matriz reducida
 * @param original: controla si se trabaja sobre la matriz general o la reducida
 * @param mes: en caso de ser reducida, se elige el mes sobre que se trabaja
 * @pre original controla que matriz usar
 * @return mayor valor
 * */
float mayorTemperatura(const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], bool original, int mes);
/**
 * @brief calcula la mayor diferencia de temperatura anual.
 * @param anio: matriz sobre la que se trabaja.
 * @return la mayor diferencia entre temperaturas.
 * */
float amplitudTermica(const float anio[MAX_F][MAX_C]);
/**
 * @brief saca el mayor y el menor valor de una matriz, así como la diferencia de temperaturas.
 * @param anio: matriz sobre la que se trabaja.
 * @param warm_day: variable por referencia donde se guardará el mayor valor.
 * @param cold_day: variable por referencia donde se guardará el menor valor.
 * @param difference: variable por referencia donde se guardará la diferencia.
 * */
void valoresExtremosAnuales (const float anio[MAX_F][MAX_C], float &warm_day, float &cold_day, float &difference);
/**
 * @brief reduce la matriz general a matriz reducida.
 * @param anio: matriz general.
 * @param M: referencia donde se guardará la matriz reducida.
 * @param col: tipo de temperatura con la que se trabajará.
 * @return true cuando se realiza la reducción.
 * */
bool ExtraeDatos(const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], int col);
/**
 * @brief obtiene la media de las temperaturas de un mes.
 * @param M: matriz reducida con la que se trabajará.
 * @param mes: mes sobre el que se trabajará.
 * @return media de temperaturas.
 * */
float mediaMensualAjustada (float M[MAX_FNEW][MAX_CNEW], const string& mes);
/**
 * @brief extrae el indice del mes pasado por argumento.
 * @param mes: mes sobre el que se trabajará.
 * @return indice del mes.
 * */
int extraerMes (string mes);
/**
 * @brief pasa a minúscula el mes pasado por argumento.
 * @param mes: referencia al string donde se guardará.
 * */
void pasarAMinuscula(string &mes);
/**
 * @brief comprueba que el mes pasado sea correcto.
 * @param numMes: indice del mes introducido
 * @return true si es correcto, false lo contrario.
 * */
bool mesCorrecto(int numMes);
/**
 * @brief Obtiene el mayor y el menor valor de una matriz reducida
 * @param anio: matriz que se reducirá.
 * @param M: referencia donde se reducirá la matriz.
 * @param valorMax: referencia donde se guardará el mayor valor.
 * @param valorMin: referencia donde se guardará el menor valor.
 * @param mes: mes con el que se trabajará.
 * @pre que el mes sea correcto.
 * */
void valoresExtremos(const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], float &valorMax, float &valorMin, string& mes);
/**
 * @brief inicializa una matriz reducida a 0
 * @param M: referencia a la matriz que será inicializada a 0.
 * */
void limpiador(float M[MAX_FNEW][MAX_CNEW]);
/**
 * @brief mostrará el menú principal.
 * @param anio: matriz general.
 * @param Maux: matriz reducida.
 * */
void menu(const float anio[MAX_F][MAX_C], float Maux[MAX_FNEW][MAX_CNEW]);
/**
 * @brief comprueba si la opcion introducida por el usuario es correcta.
 * @param valor: opcion elegida por el usuario.
 * @return true si está dentro de los rangos de las opciones. Else default.
 * */
bool valorIntroducidoCorrecto(int valor);
/**
 * @brief switch que elegirá que hará el programa.
 * @param valor: opción elegida por el usuario.
 * @param anio: matriz general.
 * @param Maux: matriz reducida.
 * @param extraida: referencia que almacena si se ha hecho una reducción.
 * @param ultimaCol: referencia que almacena que tipo de temperaturas ha elegido el usuario.
 * @param valorMin: referencia que almacena el valor minimo extraido.
 * @param valorMax: referencia que almacena el valor máximo extraido.
 * @param difference: referencia que almacena la diferencia de valores máximo y mínimo.
 * @param mes: referencia que almacena el mes con el que se está trabajando.
 * @pre opcion elegida por el usuario correcta. *
 * */
void opcionesSwitcher(int valor,const float anio[MAX_F][MAX_C], float Maux[MAX_FNEW][MAX_CNEW], bool &extraida, int &ultimaCol, float &valorMin, float &valorMax, float &difference, string &mes);
/**
 * @brief imprime por pantalla la matriz que se desea leer.
 * @param anio: matriz general.
 * @param Maux: matriz reducida.
 * @param anual: controla que tipo de matriz se va a imprimir.
 * @param col: tipo de temperatura con la que se va a trabajar.
 * @pre si se ha reducido la matriz general.
 * */
void lectorMatriz(const float anio[MAX_F][MAX_C], float Maux[MAX_FNEW][MAX_CNEW], bool anual, int col);
/**
 * @brief Acerca de la realización del proyecto.
 * */
void acercaDe();
#endif //PRACTICA4_CALCULOS_H
