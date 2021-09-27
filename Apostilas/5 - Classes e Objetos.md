# Classes e Objetos

Uma das principais estruturas de dados são as Classes, ela implementam uma forma de estruturar os dados de maneira que fique mais legivel tanto para humanos quanto para maquinas. Classes é uma feature caracteristica do C++, que o C não possui, inclusive um dos motivos para existir o C++, não atoa a linguagem C++ é conhecida como "C com classes", que faz parte da proposta inicial da linguagem.

## Classes

Em C++ classes são uma expansão das estruturas de dados, que possuem alem de possuir dados como membros possuem funções como membros. Em nossos textos iremos também nos referir a membros variaveis como propriedades, e membros funções como metodos.

Assim como as estruturas as classes são equivalentes a tipos de dados, e nos permitem instanciar objetos que são equivalentes a variaveis.

Para declararmos uma classe usamos a seguinte sintax:

```C++
class class_name {
  access_specifier_1:
    member1;
  access_specifier_2:
    member2;
  ...
} object_names;
```

Onde `class_name` será o nome da classe, `acces_specifier` são os comandos que definiram o escopo de acesso dos membros que vem em seguida na classe, `member`são os membros da classe, que podem tanto ser propriedades quanto metodos, e `object_names` que é o commando opcional que nos permite instanciar algumas objetos junto com a declaração da classe.

Os `acces_specifier` são comandos opcionais que server para especificar o nivel de acesso de alguns membros, ou seja, serve para especificar quais tipos e classes poderão acessar e modificar os membros dentro daquele escopo de acesso, sendo os escopos definidos dentro dos tres seguintes keywords:

* `private` é o escopo o qual só pode ser acessado apenas por membros da mesma classe, e classes "amigas".
* `protected` é o escopo do qual os membros podem ser acessado por outros membros da mesma classe, de classes derivadas e classes amigas.
* `public` é o escopo de membros que podem ser acessado em qualquer escopo e por qualquer membro.

É importante ressaltar que a sintaxe é muito similar com a de `struct` no C e no C++, e inclusive no caso do C++ é possivel declarar `struct` com metodos, que se comportam igualmente com as classes, variando apenas o escopo de acesso padrão dos membros, sendo por padrão nas `class` o escopo `private:` e nas `struct` o escopo `public:`.

Assim como usamos o operador "`.`" para acessar os membros de uma estrutura e tipo, podemos usar para acessar os membros de uma Classe.

### Membro Variavel (Parametros)

Quando nos referimos a classes podemos convencionar os membros em duas categorias, propriedades e metodos, sendo propriedades se referindo a dados planificados, variaveis e containers, e metodos se referindo a funções associadas a esses dados, ou a classe em se.

Para declararmos as propriedades é usado a mesma sintaxe usada para declarar variaveis:

```C++
class NomeDaClasse{
  tipo nomePropriedade;
}
```

Como vimos para declarar os parametros, basta colocar o tipo do parametro, que pode ser também outra classe ou estrutra, e o nome desse parametro, do mesmo modo que declaramos variaveis, ou os membros de uma estrutura. É importante ressaltar aqui que o espaço ocupado por uma classe será equivalente ao espaço ocupado por seus parametros, sendo assim ao instanciarmos uma variavél do tipo dessa classe, será equivalente em termos de memoria a instanciar os parametros da classe, mais a frente iremos ver o Metodo usado para instanciar objetos de uma classe.

### Membro função (Metodo)

Para declaramos um metodo, ou seja uma função que membro dessa classe, temos duas sintaxes valida, uma para declararmos o metodo dentro da classe, e outro para declararmos "fora" da classe, segue respectivamente as duas sintaxes abaixo:

* Declaração de Classe dentro da classe:

```C++
class NomeDaClasse{
  tipo nomeMetodo(tipo1 parametro1, tipo2 parametro2, ...){
    //... Bloco de codigo
  }
}
```

* Declaração de Classe fora da classe:

```C++
class NomeDaClasse{
  tipo nomeMetodo(tipo1 parametro1, tipo2 parametro2, ...);
}

tipo NomeDaClasse::nomeMetodo(tipo1 parametro1, tipo2 parametro2, ...){
  //... Bloco de Codigo
}

```

Como podemos ver no primeiro caso todo o processo de declaração do metodo ocorre igual a declarar uma função qualquer dentro do bloco de codigo da classe, onde especificamos quando comparamos com as segunda forma pode ser mais compacto e usar menos linha, pois para declararmos o metodo fora da classe, precisamos listar os metodos dentro da classe, e depois declarar ela fora da classe, e para isso será usado o operador "`::`" para indicar que aquela função, a direita do operador, pertence a classe, a esquerda do operador.

Por ser uma função todas as especificações e regras das funções ainda são validas para os metodos, com exceção que agora a função só será acessada a partir de uma instancia, objeto, da classe que o metodo pertence. Através do operador "`.`" para acessar membros do objeto, e do operador "`->`" para acessar membros a partir de um ponteiro.

