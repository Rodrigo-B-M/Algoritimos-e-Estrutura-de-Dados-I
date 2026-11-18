#include <iostream>

int main(){
    double notas[3] = {7.0, 8.0, 9.0};
    double soma = 0;

    for(int i = 0; i < 3; i++){
        soma += notas[i];    
    }
    double media = soma / 3;
    std::cout << "Média: " << media << "\n";
    
    return 0;
}