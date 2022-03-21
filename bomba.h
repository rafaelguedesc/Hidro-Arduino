//--------------------Classe para o funcionamento das bombas--------------------//



class bomba
{
private:
    int _porta;
    bool _estado;

public:
    bomba(int porta);
    int porta();
    bool estado();
    void ligar();
    void desligar();
};

// Função construtora
bomba::bomba(int porta)
{
    _porta = porta;
    _estado = false;
}
int bomba::porta()
{
  return _porta;
}
// Função informativa
bool bomba::estado()
{
    return _estado;
}

// Funçoes de funcionamento da bomba
void bomba::ligar()
{
    digitalWrite(_porta, HIGH);
}
void bomba::desligar()
{
    digitalWrite(_porta, LOW);
}
