//---------------------------------- Classe para os LEDS de alerta da hidroponica ------------------------------ //



class led
{
  private:
    int _porta;
    
  public:
    led(int porta);
    int porta();
    void acender();
    void apagar();

};
//Função construtora
led::led(int porta)
{
    _porta = porta;

}
int led::porta()
{
  return _porta;
}


//Funções de acender e apagar o LED
void led::acender()
{
    digitalWrite(_porta, HIGH);
}
void led::apagar()
{
    digitalWrite(_porta, LOW);
}
