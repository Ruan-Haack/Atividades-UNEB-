import java.util.ArrayList;
public class Usuarios
{
    private String login;
    private String senha;
    private String dataAtivacao;
    private double gastosApp;
    private ArrayList<Aplicativo> apps;
    
    public Usuarios(String log, String senha, String data, double gastoApp)
    {
        this.login = log;
        this.senha = senha;
        this.dataAtivacao = data;
        this.gastosApp = gastoApp;
        this.apps = new ArrayList<>();
    }
    
    //Getters
    public String getLogin(){return this.login;}
    public String getSenha(){return this.senha;}
    public String getData(){return this.dataAtivacao;}
    public double getgastosApp(){return this.gastosApp;}
    public ArrayList<Aplicativo> getApps() { return this.apps; }
    
    //Setters
    public void setLogin(String login)
    {
        this.login = login;
    }
    
    public void setSenha(String senha)
    {
        this.senha = senha;
    }
    
    public void setData(String data)
    {
        this.dataAtivacao = data;
    }
    
    public void setGastos(double gasto)
    {
        this.gastosApp = gasto;
    }
    
    public void adquirirApp(Aplicativo app) 
    { 
        this.apps.add(app);
        this.gastosApp += app.getPrecoMensal();
        app.AddUsr();
    }
    
    public boolean podeSubstituir() {
        
        for (int i = 0; i < apps.size(); i++) {
        
            for (int j = 0; j < apps.size(); j++) {
            
                if (i != j && apps.get(j).podeSubstituir(apps.get(i))) {
                    return true;
                }
            
            }
        
        }
        
        return false;
    }
    
    
    
}