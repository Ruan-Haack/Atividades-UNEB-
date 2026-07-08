#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// ── Nó da fila ──────────────────────────────
struct Nodo
{
    std::string senha;
    Nodo *prox = nullptr;
};

// ── Fila 
class Fila
{
    Nodo *inicio = nullptr;
    Nodo *fim = nullptr;

public:
    bool vazia() { return inicio == nullptr; }

    void inserir(const std::string &s)
    {
        Nodo *novo = new Nodo{s, nullptr};
        if (vazia())
            inicio = novo;
        else
            fim->prox = novo;
        fim = novo;
    }

    std::string remover()
    {
        if (vazia())
            return "";
        Nodo *aux = inicio;
        std::string val = aux->senha;
        inicio = inicio->prox;
        if (!inicio)
            fim = nullptr;
        delete aux;
        return val;
    }

    void imprimir()
    {
        if (vazia())
        {
            std::cout << "(vazia)\n";
            return;
        }
        for (Nodo *p = inicio; p; p = p->prox)
            std::cout << "[" << p->senha << "]" << (p->prox ? " -> " : "\n");
    }
};


Fila filaPrioritaria, filaComum;
int numP = 1, numC = 1; // contadores de senha
int contadorP = 0;      // prioritários atendidos consecutivamente

// ── Funções do sistema ───────────────────────

void emitirSenha()
{
    int idade = rand() % 100 + 1;
    std::string senha;
    if (idade >= 60)
    {
        senha = "P" + std::to_string(numP++);
        filaPrioritaria.inserir(senha);
    }
    else
    {
        senha = "C" + std::to_string(numC++);
        filaComum.inserir(senha);
    }
    std::cout << "  Idade: " << idade << " anos -> Senha emitida: " << senha << "\n";
}

void chamarSenha()
{
    std::string chamada;

    // A cada 3 prioritários, chama 1 comum (se houver)
    if (contadorP >= 3 && !filaComum.vazia())
    {
        chamada = filaComum.remover();
        contadorP = 0;
        std::cout << "  >> " << chamada << " (comum - apos 3 prioritarios)\n";
    }
    else if (!filaPrioritaria.vazia())
    {
        chamada = filaPrioritaria.remover();
        contadorP++;
        std::cout << "  >> " << chamada << " (prioritario)\n";
    }
    else if (!filaComum.vazia())
    {
        chamada = filaComum.remover();
        contadorP = 0;
        std::cout << "  >> " << chamada << " (comum)\n";
    }
    else
    {
        std::cout << "  >> Filas vazias!\n";
    }
}

void mostrarFilas()
{
    std::cout << "  Prioritaria: ";
    filaPrioritaria.imprimir();
    std::cout << "  Comum      : ";
    filaComum.imprimir();
}

// ── Main ─────────────────────────────────────
int main()
{
    srand(time(0));
    int op;

    do
    {
        std::cout << "\n=== SISTEMA DE SENHAS ===\n";
        std::cout << "1. Emitir senha\n";
        std::cout << "2. Chamar proxima senha\n";
        std::cout << "3. Ver filas\n";
        std::cout << "0. Sair\n";
        std::cout << "Opcao: ";
        std::cin >> op;

        switch (op)
        {
        case 1:
            emitirSenha();
            break;
        case 2:
            chamarSenha();
            break;
        case 3:
            mostrarFilas();
            break;
        case 0:
            std::cout << "Encerrando...\n";
            break;
        default:
            std::cout << "Opcao invalida.\n";
        }
    } while (op != 0);

    return 0;
}