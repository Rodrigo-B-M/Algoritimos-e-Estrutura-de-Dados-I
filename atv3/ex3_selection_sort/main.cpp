#include <iostream>
#include <string>
using namespace std;

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

void exibir_lista(const int vetor[], int tamanho){
    cout << "["; 
    for(int i = 0; i < tamanho; i++){
    if (i > 0) cout << ", ";
    cout << vetor[i];
    }   
    cout <<"]\n";
}

int main(){
    int tamanho = 6;
    int* lista = new int[tamanho];

    for(int i = 0; i < tamanho; i++){
    int elemento = 0;
    cout << "Informe o " << to_string(i+1) << "° número:";
    elemento = capturar_numero("");
    lista[i] = elemento;
    }

    cout << "Vetor original: ";
    exibir_lista(lista, tamanho);


    for(int i = 0; i < tamanho; i++){
        int indice_menor = i;
        for(int j = i + 1; j < tamanho; j++){
            if(lista[j] < lista[indice_menor]){
                indice_menor = j;
            }
        }
        int menor = lista[indice_menor];
        int maior = lista[i];
        lista[i] = menor;
        lista[indice_menor] = maior;
        if(i == tamanho - 1){
            cout << "Vetor final: ";
            exibir_lista(lista, tamanho);
        } else {
            cout << "Vetor após o " << to_string(i + 1) <<"° laço: ";
            exibir_lista(lista, tamanho);
        }
    }

    delete[] lista;
    return 0;
    
}



