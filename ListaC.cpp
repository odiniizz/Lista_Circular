#include "ListaC.h"

/*
Uma Lista Ordenada Simplesmente Encadeada Circular é uma estrutura de dados que organiza elementos
de forma ordenada e os conecta em uma sequência circular, onde o último elemento aponta de volta
para o primeiro. Isso significa que não há um fim definitivo na lista */

ListaC** ListaC::Inserir(ListaC **R, std::string N, int K){
    ListaC *novo = new ListaC();
    novo -> Nome = N;
    novo -> Posicao = K;
    //se for o primeiro elemento a ser inserido
    if(R[0] == NULL){
        R[0] = novo;
        R[1] = novo;
        R[1]->elo = R[0];
    }else{
    //procurando o local para a inserção
        ListaC *anterior = NULL, *atual = R[0];
        while ((atual != R[1]) && (novo->Nome > atual->Nome)){
            anterior = atual;
            atual = atual->elo;
        }
        //inserção no início da lista
        if( atual == R[0] && novo->Nome < atual->Nome){
        novo->elo = R[0];
            R[0] = novo;
            R[1]->elo = R[0];
        //inserção no final da lista
        }else if(atual == R[1] && novo->Nome > R[1]->Nome){
            R[1]->elo = novo;
            R[1] = novo;
            R[1]->elo = R[0];
        // inserindo no meio da lista
        }else{
            anterior->elo = novo;
            novo->elo = atual;
        }
    }
    return R;
};

/***********************************************************************/

void ListaC::Percorrer(ListaC **R){
    ListaC *aux = R[0];
    while(aux != R[1]){
        std::cout << aux->Nome << "\n";
        aux = aux->elo;
    }
    std::cout << aux->Nome << "\n";
};

/***********************************************************************/

ListaC** ListaC::Remover(ListaC **R, int P, bool *achei){
    ListaC *anterior = NULL, *atual = R[0];
//Pesquisando o registro a ser excluído
    while ((atual != R[1]) && (atual->Posicao != P)){
        anterior = atual ;
        atual = atual->elo;
    }
    //O registro não foi encontrado
    if(atual == R[1] && atual->Posicao != P){
        *achei = false;
    }else{
        *achei = true;
        if(atual == R[0] && R[0] != R[1]){
//O primeiro elemento da lista será excluído (existem outros elementos)
            R[0] = R[0]->elo;
            R[1]->elo = R[0];
        }else if(atual == R[0] && R[0] == R[1]){
//Só existe um elemento na lista
            R[0] = NULL;
            R[1] = NULL;
        }else if(atual == R[1]){
//O último elemento da lista será excluído
            R[1] = anterior;
            R[1]->elo = R[0];
        }else{
//Um elemento no meio da lista será excluído
            anterior->elo = atual->elo;
        }
        delete ( atual );
    }
    return R;
};
