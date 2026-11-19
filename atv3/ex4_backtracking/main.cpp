#include <iostream>
using namespace std;

void gerar_sequencia(int vetor_sequencia[], bool vetor_utilizados[], int posicao, int &contagem ){
    if(posicao == 3){
        for(int i = 0; i < 3; i++){
            cout << vetor_sequencia[i] << " ";
        }
        cout << "\n";
        contagem ++;
        return;
    }

    for(int i = 0; i < 3; i++){
        if(vetor_utilizados[i] == false){
            vetor_sequencia[posicao] = i + 1;
            vetor_utilizados[i] = true;

            gerar_sequencia(vetor_sequencia, vetor_utilizados, posicao + 1, contagem);

            vetor_utilizados[i] = false;
        }
    } 
}

int main(){
    int sequencia[3] = {1, 2, 3};
    bool utilizados[3] ={ false, false, false};
    int contagem = 0;

    gerar_sequencia(sequencia, utilizados, 0, contagem);

    cout << "Total de sequencias: " << contagem << "\n";

    return 0;
}