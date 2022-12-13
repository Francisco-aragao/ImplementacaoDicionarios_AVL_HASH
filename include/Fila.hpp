#ifndef ListaSignificado_h
#define ListaSignificado_h

#include "NoSignificado.hpp"

class ListaSignificado {
    private:
        NoSignificado *inicio = nullptr;
        NoSignificado *fim = nullptr;
    
    public:
        void adicionar(string significado);
};

#endif