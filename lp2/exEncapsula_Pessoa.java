
/* O encapsulamento é o conceito de proteger os dados de uma classe,
escondendo seus atributos do acesso direto externo e controlando 
como eles são lidos ou modificados.
*/

public class Pessoa
{
    private String CPF; 
    private String Nome;
    private int idade;
    
    // O construtor permite criar o objeto já com os valores iniciais,
    // passando por "dentro" da classe — o controle ainda é interno
    public Pessoa(String CPF, String Nome, int idade)
    {
        this.Nome = Nome;
        this.CPF = CPF;
        this.idade = idade;
    }
    
    /* 
     * Os SETTERS são métodos públicos que permitem modificar/ESCREVER os atributos
     * de forma controlada. É aqui que poderíamos, por exemplo, validar
     * os dados antes de aceitar (ex: impedir CPF vazio, idade negativa)
    */
    public void setIdade(int idade)
    {
        this.idade = idade;
    }
    
    public void setNome(String Nome)
    {
        this.Nome = Nome;
    }
    
    public void setCPF(String CPF)
    {
        this.CPF = CPF;
    }
    
    /* 
     *Os GETTERS são métodos públicos que permitem LER os atributos 
     *sem expô-los diretamente. O mundo externo "vê" o valor,
     *mas não acessa o atributo em si.
    */
    public int getIdade()
    {
        return this.idade;
    }
    
    public String getNome()
    {
        return this.Nome;
    }
    
    public String getCPF()
    {
        return this.CPF;
    }
}