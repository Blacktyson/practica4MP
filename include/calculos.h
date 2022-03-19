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
int menorTemperatura(float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], bool original, int mes);
int mayorTemperatura(float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], bool original, int mes);
int amplitudTermica(const float anio[MAX_F][MAX_C]);
void valoresExtremosAnuales (const float anio[MAX_F][MAX_C], int &warm_day, int &cold_day, int &difference);
void ExtraeDatos(const float anio[MAX_F][MAX_C], float M[12][31], int col);
float mediaMensualAjustada (const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], int tipoTemperatura, string mes);
int extraerMes (string mes);
void pasarAMinuscula(string &mes);
bool mesCorrecto(int numMes);
void valoresExtremos(const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW],float MMenor[MAX_FNEW][MAX_CNEW], int &valorMax, int &valorMin, string mes);
void limpiador(float M[MAX_FNEW][MAX_CNEW]);




#endif //PRACTICA4_CALCULOS_H
