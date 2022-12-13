#include "../include/Verbete.hpp"

Verbete::Verbete() {}

Verbete::Verbete(char tipo, string nome, string definicao) {
    this->tipo = tipo;
    this->nome = nome;
    /* if (definicao == "") { 
        cheio = false; 
    } else {
        cheio = true;
    } */
        this->significado.adicionar(definicao); 
}

char Verbete::getTipo() {
    return this->tipo;
}

string Verbete::getNome() {
    return this->nome;
}

string Verbete::getSignificados(int j) { //indice começa em 0
    int iterador = 1;
    for (NoSignificado *i = significado.getComeco(); i != nullptr; i = i->getProximo() ) {
        if (iterador == j && i->getDefinicao() != "") return i->getDefinicao();
        iterador++;
    }
    return "Vazio";
} 

bool Verbete::temSignificado() {
    //return this->cheio;
    if (significado.getComeco() == nullptr) return false;
    if (significado.getComeco()->getDefinicao().length() > 1 ) return true;
    return false;
}

void Verbete::setCheio(bool cheio) {
    this->cheio = cheio;
}

void Verbete::setSignificados(string definicao) {
    this->cheio = true;
    significado.adicionar(definicao);
}