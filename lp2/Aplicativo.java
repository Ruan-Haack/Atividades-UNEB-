public class Aplicativo
{
    private String Nome;
    private String objetivo;
    private double mb;
    private double precoMensal;
    private EmpresaTerceira empresa;
    
    public Aplicativo(String nome, String objetivo, double mb, 
    double precoMensal, EmpresaTerceira empresa)
{
    
    this.Nome = nome;
    this.objetivo = objetivo;
    this.mb = mb;
    this.precoMensal = precoMensal;
    this.empresa = empresa; 
    
}

    //SETTERS 
    
    public void setNome(String nome)
    {
        this.Nome = nome;
    }
    
    public void setObjetivo(String objetivo)
    {
        this.objetivo = objetivo;
    }
    
    public void setMb(double mb)
    {
        this.mb = mb;
    }
    
    public void setprecoMensal(double precoMensal)
    {
        if (precoMensal >= 0) {
            this.precoMensal = precoMensal;
        } else {
            System.out.println("[ERRO] -O preço não pode ser negativo!");
        }
    }
    
    public void setEmpresa(EmpresaTerceira empresa)
    {
        this.empresa = empresa;
    }
    
    //GETTERS
    
    public String getNome()
    {
        return this.Nome;
    }
        
    public String getObjetivo()
    {
        return this.objetivo;
    }

    public double getMb()
    {
        return this.mb;
    }
    
    public double getPrecoMensal()
    {
        return this.precoMensal;
    }
    
    public EmpresaTerceira getEmpresa()
    {
        return this.empresa;
    }
    
    public boolean podeSubstituir(Aplicativo outro)
    {
        return this.objetivo.equals(outro.getObjetivo()) 
           && this.precoMensal <= outro.getPrecoMensal();
    }

    public void imprimirDados()
    {
        System.out.println("Nome: " + this.Nome);
        System.out.println("Preço mensal: " + this.precoMensal);
        System.out.println("Empresa: " + this.empresa.getNome());
    }
    
}