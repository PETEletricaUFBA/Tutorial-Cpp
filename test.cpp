#include<iostream>
#include<string>

int main(){
    char foo[20] = "Tatakae";

    char bar[] = {'T','a','t','a','k','e','\0'};

    std::string snk = bar;

    std::cout << snk + foo << std::endl;

    return 0;
}