#include "../include/Arvore.hpp"

Arvore::Arvore () {
    /* std::cout << "xx\n";
    raiz = new NoArv;
    raiz = nullptr;
*/
}

Arvore::Arvore (string nomeArquivoSaida) {
    this->arquivoSaida.open(nomeArquivoSaida);
    erroAssert(arquivoSaida.is_open() == true, "Erro abertura arquivo de saida");  
}

Arvore::~Arvore() {
    arquivoSaida.close();
}

int Arvore::Max (int v1, int v2) {
    if (v1 > v2) {
        return v1;
    } else {
        return v2;
    }
}

int Arvore::Altura (NoArv *no) {
    
    if (no == nullptr) return 0;
    //if (no->getEsq() == nullptr && no->getDir() == nullptr) return 0;
    return 1 + Max(Altura(no->getEsq()), Altura(no->getDir()));
}

void Arvore::imprimir() {
    imprimirInOrdem(raiz);
}

void Arvore::imprimirInOrdem(NoArv *no) {
    if (no != nullptr) {
        cout << "\nesq: ";
        imprimirInOrdem(no->getEsq());
        cout << "fim esq\n";
        cout << "\nmeio: ";
        arquivoSaida << no->getVerbete().getNome() << " (" << no->getVerbete().getTipo() << ")\n";
        if (no->getPai() == nullptr) cout << "raiz\n";
        cout << no->getVerbete().getNome() << endl;

        /* if (no->getVerbete().temSignificado() == 0) {
            cout << no->getVerbete().getNome() << " SEM SIGNIFICADO\n";
        } else {  */
            for (int i = 1; ; i++) {
                string resultado = no->getVerbete().getSignificados(i);
                if (resultado == "Vazio") {
                    break;
                } else {
                    arquivoSaida << i << "." << resultado << "\n";
                }
                //if (i != 1) arquivoSaida <<"\n";
            //no->getVerbete().getSignificados();
            }
         /* }  */
        cout << "\ndir: ";
        imprimirInOrdem(no->getDir());

        //int altura = Altura(no);
        //cout << "\nNo: " << no->getVerbete().getNome() << " altura " << altura << endl << endl;
        //int fatorBalanc = FatorBalanceamento(no);
        //cout << "\nNo: " << no->getVerbete().getNome() << " fatorBalanc " << fatorBalanc << endl << endl;

        cout << "fim dir\n";
    }
    //if (no == raiz) arquivoSaida << endl;
  }

/* NoArv* Arvore::getRaiz() {
    if (raiz != nullptr) {
        return this->raiz;
    } else {
        return nullptr;
    }
} */

int Arvore::FatorBalanceamento(NoArv *no) {
    if (no == nullptr) return 0;
    int fatorBalanceamento = Altura(no->getDir()) - Altura(no->getEsq());
    
/*     if (fatorBalanceamento < 0) return fatorBalanceamento+= -1;
    if (fatorBalanceamento > 0) return fatorBalanceamento += 1; */

    return fatorBalanceamento;
}

void Arvore::rotacaoDir(NoArv* &no) {
    cout << "AQUI\n";
    NoArv* aux;
    aux = no;
    no = no->getEsq();
    if (aux->getPai() != nullptr) {
        if (aux->getPai() != nullptr) {
            if (aux->getPai()->getEsq() == aux) {
                aux->getPai()->setEsq(no);
            } else {
                aux->getPai()->setDir(no);
            }
        }
    }
    no->setPai(aux->getPai());
    aux->setPai(no);
    if (no->getDir() != nullptr) { //condicao caso novo nó raiz tenha já tenha filho Dir 
        aux->setEsq(no->getDir());
        no->getDir()->setPai(aux);
    } else {
        aux->setEsq(nullptr);
    }
    no->setDir(aux);
    /* cout << "rotacao " << no->getVerbete().getNome() << endl;
    cout << "rotacaoD " << no->getDir()->getVerbete().getNome() << endl;
    cout << "rotacaoE " << no->getEsq()->getVerbete().getNome() << endl;  */
    aux = nullptr;
    delete aux;
}