#### Metodo Construtor

Metodo Construtor é o metodo especial responsavel por instanciar objetos da classe, ele é chamado automaticamente sempre que um objeto é criado, o metodo construtor é declarado como qualquer metodo, com a diferença que ele irá possuir o mesmo nome da classe e não terá retorno de nenhum tipo, nem mesmo `void`.

```C++
class NomeDaClasse{
  tipo1 propriedade1;

  NomeDaClasse(tipo1 parametro1, tipo2 parametro2, ...);
}

tipo NomeDaClasse::NomeDaClasse(tipo1 parametro1, tipo2 parametro2, ...){
  //... Bloco de Codigo
}

```

Assim sempre que formos instanciar um objeto da classe iremos chamar um metodo construtor para que o objeto seja instanciado corretamente da maneira que queremos, através da sintaxe;

```C++
NomeDaClasse objetoA (parametro1, parametro2, ...);
```

##### Multiplos Construtores

É possivel inclusive que, assim como qualquer função, tenhamos diferentes construtores, com parametros diferentes, tanto em quantidade quanto em tipo. Como no exemplo abaixo:

```C++
#include <iostream>

class Rectangle {
    int width, height;
  public:
    Rectangle ();
    Rectangle (int h);
    Rectangle (int,int);
    int area (void) {return (width*height);}
};

Rectangle::Rectangle () {
  width = 5;
  height = 5;
}

Rectangle::Rectangle (int h) {
  width = h;
  height = h;
}

Rectangle::Rectangle (int a, int b) {
  width = a;
  height = b;
}

int main () {
  Rectangle rect (3,4);
  Rectangle rectb;
  Rectangle rectc(7);
  std::cout << rect.area() << std::endl; // 12
  std::cout << rectb.area() << std::endl; // 25
  std::cout << rectc.area() << std::endl;  // 49
  return 0;
}
```

Como podemos ver pelo exemplo acima a nossa classe tem três construtores, e conseguimos instanciar objetos com eles, ao passar os parametros de maneira equivalente ao construtor que se pretende usar.

Nesse exemplo também sobreescrevemos o metodo construtor padrão, que é o construtor sem parametros de entrada, usado para instanciar o objeto "`rectb`", onde é importante ressaltar que ao instanciar um objeto dessa maneira não utilizamos os "`()`" pois ao utilizarmos o parentese vazio estariamos na verdade declarando uma função com retorno da nossa classe.

###### Inicialização de Membros no construtor

Caso o metodo construtor seja usado também para inicializar outros membros, é possivel usar uma notação especifica para inicialização de membros no construtor,

```C++
class Rectangle {
    int width,height;
  public:
    Rectangle(int,int);
    int area() {return width*height;}
};
```

Levando em conta a classe acima veja alternativas para declarar o construtor que inicializia os membros "`width`" e "`height`",

* Altenativa 1, sintaxe normal
```C++
Rectangle::Rectangle (int x, int y) { width=x; height=y; }
```

* Alternativa 2, sintaxe mista

```C++
Rectangle::Rectangle (int x, int y) : width(x) { height=y; }
```

* Alternativa 3, Inicializar na declaração

```C++
Rectangle::Rectangle (int x, int y) : width(x), height(y) { }
```

A diferença entre as alternativas é quando será instanciado os membros do objeto, na sintaxe no normal da alternativa 1 os membros são instanciados e depois os valores são atribuidos, enquanto ao inicialiarmos na declaração os membros já são instanciados com os valores. O que implica em no primeiro caso é preciso que o membro tenha um construtor padrão que irá instanciar, e depois os valores serão atribuidos, no segundo caso os membros já serão instanciados com os parametros corretos, e com isso não precisando de um construtor padrão,

```C++
#include <iostream>
using namespace std;

class Circle {
    double radius;
  public:
    Circle(double r) : radius(r) { }
    double area() {return radius*radius*3.14159265;}
};

class Cylinder {
    Circle base;
    double height;
  public:
    Cylinder(double r, double h) : base (r), height(h) {}
    double volume() {return base.area() * height;}
};

int main () {
  Cylinder foo (10,20);

  cout << "foo's volume: " << foo.volume() << '\n';
  return 0;
}
```

No exemplo acima podemos ver que o membro "`base`" da classe "`Cylinder`" só pode ser instanciado usando a inicialização no construtor, pois a classe "`Circle`" não possue um construtor padrão para instanciar o objeto, como falado acima.

##### Membro destruidor

De maneira parecida ao metodo construtor padrão, temos um metodo destruidor padrão, que é chamado sempre que o objeto é destruido, e como isso podemos sobreescrever nosso destruidor para especificarmos rotina de destruição de objetos, isso se faz necessario e util quando a classe usa alocação dinamica no seu escopo, e precisamos garantir que a memoria alocada seja liberada corretamente, a declaração do destruidor é da mesma maneira do construtor padrão, acrescentando `~` ao inicio do nome do metodo, não possuindo retorno e nem parametros de entrada como no exemplo abaixo,

