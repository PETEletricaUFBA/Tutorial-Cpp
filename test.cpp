#include<iostream>
#include<string>

void funcao(std::string& a){
    
    a = "Valor novo";

    std::cout << "A função foi executada com sucesso. \n";

    return;
}


int main(){
    std::string valor = "Valor antigo";

    funcao(valor);

    std::cout << valor << std::endl;

    return 0;
}