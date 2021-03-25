# Introdução

A linguagem de programação C++ por definição possui uma estrutura mínima para funcionar que vocês veem abaixo:

```C++
#include<iostream>

int main(){

    return 0;
}
```

O código acima é um dos mais simples que podem ser feitos, vamos explorá-lo:

A primeira linha possui o comando `#include<>` esse comando é usado para importar para nosso código outro arquivo de fonte, ou como costumamos chamar, uma biblioteca, neste código chamamos a biblioteca iostream, que é a biblioteca de entradas e saídas padrão do C++, veremos o uso dela logo abaixo. Ou seja, essa linha importa para nosso código as funções da biblioteca de entrada e saída padrão, permitindo usar e implementar suas funções em nosso programa;
Ps. o “`#`” no começo do código significa que ele é um comando direto, e vai ser executado na etapa de pré processamento.

A linha seguinte possui a declaração da função `main()`, essa função é a função padrão que os compiladores irão buscar para transformar nosso código em um programa executável, e dentro dela iremos criar nosso código, as chaves "{}" demonstram o escopo da nossa função, em resumo dentro dessa função é que vamos dizer como o programa deve começar.

O `return 0`, é um comando opcional usado para simbolizar que o programa rodou sem nenhum problema.

Como vimos, essa é a estrutura básica de um programa, praticamente todo programa usando C e C++ irão seguir essa estrutura. Valendo lembrar que as bibliotecas padrão de entrada e saída do C e do C++ são diferentes, para o C temos stdlib.h para C++ temos a iostream que usamos acima.

## Variáveis e tipos

Na programação, variáveis costumam ser objetos os quais os valores variam, em contraste com constantes em que os valores permanecem o mesmo ao longo de todo programa.Em C/C++ as variáveis são pedaços da memória reservados para o uso do programa. O uso de variáveis é indispensável em praticamente qualquer programa, pois não permite armazenar, modificar, utilizar e manipular valores de modo que sem eles seria exaustivo e que o programa sempre seria executado da mesma forma.

Para utilizarmos uma variável é necessário inicialmente instanciar ela, usando a seguinte estrutura:

```C++
<type> <identifier> = {<initializer>};
```

Na estrutura acima temos o essencial para o funcionamento de uma variável, o tipo, `<type>`, o identificador, `<identifier>` e o inicializador `{<initializer>}`,

O **tipo** da variável nos diz como o programa deve interpretar o valor que será armazenado na memória, e quanto da memória será alocado para esse valor, pois enquanto o computador só entende 0s e 1s o compilador precisa saber como converter isso para 0s e 1s.

O C e o C++ possuem 4 grupos de tipos fundamentais:

* Tipos de caracteres: São usados para armazenar um único caractere como 'J' e '&', onde o tipo básico desse grupo é o `char`, de tamanho de 1 byte, tendo a tabela ASCII como base;
* Tipos de números inteiros: Eles podem armazenar números inteiros, a depender do tipo tendo tamanhos diferentes, e valores positivos ou positivos e negativos, o tipo básico é o `int`, que pode segurar valores de -2147483648 até +2147483647;
* Tipos de números com ponto flutuante: Esse tipo de variável também armazena números, mas dessa vez ele armazena valores que possuem ., ou seja valores reais, com tamanho e precisão variando de acordo com o tipo, o tipo básico é o `float` com range para valores positivos de 1.17549e-38 até 3.40282e+38 e valores negativos de -1.17549e-38 até -3.40282e+38;
* Tipo booleano: O tipo booleano, `bool`, pode representar 2 estados, verdadeiro ou falso.

Segue abaixo tabela dos tipos com o quanto de memória ela aloca para si.

| Tipo                  | Memória alocada   | Alcançe                           |
| -----------           | ---------------   | -------                           |
|char                   | 1byte             |-127 to 127 or 0 to 255            |
|unsigned char          | 1byte             | 0 to 255                          |
|signed char            | 1byte             | -127 to 127                       |
|int                    | 4bytes            | -2147483648 to 2147483647         |
|unsigned int           | 4bytes            | 0 to 4294967295                   |
|signed int             | 4bytes            |-2147483648 to 2147483647          |
|short int              | 2bytes            | -32768 to 32767                   |
|unsigned short int     | 2bytes            | 0 to 65,535                       |
|signed short int       | 2bytes            | -32768 to 32767                   |
|long int               | 8bytes            | -2,147,483,648 to 2,147,483,647   |
|signed long int        | 8bytes            | same as long int                  |
|unsigned long int      | 8bytes            | 0 to 4,294,967,295                |
|long long int          | 8bytes            | -(2^63) to (2^63)-1               |
|unsigned long long int | 8bytes            |0 to 18,446,744,073,709,551,615    |
|float                  | 4bytes            |                                   |
|double                 | 8bytes            |                                   |
|long double            | 12bytes           |                                   |
|wchar_t                | 2 or 4 bytes      | 1 wide character                  |

