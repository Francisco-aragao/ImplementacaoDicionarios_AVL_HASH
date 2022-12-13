#include <string.h>
#include <fstream>
#include <sys/resource.h>

#include "../include/msgassert.hpp"
#include "../include/memlog.hpp"
#include "../include/Arvore.hpp"

int main (int argc, char* argv[]) {
    
    // ------------------ Verificações dos parâmetros de entrada ----------------------

    erroAssert(argc == 7, "Não informado a quantiadade de parâmetros necessários"); 
    
    erroAssert(strcmp(argv[1], "-i") == 0, "Não informado o nome do arquivo de entrada"); 
    string nomeArquivoEntrada = argv[2];

    erroAssert(strcmp(argv[3], "-o") == 0, "Não informado o nome do arquivo de saida"); 
    string nomeArquivoSaida = argv[4];

    erroAssert(strcmp(argv[5], "-t") == 0, "Não informado o tipo de estrutura a ser utilizada");
    int estrutura;
    if (strcmp(argv[6], "hash") == 0) {
        estrutura = 0;
    }
    if (strcmp(argv[6], "arv") == 0) {
        estrutura = 1;
    }


    // --------------- MEMLOG --------------- 
    /* bool iniciaMem = false;     //Faço controle das funcoes do memlog
    bool ativaMem = false;
    if (argc >= 12 - auxiliar) {
        if (strcmp(argv[11 - auxiliar], "-p") == 0) {
            iniciaMemLog((char*)"log.out");
            desativaMemLog();
            iniciaMem = true;
        } else {
            finalizaMemLog();
        }
    }
    if (iniciaMem == true && argc >= 13 - auxiliar) {
        if (strcmp(argv[12 - auxiliar], "-l") == 0) {
            ativaMemLog();
            ativaMem = true;
        } else {
            desativaMemLog();
        }
    } */

    //abro os arquivos de entrada e saida
    std::ifstream arquivoEntrada;
    arquivoEntrada.open(nomeArquivoEntrada);
    erroAssert(arquivoEntrada.is_open() == true, "Erro abertura arquivo de entrada");  

    //std::ofstream arquivoSaida;
    //arquivoSaida.open(nomeArquivoSaida);
   

    // ------------------ Fim da verificações dos parâmetros de entrada ----------------------


    //Arvore arvore;

    char tipo;
    string nome;
    string significado;
    char aux;

    Arvore *arvore = new Arvore (nomeArquivoSaida);
    if (estrutura == 1) {
        int zc = 0;
        while (arquivoEntrada >> tipo) {
            arquivoEntrada >> aux; //leio [
            arquivoEntrada >> nome;
            nome.erase(nome.size() - 1); //apago ]
            //arquivoEntrada >> aux; //leio caractere de espaço
            /* if (nome == "bronchiarctia") {
                cout << "asjdlkasjdlajd\n";
                break;
            } */
            //cout << "******* nome " << nome << endl;
            getline(arquivoEntrada, significado);
            //if (significado == "") cout << "---SIG VAZIO---\n";
            arvore->adicionar(tipo, nome, significado);
            zc++;
            //if (zc == 50) break;
        }

    }

    cout << endl << endl;
    //arvore->imprimirInOrdem(arvore->getRaiz());
    arvore->imprimir();
    arvore->removerComSignificado();
    arvore->imprimir();

    delete arvore;

    arquivoEntrada.close();
    //arquivoSaida.close();

/* 
    if (ativaMem == true) desativaMemLog();
    if (iniciaMem == true) finalizaMemLog(); */

    return 0;
}