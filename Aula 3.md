# Mémoria

Na computação memoria é o dispositivo usado para armazenar as informações de uso imediato do computador, como mencionado na parte de variaveis, quando estamos programando em C/C++ muitas vezes iremos interagir com a memoria virtual do computador.

## Endereço de memoria

Para um programa em C++ a memoria do computador é como uma serie de celulas de memoria do tamanho de um byte e cada uma com um endereço unico. Por exemplo, quando uma variavél é declarada são alocadas celulas de memoria que serão usadas para armazenar o valor dessa variavél, e o endereço da variavél na memoria é o endereço que o programa aloca para ela.

### Operador Address-of

Para sabermos o endereço de memoria usado por uma variavél usamos o operador Address-of("`&`") por exemplo para printar no terminal o endereço de uma variavél podemos fazer:

```C++
std::cout << &variavel << std::endl;
```

O exemplo acima basicamente irá mostrar o endereço da celula de memoria em que a variavel está armazenada, é importante ressaltar que esse endereço só é acessivel no momento que o programa roda, e pode variar de acordo com as vezes que o programa rodar, pois a memoria será alocada e liberada quando o programa é rodado.

Somos familiar a esse operador quando vimos como declarar parametros pela referencia numa função. Pois a referencia que a função usa é o endereço de memoria da função, e com isso ela consegue acessar e modificar o valor armazenado na memoria, ao invés de simplesmente copiar para um novo espaço da memoria.

### Ponteiro de memoria

Alem de acessarmos e consultarmos o endereço de um objeto e variavél, podemos armazenalo em uma variavél, essa variavél em que armazenamos um endereço de memoria é o que chamamos de ponteiro. Justamente por apontar um local na memoria do computador.

A declaração de um ponteiro é feito a partir do tipo de valor armazenado na memoria, o operador deferencia e o nome do ponteiro, veja sintaxe abaixo:

```C++
<type> * <identifier> = {<initializer>};
```

Como podemos ver acima, a sintaxe é muito similar a de uma variavél normal, mas com o acrescimo do operador deferencia "`*`"

#### Operador deferencia

O operador usado anteriormente para declaração de um ponteiro é o operador deferencia,deference , ele tem dois usos ao lidar com a memoria, a primeira que vimos ao declarar um ponteiro, e a de acessar o valor de memoria associado ao endereço passado, veja exemplo abaixo.

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

No exemplo acima tivemos os dois usos do operador, o primeiro para declarar o ponteiro, e o segundo para atribuir um valor ao endereço de memoria em que o ponteiro está apontando.

#### Ponteiro para ponteiros

Assim como um ponteiro é em pratica uma variavél, também é possivel para nós termos ponteiros que apontam para o endereço de memoria em que um ponteiro esta armazenado, ou seja um ponteiro que aponta para outro ponteiro. Segue sintaxe abaixo:

```C++
<type> ** <identifier> = {<initializer>};
```

Como podemos ver basicamente acrescentamos mais um operador deferencia "`*`", sinalizando que é um ponteiro para um ponteiro.

É importante ressaltar que o tipo de todos os ponteiros devem ser o mesmo, que é o tipo do valor armazenado no ponteiro que aponta para um objeto/variavél.

#### Aritimetica de ponteiros

É possivel fazermos duas operações basicas com ponteiros, somar ou subtrair um numero inteiro, ou contador. Basicamente essas operações servem para navegar brevemente pela memoria do computador, indo para o endereço de memoria a frente ou atrás.

```C++
p = p + 1;
p = p - 1;

*p++;
*++p;
*p--;
*--p;
```

Nos exemplos acima basicamente varia o ponteiro a ser consultado, como na operação de incrementação comum, mas é importante ressalvar que a quantidade de bytes que irá variar vai depender do tipo do valor do ponteiro, pois ele irá saltar o equivalente a uma unidade daquele tipo, isso protege as variaveis de serem corrompidas sem intenção.

Ou seja ao somar ou subtrair uma unidade por exemplo, ele irá saltar a quantidade de celulas de memorias, em bytes, equivalente ao tamanho do tipo do ponteiro.

É importante ressaltar que em qualquer operação ao usar ponteiros deve se estar bastante atento a erros, pois é facil eles passarem despercebido e darem uma dor de cabeça muito grande.

## Arrays

## Alocação Dinamica(Opcional)
