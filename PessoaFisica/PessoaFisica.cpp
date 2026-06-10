#include "PessoaFisica.h"
#include <iostream>
 
using namespace std;
 
//construtor com a classe super
PessoaFisica::PessoaFisica(
    int id,
    string nome,
    string email,
    string telefone,
    string cpf,
    string dataNascimento, 
    vector<Conta> contas, 
    vector<Meta> metas
) : Pessoa (id, nome, email, telefone,contas, metas ) {
    this->cpf = cpf;
    this->dataNascimento = dataNascimento;
}
 
 
// Getters
string PessoaFisica::getCpf() const {
    return this->cpf;
}
string PessoaFisica::getDataNascimento() const {
    return this->dataNascimento;
}
 
// Setters
void PessoaFisica::setCpf(string cpf) {
    this->cpf = cpf;
}
void PessoaFisica::setDataNascimento(string dataNascimento) {
    this->dataNascimento = dataNascimento;
}
 

void PessoaFisica::exibirDados() const {
    cout << "ID: " << getId() << "\n"
        << "Nome: " << getNome() << "\n"
        << "Email: " << getEmail() << "\n"
        << "Telefone: " << getTelefone() << "\n"
        << "CPF: " << cpf << "\n"
        << "Data de Nascimento: " << dataNascimento << "\n";
}


