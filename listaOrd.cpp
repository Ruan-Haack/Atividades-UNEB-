#include <iostream>
using namespace std;

class Nodo{
        public:
         int info;
         struct Nodo *ant,*prox;
};

class Lista2Ord{
    Nodo *inicio;
public:
    Lista2Ord();
    void inserir(int n);
    int buscar (int n);
    int retirar(int n);
    void listar();
};



int main()
{   Lista2Ord l2;
    char op;
    int n;
    for (;;)
    {system("cls");

      cout << "\n----------------------------------";
      cout << "\n    LISTA DUPLAMENTE ENCADEADA\n\n";
      cout << "\n I: Inserir um elemento";
      cout << "\n R: Retirar um elemento";
      cout << "\n B: Buscar um elemento";
      cout << "\n L: Listar";
      cout << "\n S: Sair";
      cout << "\n\n\n Digite sua opcao: ";
      cin >> op;
      if (islower(op))op =toupper(op);

    switch (op)
    {
       case 'I': cout << "\n-----Inserir-----\n";
                 cout << "\n Digite um numero: ";
                 cin >> n;
                 l2.inserir(n);
                 break;
       case 'R': cout << "\n-----Retirar-----\n";
                 cout << "\n Digite un numero: ";
                 cin >> n;
                 if (l2.retirar(n)== 0)cout << "\n Numero nao encontra-se na Lista\n\n";
                 else cout << "\n Numero retirado da Lista\n\n ";
                 system("pause");
                 break;
       case 'B': cout << "\n-----Buscar-----\n";
                 cout << "\n Digite un numero: ";
                 cin >> n;
                 if (l2.buscar(n)== 0)cout << "\n Numero nao encontra-se na Lista\n\n";
                 else cout << "\n Numero encontra-se na Lista\n\n ";
                 system("pause");
                 break;
       case 'L': l2.listar();
                 system("pause");
                 break;
       case 'S': exit(1);

    }  // fim case

}  // fim for
    return 0;
}



//*********************************************
//   Metodos
//*********************************************
// Inserir um elemento na ordem numerica ascendente

Lista2Ord::Lista2Ord (){
    inicio = nullptr;
}

void Lista2Ord:: inserir(int n){
     Nodo *novo, *atual;
     novo = new Nodo;
     if (!novo)exit(1);
     novo->info = n;
     if(inicio == NULL){
        novo->prox = NULL;
        novo->ant = NULL;
        inicio = novo;
        return;
     }

     atual = inicio;
     while((atual->prox != nullptr) && (novo->info > atual->info)){

        atual = atual->prox;
     }
     if((atual->prox == NULL) &&(novo->info > atual->info))
          {atual->prox = novo;
           novo->ant = atual;
           novo->prox = NULL; }
     else if (atual == inicio){
           novo->prox = inicio;
           novo->ant = NULL;
           inicio->ant = novo;
           inicio = novo;
           }
           else {
            atual->ant->prox = novo;
            novo->ant = atual -> ant;
            novo->prox = atual;
            atual->ant= novo;
           }
}

// buscar um elemto na fila  1 existe 0 nao esxiste
int Lista2Ord::buscar  (int n){
    Nodo *aux;
    aux = inicio;
    while((aux != NULL)&&( n != aux-> info))
        aux = aux->prox;
    if ( aux == NULL) return 0;
    else return 1;
      }

// retirar um elemento da lista
int Lista2Ord::retirar (int n){
    Nodo  *atual, *ret;
    atual =inicio;
    if(inicio == nullptr) return 0;
     while((atual->prox != nullptr)&& (n != atual->info))
        {atual = atual->prox;}

     if(atual->info != n) return 0;
     if (atual == inicio){
           ret = inicio;
           inicio = inicio->prox;
           if (inicio != NULL)
           inicio->ant = NULL;
           }
     else if ( atual->prox !=NULL){
            ret = atual;
            atual->ant->prox = atual->prox;
            atual->prox->ant = atual->ant;
           }
           else {
            ret = atual;
            atual->ant->prox = NULL;
           }

      delete ret;
      return 1;
}
// Imprimir os elementos da lista
void Lista2Ord::listar (){
 Nodo *atual = inicio;
 cout <<"\n\nLISTA ATUAL\n\n";
  while (atual!= nullptr){
    cout << atual->info;
    if( atual->prox != nullptr)cout << " <-> ";
    atual = atual->prox;
  }
  cout << "\n\n\n";
 }

