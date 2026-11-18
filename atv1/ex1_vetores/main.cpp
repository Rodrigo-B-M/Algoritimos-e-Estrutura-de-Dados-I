#include <iostream>
#include <vector>
using namespace std;

int pedir_numero(){
    int entrada;
    cout << "Digite um número:\n";
    while(true){
        cin >> entrada;
        if(cin.fail()){
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "Valor inválido! Digite um número inteiro: \n";
            continue;
        }
        break;
    }
    return entrada;
}

int main(){
    vector <int> v(5);    
    for(int i = 0; i < v.size(); i++){
        int valor = pedir_numero();
        v[i] = valor;        
    }
    
    cout << "["; 
    for(int i = 0; i < v.size(); i++){
        if (i > 0) cout << ", ";
        cout << v[i];
    }
    cout <<"]\n";
    
    int maior = v[0];
    int menor = v[0];
    double soma = 0;
    double media = 0;
    int qtd_pares = 0;

    for(int i = 0; i < v.size(); i++){
        if (v[i] > maior){
            maior = v[i];
        }
        if (v[i] < menor){
            menor = v[i];
        }
        if (v[i] % 2 == 0){
            qtd_pares += 1;
        }
        soma += v[i];
    }
    media = soma / v.size();

    cout << "O maior número é: " << maior << "\n";
    cout << "O menor número é: " << menor << "\n";
    cout << "A média dos números é: " << media << "\n";
    cout << "Dos números informados, " << qtd_pares << " são pares!\n";
  
    return 0;
}