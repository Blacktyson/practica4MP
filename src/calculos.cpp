
// Created by Montes Ronda Juan Carlos on 17/3/22.
//

#include "../include/calculos.h"
#include <iostream>

using namespace std;

float mayorTemperatura(const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], bool original, int mes) {
    float resultado;
    if (original) {

        int j = 2;
        resultado = anio[0][j];
        for (int i = 0; i < MAX_F; i++) {

            if (anio[i][j] > resultado) {

                resultado = anio[i][j];

            }

        }
    } else {
        resultado = M[mes][0];
        for (int i = 0; i < MAX_CNEW; i++) {

            if (anio[mes][i] > resultado) {

                resultado = anio[mes][i];

            }

        }

    }

    return resultado;

}

float menorTemperatura(const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], bool original, int mes) {

    float resultado;

    if (original) {
        int j = 3;
        resultado = anio[0][j];
        for (int i = 0; i < MAX_F; i++) {

            if (anio[i][j] < resultado) {

                resultado = anio[i][j];

            }

        }
    } else {
        resultado = M[mes][0];
        for (int i = 0; i < MAX_CNEW; i++) {

            if (anio[mes][i] < resultado) {

                resultado = anio[mes][i];

            }

        }

    }


    return resultado;
}

float amplitudTermica(const float anio[MAX_F][MAX_C]) {


    float resultado = (anio[0][2] - anio[0][3]);

    for (int i = 0; i < MAX_F; i++) {

        if ((anio[i][2] - anio[i][3]) > resultado) {

            resultado = (anio[i][2] - anio[i][3]);

        }

    }

    return resultado;

}


void valoresExtremosAnuales(const float anio[MAX_F][MAX_C], float &warm_day, float &cold_day, float &difference) {

    warm_day = mayorTemperatura(anio, nullptr, true, -1);
    cold_day = menorTemperatura(anio, nullptr, true, -1);
    difference = amplitudTermica(anio);

}

bool ExtraeDatos(const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], int col) {

    int contador = 0;
    bool mesPeque;

    for (int i = 0; i < MAX_FNEW; i++) {
        mesPeque = false;
        for (int j = 0; j < MAX_CNEW && !mesPeque; j++) {

            if ((anio[contador][0] == MAX_CNEW - 2 or anio[contador][0] == MAX_CNEW - 1) and
                anio[contador + 1][0] == 1) {
                if (anio[contador][0] == MAX_CNEW - 2) {

                    M[i][j] = anio[contador][col];
                    M[i][j + 1] = MARCA_FIN;
                    M[i][j + 2] = MARCA_FIN;
                    contador++;
                    mesPeque = true;


                } else if (anio[contador][0] == MAX_CNEW - 1 and !mesPeque) {
                    M[i][j] = anio[contador][col];
                    M[i][j + 1] = MARCA_FIN;
                    contador++;
                    mesPeque = true;
                }

            } else {

                M[i][j] = anio[contador][col];

                contador++;
            }
        }
    }
    return true;
}

float mediaMensualAjustada(float M[MAX_FNEW][MAX_CNEW], const string &mes) {

    float suma = 0;
    float media;
    for (int i = 0; i < MAX_CNEW; i++) {

        suma += M[extraerMes(mes)][i];
    }
    media = suma / MAX_CNEW;
    return media;
}

int extraerMes(string mes) {

    int resultado;
    pasarAMinuscula(mes);
    if (mes == "enero") {
        resultado = 0;
    } else if (mes == "febrero") {
        resultado = 1;
    } else if (mes == "marzo") {
        resultado = 2;
    } else if (mes == "abril") {
        resultado = 3;
    } else if (mes == "mayo") {
        resultado = 4;
    } else if (mes == "junio") {
        resultado = 5;
    } else if (mes == "julio") {
        resultado = 6;
    } else if (mes == "agosto") {
        resultado = 7;
    } else if (mes == "septiembre") {
        resultado = 8;
    } else if (mes == "octubre") {
        resultado = 9;
    } else if (mes == "noviembre") {
        resultado = 10;
    } else if (mes == "diciembre") {
        resultado = 11;
    } else
        resultado = -1;
    return resultado;
}

void pasarAMinuscula(string &mes) {
    for (char &me: mes) {
        me = tolower(me);
    }
}

bool mesCorrecto(int numMes) {

    bool correcto = false;

    if (numMes != -1) {

        correcto = true;

    }
    return correcto;
}