void Arvore::rotacaoEsq(NoArv* &no) {
    NoArv* aux;
    aux = no;
    no = no->getDir();
    if (aux->getPai() != nullptr) {
        if (aux->getPai() != nullptr) {
            if (aux->getPai()->getEsq() == aux) {
                aux->getPai()->setEsq(no);
            } else {
                aux->getPai()->setDir(no);
            }
        }
    }
    no->setPai(aux->getPai());
    aux->setPai(no);
    if (no->getEsq() != nullptr) { //condicao caso novo nó raiz tenha já tenha filho Esq 
        aux->setDir(no->getEsq());
        no->getEsq()->setPai(aux);
    } else {
        aux->setDir(nullptr);
    }
    no->setEsq(aux);
    //aux->setDir(nullptr);
    /* cout << "no " << no->getVerbete().getNome() << endl;
    cout << "noD " << no->getDir()->getVerbete().getNome() << endl;
    cout << "noE " << no->getEsq()->getVerbete().getNome() << endl; */

}

void Arvore::rotacaoEsqDir(NoArv* &no) {
    NoArv *filho;
    NoArv *neto;
    filho = no->getEsq();
    neto = filho->getDir();
    no->setEsq(neto);
    filho->setDir(nullptr);
    neto->setEsq(filho);
    neto->setPai(no);
    filho->setPai(neto);
    cout << "aaaa " << no->getVerbete().getNome() << endl;
    cout << filho->getVerbete().getNome() << endl;
    cout << neto->getVerbete().getNome() << endl;
    rotacaoDir(no);
}

void Arvore::rotacaoDirEsq(NoArv* &no) {
    NoArv *filho;
    NoArv *neto;
    filho = no->getDir();
    neto = filho->getEsq();
    no->setDir(neto);
    filho->setEsq(nullptr);
    neto->setDir(filho);
    neto->setPai(no);
    filho->setPai(neto);
    rotacaoEsq(no);
}

/* void Arvore::adicionarZ (char tipo, string nome, string definicao) {
    NoArv *no = new NoArv (tipo, nome, definicao);
    
    if (raiz == nullptr) {
        raiz = no;
        return;
    }

    if (nome == raiz->getVerbete().getNome()) {
        raiz->getVerbete().setSignificados(definicao);
        //raiz->getVerbete().printSignificados();
        return;
    } 

    NoArv *anterior;
    NoArv *atual = raiz;

    while (true) {
        anterior = atual;
        if (nome < raiz->getVerbete().getNome()) {
            atual = atual->getEsq();
            if (atual == nullptr) {
                anterior->setEsq(no); 
                return;
            } 
        } else if (nome > raiz->getVerbete().getNome()) {
            atual = atual->getDir();
            if (atual == nullptr) {
                anterior->setDir(no); 
                return;
            } 
        }
    }

     
} */

