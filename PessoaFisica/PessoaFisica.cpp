#include "PessoaFisica.h"
#include <iostream>
 
using namespace std;
 
// Construtor com a classe super
PessoaFisica::PessoaFisica(
    int id,
    string nome,
    string email,
    string cpf
) : Pessoa (id, nome, email) {this->cpf = cpf;}
 
 
// Getters
string PessoaFisica::getCpf() const {return cpf;}
 
 
// Setters
void PessoaFisica::setCpf(string cpf) {this->cpf = cpf;}
 
 
void PessoaFisica::exibirDados() const {
    Pessoa::exibirDados();
    cout << "CPF: " << cpf << "\n";
}