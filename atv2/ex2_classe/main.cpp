#include <iostream>
#include <string>
using namespace std;

class ContaBancaria {
    private:
    int numero_conta;
    double saldo;

    public:
    ContaBancaria(int numero){
        numero_conta = numero;
        saldo = 0.00;
    }
    bool depositar(double valor){
        if(valor > 0){
            saldo += valor;
            return true;
        } else{
            return false;
        }
    }
    bool sacar(double valor){
        if (valor <= saldo && valor > 0){
            saldo -= valor;         
            return true;
        } else{       
            return false;
        }
    }
    double consultarSaldo() const{ 
        return saldo;
    }
}; 

void operacao(bool operacao, string texto){
    if(operacao == true){
        cout << texto << " realizado com sucesso!\n"; 
    } else{
        cout << texto << " não realizado! Valor inválido\n"; 
    }
}

int main(){
    ContaBancaria cliente1(1);
    cout << "Conta criada com sucesso!\nSaldo atual: "<< cliente1.consultarSaldo() << "\n\n";
    //Depósito válido:
    operacao(cliente1.depositar(100.50), "Depósito");
    cout << "Saldo atual: "<< cliente1.consultarSaldo() << "\n\n";   

    //Depósito negativo:
    operacao(cliente1.depositar(-100000), "Depósito");
    cout << "Saldo atual: "<< cliente1.consultarSaldo() << "\n\n";  

    //Saque válido:
    operacao(cliente1.sacar(50), "Saque");
    cout << "Saldo atual: "<< cliente1.consultarSaldo() << "\n\n";  

    //Saque superior ao saldo:
    operacao(cliente1.sacar(1000), "Saque");
    cout << "Saldo atual: "<< cliente1.consultarSaldo() << "\n\n";  

    return 0;
}