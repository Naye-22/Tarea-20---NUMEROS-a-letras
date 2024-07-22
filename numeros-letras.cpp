/*
Autor:Nayeli Cruz
Fecha: 2024-07-21
Tema: Programa que convierte números a letras
*/
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const string unidades[]= { " ","uno", "dos", "tres", 
"cuatro","cinco","seis","siete","ocho","nueve"};
const string decenas[]={" ","diez","veinte","treinta",
"cuarenta","cincuenta","sesenta","setenta","ochenta",
"noventa"};
const string centenas[]={" ","cien","doscientos","trescientos",
"cuatrocientos","quinientos","seiscientos","setecientos",
"ochocientos","novecientos"};
const string especiales[] = {"diez","once","doce","trece","catorce","quince","dieciseis",
"diecisiete","dieciocho","diecinueve"};

string GetUnidades(int num)
{
    return unidades[num];
}

string GetDecenas(int num)
{
    if (num < 10)
        return GetUnidades(num);
    else if (num < 20)
        return especiales[num - 10];
    else 
    {
        int x = num / 10;
        int resto = num % 10;
        string aux = decenas[x];
        if (resto > 0)
            aux = aux + " y " + GetUnidades(resto);
        return aux;
    }
}

string GetCentenas(int num)
{
    if (num < 100)
        return GetDecenas(num);
    else 
    {
        int x = num / 100;
        int resto = num % 100;
        string aux = centenas[x];
        if (resto > 0)
            aux = aux + " " + GetDecenas(resto);
        return aux;
    }
}

string GetMiles(int num)
{
    if (num < 1000)
        return GetCentenas(num);
    else 
    {
        int x = num / 1000;
        int resto = num % 1000;
        string aux = (x == 1 ? "mil" : GetCentenas(x) + " mil");
        if (resto > 0)
            aux = aux + " " + GetCentenas(resto);
        return aux;
    }
}

string GetDecenasDeMiles(int num)
{
    if (num < 10000)
        return GetMiles(num);
    else 
    {
        int x = num / 1000;
        int resto = num % 1000;
        string aux = GetCentenas(x) + " mil";
        if (resto > 0)
            aux = aux + " " + GetCentenas(resto);
        return aux;
    }
}

string GetCientosDeMiles(int num)
{
    if (num < 100000)
        return GetDecenasDeMiles(num);
    else 
    {
        int x = num / 1000;
        int resto = num % 1000;
        string aux = GetCentenas(x) + " mil";
        if (resto > 0)
            aux = aux + " " + GetCentenas(resto);
        return aux;
    }
}
// Función para generar números aleatorios y mostrar su representación en palabras en español
void GenerarNumerosAleatorios() 
{
    srand(time(0)); // Inicializar la semilla de números aleatorios usando el tiempo actual

    // Generar 100 números aleatorios y mostrar su representación en palabras
    for (int i = 0; i < 100; i++) {
        int num = rand() % 999999 + 1; // Generar un número aleatorio entre 1 y 999999
        string letras = GetCientosDeMiles(num); // Obtener la representación en palabras del número
        cout << num << " : " << letras << endl; // Mostrar el número y su representación en palabras
 
    }
}
int main()
{
    
    GenerarNumerosAleatorios();
    return 0;
}
