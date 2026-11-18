#include <iostream>
# include <string>
using namespace std;

int somar(const int vetor[], int tamanho){
    if(tamanho == 0){
        return 0;
    }
    int resultado = 0;
    resultado += vetor[tamanho-1] + somar(vetor, tamanho-1);

    return resultado;
}

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
    int tamanho = 5;
    int* lista = new int[tamanho];

    for(int i = 0; i < tamanho; i++){
        int elemento = 0;
        cout << "Informe o " << to_string(i+1) << "° número:";
        elemento = capturar_numero("");
        lista[i] = elemento;
    }

    cout << somar(lista, tamanho);

    delete[] lista;

    return 0;
}