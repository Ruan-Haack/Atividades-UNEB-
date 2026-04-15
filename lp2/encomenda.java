public class encomenda
{
    String remetente, destinatario, endereco, cep, origem;
    int codigo;
    float peso;
    
    public Encomenda(String remetente, String dest, String end, String cep,
    String origem, int cod, float peso)
    {
        this.remetente = remetente;
        this.destinatario = dest;
        this.endereco = end;
        this.cep = cep;
        this.origem = origem;
        this.codigo = cod;
        this.peso = peso;
    }
    
    //sem origem, nacional por padrao
    public Encomenda(String remetente, String dest, String end, String cep,
    int cod, float peso)
    {
        this.remetente = remetente;
        this.destinatario = dest;
        this.endereco = end;
        this.origem = "Brasil";
        this.cep = cep;
        this.codigo = cod;
        this.peso = peso;
    }
    
    public float Postarencomenda()
    {
        float precoEnvio;
        
        if(peso <= 100)
        {   
            precoEnvio = 2.50f;
        }else if(peso > 100 && peso <= 400) 
        {
            precoEnvio = 12.00f;
        }else 
        {
        //Math.floor (arredonda pra baixo) devolve um double e '(float)' converte o tipo para não dar erro
            float acrescimo = (float) Math.floor((peso - 400) / 100) * 1.00f;
            precoEnvio = 12 + acrescimo;
        }
        
        //se origem != de brasil, então aplica a taxa
        if(!this.origem.equals("Brasil") && !this.origem.equals("Brazil"))
        {
                precoEnvio += precoEnvio * 0.15f;
        }   
        return precoEnvio;
    }

}
