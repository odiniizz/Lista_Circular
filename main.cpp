#include "ListaC.h"

using namespace std;

int main(){
    ListaC **P, obj;
    string n;
    int op, sorteado, i = 0;
    bool a;
    P = new ListaC *[2];
    P[0] = NULL;
    P[1] = NULL;

    do{
        system ("clear");
        cout << " ############ MENU ############\n\n";
        cout << "1 - Inserir Nomes\n";
        cout << "2 - Realizar o sorteio\n";
        cout << "3 - Listar\n";
        cout << "4 - Sair\n";
        cout << " Escolha a opção: ";
        cin >> op;

        switch (op){
        case 1:
            i++;
            cout << "Digite o nome: ";
            cin.ignore();
            getline(cin, n);
            P = obj.Inserir(P, n, i);
            cout << "Dados inseridos com sucesso!\n";
        break;

        case 2:
            sorteado = rand() % 30 + 1;
                cout << "O número sorteado foi: " << sorteado << endl;
                cout << "O registro nessa posição será excluído.\n";
                if (P[0] == NULL){
                    cout << "Não há nenhum registro para excluir!\n";
                } else {
                    P = obj.Remover(P, sorteado, &a);
                    if(a){
                        cout << "Registro excluído com sucesso!\n";
                    } else {
                        cout << "Registro não localizado!\n";
                    }
                }
        break;

        case 3:
            if(P[0] == NULL){
                cout << "Não há registros para a listagem!\n";
            }else{
                cout << "###### Listagem ######\n";
                obj.Percorrer(P);
            }
        break;

        case 4:
            cout << "Até a próxima!\n";
        break;

        default:
            cout << "Opção inválida!\n";
        }
        cout << "Pressione 'Enter' para continuar!";
        cin.ignore().get();
    }while(op != 4);

    return 0;
}
