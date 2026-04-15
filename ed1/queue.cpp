#include <iostream>

class Nodo
{
public:
    int info;
    Nodo *prox;
};

class Queue
{
    Nodo *inicio;
    Nodo *fim;

public:
    Queue();
    void inserir(int n);
    int retirar();
    void imprimir();
};

Queue::Queue() // construtor
{
    inicio = nullptr;
    fim = nullptr;
};

void Queue::inserir(int n)
{
    Nodo *novo = new Nodo();
    novo->info = n;
    novo->prox = nullptr;

    if (novo == nullptr)
        exit(1);

    if (inicio == nullptr)
    {
        inicio = novo;
    }
    else
        fim->prox = novo;

    fim = novo;
};

int Queue::retirar()
{
    Nodo *aux;
    aux = inicio;
    int valor = aux->info;
    inicio = inicio->prox; // atribuindo o proximo elemento ao inicio

    if (aux == nullptr)
        exit(1);

    if (inicio == nullptr)
    {
        fim = nullptr;
    }
    delete aux;
    return valor;
};
void Queue::imprimir()
{
    Nodo *aux = inicio;
    while (aux != nullptr)
    {
        std::cout << "[" << aux->info << "] -> ";
        aux = aux->prox;
    }
    std::cout << "NULL" << std::endl;
};

int main()
{
    Queue fila;

    //number just for an example, but it works with I/O
    fila.inserir(5);
    fila.inserir(8);
    fila.inserir(0);
    fila.inserir(3);

    std::cout << "Numeros na fila: ";
    fila.imprimir();

    std::cout << "Retirando um numero: " << fila.retirar() << std::endl;

    std::cout << "Fila apos remocao: ";
    fila.imprimir();
    std::cout << "Retirando um numero: " << fila.retirar();

    std::cout << "Fila apos remocao: ";
    fila.imprimir();

    return 0;
}
