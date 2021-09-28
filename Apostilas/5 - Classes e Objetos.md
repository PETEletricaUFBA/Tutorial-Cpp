# Classes e Objetos

Uma das principais estruturas de dados são as Classes, elas implementam uma forma de estruturar os dados de maneira que fique mais legível tanto para humanos quanto para máquinas. Classes é uma feature característica do C++, que o C não possui, inclusive um dos motivos para existir o C++, não à toa a linguagem C++ é conhecida como "C com classes", que faz parte da proposta inicial da linguagem.

## Classes

Em C++ classes são uma expansão das estruturas de dados, que além de possuir dados como membros possuem também funções como membros. Em nossos textos iremos também nos referir a membros variáveis como propriedades, e membros funções como métodos.

Assim como as estruturas, as classes são equivalentes a tipos de dados, e nos permite instanciar objetos que são equivalentes a variáveis.

Para declararmos uma classe usamos a seguinte sintaxe:

```C++
class class_name {
  access_specifier_1:
    member1;
  access_specifier_2:
    member2;
  ...
} object_names;
```

Onde `class_name` será o nome da classe, `acces_specifier` são os comandos que definiram o escopo de acesso dos membros que vem em seguida na classe, `member`são os membros da classe, que podem tanto ser propriedades quanto métodos, e `object_names` que é o comando opcional que nos permite instanciar algumas objetos junto com a declaração da classe.

Os `acces_specifier` são comandos opcionais que serve para especificar o nível de acesso de alguns membros, ou seja, serve para especificar quais tipos e classes poderão acessar e modificar os membros dentro daquele escopo de acesso, sendo os escopos definidos dentro dos três seguintes keywords:

* `private` é o escopo o qual só pode ser acessado apenas por membros da mesma classe, e classes "amigas".
* `protected` é o escopo do qual os membros podem ser acessados por outros membros da mesma classe, de classes derivadas e classes amigas.
* `public` é o escopo de membros que pode ser acessado em qualquer escopo e por qualquer membro.

É importante ressaltar que a sintaxe é muito similar com a de `struct` no C e no C++, e inclusive no caso do C++ é possível declarar `struct` com métodos, que se comportam igualmente com as classes, variando apenas o escopo de acesso padrão dos membros, sendo por padrão nas `class` o escopo `private:` e nas `struct` o escopo `public:`.

Assim como usamos o operador "`.`" para acessar os membros de uma estrutura e tipo, podemos usar para acessar os membros de uma Classe.

### Membro Variável (Parâmetros)

Quando nos referimos a classes podemos convencionar os membros em duas categorias, propriedades e métodos, sendo propriedades se referindo a dados planificados, variáveis e containers, e métodos se referindo a funções associadas a esses dados, ou a classe em se.

Para declararmos as propriedades é usado a mesma sintaxe usada para declarar variáveis:

```C++
class NomeDaClasse{
  tipo nomePropriedade;
}
```

Como vimos para declarar os parâmetros, basta colocar o tipo do parâmetro, que pode ser também outra classe ou estrutura, e o nome desse parâmetro, do mesmo modo que declaramos variáveis, ou os membros de uma estrutura. É importante ressaltar aqui que o espaço ocupado por uma classe será equivalente ao espaço ocupado por seus parâmetros, sendo assim ao instanciarmos uma variável do tipo dessa classe, será equivalente em termos de memória a instanciar os parâmetros da classe, mais a frente iremos ver o Método usado para instanciar objetos de uma classe.

### Membro função (Método)

Para declararmos um método, ou seja uma função que membro desta classe, temos duas sintaxes válida, uma para declararmos o método dentro da classe, e outro para declararmos "fora" da classe, seguem respectivamente as duas sintaxes abaixo:

* Declaração de Classe dentro da classe:

```C++
class NomeDaClasse{
  tipo nomeMetodo(tipo1 parametro1, tipo2 parametro2, ...){
    //... Bloco de código
  }
}
```

* Declaração de Classe fora da classe:

```C++
class NomeDaClasse{
  tipo nomeMetodo(tipo1 parametro1, tipo2 parametro2, ...);
}

tipo NomeDaClasse::nomeMetodo(tipo1 parametro1, tipo2 parametro2, ...){
  //... Bloco de Código
}

```

