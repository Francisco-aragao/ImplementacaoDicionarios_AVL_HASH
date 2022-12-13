#include "../include/NoArv.hpp"

NoArv::NoArv() {}

NoArv::NoArv(char tipo, string nome, string definicao) {
     Verbete verbete = Verbete(tipo, nome, definicao);
     this->verbete = verbete;
}

NoArv* NoArv::getDir() {
    return this->direita;
}


NoArv* NoArv::getEsq() {
    return this->esquerda;
}

NoArv* NoArv::getPai() {
    return this->pai;
}

Verbete NoArv::getVerbete() {
    return this->verbete;
}

void NoArv::adicionar(char tipo, string nome, string definicao) {
    Verbete verbete = Verbete(tipo, nome, definicao);
}

void NoArv::setDir(NoArv* no) { 
    direita = no; 
}

void NoArv::setEsq(NoArv* no) { 
    esquerda = no; 
}

void NoArv::setPai(NoArv *no) {
    pai = no;
}