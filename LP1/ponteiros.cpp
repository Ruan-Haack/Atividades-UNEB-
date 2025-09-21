#include <iostream>

void mostrar(int *ptr,int var);
// int somar1(int *p);

int main(){   

    int var = 15;
    int *ptr = &var;

    mostrar(ptr, var);

    //  usando lambda, passando a referência da variavel do parametro
    auto somar1 = [](int &p)
    {   std::cout << "---------" << std::endl;
        std::cout << "SOMANDO" << std::endl;
        p = p+1;
        std::cout << "---------\n\n";
    };

    somar1(var);
    mostrar(ptr, var);
    std::cout << "FINAL"<< std::endl;
    return 0;
}

void mostrar(int *ptr, int var){
    std::cout << "conteudo de var: " << var << std::endl;
    std::cout << "endereço de var: " << &var << std::endl;
    std::cout << "Conteudo apontado por ponteiro: " << *ptr << std::endl;
    std::cout << "Endereço apontado por ponteiro: " << ptr << std::endl;
    std::cout << "Endereço do ponteiro: " << &ptr << std::endl;
}