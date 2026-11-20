#include <iostream>
using namespace std;

struct No{
    int valor_elemento;
    No* proximo_elemento;
};

int capturar_numero(string texto){
    int entrada;
    while(true){
        cout << texto << "\n";
        if(cin >> entrada){
            return entrada;
        }
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\n";
        continue;
    }
}

int main(){
    No* inicio = nullptr;

    while(true){
        int opcao_usuario;
        cout << "Selecione uma opcao:\n";
        cout << "1 - Inserir um número no incio da lista.\n";
        cout << "2 - Apresentar todos elementos da lista.\n";
        cout << "3 - Buscar um número na lista.\n";
        cout << "4 - Remover um número na lista.\n";
        cout << "5 - Encerrar.\n";

        opcao_usuario = capturar_numero("");
        switch(opcao_usuario){
            case 1:{
                int numero_recebido = capturar_numero("Digite o número que deseja incluir:");
                No* novo = new No;
                novo -> valor_elemento = numero_recebido;
                novo -> proximo_elemento = inicio;
                inicio = novo;
                cout << numero_recebido << " Incluido com sucesso!\n\n";
                break;
            }
            case 2:{
                No* atual = inicio;
                int contador = 0;
                while(atual != nullptr){
                    contador ++;
                    cout << contador <<"°) " << atual -> valor_elemento << "\n";
                    atual = atual -> proximo_elemento;   
                }
                if(contador == 0){
                    cout << "A lista não possui nenhum número!\n\n";
                } else{
                    cout << "\n\n";
                }
                break;                
            }
            case 3:{
                int numero_recebido = capturar_numero("Digite o número que deseja buscar:");
                No* atual = inicio;
                int contador = 0;
                bool sucesso = false;
                while(atual != nullptr){
                    contador ++;
                    if(atual -> valor_elemento == numero_recebido){
                        sucesso = true;
                        break;
                    }
                    atual = atual -> proximo_elemento; 
                }
                if(sucesso == false){
                    cout << "O número " << numero_recebido << " não foi localizado na lista! \n\n";
                } else{
                    cout << "A primeira ocorrência do numero " << numero_recebido << " foi localizada na " << contador << "° posição! \n\n";
                }
                break;
            }
            case 4:{
                int numero_recebido = capturar_numero("Digite o número que deseja excluir:");
                No* atual = inicio;
                No* anterior = nullptr;
                bool sucesso = false;
                while(atual != nullptr){                   
                    if(atual -> valor_elemento == numero_recebido){
                        sucesso = true;
                        if(anterior == nullptr){
                            inicio = atual -> proximo_elemento;
                        } else{
                            anterior -> proximo_elemento = atual -> proximo_elemento;                            
                        }
                        delete atual;  
                        break;                  
                    }
                    anterior = atual;
                    atual = atual -> proximo_elemento;
                }
                if(sucesso == false){
                    cout << "O número " << numero_recebido << " não foi localizado. \n\n";
                } else{
                    cout << "A primeira ocorrência do número " << numero_recebido << " foi excluida com sucesso!\n\n";
                }
                break;
            }
            case 5:{
                cout << "\nEncerrando...\n\n";
                No* excluir = inicio;
                No* transitorio = nullptr;
                while(excluir != nullptr){
                    transitorio = excluir -> proximo_elemento;
                    delete excluir;
                    excluir = transitorio;
                }
                return 0;
            }
            default:{
                cout << "Opção invalida!\n\n";
                break;
            }
        }
    }
}