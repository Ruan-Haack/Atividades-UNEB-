
public class Livro  
{
    String titulo;
    String autor;
    String editora;
    int ano_pub;
    String genero;
    int paginas;

    public void cadastrarLivros(String titulo, String autor, String editora, int ano, String genero, int pg)
    {
        this.titulo = titulo;
        this.autor = autor;
        this.editora = editora;
        this.ano_pub = ano;
        this.genero = genero;
        this.paginas = pg;
    }

    public void classificar()
    {       
        int ano_atual = 2026;
        int idade = ano_atual - this.ano_pub;

        if (idade > 500)
        {
            System.out.println("---------- LIVRO ANTIGO ----------");
        } else if( idade > 100) 
        {
            System.out.println("---------- LIVRO TRADICIONAL ----------");
        } else  
            System.out.println("---------- LIVRO MODERNO ----------");
    }

    public void calcEmprestimo()
    {
        if (this.paginas <= 50)
        {
            System.out.println("---------- DEVOLVER EM ATEH 4 DIAS ----------");  
        } else if (this.paginas <= 300)
        {
            System.out.println("---------- DEVOLVER EM ATEH 7 DIAS ----------");  
        } else
        {
            System.out.println("---------- DEVOLVER EM ATEH 14 DIAS ----------");  
        }

    }
}   