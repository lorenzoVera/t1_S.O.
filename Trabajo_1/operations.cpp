#include "main.h"
#include "operations.h"

void palindromo(string txt){
    string reversedWord = txt;
    reverse(reversedWord.begin(), reversedWord.end());

    if (txt == reversedWord) {
        cout << "Es palíndromo." << endl;
    } else {
        cout << "No es palíndromo" << endl;
    }
}

int countVowels(string txt){
    int count = 0;
    for (char c : txt) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                count++;
                break;
        }
    }
    return count;
}

int cantLetters(string txt){
    int count = 0;
    for (char c : txt) {
        if (isalpha(c)) {
            count++;
        }
    }
    return count;
}

int summation(vector<int> numbers){
    int sum = 0;
    for(unsigned i=0 ; i<numbers.size() ; i++) {
        sum += numbers[i];
    }
    return sum;
}

float average(vector<int> numbers){
    int total = numbers.size();
    if (total == 0) {
        cout << "El vector está vacío." << endl;
        return 0;
    }
    int suma = summation(numbers);
    return (float)suma/total;
}