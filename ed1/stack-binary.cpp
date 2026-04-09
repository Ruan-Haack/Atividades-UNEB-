#include <iostream> 

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
    void empilhar(int num);
    int desempilhar();
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
    if(novo == nullptr) exit(1);

    novo->info = n;
    novo->prox = nullptr;

    if(topo != nullptr)
        novo->prox = topo;
    
    topo = novo;
};

int Pilha::desempilhar()
{
    int deletado;
    Nodo *aux;
    if(topo == nullptr)
    {
        std::cout << "Pilha vazia...";
        exit(0);
    } else 
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
    while(aux != nullptr)
    {
        std::cout << aux->info;
        aux = aux->prox;
    }
    std::cout << std::endl;
}

void binario(int decimal, Pilha &P)
{
    while( decimal > 0)
    {   
        P.empilhar(decimal % 2);
        std::cout << "Valor empilhado: " << decimal % 2 << std::endl;
        decimal /= 2;
    }
}

int dec(Pilha &P)
{


}

int main() 
{   
    int decimal = 0;
    Pilha P;

    std::cout << "Digite um numero decimal: ";
    std::cin >> decimal;
    binario(decimal, P);
    
    int d = dec(P);
    std::cout << "Numero em Binário: "; P.imprimir();
    
    return 0;
}