Outro tipo muito importante de variaveis, é a string, uma string é de forma resumida um objeto que armazena caracteres em uma sequencia da memoria, portanto não possui tamanho fixo, a duas maneiras de instanciar uma string, sendo uma outra preferivel de acordo com os usos que serão atribuidas a ela, veja abaixo:

* Exemplo 1

```C++
#include<iostream>
#include<string>

int main(){
    std::string myString;
    myString = "De mais amor do que voce recebe!";

    return 0;
}
```

* Exemplo 2

```C++
#include<iostream>

int main(){
    const char* myString;
    myString = "De mais amor do que voce recebe!";

    return 0;
}
```

O primeiro caso é usando biblioteca `<string>` nela permite uma manipulação e uso mais facil da string, pois a string é tratada como um objeto que contem a array ordenada de caracteres. Enquanto o segundo exemplo nos tempos um ponteiro, seta, que indica um lugar na memoria com a string, caracteres ordenados. Cada caso vai ter sua vantagem e uso, geralmente o segundo sendo usado para quando o valor da string não muda ao longo do codigo, e o primeiro para quando a string requer uma manipulação.

Ps. Os valores do tipo string e tipo caracteres são declarados usando aspas duplas "`""`" para strings e aspas simples "`''`" para os caracteres.

O **identificador** da variável é o nome que atribuímos a ela, que deverá ser composta por letras, dígitos ou o caractere underscore(_), espaço, pontuações e símbolos não podem ser utilizados no identificador, podendo ocasionar em erros no código. Existem algumas boas práticas para usar as variáveis, e dentre elas está evitar ter variáveis com identificadores iguais, ou com identificadores que sejam iguais ou parecidos com comandos padrões do C e do C++, o que pode ocasionar mal funcionamento no código e erros.
O C/C++ é case sensitive, ou seja, as letras maiúsculas e minúsculas são diferentes.

Ao instanciar uma variável o único elemento da estrutura que é opcional e facultativo é **inicializador**, ele serve para atribuir o valor inicial a variável.
Ps, existem outras formas menos comuns de instanciar as variáveis, recomendo pesquisar sobre.

Agora que a variável foi instanciada podemos acessar e modificar o valor armazenado nela, para acessar o valor basta chamarmos pelo identificador `<identifier>`, utilizando ao longo do codigo.

Já para modificar, o método padrão consiste em usar o operador "`=`" Assignment, usado para associar valor a uma variaveis:

```C++
<identifier> = {<value>};
```

Ps, não por coincidência é o mesmo operador usado para instanciar a variável, ele é responsável por associar valor a variável.

## Operadores

Agora que sabemos o que são variáveis, iremos operar elas, para isso usaremos operadores, os quais são funções especiais que vem por padrão no C/C++ e nos permite operar as variáveis e constantes.

Acima já vimos sobre o operador "`=`" usado para atribuir valores à variáveis. Falaremos sobre alguns desses operadores, os quais são bastante utilizados ao escrever um programa.

### Operadores Aritméticos

São 5 operadores aritméticos padrão da linguagem,

| Operador  | Descrição     |
|-----------|-----------    |
| +         | Adição        |
| -         | Subtração     |
| *         | Multiplicação |
| /         | Divisão       |
| %         | Resto (modulo)|

Os quatro primeiro operadores correspondem a seus respectivos operadores matemáticos, estando atento ao uso do operador divisão, pois caso os dois valores sejam inteiros, ele vai retornar o valor inteiro da divisão arredondado para baixo.
E o quinto operador retorna o resto da divisão de dois inteiros.
O uso dos operadores aritméticos opera os valores a direita e esquerda no operador, podendo ser usados em conjunto com alguns outros operadores, como o operador de associação "`=`" por exemplo.

```C++
int x = 0;

x = 7 % 3; // o x agora armazena o valor 1, pois é o resto da divisão do inteiro 7 pelo número 3;
```

### Operadores associação composta

Os operadores associação composta são operadores que operam em uma variável modificando o valor atual da variável através de uma operação.

| Operador      | Operação equivalente  |
|-----------    |-----------            |
| x += y;       | x = x + y;            |
| x -= y;       | x = x - y;            |
| x /= y;       | x = x / y;            |
| x *= y + 1;   | x = y * (y + 1);      |

Valendo ressaltar nesse momento que o operador "`=`", não é equivalente ao sinal de igualdade da matemática, pois aqui ele atribui o valor da direita a variável da esquerda.

