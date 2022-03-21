class medidor
{
  private:
    int _porta;
    
  public:
    medidor(int porta);
    int porta();
    void estado();


//Funções de acender e apagar o LED
void medidor::estado()
{
    digitalRead(_porta);
}
