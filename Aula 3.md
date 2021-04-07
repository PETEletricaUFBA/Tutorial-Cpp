# Mémoria

Na computação memória é o dispositivo usado para armazenar as informações de uso imediato do computador, como mencionado na parte de variáveis, quando estamos programando em C/C++ muitas vezes iremos interagir com a memória virtual do computador.

## Endereço de memória

Para um programa em C++ a memória do computador é como uma série de células de memória do tamanho de um byte e cada uma com um endereço único. Por exemplo, quando uma variável é declarada são alocadas células de memória que serão usadas para armazenar o valor dessa variável, e o endereço da variável na memória é o endereço que o programa aloca para ela.

### Operador Address-of

Para sabermos o endereço de memória usado por uma variável usamos o operador Address-of("`&`") por exemplo para printar no terminal o endereço de uma variável podemos fazer:

```C++
std::cout << &variavel << std::endl;
```

O exemplo acima basicamente irá mostrar o endereço da célula de memória em que a variável está armazenada, é importante ressaltar que esse endereço só é acessível no momento que o programa roda, e pode variar de acordo com as vezes que o programa rodar, pois a memória será alocada é liberada quando o programa é rodado.

Somos familiares a esse operador quando vimos como declarar parâmetros pela referência em funções. Pois a referência que a função usa é o endereço de memória da função, e com isso ela consegue acessar e modificar o valor armazenado na memória, ao invés de simplesmente copiar para um novo espaço da memória.

### Ponteiro de memória

Além de acessarmos e consultarmos o endereço de um objeto é variável, podemos armazená-lo em uma variável, essa variável em que armazenamos um endereço de memória é o que chamamos de ponteiro. Justamente por apontar um local na memória do computador.

A declaração de um ponteiro é feito a partir do tipo de valor armazenado na memória, o operador deferência e o nome do ponteiro, veja sintaxe abaixo:

```C++
<type> * <identifier> = {<initializer>};
```

Como podemos ver acima, a sintaxe é muito similar a de uma variável normal, mas com o acréscimo do operador deferência "`*`"

#### Operador deferencia

O operador usado anteriormente para declaração de um ponteiro é o operador deferência, deference , ele tem dois usos ao lidar com a memória, a primeira que vimos ao declarar um ponteiro, e a de acessar o valor de memória associado ao endereço passado, veja exemplo abaixo.

```C++
#include<iostream>
#include<string>

int main(){
    int variavel = 10;

    int* ponteiro;

    ponteiro = &variavel;

    *ponteiro = 25;

    std::cout << variavel << std::endl;

    return 0;
}
```

No exemplo acima tivemos os dois usos do operador, o primeiro para declarar o ponteiro, e o segundo para atribuir um valor ao endereço de memória em que o ponteiro está apontando.

#### Ponteiro para ponteiros

Assim como um ponteiro é em pratica uma variável, também é possível para nós termos ponteiros que apontam para o endereço de memória em que um ponteiro está armazenado, ou seja um ponteiro que aponta para outro ponteiro. Segue sintaxe abaixo:

```C++
<type> ** <identifier> = {<initializer>};
```

Como podemos ver basicamente acrescentamos mais um operador deferência "`*`", sinalizando que é um ponteiro para um ponteiro.

É importante ressaltar que o tipo de todos os ponteiros devem ser o mesmo, que é o tipo do valor armazenado no ponteiro que aponta para um objeto/variável.

#### Aritmética de ponteiros

É possível fazermos duas operações básicas com ponteiros, somar ou subtrair um número inteiro, ou contador. Basicamente essas operações servem para navegar brevemente pela memória do computador, indo para o endereço de memória a frente ou atrás.

```C++
p = p + 1;
p = p - 1;

*p++;
*++p;
*p--;
*--p;
```

Nos exemplos acima basicamente varia o ponteiro a ser consultado, como na operação de incrementação comum, mas é importante ressalvar que a quantidade de bytes que irá variar vai depender do tipo do valor do ponteiro, pois ele irá saltar o equivalente a uma unidade daquele tipo, isso protege as variáveis de serem corrompidas sem intenção.

Ou seja, ao somar ou subtrair uma unidade, por exemplo, ele irá saltar a quantidade de células de memórias, em bytes, equivalente ao tamanho do tipo do ponteiro.

É importante ressaltar que em qualquer operação ao usar ponteiros deve-se estar bastante atento a erros, pois é fácil eles passarem despercebidos e darem uma dor de cabeça muito grande.

## Arrays

Arrays são sequência de valores do mesmo tipo organizados ordenadamente continuamente na memória do computador. Ou seja uma array de inteiros de tamanho 5, são 5 valores inteiros organizados lado a lado em um pedaço da memória do computador, ordenados por um index, veja abaixo a sintaxe:

