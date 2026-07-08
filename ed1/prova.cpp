#include <iostream>

class Nodo
{
public:
    int info;
    Nodo *prox;
};

class Fila
{
public:
    int info;
    Nodo *inicio, *fim;

public:
    Fila();
    void inserir(int n);
    int retirar();
};

void Fila::inserir(int n)
{
    Nodo *novo = new Nodo();
    if (novo == nullptr)
        exit(1);

    novo->info = n;
    novo->prox = nullptr;

    if (inicio == nullptr)
    {
        inicio = novo;
    }
    else
    {
        fim->prox = novo;
    }
    fim = novo;
}

int Fila::retirar()
{
    if (inicio == nullptr)
        exit(1); // fila vazia
    Nodo *aux = inicio;
    int valor = aux->info;
    inicio = inicio->prox;

    if(inicio == nullptr)
    {
        fim = nullptr;
    }
    delete aux;
    return valor;
}

class Pilha
{
public:
    Nodo *topo;
    Fila F;

public:
    Pilha();
    void inserir(int n);
    void retirar(int n);
};

Pilha::Pilha()
{
    topo = nullptr;
}

void Pilha::inserir(int n)
{
    Nodo *novo = new Nodo();
    novo->info =n;
    novo->prox = topo;
    topo = novo;
}

void Pilha::retirar(int n)
{
    if (topo == nullptr)
        exit(1);

    Nodo *aux = topo;

    while (aux != nullptr && aux->info != n)
    {
        if (aux->prox->info == n)
        {
            break; // para no nó anterior ao nó que contém o n
        }
        aux = aux->prox;
        F.inserir(topo->info); //guardando na estrutura auxiliar fila
        topo = aux;
    }

    if (aux == nullptr)
    {
        std::cout << "N não encontrado" << std::endl;
        exit(0);
    }
    else
    {
        std::cout << "Retirando: " << aux->prox->info << std::endl;
        aux->prox = aux->prox->prox;
    }
}

int main()
{

    return 0;
}