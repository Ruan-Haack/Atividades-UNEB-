#include <iostream>
#include <math.h>
#include <stdlib.h>

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
    if (topo == nullptr)
    {
        std::cout << "Pilha vazia...";
        exit(0);
    }
    Nodo *aux;
    int deletado = aux->info;

    aux = topo;
    deletado = aux->info;
    topo = topo->prox;
    delete aux;
    return deletado;
};

void Pilha::imprimir()
{
    Nodo *aux = topo;
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
    int contador = 0, decimal = 0;

    while (aux != nullptr) // contar quantos elementos tem na pilha
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
            contador--;
        }
        else
        {
            decimal += pow(2, contador);
            contador--;
        }
        aux = aux->prox;
    }
    return decimal;
}

void menu(int d, Pilha &P)
{
    int op;
    int conver;
    for (;;)
    {
        std::cout << "1 - Converter para binário" << std::endl;
        std::cout << "2 - Converter para decimal (necessário passar pela opção 1 antes)" << std::endl;
        std::cout << "3 - Imprimir" << std::endl;
        std::cout << "4 - Sair" << std::endl;
        std::cout << "Digite uma opção: ";
        std::cin >> op;
        switch (op)
        {
        case 1:
        {
            binario(d, P);
            break;
        }
        case 2:
        {
            system("clear");
            conver = 0;
            conver = P.ConverDec();
            std::cout << "Numero em Decimal novamente: " << conver << std::endl;
            break;
        }
        case 3:
        {
            system("clear");
            P.imprimir();
            std::cout << std::endl;
            break;
        }
        case 4:
        {
            system("clear");
            std::cout << "Saindo...";
            exit(0);
            break;
        }
        default:
            system("clear");
            std::cout << "Numero invalido, encerrando programa...";
            exit(0);
            break;
        }
        op = 0;
    }
}
int main()
{
    int d = 0;
    Pilha P;

    std::cout << "Digite um numero decimal: ";
    std::cin >> d;
    menu(d, P);

    return 0;
}