public class Passagem
{
    String ID, origem, destino, data, horapartida,tipopassagem, cpf;
    int numassento;
    float precobase;
        
    public Passagem(String id, String ori,String dest ,String data, String hora, String tipo,
    float preco)
    {
        this.ID = id;
        this.origem = ori;
        this.destino = dest;
        this.data = data;
        this.horapartida = hora;
        this.tipopassagem = tipo;
        this.precobase = preco;
    }
    
    public Passagem(String id, String ori,String dest ,String data, String hora, String tipo, String cpf,
    float preco)
    {
        this.ID = id;
        this.origem = ori;
        this.destino = dest;
        this.data = data;
        this.horapartida = hora;
        this.tipopassagem = tipo;
        this.cpf = cpf;
        this.precobase = preco;
    }   
    
    public int EscolherAssento(int lugar)
    {
        return this.numassento = lugar;
    }
    
    public void CancelarPassagem()
    {
        System.out.println("Numero do assento e cpf excluido!!");
        this.numassento = 0;
        this.cpf = null;
    }
    
    public float CalcularPreco()
    {
        float precofinal;
        this.tipopassagem = this.tipopassagem.toUpperCase();
        switch (this.tipopassagem)
        {
            case "ECONOMICA":
                 precofinal = this.precobase + (this.precobase * 0.1f);
                break;
            case "EXECUTIVA":
                precofinal = this.precobase + (this.precobase * 0.5f);
                break;
            case "PRIMEIRA CLASSE":
                precofinal = this.precobase + (this.precobase * 0.9f);
                break;    
            default:
                System.out.println("Classe invalida ou inesistente!!");
                return 1;
        }
        return precofinal;
    }
    
    public float CalcularPreco(float percentual)
    {
        float precofinal = this.precobase + (this.precobase * percentual);
        return precofinal;
    }
}