NoArv* Arvore::adicionarNo (NoArv *raiz, char tipo, string nome, string definicao) {
    if (raiz == nullptr) {
        NoArv *no = new NoArv (tipo, nome, definicao);
        //if (definicao == "") cout << "definicao vazia\n";
        return no;
    }
    //cout << "************nome " << nome << endl;
    if (nome < raiz->getVerbete().getNome()) {
        raiz->setEsq(adicionarNo(raiz->getEsq(), tipo, nome, definicao));
        raiz->getEsq()->setPai(raiz);
    } else if (nome > raiz->getVerbete().getNome()) {
        raiz->setDir(adicionarNo(raiz->getDir(), tipo, nome, definicao));
        raiz->getDir()->setPai(raiz);
    } else if (nome == raiz->getVerbete().getNome()) { //caso nomes iguais, comparo o tipo
        if (tipo == raiz->getVerbete().getTipo()) {
            //cout << "-------aqui\n";
            raiz->getVerbete().setSignificados(definicao);
            raiz->getVerbete().setCheio(true);
            //cout << "***NO " << raiz->getVerbete().getNome()<< " " << raiz->getVerbete().temSignificado() << " CHEIO\n";
        } else if (tipo < raiz->getVerbete().getTipo()) {
            raiz->setEsq(adicionarNo(raiz->getEsq(), tipo, nome, definicao));
            raiz->getEsq()->setPai(raiz);
        } else if (tipo > raiz->getVerbete().getTipo()) {
            raiz->setDir(adicionarNo(raiz->getDir(), tipo, nome, definicao));
            raiz->getDir()->setPai(raiz);
        }
    } 

    /* int balanceamento = FatorBalanceamento(raiz);
    cout << raiz->getVerbete().getNome() << " fb " << balanceamento << endl;
    // 1 rotação
    //balanceamento < -1 (2 filhos na esq) -> (1 rotação pra dir) 
    if (balanceamento < -1 && raiz->getEsq()->getEsq() != nullptr) {
        if (raiz->getEsq() != nullptr && FatorBalanceamento(raiz->getEsq()) > 0) {
            //cout << "\nAQUI\n";
            //cout << raiz->getVerbete().getNome() << " raiz e filho Esq " << raiz->getEsq()->getVerbete().getNome() << endl;
            NoArv *filhoEsq = raiz->getEsq();
            //cout << "filho Esq " << filhoEsq->getVerbete().getNome() << endl;
            rotacaoEsq(filhoEsq);
            raiz->setEsq(filhoEsq);
            filhoEsq = nullptr;
            //cout << raiz->getVerbete().getNome() << " raiz e filho Esq " << raiz->getEsq()->getVerbete().getNome() << endl;
        }
        cout << "rotacaoD " << raiz->getVerbete().getNome() << endl;
        rotacaoDir(raiz);
    } 
    //balanceamento > 1 (2 filhos na dir) -> (1 rotação pra esq) 
    if (balanceamento > 1 && raiz->getDir()->getDir() != nullptr) {
        if (raiz->getDir() != nullptr && FatorBalanceamento(raiz->getDir()) < 0) {
            //cout << "\nAQUI\n";
            //cout << raiz->getVerbete().getNome() << " raiz e filho dir " << raiz->getDir()->getVerbete().getNome() << endl;
            NoArv *filhoDir = raiz->getDir();
            //cout << "filho dir " << filhoDir->getVerbete().getNome() << endl;
            rotacaoDir(filhoDir);
            raiz->setDir(filhoDir);
            filhoDir = nullptr;
            //cout << raiz->getVerbete().getNome() << " raiz e filho dir " << raiz->getDir()->getVerbete().getNome() << endl;
        }
        cout << "rotacaoE " << raiz->getVerbete().getNome() << endl;
        rotacaoEsq(raiz);
        cout << "---esq---\n";
        //imprimirInOrdem(raiz);
        cout << "---fim esq---\n";
    } 

    balanceamento = FatorBalanceamento(raiz);
    // 2 rotações
    //balanceamento < -1 (1 filho esq e neto dir) -> (1 rotação pra dir, outra esq) 
    if (balanceamento < -1 && raiz->getEsq()->getDir() != nullptr) {
        cout << "rotacaoED " << raiz->getVerbete().getNome() << endl;
        rotacaoEsqDir(raiz);
    } 
    //balanceamento > 1 (1 filho esq e neto dir) -> (1 rotação pra dir, outra esq) 
    if (balanceamento > 1 && raiz->getDir()->getEsq() != nullptr) {
        cout << "rotacaoDE " << raiz->getVerbete().getNome() << endl;
        rotacaoDirEsq(raiz);
    }  */

    balancear(raiz);
    
/*     if (raiz == this->raiz && raiz->getVerbete().getNome() == "e") {
        cout << "XXXXXXXraiz " << FatorBalanceamento(raiz) << endl;
        cout << raiz->getVerbete().getNome() << endl;
        cout << raiz->getDir()->getVerbete().getNome() << endl;
        cout << raiz->getEsq()->getVerbete().getNome() << endl;
    } */
    
    
    return raiz;
}

void Arvore::adicionar (char tipo, string nome, string definicao) {
    //NoArv *no = new NoArv (tipo, nome, definicao);
    //cout << "************nome " << nome << endl;
    raiz = adicionarNo(raiz, tipo, nome, definicao);
     
}

void Arvore::removerComSignificado() {
    cout << "\n ------------------ \n";
    removerNoComSignificado(raiz);
}

