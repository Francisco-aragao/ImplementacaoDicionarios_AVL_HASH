#ifndef FilaSignificado_h
#define FilaSignificado_h

#include "NoSignificado.hpp"

class FilaSignificado {
    private:
        NoSignificado *comeco = nullptr;
        NoSignificado *fim = nullptr;

    public:
        void adicionar(string definicao);
        NoSignificado* getComeco();
        NoSignificado* getFim();
};

#endif