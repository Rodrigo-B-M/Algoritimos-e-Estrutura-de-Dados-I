#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int capturar_qtd_notas(){
    int entrada;
    while(true){
        string linha;
        char sobra;
        cout << "Informe a quantidade de notas: \n";
        if(getline(cin, linha).fail() == true){
            return -1;
        }
        stringstream conversor(linha);
        conversor >> entrada;
        if(conversor.fail() == true){
            cout << "Valor inválido! Digite um número inteiro: \n";
            continue;
        }
        conversor >> sobra;
        if(conversor.fail() == false){
            cout << "Valor inválido! Digite apenas números inteiros: \n";
            continue;
        }
        if(entrada > 0){
            break;
        }
        cout << "Número invalido! Digite um número inteiro positivo:\n";
    }
    return entrada;
} 

double capturar_notas(string texto){
    double entrada;
    while(true){
        cout << texto << "\n";
        string linha;
        char sobra;
        if(getline(cin, linha).fail() == true){
            return -1;
        }
        stringstream conversor(linha);
        conversor >> entrada;
        if(conversor.fail() == true){
            cout << "Valor inválido! Digite um número.\n";
            continue;
        }
        conversor >> sobra;
        if(conversor.fail() == false){
            cout << "Valor inválido! Digite apenas números.\n";
            continue;
        }
        if(entrada >= 0 && entrada <= 10){
            break;
        }
        cout << "Nota invalida! Digite um numero de 0 a 10.\n";
    }
    return entrada; 
}

int main(){
    int qtd_notas = capturar_qtd_notas();
    if(qtd_notas == -1){
        return 1;
    }
    double nota;
    ofstream arquivo("notas.txt");

    if (arquivo.is_open() == false){
    cout << "Falha ao abrir o arquivo!";
    return 1;
    }

    for(int i = 0; i < qtd_notas; i++){
        nota = capturar_notas("Informe a nota do " + to_string(i + 1) + "º aluno: ");
        if(nota == -1){
            return 1;
        }
        arquivo << nota << "\n";
    }
    arquivo.close();
    cout << "\nNotas salvas com sucesso!\n\n";

    
    ifstream file("notas.txt");
    
    if (file.is_open() == false){
        cout << "Falha ao abrir o arquivo";
        return 1;
    }
    
    double soma = 0;
    int contador = 0;
    double nota_lida = 0;

    while(file >> nota_lida){
        cout << "Informação encontrada: " << nota_lida <<"\n";
        soma += nota_lida;
        contador +=1;
    }

    file.close();

    if(contador == 0){
        cout << "Nenhuma nota foi encontrada no arquivo!\n";
        return 1;
    } 

    double media = soma / contador;

    cout << "Foram obtidas " << contador << " notas do arquivo.\n";
    cout << "A média da turma ficou em " << media << "!\n"; 

    return 0;
}
