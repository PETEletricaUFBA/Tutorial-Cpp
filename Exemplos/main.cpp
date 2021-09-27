#include <iostream>
#include <string>

struct movies_t {
        std::string title;
        int year;
    };

struct linkedInt
{
    int N;
    linkedInt *front;
    linkedInt *back;    
};


int main() {

    linkedInt N1;
    linkedInt N2;
    linkedInt N3;

    N2.back = &N3;
    N1.front = &N2;
    N2.back = &N1;
    N2.front = &N3;
    N3.back = &N2;
    N3.front = &N1;
}