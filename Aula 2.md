# Controle de fluxo

## Funções

Em C++ função são blocos de codigo que recebem nomes, e que possam ser chamados a qualquer momento do programa, a estrutura basica de uma função é:

```C++
<type> <name> ( <type> parameter1, <type> parameter2, ...){
    statements 
}
```

Onde:

* `<type>` é o tipo do valor que a função retorna, podendo ser armazenado em um objeto/variavél;
* `<name>` é o identificador da função, com o qual podemos chamar ela;
* `<type> parameter1, <type> parameter2, ...` São os parametros usados pela função, a declaração é muito parecida com a declaração de variavéis, pois em geral os parametros atuam como uma variavél de escopo local, dentro da função. A proposta dos parametros é permitir passar para a função argumentos que ela possa utilizar e processar;
(Ps. Os tipos de cada parametro não precisa ser o mesmo, e também nenhum deles precisa ser o mesmo do tipo da função.)
* `statements` São de fato os comandos que vão dentro do bloco de codigo da função, delimitado pelas chaves "`{}`", especificando o que a função atualmente faz.

Na estrutura acima vimos o essencial para o funcionamento de uma função, como podemos ver essa estrutura já nos é familiar, pois a primeira coisa que fizemos a escrever o codigo foi declarar uma função, a `main()`.

Assim como as variaveis as funções só podem ser usadas após terem sido declaradas, por isso as declarações de funções e funções viram sempre antes de serem chamadas no codigo.

Vamos dar uma olhada melhor através de um exemplo:

```C++
#include<iostream>

int soma(int a, int b){
    int r;
    r = a + b;
    return r;
}


int main(){
    int z;

    z = soma(3, 4);

    return 0;
}
```

O exemplo acima apresenta duas funções, a nossa querida `main()`, e uma função `soma()` que declaramos para somar dois numeros que passarmos como argumento. A função `main()`, é a unica função que é chamada automaticamente ao rodarmos o programa, e todas as outras são executadas ao serem chamadas, direta ou indiremante pela função `main()`.

Para o uso da função `soma()` que declaramos, nos chamamos ela pelo seu nome e passando os valores do tipo correto como argumento, e armazenamos o valor que ela retorna em uma variavél do mesmo tipo da função.

Algo importante a se notar é o comando `return`, ele é essencial em toda função e o valor atribuido a ele deve ser sempre do mesmo tipo da função. A função main e função do tipo void, não precisam ter seu retorno especifico, a função main por padrão irá retornar 0, mas em alguns casos é vantajoso especificar o retorno e visto como boa pratica, e a função void não retorna valor, mas o comando return pode ser usado para encerrar a função.

A mesma função pode ser chamada varias vezes no mesmo programa, e os argumentos passados a ela não precisam ser sempre o mesmo. Nem sempre será necessario armazenar o retorno de uma função a depender da utilidade atribuida a ela.

No exemplo vimos o uso de argumentos sendo passados pelo valor, ou seja, nos informamos o valor a ser usado na função, e a função irá fazer uma copia local desse valor para usar durante o escopo da função. Isso garante que caso seja usado uma variavél como argumento a função irá apenas copiar o valor e nenhuma alteração realizada no valor irá impactar na variavél.

Em algumas situações você pode querer modificar o valor da variavél que é passada como argumento, nesse caso será necessario ao declarar a função, declarar os parametros pela referencia, para isso basta inserir um "`&`" antes do identificador do parametro. (Ps. referencia vai mostrar a função aonde na memoria aquela variavél esta armazenada, enquanto pelo valor só seria possivel ver o valor armazenado.)

Veja 2 exemplos abaixo de comparação do uso de ambas as situações.

* Exemplo 1 - Passando pelo valor

```C++
#include<iostream>
#include<string>

void funcao(std::string a){
    
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
```

* Exemplo 2 - Passando pela referencia

```C++
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
```

Como podemos ver ao executar os exemplos, no primeiro caso o valor da string não foi modificado, enquanto no segundo sim, e isso acontece pois como foi falado, no primeiro caso a função apenas copia o valor da variavél, e no segundo ela manipula a variavél em se.

Ao declararmos uma função também é possivel pré determinar valores padrões para os parametros definidos, esses valores serão usados quando ao chamarmos a função o argumento equivalente não tenha sido explicitado, para isso é usado o operador "`=`", o mesmo usado para atribuir valores a variavéis, como podem ver no exemplo abaixo:

```C++
#include <iostream>
using namespace std;

int divide (int a, int b=2)
{
  int r;
  r=a/b;
  return (r);
}

int main ()
{
  cout << divide (12) << '\n';
  cout << divide (20,4) << '\n';
  return 0;
}
```

Ao executar o exemplo acima fica mais claro quando o valor padrão é usado e quando ele é sobrescrito. O uso de valores padrões pode ajudar bastante a evitar repetir a se mesmo ao escrever o codigo.

Como vimos uma função pode ser chamada no bloco de codigo de outra função, como por exemplo na função `main()`, sendo bem interessante para modularizar bem o programa, e permitindo também um recurso muito util na programação funcional, a capacidade de uma função chamar a se, permitindo recursividade.

## Condicionais