Dentre os operadores associação composta, existem os incrementadores e decrementadores, bastante usados em programas, portanto merecendo um destaque, eles são:

Incrementadores:

* i++;
* ++i;
* i+=1;
* i = i + 1;

Decrementadores:

* i--;
* --i;
* i-=1;
* i = i - 1;

Em geral não diferença no funcionamento dos incrementadores e decrementadores entre si, armazenando na variável o mesmo valor, porém em termos de retorno da operação eles podem evaluar valores diferentes, por isso ficar atento, por exemplo no caso de i++ e ++i veja diferença abaixo:

|Exemplo 1  |Exemplo 2  |
|-----      |------     |
|x = 3;     |x = 3;     |
|y = ++x;   |y = x++;   |

No exemplo 1 o valor armazenado em y será 4, enquanto no exemplo 2 o valor armazenado em y será 3, enquanto em ambos o caso o valor armazenado em x será 4;

### Operadores de comparação

Operadores de comparação retornam valores booleanos e tem como princípio comparar dois valores, e retornando verdadeiro ou falso de acordo com a operação realizada.

| Operador  | descrição         |
|----       |----               |
| ==        | Igual a           |
| !=        | Não igual a       |
| <         | Menor que         |
| >         | Maior que         |
| <=        | Menor ou igual a  |
| >=        | Maior ou igual a  |

### Operadores Logicos

Operadores lógicos são operadores que modificam um valor lógico, booleano.

Operador negado,  "`!`", ele inverte o valor que ele opera:

```C++
!false // isso equivale a verdadeiro.
!true // isso equivale a falso.
```

Operador e, "`&&`", ele retorna verdadeiro apenas se ambos os valores dos dois lados forem verdadeiros, segue tabela verdade,

| && OPERATOR (and)     | | |
|---    | ---   | ---       |
|a      |   b   | a && b    |
|true   |true   | true      |
|true   |false  | false     |
|false  |true   | false     |
|false  |false  | false     |

Operador ou, "`||`", ele retorna verdadeiro se ao menos um dos valores forem verdadeiros, segue tabela verdade

| || OPERATOR (or)      | | |
|---    | ---   | ---       |
|a      |   b   | a || b    |
|true   |true   | true      |
|true   |false  | true      |
|false  |true   | true      |
|false  |false  | false     |

## Entradas e Saída padrão

Até então o que aprendemos não torna o programa muito interativo, e interatividade é algo extremamente importante em um programa, vamos aprender agora a interagir com o usuario através de entradas e saidas padrão do C++;

Como falado anteriormente a biblioteca `<iostream>` é a biblioteca padrão do C++ responsavél pelo fluxo de entrada e saida de dados. A biblioteca nos permite acessar e chamar oito objetos para manipular o fluxo de dados, para caracteres normais e wide caracteres, como podem ver abaixo.

| Caracteres padrão (char)|                             |
|-------|-----------                                    |
| cin   | Standard input stream (object) Entrada padrão |
| cout  | Standard output stream (object) Saida padrão  |
| cerr  | Standard output stream for errors (object )   |
| clog  | Standard output stream for logging (object )  |

| caracteres Wide (wchar_t)|                                            |
|-------|-----------                                                    |
| wcin  | Standard input stream (wide) (object )                        |
| wcout |Standard output stream (wide) (object )                        |
| wcerr |Standard output stream for errors (wide-oriented) (object )    |
| wclog |Standard output stream for logging (wide) (object )            |

Os objetos de entrada e saida padrão mais comuns são o cin e cout, respectivamente, por trabalharmos normalmente com caracteres comuns. Tente intepretar o exemplo abaixo.

```C++
#include<iostream>

int main(){
    int idade = 0;

    std::cout << "Qual a idade de Joelton??" << std::endl;
    std::cin >> idade;

    std::cout << "Então Joelton tem " << idade << " anos de idade!" << std::endl;
}
```

O exemplo acima trabalhamos ambas, a entrada e saida, começaremos pelo objeto `cout`,usado para instanciar o objeto que irá mostrar no terminal o valor passado utilizando o operador de associação "`<<`", o operador pode ser usado para associar varios valores a mesma saida cout, e com isso podendo trabalhar com mais de um dos tipos padrões. Outro elemento usado no fim de cada `cout`, foi o `endl`, ele serve para indicar ao terminal que esse é o fim da linha da saida, sem ele todas saidas ocorreriam sem um "enter" uma apos o outro;

O objeto `cin`, irá istanciar o objeto que irá coletar os dados que o usuario irá passar no terminal e armazenar em uma variavél usando o operador de associação `>>`, sentido oposto do `cout`, apontando para a variavel que irá receber o valor.