Como podemos ver no primeiro caso todo o processo de declaração do método ocorre igual a declarar uma função qualquer dentro do bloco de código da classe, onde especificamos quando comparamos com as segunda forma pode ser mais compacto e usar menos linha, pois para declararmos o método fora da classe, precisamos listar os métodos dentro da classe, e depois declarar ela fora da classe, e para isso será usado o operador "`::`" para indicar que aquela função, a direita do operador, pertence a classe, à esquerda do operador.

Por ser uma função, todas as especificações e regras das funções ainda são válidas para os métodos, com exceção que agora a função só será acessada a partir de uma instância, objeto, da classe a que o método pertence. Através do operador "`.`" para acessar membros do objeto, e do operador "`->`" para acessar membros a partir de um ponteiro.

#### Método Construtor

Método Construtor é o método especial responsável por instanciar objetos da classe, ele é chamado automaticamente sempre que um objeto é criado, o método construtor é declarado como qualquer método, com a diferença que ele irá possuir o mesmo nome da classe e não terá retorno de nenhum tipo, nem mesmo `void`.

```C++
class NomeDaClasse{
  tipo1 propriedade1;

  NomeDaClasse(tipo1 parametro1, tipo2 parametro2, ...);
}

tipo NomeDaClasse::NomeDaClasse(tipo1 parametro1, tipo2 parametro2, ...){
  //... Bloco de Código
}

```

Assim sempre que formos instanciar um objeto da classe iremos chamar um método construtor para que o objeto seja instanciado corretamente da maneira que queremos, através da sintaxe;

```C++
NomeDaClasse objetoA (parametro1, parametro2, ...);
```

##### Múltiplos Construtores

É possível inclusive que, assim como qualquer função, tenhamos diferentes construtores, com parâmetros diferentes, tanto em quantidade quanto em tipo. Como no exemplo abaixo:

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

Como podemos ver pelo exemplo acima, a nossa classe tem três construtores, e conseguimos instanciar objetos com eles, ao passar os parâmetros de maneira equivalente ao construtor que se pretende usar.

Nesse exemplo também sobrescrevemos o método construtor padrão, que é o construtor sem parâmetros de entrada, usado para instanciar o objeto "`rectb`", onde é importante ressaltar que ao instanciar um objeto dessa maneira não utilizamos os "`()`" pois ao utilizarmos o parêntese vazio estaríamos na verdade declarando uma função com retorno da nossa classe.

###### Inicialização de Membros no construtor

Caso o método construtor seja usado também para inicializar outros membros, é possível usar uma notação específica para inicialização de membros no construtor,

```C++
class Rectangle {
    int width,height;
  public:
    Rectangle(int,int);
    int area() {return width*height;}
};
```

Levando em conta a classe acima veja alternativas para declarar o construtor que inicializa os membros "`width`" e "`height`",

* Alternativa 1, sintaxe normal
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

A diferença entre as alternativas é quando será instanciado os membros do objeto, na sintaxe no normal da alternativa 1 os membros são instanciados e depois os valores são atribuídos, enquanto ao inicializamos na declaração os membros já são instanciados com os valores. O que implica em no primeiro caso é preciso que o membro tenha um construtor padrão que irá instanciar, e depois os valores serão atribuídos, no segundo caso os membros já serão instanciados com os parâmetros corretos, e com isso não precisando de um construtor padrão,

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

No exemplo acima podemos ver que o membro "`base`" da classe "`Cylinder`" só pode ser instanciado usando a inicialização no construtor, pois a classe "`Circle`" não possui um construtor padrão para instanciar o objeto, como falado acima.

##### Membro destruidor

De maneira parecida ao método construtor padrão, temos um método destruidor padrão, que é chamado sempre que o objeto é destruído, e como isso podemos sobrescrever nosso destruidor para especificarmos rotina de destruição de objetos, isso se faz necessário e útil quando a classe usa alocação dinâmica no seu escopo, e precisamos garantir que a memória alocada seja liberada corretamente, a declaração do destruidor é da mesma maneira do construtor padrão, acrescentando `~` ao início do nome do método, não possuindo retorno e nem parâmetros de entrada como no exemplo abaixo,

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

Nesse exemplo o método destruidor será chamado ao fim da função main, pois é o escopo de tempo de vida o qual o objeto `bar`, e `foo` pertencem. Sendo importante ressaltar que não é preciso chamar explicitamente a função, visto que sempre que o objeto é destruído é chamado, porém é possível chamá-la como qualquer função membro da classe, que é o que chamamos de pseudo-destruição, pois a rotina dentro do método será executado, mas o ciclo de vida do objeto não terá sido encerrado.

