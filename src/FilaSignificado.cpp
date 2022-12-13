#include "../include/FilaSignificado.hpp"

void FilaSignificado::adicionar (string definicao) {
    NoSignificado *no = new NoSignificado;
    no->setDefinicao(definicao);
    no->setProximo(nullptr);

    if (comeco != nullptr && comeco->getDefinicao().length() <= 1) { //caso significado for vazio
        comeco->setDefinicao(definicao);
        return;
    }

    if (comeco == nullptr) {
        //this->comeco = new NoSignificado;
        this->comeco = no;
        //fim = comeco;
    } else  {
        /* cout << "\nmeio\n";
        cout << "1 comeco : " << comeco->getDefinicao() << endl;
        if (fim != nullptr) cout << "2 fim : " << fim->getDefinicao() << endl;
        comeco->setProximo(no);
        fim = no;
        fim->setProximo(nullptr);
        cout << "2 fim : " << comeco->getProximo()->getDefinicao() << endl;
        cout << "1 comeco : " << comeco->getDefinicao() << endl;
        cout << "2 fim : " << fim->getDefinicao() << endl;
        if (comeco == fim) cout << "\n\nIGUAL\n\n"; */
        for (NoSignificado *i = comeco;  ;) {
            if (i->getProximo() != nullptr) { 
                i = i->getProximo();
            } else {
                i->setProximo(no);
                break;
            }
            
        }
     }/* else {
        cout << "\nPROXIMO\n";
        cout << "1 comeco : " << comeco->getDefinicao() << endl;
        fim->setProximo(no);
        fim = no;
        cout << "1.1 ṕrox : " << comeco->getProximo()->getDefinicao() << endl;
        cout << "2 fim : " << fim->getDefinicao() << endl;
    } */
}

NoSignificado* FilaSignificado::getComeco() {
    return this->comeco;
}
NoSignificado* FilaSignificado::getFim() {
    return this->fim;
}