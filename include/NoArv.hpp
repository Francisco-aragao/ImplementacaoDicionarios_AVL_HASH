#ifndef NoArv_h
#define NoArv_h

#include "../include/Verbete.hpp"

#include <iostream>

using std::string;

class NoArv {
  private:
    Verbete verbete;
    NoArv *direita = nullptr;
    NoArv *esquerda = nullptr;
    NoArv *pai = nullptr;
  
  public:
    NoArv();
    Verbete getVerbete();
    NoArv(char tipo, string nome, string significado);
    void adicionar(char tipo, string nome, string significado);
    NoArv* getDir();
    NoArv* getEsq();
    NoArv* getPai();
    void setDir(NoArv* no);
    void setEsq(NoArv* no);
    void setPai(NoArv* no);
        
};

#endif