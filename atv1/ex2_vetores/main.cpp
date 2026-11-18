#include <iostream>
#include <string>
using namespace std;

int capturar_qtd_alunos(){
    int entrada;
    while(true){
        cout << "Informe a quantidade de alunos: \n";
        cin >> entrada;
        if(cin.fail()){
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "Valor inválido! Digite um número inteiro: \n";
            continue;
        }
        if(entrada > 0){
            break;
        }
        cout << "Número invalido! Digite um número inteiro positivo:\n";
    }
    return entrada;
} 

double ler_notas(string texto){
    double entrada;
    while(true){
        cout << texto << "\n";
        cin >> entrada;
        if(cin.fail()){
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "Valor inválido! Digite um número.\n";
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
    int qtd_alunos = capturar_qtd_alunos();
    double* lista = new double[qtd_alunos];
    double nota;
    double soma = 0;

    for(int i = 0; i < qtd_alunos; i++){
        nota = ler_notas("Informe a nota do " + to_string(i + 1) + "º aluno: ");
        lista[i] = nota;
        soma += lista[i];
    }

    double media = soma / qtd_alunos;

    cout << "A média da turma ficou em " << media <<"!\n";

    int contador = 0;
    for(int i = 0; i < qtd_alunos; i++){
        if(lista[i] >= media){
            contador += 1;
        }
    }

    cout << "Ao todo, " << contador << " alunos obtiveram nota maior ou igual à média da turma!";

    delete[] lista;

    return 0;
}