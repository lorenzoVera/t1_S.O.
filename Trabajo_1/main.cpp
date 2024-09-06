#include "main.h"

//  definición de las variables de entorno
string username;
string password;
string text;
vector<int> numbers;
int num;

int main(int argc, char* argv[]) {

    valid_input(argc, argv);

    cout << "Bienvenido al programa" << endl;
    cout << "Presione enter para continuar ..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    clear_screen();

    int selection;
    do {
        menu(); // Muestra el menú principal
        cout << "Ingrese una opción: ";
        cin >> selection;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer del input

        switch(selection) {
            case 1:
                perfil();
                break;
            case 2:
                options();
                break;
            case 3:
                cout << "Saliendo del programa ..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
                break;
        }
    } while (selection != 3);

    return EXIT_SUCCESS;
}

void menu(){
    cout << "Menú:" << endl;
    cout << "|  1) Mostrar perfil de usuario            |" << endl;
    cout << "|  2) Opciones                             |" << endl;
    cout << "|  3) Salir                                |" << endl;  
}

void options(){
    cout << "Optiones:" << endl;
    cout << "|  1) Detección de palíndromo              |" << endl;
    cout << "|  2) Contar vocales                       |" << endl;
    cout << "|  3) Cantidad de letras en un texto       |" << endl;
    cout << "|  4) Promedio y sumatoria de un vector    |" << endl;
    cout << "|  5) Calcular f(x) = 5x^2 + 1/x           |" << endl;
    cout << "|  6) Salir                                |" << endl;
    cout << "Ingrese una opción: " << endl; 
    int option;
    cin >> option;

    switch(option) {
        case 1:
            palindromo(text);
            break;
        case 2:
            cout << "Número de vocales: " << countVowels(text) << endl;
            break;
        case 3:
            cout << "Número de letras: " << cantLetters(text) << endl;
            break;
        case 4:
            cout << "Promedio: " << average(numbers) << endl;
            cout << "Sumatoria: " << summation(numbers) << endl;
            break;
        case 5:
            cout << "Resultado de f(x) = 5x^2 + 1/x: " << (5*num*num + 1.0/num) << endl;
            break;
        default:
            cout << "Opción inválida" << endl;
            break;
    }
}

void perfil(){
    cout << "Perfil de Usuario" << endl;
    cout << "|  Usuario: " << username << endl;
    cout << "|  Contraseña: " << password << endl;
    cout << "|  Texto: " << text << endl;
    cout << "|  Vector:: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    cout << "|  Número: " << num << endl;
}

void valid_input(int argc, char* argv[]){
    int c;
    while ((c = getopt(argc, argv, "u:p:t:v:n")) != -1){
        switch (c){
            case 'u':
                if (optarg != nullptr) {
                    username = optarg;
                } else {
                    cerr << "Error: Argumento para -u es nulo." << endl;
                }
                break;
            case 'p':
                if (optarg != nullptr) {
                    password = optarg;
                } else {
                    cerr << "Error: Argumento para -p es nulo." << endl;
                }
                break;
            case 't':
                if (optarg != nullptr) {
                    text = optarg;
                } else {
                    cerr << "Error: Argumento para -t es nulo." << endl;
                }
                break;
            case 'v':
                if (optarg != nullptr) {
                    vector<string> txtValues = split(optarg, ';');
                    numbers = string_a_int(txtValues);
                } else {
                    cerr << "Error: Argumento para -v es nulo." << endl;
                }
                break;
            case 'n':
                if (optarg != nullptr) {
                    num = stoi(optarg);
                } else {
                    cerr << "Error: Argumento para -n es nulo." << endl;
                }
                break;
            default:
                cerr << "Opción inválida" << endl;
                break;
        }
    }
}

vector<int> string_a_int(const vector<string>& txtValues) {
    vector<int> result;
    for (const string& str : txtValues) {
        result.push_back(stoi(str)); 
    }
    return result;
}

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");   // Comando para limpiar pantalla en Windows
    #else
        system("clear"); // Comando para limpiar pantalla en Unix/Linux/Mac
    #endif
}