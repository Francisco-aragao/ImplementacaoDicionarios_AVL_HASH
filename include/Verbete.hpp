#ifndef Verbete_h
#define Verbete_h

#include "../include/FilaSignificado.hpp"

using std::string;

class Verbete {
  private:
    char tipo;
    string nome;  
    FilaSignificado significado;
    bool cheio = false;

  public:
    Verbete();
    Verbete(char tipo, string nome, string definicao);
    char getTipo();
    string getNome();
    string getSignificados(int j);
    bool temSignificado();
    void setSignificados(string definicao);
    void setCheio(bool cheio);
};

#endif