//
// Created by jotace on 17/3/22.
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
float menorTemperatura(float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], bool original, int mes);
float mayorTemperatura(float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], bool original, int mes);
float amplitudTermica(const float anio[MAX_F][MAX_C]);
void valoresExtremosAnuales (const float anio[MAX_F][MAX_C], float &warm_day, float &cold_day, float &difference);
void ExtraeDatos(const float anio[MAX_F][MAX_C], float M[12][31], int col);
float mediaMensualAjustada (const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], int tipoTemperatura, string mes);
int extraerMes (string mes);
void pasarAMinuscula(string &mes);
bool mesCorrecto(int numMes);
void valoresExtremos(const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], float &valorMax, float &valorMin, string mes);
void limpiador(float M[MAX_FNEW][MAX_CNEW]);
void menu(const float anio[MAX_F][MAX_C], float Maux[MAX_FNEW][MAX_CNEW]);
void escribirMenu();
bool valorIntroducidoCorrecto(int valor);
void opcionesSwitcher(int valor,const float anio[MAX_F][MAX_C], float Maux[MAX_FNEW][MAX_CNEW]);
void lectorMatriz(const float anio[MAX_F][MAX_C], float Maux[MAX_FNEW][MAX_CNEW], bool anual, int col);





#endif //PRACTICA4_CALCULOS_H