void valoresExtremos(const float anio[MAX_F][MAX_C], float M[MAX_FNEW][MAX_CNEW], float &valorMax, float &valorMin,
                     string &mes) {

    extraerMes(mes);
    limpiador(M);
    ExtraeDatos(anio, M, 2);
    limpiador(M);
    ExtraeDatos(anio, M, 3);

    valorMax = mayorTemperatura(anio, M, false, extraerMes(mes));
    valorMin = menorTemperatura(anio, M, false, extraerMes(mes));

}

void limpiador(float M[MAX_FNEW][MAX_CNEW]) {
    for (int i = 0; i < MAX_FNEW; i++) {
        for (int j = 0; j < MAX_CNEW; j++) {
            M[i][j] = 0;
        }
    }
}

void menu(const float anio[MAX_F][MAX_C], float Maux[MAX_FNEW][MAX_CNEW]) {

    char enter;
    int valorIntroducido = 100000000;
    bool extraida = false;
    int ultimaCol = 0;
    float valorMin, valorMax, difference;
    string mes;


    string separator = "=================================================================================";

    cout << endl << "BIENVENIDO/A AL MENÚ DE LA PRÁCTICA DE MATRICES" << endl
         << "Realizado por Montes Ronda Juan Carlos 1ºD3" << endl << "A continuación se le mostrarán las opciones.";

    cout << endl << separator << endl;
    while (valorIntroducido != 0) {
        cout << endl;
        cout << "1. Leer matriz anual." << endl;
        cout << "2. Generar matriz por temperaturas." << endl;
        cout << "3. Leer matriz por temperaturas." << endl;
        cout << "4. Obtener los valores mayores, menores y la mayor amplitud anual" << endl;
        cout << "5. Obtener la media de las temperaturas de un mes" << endl;
        cout << "6. Obtener valores minimos y maximos de un mes" << endl;
        cout << "7. Acerca del proyecto (?)" << endl;
        cout << endl << separator << endl;
        cout << "0. Salir del menú y cerrar el programa" << endl;
        cout << separator << endl;
        cout << "Inserte el número equivalente a la opción deseada: " << endl;
        cin >> valorIntroducido;
        if (!valorIntroducidoCorrecto(valorIntroducido)) {
            while (!valorIntroducidoCorrecto(valorIntroducido)) {

                cout << "La opcion pedida no corresponde a ninguna opcion" << endl;
                cin >> valorIntroducido;


            }
        }
        if (valorIntroducido == 2) {
            extraida = true;

        }

        opcionesSwitcher(valorIntroducido, anio, Maux, extraida, ultimaCol, valorMin, valorMax, difference, mes);
        if (valorIntroducido != 0) {
            cout << " Inserte cualquier letra para volver al menú" << endl;
            cin >> enter;
        }
    }
}

bool valorIntroducidoCorrecto(int valor) {
    bool incorrecto = false;
    if (valor >= 0 and valor < 8) {

        incorrecto = true;

    }
    return incorrecto;
}