void Arvore::balancear (NoArv* &no) {
    int balanceamento = FatorBalanceamento(no);
    cout << no->getVerbete().getNome() << " fb " << balanceamento << endl;
    //cout << "XXXX\n";

    // 1 rotação
    //balanceamento < -1 (2 filhos na esq) -> (1 rotação pra dir) 
    if (balanceamento < -1 && no->getEsq()->getEsq() != nullptr) {
        if (no->getEsq() != nullptr && FatorBalanceamento(no->getEsq()) > 0) {
            NoArv *filhoEsq = no->getEsq();
            rotacaoEsq(filhoEsq);
            no->setEsq(filhoEsq);
            filhoEsq = nullptr;
        }
        cout << "rotacaoD " << no->getVerbete().getNome() << endl;
        rotacaoDir(no);
    } 
    //balanceamento > 1 (2 filhos na dir) -> (1 rotação pra esq) 
    if (balanceamento > 1 && no->getDir()->getDir() != nullptr) {
        if (no->getDir() != nullptr && FatorBalanceamento(no->getDir()) < 0) {
            NoArv *filhoDir = no->getDir();
            rotacaoDir(filhoDir);
            no->setDir(filhoDir);
            filhoDir = nullptr;

        }
        cout << "rotacaoE " << no->getVerbete().getNome() << endl;
        rotacaoEsq(no);
        cout << "---esq---\n";
        //imprimirInOrdem(no);
        cout << "---fim esq---\n";
    } 

    balanceamento = FatorBalanceamento(no);
    // 2 rotações
    //balanceamento < -1 (1 filho esq e neto dir) -> (1 rotação pra dir, outra esq) 
    if (balanceamento < -1 && no->getEsq()->getDir() != nullptr) {
        cout << "rotacaoED " << no->getVerbete().getNome() << endl;
        rotacaoEsqDir(no);
    } 
    //balanceamento > 1 (1 filho esq e neto dir) -> (1 rotação pra dir, outra esq) 
    if (balanceamento > 1 && no->getDir()->getEsq() != nullptr) {
        cout << "rotacaoDE " << no->getVerbete().getNome() << endl;
        rotacaoDirEsq(no);
    } 

}

NoArv* Arvore::buscaProfundidade(NoArv *no, string direcao) {
    if (direcao == "esq") {
        if (no->getEsq() == nullptr) {
            return no;
        } else {
            return buscaProfundidade(no->getEsq(), direcao);
        }
    }
    if (direcao == "dir") {
        if (no->getDir() == nullptr) {
            return no;
        } else {
            return buscaProfundidade(no->getDir(), direcao);
        }
    }
    return nullptr;
}

