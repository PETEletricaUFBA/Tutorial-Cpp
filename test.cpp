#include<iostream>
#include<string>

int main(){
    int variavel = 10;

    int* ponteiro;

    int******** ponteiroparaponteiro;

    ponteiro = &variavel;

    *ponteiro = 25;

    std::cout << variavel << std::endl;

    return 0;
}