```C++
#include <iostream>
#include <string>
using namespace std;

class Example4 {
    string* ptr;
  public:
    Example4() : ptr(new string) {}
    Example4 (const string& str) : ptr(new string(str)) {}
    ~Example4 () {delete ptr;}
    const string& content() const {return *ptr;}
};

int main () {
  Example4 foo;
  Example4 bar ("Example");

  cout << "bar's content: " << bar.content() << '\n';
  return 0;
}
```

Nesse exemplo o metodo destruidor será chamado ao fim da função main, pois é o escopo de tempo de vida o qual o objeto bar, e foo pertencem. Sendo importante ressaltar que não é preciso chamar explicitamente a função, visto que sempre que o objeto é destruido é chamado, porem é possivel chama-la como qualquer função membro da classe, que é o que chamamos de pseudo-destruição, pois a rotina dentro do metodo será executado, mas o ciclo de vida do objeto não terá sido encerrado.

### Membros Estaticos

Membros estaticos são propriedades de uma classe que é compartilhado entre todos os objetos dessa classe, ou seja ou acessarmos e modificarmos o valor de um membro estatico, esse valor será alterado em todos os outros objetos, exemplo abaixo:

```C++  
#include <iostream>

class Dummy {
  public:
    static int n;
    Dummy () { 
      n++; 
    };
};

int Dummy::n=0;

int main () {
  Dummy a;
  Dummy b[5];
  std::cout << a.n << std::endl; // 6
  Dummy * c = new Dummy;
  std::cout << Dummy::n << std::endl; // 7
  delete c;

  return 0;
}
```

No exemplo acima vemos uma aplicação de membro estatico para realizar contagem do numero de objetos da classe declarada, é importante ressaltar que o membro estatico precisa ser instanciados fora do escopo da classe, no exemplo usamos a linha `int Dummy::n=0;`, isso ocorre pois os membros estaticos se comportam de maneira similar a variaveis e funções *`non-member`*, que não pertecem a classes funções, com a diferença de que usufruem dos escopos de acessos das classes.

Tanto o comando `a.n` quanto o `Dummy::n` no nosso exemplo dizem respeito a mesma variavél, e possuem o mesmo acesso, assim o uso de um em deprimento do outro vai variar de caso e de escolha pessoal.

Funções também podem ser membros estaticos da classe, se comportando como uma função externa(não membra da classe), mas acessada como um membro da classe. E por se comportar como uma função externa ela não poderá acessar os membros não estaticos da classe, ou seja, ela tem o escopo de uma função declarada fora da classe.

#### Membros valor constantes(Const)

Objetos de uma classe podem ser instanciado como um objeto constante:

```C++
const MyClass myobject;
```

Desse modo os membros do objeto só serão acessados em modo de apenas leitura, ou seja os valores associados aos membros do objeto não poderão ser mudados ao longo do programa, um objeto constante também só poderá acessar e chamar funções constantes, "`const`" da classe, 

```C++
int get() const {return x;}
```

As funções `const` por serem constantes não podem modificar valores de membros não estaticos da classe nem chamar outras funções não `const`, respeitando assim o carater de apenas leitura do objeto.

É importante notar que a declaração acima é para uma função constante, e alem disso também podemos ter notação para funções que retornam valores constantes,

```C++
int get() const {return x;}        // const member function
const int& get() {return x;}       // member function returning a const&
const int& get() const {return x;} // const member function returning a const&
```

Embora objetos constantes só possam acessar metodos constantes, objetos padrões não constantes, também podem acessar as funções constante livremente, e com isso é comum a pratica de boa parte das funções que não alteram valores da classe, serem declaradas como constantes.

### Instanciar objetos

Já vimos anteriormente como instanciarmos objetos e armazenamos em variaveis, dentre as formas de instanciar um objeto em C++ temos,

* Forma funcional: 

```C++
NomeDaClasse nomeDoObjeto(parametro);
```

Nessa forma o objeto é instanciado de maneira analoga a chamar uma função, por isso o nome funcional, e nesse modo passamos os parametros de acordo com o construtor a ser usado.

* Forma associativa

```C++
NomeDaClasse nomeDoObjeto = parametro;
```

A forma associativa só poderá ser usada quando o construtor possuir apenas um parametro

* Forma mista

Também é possivel usar o misto da associativa e da funcional para instanciar o objeto, como no exemplo abaixo

```C++
NomeDaClasse nomeDoObjeto = NomeDaClasse(parametro1, parametro2);
```

* Inicialização Uniforme

```C++
NomeDaClasse nomeDoObjeto {parametro};
```

ou

```C++
NomeDaClasse nomeDoObjeto = {parametro};
```

Essa forma é similar a forma funcional, mas com a diferença de que é usado "`{}`" no lugar dos "`()`", e também podemos usar o operador "`=`" entre o pod e o nome do objeto para tornar a leitura mais clara.

### Uso de ponteiros com classes

<!-- TODO -->

### Uso do comando this

<!-- TODO -->