void opcionesSwitcher(int valor, const float anio[MAX_F][MAX_C], float Maux[MAX_FNEW][MAX_CNEW], bool &extraida,
                      int &ultimaCol, float &valorMin, float &valorMax, float &difference, string &mes) {

    int tipoTemperatura;
    string queTemperatura;
    if (ultimaCol == 2) {

        queTemperatura = "maximas";

    } else if (ultimaCol == 3) {
        queTemperatura = "minimas";
    }

    switch (valor) {

        case 1:
            extraida = false;
            lectorMatriz(anio, Maux, extraida, 0);
            break;
        case 2:
            cout << "Inserte el tipo de temperatura (2 maximas) (3 minimas): " << endl;
            cin >> tipoTemperatura;
            while (tipoTemperatura < 2 or tipoTemperatura > 3) {
                cout << "Has introducido un valor incorrecto. (2 maximas) (3 minimas): " << endl;
                cin >> tipoTemperatura;


            }
            extraida = ExtraeDatos(anio, Maux, tipoTemperatura);
            cout << "Matriz extraida correctamente" << endl;
            break;
        case 3:
            if (!extraida) {
                while (!extraida) {

                    cout
                            << "Primero debes etraer la matriz de datos. Inserte el tipo de temperatura (2 maximas) (3 minimas): "
                            << endl;
                    cin >> tipoTemperatura;
                    while (tipoTemperatura < 2 or tipoTemperatura > 3) {
                        cout << "Has introducido un valor incorrecto. (2 maximas) (3 minimas): " << endl;
                        cin >> tipoTemperatura;
                    }
                    extraida = ExtraeDatos(anio, Maux, tipoTemperatura);
                    cout << "Matriz extraida correctamente" << endl;

                }
                lectorMatriz(anio, Maux, extraida, tipoTemperatura);
            } else if (extraida) {

                lectorMatriz(anio, Maux, extraida, ultimaCol);
            }
            break;
        case 4:
            valoresExtremosAnuales(anio, valorMax, valorMin, difference);
            cout << "Temperatura más alta del año: " << valorMax << "." << endl;
            cout << "Temperatura más pequeña del año: " << valorMin << "." << endl;
            cout << "Mayor amplitud térmica: " << difference << "." << endl;
            break;
        case 5:
            if (!extraida) {
                while (!extraida) {

                    cout
                            << "Primero debes etraer la matriz de datos. Inserte el tipo de temperatura (2 maximas) (3 minimas): "
                            << endl;
                    cin >> tipoTemperatura;
                    while (tipoTemperatura < 2 or tipoTemperatura > 3) {
                        cout << "Has introducido un valor incorrecto. (2 maximas) (3 minimas): " << endl;
                        cin >> tipoTemperatura;
                    }
                    extraida = ExtraeDatos(anio, Maux, tipoTemperatura);
                    cout << "Matriz extraida correctamente" << endl;
                }
                cout << "Inserte el mes: " << endl;
                cin >> mes;
                while (!mesCorrecto(extraerMes(mes))) {

                    cout << "El mes introducido no existe. Vuelva a escribirlo: " << endl;
                    cin >> mes;
                }
                cout << "La media de temperaturas " << queTemperatura << " del mes de " << mes << " es de: "
                     << mediaMensualAjustada(Maux, mes) << endl;
            } else if (extraida) {
                cout << "Inserte el mes: " << endl;
                cin >> mes;
                while (!mesCorrecto(extraerMes(mes))) {

                    cout << "El mes introducido no existe. Vuelva a escribirlo: " << endl;
                    cin >> mes;
                }

                cout << "La media de temperaturas " << queTemperatura << " del mes de " << mes << " es de: "
                     << mediaMensualAjustada(Maux, mes) << endl;
            }
            break;
        case 6:
            if (!extraida) {
                while (!extraida) {

                    cout << "Matriz de datos generada automáticamente..." << endl;
                    extraida = ExtraeDatos(anio, Maux, 2);

                }
                cout << "Inserte el mes: " << endl;
                cin >> mes;
                while (!mesCorrecto(extraerMes(mes))) {

                    cout << "El mes introducido no existe. Vuelva a escribirlo: " << endl;
                    cin >> mes;
                }
                valoresExtremos(anio, Maux, valorMax, valorMin, mes);
                cout << "La temperatura minima del mes de " << mes << " es de: " << valorMin << endl;
                cout << "La temperatura máxima del mes de " << mes << " es de: " << valorMax << endl;
            } else if (extraida) {
                cout << "Inserte el mes: " << endl;
                cin >> mes;
                while (!mesCorrecto(extraerMes(mes))) {

                    cout << "El mes introducido no existe. Vuelva a escribirlo: " << endl;
                    cin >> mes;
                }

                valoresExtremos(anio, Maux, valorMax, valorMin, mes);
                cout << "La temperatura minima del mes de " << mes << " es de: " << valorMin << endl;
                cout << "La temperatura máxima del mes de " << mes << " es de: " << valorMax << endl;


            }
            break;
        case 7:
            acercaDe();
            break;
    }

    ultimaCol = tipoTemperatura;

}

void lectorMatriz(const float anio[MAX_F][MAX_C], float Maux[MAX_FNEW][MAX_CNEW], bool extraida, int col) {

    if (!extraida) {

        for (int i = 0; i < MAX_F; i++) {
            cout << endl;
            for (int j = 0; j < MAX_C; j++)
                cout << anio[i][j] << "\t";

        }
        cout << endl;

    } else if (extraida) {
        ExtraeDatos(anio, Maux, col);
        for (int i = 0; i < MAX_FNEW; i++) {
            for (int j = 0; j < MAX_CNEW; j++) {
                cout << Maux[i][j] << "\t";
            }
            cout << endl;
        }
    }
}

void acercaDe() {
    cout
            << "Este proyecto ha sido realizado con muchas horas de trabajo para que el formato visual sea lo mejor posible."
            << endl;
    cout
            << "Se redactará un readme donde se explicará todo lo del proyecto así mismo como en el .h estarán especificadas lo que hacen cada una de las funciones"
            << endl;
    cout << "Realizado por Montes Ronda Juan Carlos 1ºD3" << endl;
}