# Estruturas de dados

Quando falamos em Estruturas de dados estamos nos referindo a maneiras de estruturar e organizar dados do nosso programa, ou seja, organizar como a memoria deve ser alocado para aquele dado ou conjunto de dados, e como codigo irá descrever essa estrutura.

## Estrutura de dados

Uma estrutura de dados é um conjunto de dados agrupados em um unico nome, onde cada elemento da estrutura é conhecido como *membro*, podendo os membros serem de tipos e tamanho diferentes. No C/C++ para declararmos uma estrutura usamos a seguinte sintax:

```C++
struct type_name {
    member_type1 member_name1;
    member_type2 member_name2;
    member_type3 member_name3;
    .
    .
} object_names;
```

Onde `type_name` é o nome da estrutura, e `member_typeN` e `member_nameN` são respectivamente o tipo e nome dos membros da estrutura, `object_names` é um commando facultativo que permite já pré instanciar alguns objetos da estrutura no momento de declaração da estrutura. Nos dois exemplos abaixo veremos duas formas de declarar e instanciar uma estrutura e seus objetos.

* Exemplo 1 :

```C++
struct product {
  int weight;
  double price;
} ;

product apple;
product banana, melon;
```

* Exemplo 2 :

```C++
struct product {
  int weight;
  double price;
} apple, banana, melon;
```

Ambos os casos são equivalentes e descrevem a declaração e instancia de uma estrutura de dados como podem ver, o uso de cada caso vai variar com o que se está estruturando, quando e em qual escopo deseja instanciar o objeto.

Para acessar, atribuir e modificar o valor de um membro de um elemento de uma estrutura é usado o operador "`.`".

Usando a estrutura do exemplo acima vamos atribuir um valor ao membro `weight` do elemento banana para então podermos printar.

```C++
banana.wieght = 1;
std::cout << banana.weight;
```

Também podemos armazenar o valor do membro numa variavél, desde que o membro da estrutura e a variavél sejam do mesmo tipo,

```C++
int pesoBanana = banana.weight;
```

Como vimos não há diferença entre os membros de uma estrutura e uma variavél, pois em termos praticos são a mesma coisa, outro fato importante é que estruturas também são tipos, e com isso quando instancia um objeto de cada estrutura estamos instanciando uma variavél, ou seja reservando um espaço da memoria de tamanho equivalente ao determinado pela estrutura para atribuir um valor.

### Estruturas e ponteiros

Como qualquer outro tipo de dados, o endereço de memoria de uma estrutura podem ser apontado usando seu proprio tipo de ponteiro,

```C++
struct movies_t {
  std::string title;
  int year;
};

movies_t amovie;
movies_t * pmovie;

pmovie = &amovie;
```

Como podemos ver os operadores padrões do ponteiro irá funcionar bem, e o ponteiro irá apontar para o lugar da memoria onde está armazenado o objeto da estrutura, outro operador importante para lidar com ponteiro e estruturas é o operador `->`, que serve para acessar o membro de um objeto a partir do seu endereço.

As seguintes linhas de comando são equivalente,

```C++
pmovie->title
```

e

```C++
(*pmovie).title
```

Mas é importante se lembrar e não confundir com,

```C++
*pmovie.title
```

que é equivalente a um hipotetico ponteiro `title`, que no caso não existe dentro da estrutura,

```C++
*(pmovie.title)
```

### Estruturas entrelaçadas

Como uma estrutura é uma forma de declarar um tipo é importante deixar claro que é possivel inclusive ter como membros de uma estrutura elementos de outras estruturas, criando assim estruturas entrelaçadas.

```C++
struct movies_t {
  string title;
  int year;
};

struct friends_t {
  string name;
  string email;
  movies_t favorite_movie;
} charlie, maria;

friends_t * pfriends = &charlie;
```

Algo interessante é que embora uma estrutura não possa ter como elemento um membro do mesmo tipo da estrutura ainda é possivel ter como membro um ponteiro para o mesmo tipo da estrutura, como no exemplo a seguir:

```C++
struct linkedInt
{
    int N;
    linkedInt *front;
    linkedInt *back;    
};

    linkedInt N1;
    linkedInt N2;
    linkedInt N3;

    N2.back = &N3;
    N1.front = &N2;
    N2.back = &N1;
    N2.front = &N3;
    N3.back = &N2;
    N3.front = &N1;
```
