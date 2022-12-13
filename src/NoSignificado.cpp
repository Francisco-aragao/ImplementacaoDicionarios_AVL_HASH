#include "../include/NoSignificado.hpp"

void NoSignificado::setDefinicao(string definicao) {
    this->definicao = definicao;
}

string NoSignificado::getDefinicao() {
    return this->definicao;
}

void NoSignificado::adicionar (string definicao) {
    NoSignificado *no = new NoSignificado;
    no->definicao = definicao;
    proximo = no;
}

void NoSignificado::setProximo(NoSignificado *no) {
    if (no != nullptr) {
        this->proximo = no;
    } else {
        this->proximo = nullptr;
    }
}

NoSignificado* NoSignificado::getProximo() {
    return this->proximo;
}