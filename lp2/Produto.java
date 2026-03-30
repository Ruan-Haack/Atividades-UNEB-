
public class Produto
{
    float preco_custo;
    float preco_venda;
    String nome_produto; 
    int codigo;
    int qtd_disponivel;

    public Produto(float preco, String nome, int codigo, int qtd_disponivel)
    {
        this.preco_custo = preco;
        this.nome_produto = nome;
        this.codigo = codigo;
        this.qtd_disponivel = qtd_disponivel;
    }

    public float precoVenda(float percentual)
    {
        if(percentual >= 70)
        {
            System.out.println("-----------PREÇO ABUSIVO-----------");
            return preco_custo + (preco_custo * (10f/100f)); //taxa minima para lucrar
        };
        float lucro = preco_custo * (percentual/100f);
        
        return this.preco_venda = preco_custo + lucro;
    }

    public void abastecerEstoque(int qtd_adicao)
    {
        if (qtd_adicao > 0)
        {
            this.qtd_disponivel += qtd_adicao;
        } else
        {
            System.out.println("A quantidade a adicionar deve ser maior que 0");
        }
    }

    public void removerEstoque(int qtd_remove)
    {
        if (qtd_remove > 0)
        {
            if((this.qtd_disponivel - qtd_remove) < 0)
            {
                System.out.println("Produtos Insuficientes, total: " + this.qtd_disponivel);

            } else
                this.qtd_disponivel -= qtd_remove;
        } else
        {
            System.out.println("A quantidade a adicionar deve ser maior que 0");
        }

    }

    public void exibirResumo(int quantidade) {
        System.out.println("Produto: " + nome_produto);
        System.out.println("Quantidade: " + quantidade);
        System.out.println("Total: R$ " + preco_venda * quantidade);
    }

}