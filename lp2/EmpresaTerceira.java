
public class EmpresaTerceira
{
    // instance variables - replace the example below with your own
    private String telefone;
    private String CNPJ;
    private String Nome;
    
    public EmpresaTerceira(String telefone, String cnpj, String nome)
    {
        this.telefone = telefone;
        this.CNPJ = cnpj;
        this.Nome = nome;
    }

    public void setTelefone(String telefone)
    {
        this.telefone = telefone;
    }

    public void setCNPJ(String cnpj)
    {
        this.CNPJ = cnpj;
    }
    
    public void setNome(String nome)
    {
        this.Nome = nome;
    }
    
    public String getTelefone()
    {
        return this.telefone;
    }
    
    public String getNome()
    {
        return this.Nome;
    }
    
    public String getCNPJ()
    {
        return this.CNPJ;
    }
    
}
