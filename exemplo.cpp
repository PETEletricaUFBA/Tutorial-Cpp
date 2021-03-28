#include <iostream>
using namespace std;

class Mother {
  public:
    Mother ()
      { cout << "Mother: no parameters\n"; }
    Mother (int a)
      { cout << "Mother: int parameter\n"; }
    void printar(){
        cout << "Morrer em marte, mas não no impacto." <<std::endl;
    }
};
class Father {
    public:
        Father(){
            cout << "Não achei os cigarros!\n";
        }
    void log(){
        cout << "Se a classe for operária, a ela tudo pertence.\n";
    }
};

class Daughter : public Mother, public Father {
  public:
    Daughter (int a)
      { cout << "Daughter: int parameter\n\n"; }
};

class Son : public Mother {
  public:
    Son (int a) : Mother (a)
      { cout << "Son: int parameter\n\n"; }
};

int main () {

    Mother sofi;
    Daughter kelly(0);
    Son bud(0);
    
    sofi.printar();
    bud.printar();
    kelly.printar();
    kelly.log();

    return 0;
}