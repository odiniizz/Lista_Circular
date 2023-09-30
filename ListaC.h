#include <iostream>

class ListaC{
    private:
        std::string Nome;
        int Posicao;
        ListaC *elo;
    public:
        ListaC** Inserir(ListaC**, std::string, int);
        void Percorrer(ListaC**);
        ListaC** Remover(ListaC**, int s, bool*);
};
