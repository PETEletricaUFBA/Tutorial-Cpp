# Controle de fluxo

Em C++ as declarações e comandos são instruções executadas pelo programa, elas sempre terminam em ponto-vírgula "`;`" e são executadas na ordem em que foram chamadas.

Além dos comandos individuais que terminam em "`;`" existem também os comandos compostos, que são blocos de códigos executados em conjunto, esses blocos são delimitados por chaves "`{}`".
Como veremos abaixo a ordem e caminho em que esses comandos são executados são quem irão determinar o fluxo de dados do programa, e sua execução.

## Funções

Em C++ funções são blocos de código que recebem nomes, e que possam ser chamados a qualquer momento do programa, a estrutura básica de uma função é:

```C++
<type> <name> ( <type> parameter1, <type> parameter2, ...){
    statements 
}
```

Onde:

* `<type>` é o tipo do valor que a função retorna, podendo ser armazenado em um objeto/variável;
* `<name>` é o identificador da função, com o qual podemos chamar ela;
* `<type> parameter1, <type> parameter2, ...` São os parâmetros usados pela função, a declaração é muito parecida com a declaração de variáveis, pois em geral os parâmetros atuam como uma variável de escopo local, dentro da função. A proposta dos parâmetros é permitir passar para a função argumentos que ela possa utilizar e processar;
(Ps. Os tipos de cada parâmetro não precisa ser o mesmo, e também nenhum deles precisa ser o mesmo do tipo da função.)
* `statements` São de fato os comandos que vão dentro do bloco de código da função, delimitado pelas chaves "`{}`", especificando o que a função atualmente faz.

Na estrutura acima vimos o essencial para o funcionamento de uma função, como podemos ver essa estrutura já nos é familiar, pois a primeira coisa que fizemos ao escrever o código foi declarar uma função, a `main()`.

Assim como as variáveis, as funções só podem ser usadas após terem sido declaradas, por isso as declarações de funções e funções vêm sempre antes de serem chamadas no código.

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

O exemplo acima apresenta duas funções, a nossa querida `main()`, e uma função `soma()` que declaramos para somar dois números que passarmos como argumento. A função `main()`, é a única função que é chamada automaticamente ao rodarmos o programa, e todas as outras são executadas ao serem chamadas, direta ou indiretamente pela função `main()`.

Para o uso da função `soma()` que declaramos, nós chamamos ela pelo seu nome e passando os valores do tipo correto como argumento, e armazenamos o valor que ela retorna em uma variável do mesmo tipo da função.

Algo importante a se notar é o comando `return`, ele é essencial em toda função e o valor atribuído a ele deve ser sempre do mesmo tipo da função. A função main e função do tipo void, não precisam ter seu retorno específico, a função main por padrão irá retornar 0, mas em alguns casos é vantajoso especificar o retorno, o que é visto como boa prática, e a função void não retorna valor, mas o comando return pode ser usado para encerrar a função.

A mesma função pode ser chamada várias vezes no mesmo programa, e os argumentos passados a ela não precisam ser sempre o mesmo. Nem sempre será necessário armazenar o retorno de uma função a depender da utilidade atribuída a ela.

No exemplo vimos o uso de argumentos sendo passados pelo valor, ou seja, nós informamos o valor a ser usado na função, e a função irá fazer uma cópia local deste valor para usar durante o escopo da função. Isso garante que caso seja usado uma variável como argumento a função irá apenas copiar o valor e nenhuma alteração realizada no valor irá impactar na variável.

Em algumas situações você pode querer modificar o valor da variável que é passada como argumento, nesse caso será necessário ao declarar a função, declarar os parâmetros pela referência, para isso basta inserir um "`&`" antes do identificador do parâmetro. (Ps. referência vai mostrar a função onde na memória aquela variável está armazenada, enquanto pelo valor só seria possível ver o valor armazenado.)

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

* Exemplo 2 - Passando pela referência

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

Como podemos ver ao executar os exemplos, no primeiro caso o valor da string não foi modificado, enquanto no segundo sim, e isso acontece pois como foi falado, no primeiro caso a função apenas copia o valor da variável, e no segundo ela manipula a variável em se.

