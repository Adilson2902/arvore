#include <iostream>
using namespace std;
struct Arvore{
    int num;
    Arvore *esquerda,*direita;
};

struct Pilha{
    Arvore *num;
    Pilha *prox;
};

int main() {
    Arvore *raiz = NULL;
    Arvore *aux ;
    Arvore *aux1;
    Arvore *novo;
    Arvore *anterior;
    Pilha *topo;
    Pilha *aux_pilha;
    int op , achou,numero;
    do{
        cout<<"\n Menu de Opções \n";
        cout<<"\n 1 - Inserir na Arvore \n";
        cout<<"\n 2 - Consulta um nó da arvore \n";
        cout<<"\n 3 - Consulta toda a arvore em ordem\n";
        cout<<"\n 4 - Consulta toda a arvore na pre-ordem \n";
        cout<<"\n 5 - Consulta toda a arvore na pos-ordem";
        cout<<"\n 6 - Remove um nó da arvore \n";
        cout<<"\n 7 - Esvazia a arvore \n";
        cout<<" Sua Escolha :";
        cin>>op;
        while (op <1 || op>8){
            cout<<" Digite novamente";
            cin>>op;

        }

        if(op == 1){
            cout<<"\n Digite o numero a ser inserido na arvore ";
             novo = new Arvore;
            cin>>novo->num;
            novo->direita = NULL;
            novo->esquerda = NULL;
            if(raiz == NULL){
                raiz = novo;
            }else{
                aux = raiz;
                achou = 0 ;
                while (achou == 0){
                    if(novo->num> aux->num) {
                        if (aux->direita == NULL) {
                            aux = novo;
                            achou = 1;
                        } else {
                            aux = aux->direita;
                        }
                    }else if(novo->num <aux->num){
                        if(aux ->esquerda == NULL){
                            aux = novo;
                            achou = 1;
                        }else{
                            aux = aux->esquerda;
                        }
                    }
                }


            }

             cout<<" Inserido o numero na arvore \n";

        }else if(op == 2){
            if(raiz == NULL){
                cout<<" Lista Vazia \n";
            }else{

                cout<<" Digite o elemento a ser consulta \n";
                cin>>numero;
                achou = 0;
                aux = raiz;
                while (aux != NULL && achou == 0){
                    if( numero == aux->num){
                        cout<<" Numero encontrado na arvore \n";
                        achou = 1;
                    } else if( numero > aux->num){
                         aux = aux->direita;
                    }else{
                        aux = aux->esquerda;
                    }
                }
            }
            if( achou == 0 ){
                cout<<" Numero Não está na arvore \n";

            }

        }else if(op == 3){
             if(raiz == NULL){
                 cout<<" Arvore Vazia \n";
             }else{
                 aux = raiz ;
                 topo = NULL;
                 do{

                    while ( aux != NULL){
                        aux_pilha = new Pilha;
                        aux_pilha->num = aux;
                        aux_pilha->prox = topo;
                        topo = aux_pilha;
                        aux = aux->esquerda;
                    }

                    if(topo !=NULL){
                        aux_pilha = topo;
                        cout<<aux_pilha->num->num<<" ";
                        aux = topo->num->direita;
                        topo = topo->prox;
                    }



                 }while (aux != NULL || topo != NULL);
             }
        } else if(op == 4){
            if(raiz == NULL){
                cout<<" Lista Vazia \n";
            } else {

                aux = raiz;
                topo = NULL;

                do {

                    while (aux != NULL) {
                        aux_pilha = new Pilha;
                        cout << aux->num << " ";
                        aux_pilha->num = aux;
                        aux_pilha->prox = topo;
                        topo = aux_pilha;
                        aux = aux->esquerda;
                    }

                    if (topo != NULL) {
                        aux_pilha = topo;
                        topo = topo->prox;
                        aux = aux_pilha->num->direita;
                    }


                } while (topo != NULL || aux != NULL);


            }
        } else if (op == 5){
            if(raiz == NULL){
                cout<<" arvore vazia \n";
            } else {
                aux = raiz;
                topo = NULL;
                do{
                do {
                    while (aux != NULL) {
                        aux_pilha = new Pilha;
                        aux_pilha->num = aux;
                        aux_pilha->prox = topo;
                        topo = aux_pilha;
                        aux = aux->esquerda;
                    }

                    if (topo->num->direita != NULL) {
                        aux = topo->num->direita;
                    }

                }while (aux != NULL);
                if(topo != NULL){
                    cout<<topo->num->num<<" ";
                    if(topo ->prox != NULL){
                        if (topo->prox->num->direita != NULL && topo->prox->num->direita != topo->num){
                            aux = topo->prox->num->direita;
                            topo = topo->prox;
                        }else{
                            while(topo->prox != NULL && topo->prox->num->direita == topo->num){
                                topo = topo->prox;
                                cout<<topo->num->num<<" ";

                            }
                            topo = topo->prox;
                            if(topo != NULL){
                                aux = topo->num->direita;
                            }else{
                                aux = NULL;

                            }


                        }
                    }else{
                        topo = topo->prox;
                        aux = NULL;
                }

                }
            }while (topo != NULL || aux != NULL);
        }
        } else if (op == 6){
            if(raiz == NULL){
                cout<<" Arvore Vazia \n";
            } else{
                cout<<" Digite o numero que deseja excluir ";
                cin>> numero;
                aux = raiz;
                achou = 0;
                while (achou == 0 && aux != NULL){
                if(aux->num == numero){
                    achou = 1;

                } else if(aux->num >numero){
                    aux = aux->esquerda;

                } else{
                    aux = aux->direita;
                }

                }
                if(achou == 0){
                    cout<<" Numero não encontrado";
                } else{
                    if(aux != raiz){

                        anterior = raiz;
                        while (anterior->direita != aux && anterior->esquerda != aux){
                            if(anterior->num > numero){
                                anterior = anterior ->esquerda;
                            }else{
                                anterior = anterior->direita;
                            }
                        }

                        if(anterior->direita == aux){
                            anterior->direita = NULL;
                        } else{
                            anterior->esquerda = NULL;
                        }
                        delete(aux);

                    } else{

                        if(aux->direita != NULL
                        && aux->esquerda == NULL){
                            if (anterior ->esquerda == aux){

                                anterior->esquerda = aux->direita;
                            } else{
                                anterior->direita = aux->direita;
                            }
                            delete(aux);
                        } else if(aux->esquerda != NULL
                                && aux->direita == NULL){
                            if (anterior->esquerda == aux){
                                anterior->esquerda = aux->esquerda;

                            }else{
                                anterior->direita = aux->esquerda;
                            }
                            delete(aux);
                        } else if(aux->esquerda != NULL
                                  && aux->direita != NULL){
                             if (anterior->direita == aux){
                                 anterior->direita = aux->direita;
                                 aux1 = aux->esquerda;
                             } else{
                                 anterior->esquerda = aux->direita;
                                 aux1 = aux->esquerda;
                             }
                             delete(aux);

                             aux = anterior;
                             while (aux != NULL){
                                 if (aux->num <aux1->num){
                                     if (aux->direita == NULL){
                                         aux->direita = aux1;
                                         aux = NULL;
                                     }else{
                                         aux = aux->direita;
                                     }
                                 }
                             }
                        }else if(aux->num > aux1->num){
                            if(aux->esquerda == NULL){
                                aux->esquerda = aux1;
                                aux = NULL;

                            }else{
                                aux->esquerda;
                            }

                        } else{
                            if(aux->direita != NULL && aux->esquerda != NULL){

                                raiz = aux->direita;
                                delete(aux);
                            } else if(aux->esquerda != NULL){

                                raiz = aux->direita;
                                aux1 = aux->esquerda;

                                delete(aux);
                                aux = raiz;
                                while (aux != NULL){
                                    if(aux ->num < aux1->num){
                                            if(aux->direita == NULL){
                                                    aux->direita = aux1;
                                                    aux = NULL;
                                            }else{
                                                aux = aux->direita;
                                            }

                                    }else if(aux->num > aux1->num){
                                        if(aux->esquerda == NULL){
                                            aux->esquerda = aux1;
                                            aux = NULL;
                                        } else{
                                            aux= aux->esquerda;
                                        }
                                    }

                                }
                            }
                        }

                    }
                }
            }
        } else if (op == 7){
            if(raiz == NULL){
                cout<<" Arvore Vazia \n ";

            } else{do {
                    aux = raiz;
                    topo = NULL;
                    while (aux != NULL) {
                        aux_pilha = new Pilha;
                        cout << aux_pilha->num << " ";
                        aux_pilha->num = aux;
                        aux_pilha->prox = topo;
                        topo = aux_pilha;
                        aux = aux->esquerda;


                    }

                    if (topo != NULL) {

                        aux_pilha = topo;
                        topo = topo->prox;
                        aux = aux_pilha->num->direita;
                    }


                }while (aux != NULL || topo != NULL);


                    aux_pilha = topo;

                    while (aux_pilha != NULL){

                        topo = topo->prox;
                        delete(topo->num);
                        delete(aux_pilha);
                        aux_pilha = topo;
                    }

                    raiz =NULL;
            }


        }


    }while (op !=8);









}