import java.util.ArrayList;
public class Aplicativo
{
    private String Nome;
    private String objetivo;
    private int usuarios;
    private double mb;
    private double precoMensal;
    private EmpresaTerceira empresa;
    
    public Aplicativo(String nome, String objetivo, double mb, 
    double precoMensal, EmpresaTerceira empresa, int usr)
{
    
    this.Nome = nome;
    this.objetivo = objetivo;
    this.mb = mb;
    this.precoMensal = precoMensal;
    this.empresa = empresa;
    this.usuarios = usr;
    
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
    
    public void setUsr(int Usr)
    {
        this.usuarios = Usr;
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
    
    public int getUsr()
    {
        return this.usuarios;
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
    
    public void AddUsr() 
    {
        usuarios = usuarios + 1;
    }
    
    public static Aplicativo appcomMaisUsuarios(ArrayList<Aplicativo> lista) 
    {
    
        Aplicativo maior = lista.get(0);
    
        for (Aplicativo app : lista) {
            if (app.getUsr() > maior.getUsr()) {
                maior = app;
            }
        }
        return maior;
    }
    
}