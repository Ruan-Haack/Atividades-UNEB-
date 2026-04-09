#include <iostream>
#include <math.h>
class Nodo
{
public:
    int info;
    Nodo *prox;
};

class Pilha
{
private:
    Nodo *topo;

public:
    Pilha();
    void empilhar(int n);
    int desempilhar();
    int ConverDec();
    void imprimir();
};

Pilha::Pilha()
{
    topo = nullptr;
};

void Pilha::empilhar(int n)
{
    Nodo *novo;
    novo = new Nodo;
    if (novo == nullptr)
        exit(1);

    novo->info = n;
    novo->prox = nullptr;

    if (topo != nullptr)
        novo->prox = topo;

    topo = novo;
};

int Pilha::desempilhar()
{
    int deletado;
    Nodo *aux;
    if (topo == nullptr)
    {
        std::cout << "Pilha vazia...";
        exit(0);
    }
    else
    {
        aux = topo;
        deletado = aux->info;
        topo = topo->prox;
        delete aux;
        return deletado;
    }
};

void Pilha::imprimir()
{
    Nodo *aux;
    aux = topo;
    while (aux != nullptr)
    {
        std::cout << aux->info;
        aux = aux->prox;
    }
    std::cout << std::endl;
}

void binario(int decimal, Pilha &P)
{
    while (decimal > 0)
    {
        P.empilhar(decimal % 2);
        std::cout << "Valor empilhado: " << decimal % 2 << std::endl;
        decimal /= 2;
    }
}

int Pilha::ConverDec()
{
    Nodo *aux;
    aux = topo;
    int contador = 0, decimal=0;

    while (aux != nullptr)
    {
        contador++;
        aux = aux->prox;
    }
    aux = topo;
    contador--; // pois deve começar no zero
    while (aux != nullptr)
    {
        if (aux->info == 0)
        {
            std::cout << "Numero 0"<< std::endl;
            contador--;
        }
        else
        {
            decimal += pow(2, contador);
            contador--;
        }
        aux = aux->prox;
    }
    std::cout << "Contador: " << contador << std::endl;
    return decimal;
}

int main()
{
    int d = 0;
    Pilha P;

    std::cout << "Digite um numero decimal: ";
    std::cin >> d;
    binario(d, P);

    int conver = P.ConverDec();
    std::cout << "Numero em Binário: ";
    P.imprimir();
    std::cout << "Numero em Decimal novamente: " << conver;    
    return 0;
}