void Arvore::removerNoComSignificado(NoArv* no) {

    if (no == nullptr) return;

    if (no->getEsq() != nullptr) {
        NoArv* noEsq = no->getEsq();
        removerNoComSignificado(no->getEsq());
        //removerNoComSignificado(noEsq);
        //no = noEsq;
        noEsq = nullptr;
        delete noEsq;
    }
    if (no->getDir() != nullptr) {
        NoArv* noDir = no->getDir();
        // removerNoComSignificado(noDir);
        removerNoComSignificado(no->getDir());
        //no = noDir;
        noDir = nullptr;
        delete noDir;
    }

/*     cout << raiz->getVerbete().getNome()  << " balanc \n";
    cout << no->getVerbete().getNome()  << " balanc \n";
    cout << raiz->getDir()->getVerbete().getNome()  << " balancD \n";
    cout << raiz->getEsq()->getVerbete().getNome()  << " balancE \n";
    cout << raiz->getEsq()->getDir()->getVerbete().getNome()  << " balancED \n";
    cout << raiz->getEsq()->getEsq()->getVerbete().getNome()  << " balancEE \n";
    cout << raiz->getEsq()->getEsq()->getDir()->getVerbete().getNome()  << " balancEED \n"; 
 */
   balancear(no);

/*     cout << raiz->getEsq()->getEsq()->getVerbete().getNome()  << " balancEE dps\n";
    cout << raiz->getEsq()->getEsq()->getDir()->getVerbete().getNome()  << " balancEED dps\n";
    cout << "\nbbbbbbb FIM\n"; */

    //cout << no->getVerbete().getNome() << " nome " << no->getVerbete().temSignificado() << "\n";

    //if (no->getVerbete().temSignificado() == true) cout << no->getVerbete().getNome() << " tem sig\n";

    if (no->getVerbete().temSignificado() == true) {

        if (no->getEsq() == nullptr && no->getDir() == nullptr) { //apago folha
            if (no->getPai() == nullptr) return; //apago raiz
            if (no == no->getPai()->getEsq()) {
                no->getPai()->setEsq(nullptr);
            }  else {
                cout << no->getVerbete().getNome() << " retiroF\n";
                no->getPai()->setDir(nullptr);
            }
            //NoArv* pai = no->getPai();
            //balancear(pai);
            //no->setPai(pai);

            no = nullptr;
            delete no; 
            return;
        }
        //apago no com filho direito
        if (no->getDir() != nullptr && no->getEsq() == nullptr) {
            if (no->getPai() == nullptr) { //apago raiz
                raiz = no->getDir();
                no->getDir()->setPai(nullptr);
                no = nullptr;
            } else {
                cout << "ta retirando filho dir\n";
                cout << no->getVerbete().getNome() << " retiroD\n";
                NoArv* aux = no;
                no->getPai()->setDir(no->getDir());
                no = no->getDir();
                cout << no->getVerbete().getNome() << " novo no\n";
                no->setPai(aux->getPai());
                aux = nullptr;
            /*  if (no == no->getPai()->getEsq()) {
                    no->getPai()->setEsq(no->getDir());
                    no->getDir()->setPai(no->getPai());
                    no = nullptr;
                } else {
                    no->getPai()->setDir(no->getDir());
                    no->getDir()->setPai(no->getPai());
                    no = nullptr;
                } */
                delete aux;
            }
            return;
        }

         //apago no com filho esquerdo
        if (no->getEsq() != nullptr && no->getDir() == nullptr) {
            if (no->getPai() == nullptr) { //apago raiz
                raiz = no->getEsq();
                no->getEsq()->setPai(nullptr);
                no = nullptr;
            } else {
                cout << "ta retirando filho Esq\n";
                cout << no->getVerbete().getNome() << " retiroE\n";
                NoArv* aux = no;
                no->getPai()->setEsq(no->getEsq());
                no = no->getEsq();
                cout << no->getVerbete().getNome() << " novo no\n";
                no->setPai(aux->getPai());
                aux = nullptr;
                delete aux;
            }
            return;
        }

        //apago nó com 2 filhos
        if (no->getDir() != nullptr && no->getEsq() != nullptr ) {
            int fb = FatorBalanceamento(no);
            if (fb == 0) cout << "------BALANC 0 " << no->getVerbete().getNome() << "\n";
            //if (fb == 0 && no->getPai() == nullptr) cout << "PAI NULO " << no->getVerbete().getNome() << "\n";
         

            if (fb == 0 && no->getPai() == nullptr) {  //raiz com 2 filhos - pego filho mais a direita
                NoArv *Dir = buscaProfundidade(no->getEsq(), "dir");
                cout << "no " << no->getVerbete().getNome() << " dir " << no->getDir()->getVerbete().getNome() << "\n" << " esq " << no->getEsq()->getVerbete().getNome() << "\n";
                cout << " DIR " << Dir->getVerbete().getNome() << "\n";
                cout << no->getDir()->getVerbete().getNome() << " dirNo\n";
                if (no->getEsq() != Dir) Dir->getPai()->setDir(nullptr);
                
                if (Dir->getEsq() != nullptr) {
                    Dir->getPai()->setDir(Dir->getEsq());
                    Dir->getEsq()->setPai(Dir->getPai());
                }
                
                if (no->getDir() != nullptr && no->getDir() != Dir) {
                    Dir->setDir(no->getDir());
                    no->getDir()->setPai(Dir);

                }
            cout << "UUUUUUUUUUUUUUU\n";
                Dir->setPai(nullptr);
                
                if (no->getEsq() != Dir) {
                    Dir->setEsq(no->getEsq());
                    no->getEsq()->setPai(Dir);
                }
                NoArv* aux = no;
                no = nullptr;
                delete no;
                no = Dir;
                aux = nullptr;
                delete aux;
                return;
            } else if (fb == 0 && no->getPai() != nullptr) {
                cout << "******NOME: " << no->getVerbete().getNome() << "\n";
                //if (no->getDir() != nullptr) {
                    NoArv *Dir = buscaProfundidade(no->getEsq(), "dir");
                cout << "no " << no->getVerbete().getNome() << " dir " << no->getDir()->getVerbete().getNome() << " " << " esq " << no->getEsq()->getVerbete().getNome() << "\n";
                //cout << " esq D " << no->getEsq()->getDir()->getVerbete().getNome()  << "\n";
                cout << " DIR " << Dir->getVerbete().getNome() << "\n";

                       cout << "xxxxz\n";
                    if (no->getEsq() != Dir) Dir->getPai()->setDir(nullptr);
                    
                    if (Dir->getEsq() != nullptr) {
                        Dir->getPai()->setDir(Dir->getEsq());
                        Dir->getEsq()->setPai(Dir->getPai());
                    }

                    if (no->getDir() != nullptr && no->getDir() != Dir) {
                        no->getDir()->setPai(Dir);
                    }
                    Dir->setPai(no->getPai());
                    Dir->setDir(no->getDir());

                    if (no->getPai() != nullptr && no->getPai()->getDir() == no) {
                        no->getPai()->setDir(Dir);
                    } else if (no->getPai() != nullptr && no->getPai()->getEsq() == no) {
                        no->getPai()->setEsq(Dir);
                    }
                    if (no->getEsq() != Dir) {
                        Dir->setEsq(no->getEsq());
                        no->getEsq()->setPai(Dir);
                    }
                    NoArv* aux = no;
                    no = nullptr;
                    delete no;
                    no = Dir;
                    aux = nullptr;
                    //delete Dir;
                    delete aux;
               // }
                /* if (no->getEsq() != nullptr) {

                } */
                
                return;
            }

            if (fb > 0) {
            cout << "****ENTROUA*****\n";
                cout << "No que vou apagar " << no->getVerbete().getNome() << "\n";
                NoArv *esq = buscaProfundidade(no->getDir(), "esq");
                cout << "no mais esq subarv dir : " << esq->getVerbete().getNome() << "\n";
                cout << "pai dele aponta : " << esq->getPai()->getEsq()->getVerbete().getNome() << "\n";
                no->getEsq()->setPai(esq);
                esq->setEsq(no->getEsq());
                
                if (esq->getDir() != nullptr) {
                    if (esq->getPai() != nullptr) {
                        esq->getPai()->setEsq(esq->getDir());
                        esq->getDir()->setPai(esq->getPai());
                    }
                } else {
                    esq->getPai()->setEsq(nullptr);
                    cout << "aaaaaa\n";
                }
                esq->setPai(no->getPai());

                if (no->getPai() != nullptr && no->getPai()->getEsq() == no) {
                    no->getPai()->setEsq(esq);
                } else if (no->getPai() != nullptr && no->getPai()->getDir() == no) {
                    no->getPai()->setDir(esq);
                }

                if (no->getDir() != esq) {
                    esq->setDir(no->getDir());
                    no->getDir()->setPai(esq);
                }
                NoArv* aux = no;
                cout << "Antigo no " << no->getVerbete().getNome() << "\n";
                cout << "Antigo noD " << no->getDir()->getVerbete().getNome() << "\n";
                cout << "Antigo noE " << no->getEsq()->getVerbete().getNome() << "\n";
                no = nullptr;
                delete no;
                no = esq;
                aux = nullptr;
                delete aux;
                cout << "Novo no " << no->getVerbete().getNome() << "\n";
                cout << "Novo noD " << no->getDir()->getVerbete().getNome() << "\n";
                cout << "Novo noE " << no->getEsq()->getVerbete().getNome() << "\n";
                //balancear(no);
                return;
            } else if (fb < 0) {
                NoArv *Dir = buscaProfundidade(no->getEsq(), "dir");

                cout << "****ENTROUB*****\n";
                cout << "No que vou apagar " << no->getVerbete().getNome() << "\n";
                cout << "no mais esq subarv dir : " << Dir->getVerbete().getNome() << "\n";
                //cout << "pai dele aponta : " << Dir->getPai()->getEsq()->getVerbete().getNome() << "\n";

                    cout << "aaaaaa\n";
                no->getDir()->setPai(Dir);
                Dir->setDir(no->getDir());
                if (Dir->getEsq() != nullptr) {
                    if (Dir->getPai() != nullptr) {
                        Dir->getPai()->setDir(Dir->getEsq());
                        Dir->getEsq()->setPai(Dir->getPai());
                    }
                } else {
                    Dir->getPai()->setDir(nullptr);
                }

                Dir->setPai(no->getPai());

                if (no->getPai() != nullptr && no->getPai()->getDir() == no) {
                    no->getPai()->setDir(Dir);
                } else if (no->getPai() != nullptr && no->getPai()->getEsq() == no) {
                    no->getPai()->setEsq(Dir);
                }
                if (no->getEsq() != Dir) {
                    Dir->setEsq(no->getEsq());
                    no->getEsq()->setPai(Dir);
                }
                NoArv* aux = no;
                no = nullptr;
                delete no;
                no = Dir;
                aux = nullptr;
                delete aux;
                return;
            }
            //imprimirInOrdem(this->raiz);
        }
            cout << "\n*******\n";
    }
        return;
}
