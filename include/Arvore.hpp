#ifndef Arvore_h
#define Arvore_h

#include "../include/NoArv.hpp"
#include "../include/msgassert.hpp"

#include <iostream>
#include <fstream>

using std::ofstream;

using std::string;

class Arvore {
  private:
    NoArv *raiz = nullptr;
    ofstream arquivoSaida;
  
  public:
    Arvore();
    Arvore(string nomeArquivoSaida);
    ~Arvore();
    //NoArv* getRaiz();
    //void adicionarZ(char tipo, string nome, string significado);
    void adicionar(char tipo, string nome, string significado);
    NoArv* adicionarNo(NoArv *raiz, char tipo, string nome, string definicao);
    int Max(int v1, int v2);
    void imprimirInOrdem(NoArv *no);
    void imprimir();
    int Altura (NoArv *no);
    int FatorBalanceamento(NoArv *no);
    void rotacaoDir(NoArv* &no);
    void rotacaoEsq(NoArv* &no);
    void rotacaoEsqDir(NoArv* &no);
    void rotacaoDirEsq(NoArv* &no);
    void removerComSignificado();
    void removerNoComSignificado(NoArv* no);
    void balancear(NoArv* &no);
    NoArv* buscaProfundidade(NoArv* no, string direcao);
    
};

#endif