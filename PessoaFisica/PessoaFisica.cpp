#include "PessoaFisica.h"
#include <iostream>
 
using namespace std;
 
// Construtor com a classe super
PessoaFisica::PessoaFisica(
    int id,
    string nome,
    string email,
    string telefone,
    string cpf,
    string dataNascimento
) : Pessoa (id, nome, email, telefone) {
    this->cpf = cpf;
    this->dataNascimento = dataNascimento;
}
 
 
// Getters
string PessoaFisica::getCpf() const {return this->cpf;}
string PessoaFisica::getDataNascimento() const {return this->dataNascimento;}
 
 
// Setters
void PessoaFisica::setCpf(string cpf) {this->cpf = cpf;}
void PessoaFisica::setDataNascimento(string dataNascimento) {this->dataNascimento = dataNascimento;}
 
 
void PessoaFisica::exibirDados() const {
    Pessoa::exibirDados();
    cout << "CPF: " << cpf << "\n"
         << "Data de Nascimento: " << dataNascimento << "\n";
}