```C++
<type> name [elements] = {<initializer>};
```

Muito similar a declaração de uma variável essa forma de declarar uma array acrescentamos apenas o número de elementos que nossa array irá possuir. Para melhor compreensão vejam exemplo e abstração a seguir.

```C++
int array[5] = {3,7,7,0,2};
```

|index  | 0 | 1 | 2 | 3 | 4 |
|--     |-- |-- |-- |-- |-- |
|array  | 3 | 7 | 7 | 0 | 2 |

Como podemos ver acima, é o exemplo da declaração de uma array com todos valores já inicializados, e a abstração do mesmo relacionado com o índice, quem sempre começa com 0 e vai até o tamanho da array - 1.

No caso da declaração da array e um ou mais valores não sejam iniciados será adotado o valor padrão, mas é boa prática sempre que declarar iniciar todos os valores, mesmo que com 0 para deixar explícito.

Caso tente inicializar mais valores do que a array suporta o programa poderá ocasionar no erro de segment fault, que ocorre ao tentar acessar uma memória que não possui acesso.

O C++ também possibilita a possibilidade de deixar os colchetes vazios e não especificar o tamanho da array, onde por padrão o compilador irá definir como base na quantidade de elementos inicializados ao inicializar a array.

Importante ressaltar que por métodos padrões o tamanho de uma array é sempre fixo e não pode ser modificado ao longo do programa, existem alternativas dinâmicas e formas de contornar isso, mas por padrão o tamanho da array é sempre o mesmo.

### Array e Ponteiro

Algo importante para lembrarmos é que array é um lugar da memória que armazenamos valores. Em concepção uma array é extremamente similar a um ponteiro, funcionando praticamente da mesma forma com que o ponteiro que aponta para o primeiro elemento da array funciona.

Permitindo manipular, declarar e inicializar arrays utilizando ponteiros. Incluindo ser possível atribuir o array a um ponteiro.

A principal diferença entre os dois é que enquanto podemos modificar para um ponteiro está apontando, uma array irá sempre apontar para o mesmo bloco de memória.

### Acessar elementos da array

Para acessarmos os valores armazenados em cada elemento da array não se difere muito de acessar o valor de uma variável, como vemos na sintaxe a seguir:

```C++
array[index];
```

Ou ainda podemos acessar o valor usando o operador deferencia "`*`", ao tratar a array como um ponteiro, veja sintaxe a seguir:

```C++
*(array + index);
```

Cada elemento da array sozinho comporta-se exatamente como uma variável, sendo assim as operações válidas numa variável igualmente válidas a cada elemento da array.

### Multidimensional Arrays, Array de arrays

Algo muito útil em termos de arrays são as arrays multidimensionais, ou seja arrays de arrays. Por exemplo, uma array bidimensional pode ser comparada a uma matriz na matemática, onde o tamanho é definido pelas linhas e colunas, ou primeira e segunda dimensão. Veja um exemplo de declaração de array multidimensional abaixo.

```C++
int arrayGrauTres[3][3][3] = {{{3,3,3},{3,3,3},{3,3,3}},{{2,2,2},{2,2,2},{2,2,2}},{{1,1,1},{1,1,1},{1,1,1}}};
```

Tecnicamente em concepção não há limite de tamanho para as arrays, nem quantidade de dimensões, porém existem limites de memória para cada computador que acabam criando um limite prático para os tamanhos e usos de arrays, por isso é extremamente importante se atentar ao tamanho que será reservado para arrays.

Sendo completamente compatível com a ideia de ponteiro de ponteiros, não por coincidência, mas por em concepção ambos serem endereços da memória.

### Arrays de Caracteres e strings

Como vimos anteriormente temos um tipo especial, o "`sdt::string`" que é uma espécie de Array de `characters` que termina em "`\0`".

Como a string é uma array de characters, podemos armazenar ela usando a notação normal de uma array:

```C++
    char foo[20] = "Tatakae";

    char bar[] = {'T','a','t','a','k','e','\0'};
```

Na primeira declaração do exemplo acima o "`\0`" fica subentendido, e o compilador coloca por padrão ao fim da string, e no segundo caso colocamos explicitamente ao inicializar a array elemento por elemento.

É importante ressaltar que a ali a array não precisa estar completamente preenchida, e por padrão a maioria das bibliotecas que acessam strings e arrays de characters irão parar ao se depararem com o `\0`, em contrapartida caso o '\0' seja removido, ou não explicitado como deveria, o programa pode acabar acessando memória indevida fora da string, e printando valores aleatórios, ou até mesmo ocasionando em erro de segment fault.

Em ambos os casos as arrays podem ser armazenadas em formas de "`std::string`" e utilizar das funções que a biblioteca `<string>` oferece.

## Alocação Dinâmica(Opcional)

