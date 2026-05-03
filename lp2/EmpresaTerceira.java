
public class EmpresaTerceira
{   
    private String telefone;
    private String CNPJ;
    private String Nome;
    private Usuarios user;
    
    public EmpresaTerceira(String telefone, String cnpj, String nome, Usuarios user)
    {
        this.telefone = telefone;
        this.CNPJ = cnpj;
        this.Nome = nome;
        this.user = user;
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
    
    public void setUsr(Usuarios user)
    {
        this.user = user;
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
    
    public Usuarios getUsr()
    {
        return this.user;
    }
    
    public boolean podediminuirValor() {
        return user.podeSubstituir();
    }
}
