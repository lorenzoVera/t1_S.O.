#include <iostream>     //  cout, cin
#include <unistd.h>     //  getopt
#include <cstdlib>      //  EXIT_SUCCESS
#include <vector>       //  vector
#include <sstream>      //  istringstream
#include <limits>       //  numeric_limits
#include <algorithm>    

using namespace std;

//  Variables de entorno
extern string username;
extern string password;
extern string text;
extern vector<int> numbers;
extern int num;

//  Funciones
int main(int argc, char* argv[]);                           // Función main
void menu();                                                // Función para mostrar el menú
void options();                                             // Función para mostrar las opciones
void perfil();                                              // Función para mostrar el perfil del usuario
void valid_input(int argc, char* argv[]);                   // Función para validar los argumentos del input
vector<int> string_a_int(const vector<string>& txtValues);  // Función para convertir un vector de strings a un vector de enteros
vector<string> split(const string& s, char delimiter);      // Función para separar un string por un delimitador 
void clear_screen();                                        // Función para limpiar la pantalla

void palindromo(string txt);         //  Función que retorna true si es palindromo y false sino   
int countVowels(string txt);        //  Función que retorna la cantidad de vocales de un string
int cantLetters(string txt);        //  Función que retorna la cantidad de letras de de un string
int summation(vector<int>numbers);  //  Función que retorna la sumatoria de los numeros almacenados en un vector 
float average(vector<int>numbers);  //  Función que retorna el promedio de los numeros almacenados en un vector 