Ao declararmos uma função também é possível pré determinar valores padrões para os parâmetros definidos, esses valores serão usados quando ao chamarmos a função o argumento equivalente não tenha sido explicitado, para isso é usado o operador "`=`", o mesmo usado para atribuir valores a variáveis, como podem ver no exemplo abaixo:

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

Ao executar o exemplo acima fica mais claro quando o valor padrão é usado e quando ele é sobrescrito. O uso de valores padrões pode ajudar bastante a evitar repetir a si mesmo ao escrever o código.

Como vimos uma função pode ser chamada no bloco de código de outra função, como por exemplo na função `main()`, sendo bem interessante para modularizar bem o programa, e permitindo também um recurso muito útil na programação funcional, a capacidade de uma função chamar a se, permitindo recursividade.

## Condicionais

Um programa não precisa ser sempre uma linha reta, e é interessante que não seja, algo muito importante na maioria dos programas de uso diário é a interação com o usuário e para isso é importante que o programa de liberdade para usuário interagir, visando esse aspecto os controles de fluxo são extremamente importantes.

### Condicionais de seleção: if e else

O comando "`if`" é usado para fazer com que o programa só execute um statement caso as condições impostas pelo programa sejam atendidas, ou verdadeiras. A sintaxe usada para chamar o comando if é:

```C++
if (condition) statement
```

A sintaxe acima aponta que o statement, comando, só será executado caso a condição entre parênteses retorne valor booleano verdadeiro, do contrário o comando será ignorado.
Ps. O comando tanto pode ser um comando simples quanto um comando composto.

Por padrão o if divide o código em dois caminhos, onde um if pode ser seguido por um else, e quando não explicitado como no exemplo acima o programa irá interpretar como statement do else está vazio, para melhorar compreensão vejam a sintaxe completa abaixo:

```C++
if (condition) statement1 else statement2
```

Nesse caso de forma clara o programa irá executar o statement1 ou o statement2 a depender da condição, sendo executado a statement1 caso a condição seja atendida, retorne valor verdadeiro, e o statement 2 caso a condição não seja atendida, retorne valor falso.

Algo muito interessante das condicionais é que é possível encasquetar várias condicionais if else, pois o "`if(){}else{}`" é um statement, comando, assim tratando concatenando os "`if(){}else{}`" para tornar o fluxo do programa tão livre quanto desejado, segue um exemplo abaixo:

```C++
if (x > 0)
  cout << "x is positive";
else if (x < 0)
  cout << "x is negative";
else
  cout << "x is 0";
```

Nesse caso pelo contexto da sintaxe completa do "`if(){}else{}`", esse segundo "`if(){}else{}`" é o statement2 do primeiro "`if(){}else{}`".

A vantagem de concatenar vários "`if(){}else{}`", é que você garante que algumas condicionais só irão ser verificadas se as de hierarquia superior for verdadeira ou falsa.

Como no exemplo, o programa só irá verificar se o x é negativo caso o primeiro if retorne falso, não seja maior que 0, e só irá dizer que é 0 caso ambos os ifs sejam falsos.

### Condicionais de repetição e interação: while, do...while e for

Além de bifurcações no fluxo do programa, algumas vezes é interessante que o código repita alguns blocos e pedaços de código, e nesse sentido os laços de repetição ou iteração são úteis e práticos.

É importante ressaltar que mesmo que o programa em sua execução tenha pedaços repetitivos repetir de forma desnecessária comandos no código fonte pode ser algo cansativo e ineficaz, nesse cenário os laços de repetições se provam úteis em conjunto com  as funções, que faz com que seja cada vez menos necessário repetir o mesmo código de forma explícita ao escrever um programa.

Começaremos pela condicional de repetição while, a while irá repetir um statement, enquanto uma condição for verdadeira como veremos na sintaxe abaixo.

```C++
while (expression) statement
```

O programa irá rodar o statement do comando enquanto a expressão da condicional for verdadeira, e a após a expressão deixar de ser verdadeira o comando, statement, irá deixar de ser executado e o programa irá executar o resto do código que vem em após a repetição while, segue exemplo:

```C++
#include <iostream>

int main ()
{
  int n = 10;

  while (n>0) {
    std::cout << n << ", ";
    --n;
  }

  std::cout << "Lançar!\n";
}
```

No exemplo acima o valor de "`n`" vai diminuir até chegar em 0, onde o laço irá parar e em seguida ir para o statement seguinte fora do loop.

Ps. vale ressaltar que por padrão a verificação da expressão dada ao while é executada antes de cada execução do loop, e por isso no exemplo o 0 não será printado.

A condicional while possui uma alternativa extremamente similar a ela, a "`do{}while;`", se diferenciando da anterior por garantir que o statement será executado ao menos uma única vez dentro do programa, mesmo que inicialmente a expressão seja falsa, veja sintaxe abaixo:

```C++
do statement while (condition);
```

O uso do do-while, como apontado, é preferível quando é necessário que o código seja executado ao menos uma vez ao longo do programa, pois nesse caso a expressão condicional só será verificada ao fim da execução do statement.

Ainda temos a condicional de iteração for, usada para iterar, repetir, o código em certa quantidade de vezes, vejamos a sintaxe a seguir:

```C++
for (initialization; condition; iterator) statement;
```

A sintaxe se assemelha um pouco com o while, mas vemos a diferença nas expressões condicionais, enquanto no while, a condicional irá verificar um booleano e rodar enquanto verdadeiro, no for, será necessário iniciar um valor, determinar a condicional que o valor deve atender, e sua forma de iteração.

Ps. a iteração pode tanto estar dentro do parêntese, ou opcionalmente dentro do statement, sendo o primeiro caso preferível.

Todos os 3 parâmetros da expressão condicional do for podem ser deixados em branco, mas é necessário que os pontos-vírgula "`;`" sejam explicitados. Caso o inicializador esteja em branco, o programa irá assumir que a variável foi declarada e inicializada anteriormente, para a condicional em branco, o for será sempre verdadeiro, um loop infinito, e como citado caso iterator esteja em branco, ele irá assumir que o código irá iterar por si.

Ps. "`for (;n<10;)`" é equivalente a "`while(n<10)`".

Vejam o exemplo a seguir:

```C++
#include <iostream>

int main ()
{

  for (int n =10; n>0; n--) {
    std::cout << n << ", ";
  }

  std::cout << "Lançar!\n";
}
```

O exemplo acima podemos ver que o statement será executado entre a verificação do condicional e a iteração do iterator. Sendo importante ressaltar que o escopo da variável n declarada dentro do inicializador é local e será destruído ao fim do loop.

Na maioria dos casos loops infinitos serão um problema, e dada essa situação, será necessário que dentro do statement e da execução dos loops seja garantido que em algum momento do programa o loop será fechado e encerrado. Repetir um loop mais vezes do que o necessário pode muitas vezes ser um desperdício de memória e processamento, por isso é sempre importante se atentar ao uso dos mesmos.

### Controle de fluxo: Break e Continue

Em alguns momentos será necessário forçar e ter um controle maior de iterações específicas da condicional, como por exemplo encerrar um loop infinito, ou pular certa iteração.

O comando "`break`", é responsável por forçar o encerramento de um comando condicional.

O comando "`continue`", é responsável por garantir o fim de uma iteração, fazendo com que nem todo o statement composto seja executado, pois ele força o programa a parar e ir para iteração seguinte.

### Condicional de seleção: switch

Uma alternativa às condicionais if e else, é o comando switch pois ele irá buscar por um valor dentre algumas possibilidades bem parecido com a concatenação de if e elses, mas limitado a expressões constantes, sua sintaxe é:

```C++
switch (expression)
{
  case constant1:
     group-of-statements-1;
     break;
  case constant2:
     group-of-statements-2;
     break;
  .
  .
  .
  default:
     default-group-of-statements
}
```

Como vimos na sintaxe o switch irá fazer uma verificação de caso a caso, e caso chegue ao default irá rodar o grupo de statements default. É muito importante usar o break ao fim de cada grupo de statements pois como o programa não dá o break por default, ele irá continuar verificando todos os casos seguintes mesmo se o caso desejado já tenha sido atingido, incluindo executar o caso default se chegar até ele.
