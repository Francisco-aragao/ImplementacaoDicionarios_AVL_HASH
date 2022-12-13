#ifndef NoSignificado_h
#define NoSignificado_h

#include <iostream>
using std::string;
using std::cout;
using std::endl;

class NoSignificado {
    private:
        int posicao = 0;
        string definicao;
        NoSignificado *proximo = nullptr;
    
    public:
        void setDefinicao(string definicao);
        string getDefinicao();
        void adicionar(string definicao);
        NoSignificado* getProximo();
        void setProximo(NoSignificado *no);

};

#endif