### Membros Estáticos

Membros estáticos são propriedades de uma classe que é compartilhado entre todos os objetos dessa classe, ou seja ou acessarmos e modificarmos o valor de um membro estático, esse valor será alterado em todos os outros objetos, exemplo abaixo:

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

No exemplo acima vemos uma aplicação de membro estático para realizar contagem do número de objetos da classe declarada, é importante ressaltar que o membro estático precisa ser instanciados fora do escopo da classe, no exemplo usamos a linha `int Dummy::n=0;`, isso ocorre pois os membros estáticos se comportam de maneira similar a variáveis e funções *`non-member`*, que não pertencem a classes , com a diferença de que usufruem dos escopos de acessos das classes.

Tanto o comando `a.n` quanto o `Dummy::n` no nosso exemplo dizem respeito a mesma variável, e possuem o mesmo acesso, assim o uso de um em detrimento do outro vai variar de caso e de escolha pessoal.

Funções também podem ser membros estáticos da classe, se comportando como uma função externa(não membra da classe), mas acessada como um membro da classe. E por se comportar como uma função externa ela não poderá acessar os membros não estáticos da classe, ou seja, ela tem o escopo de uma função declarada fora da classe.

#### Membros valor constantes(Const)

Objetos de uma classe podem ser instanciado como um objeto constante:

```C++
const MyClass myobject;
```

Desse modo os membros do objeto só serão acessados em modo de apenas leitura, ou seja os valores associados aos membros do objeto não poderão ser mudados ao longo do programa, um objeto constante também só poderá acessar e chamar funções constantes, "`const`" da classe,

```C++
int get() const {return x;}
```

As funções `const` por serem constantes não podem modificar valores de membros não estáticos da classe nem chamar outras funções não `const`, respeitando assim o caráter de apenas leitura do objeto.

É importante notar que a declaração acima é para uma função constante, e além disso também podemos ter notação para funções que retornam valores constantes,

```C++
int get() const {return x;}        // const member function
const int& get() {return x;}       // member function returning a const&
const int& get() const {return x;} // const member function returning a const&
```

Embora objetos constantes só possam acessar métodos constantes, objetos padrões não constantes, também podem acessar as funções constante livremente, e com isso é comum a prática de boa parte das funções que não alteram valores da classe, serem declaradas como constantes.

### Instanciar objetos

Já vimos anteriormente como instanciar os objetos e armazenar em variáveis, dentre as formas de instanciar um objeto em C++ temos,

* Forma funcional:

```C++
NomeDaClasse nomeDoObjeto(parametro);
```

Dessa forma o objeto é instanciado de maneira análoga a chamar uma função, por isso o nome funcional, e nesse modo passamos os parâmetros de acordo com o construtor a ser usado.

* Forma associativa

```C++
NomeDaClasse nomeDoObjeto = parametro;
```

A forma associativa só poderá ser usada quando o construtor possuir apenas um parâmetro

* Forma mista

Também é possível usar o misto da associativa e da funcional para instanciar o objeto, como no exemplo abaixo

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

Como qualquer outro tipo de dados, o endereço de memória de uma classe podem ser apontado usando seu próprio tipo de ponteiro,

```C++
class movies_t {
  public:
  std::string title;
  int year;
};

movies_t amovie;
movies_t * pmovie;

pmovie = &amovie;
```

Como podemos ver os operadores padrões do ponteiro irá funcionar bem, e o ponteiro irá apontar para o lugar da memória onde está armazenado o objeto da classe, outro operador importante para lidar com ponteiro e classes é o operador `->`, que serve para acessar o membro de um objeto a partir do seu endereço.

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

que é equivalente a um hipotético ponteiro `title`, que no caso não existe dentro da classe,

```C++
*(pmovie.title)
```

### Uso do comando this

O comando this é um ponteiro para o objeto o qual a função método é executada, sendo usada com alguns membros da classe para referenciar a si mesmo, como no exemplo abaixo

```C++
// example on this
#include <iostream>
using namespace std;

class Dummy {
  public:
    bool isitme (Dummy& param);
};

bool Dummy::isitme (Dummy& param)
{
  if (&param == this) return true;
  else return false;
}

int main () {
  Dummy a;
  Dummy* b = &a;
  if ( b->isitme(a) )
    cout << "yes, &a is b\n";
  return 0;
}
```
