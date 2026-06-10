#include "PessoaJuridica.h"
#include <iostream>

using namespace std;

PessoaJuridica::PessoaJuridica(
    int id,
    string nome,
    string email,
    string telefone,
    string cnpj,
    string razaoSocial,
    vector<Conta> contas, 
    vector<Meta> metas
) : Pessoa (id, nome, email, telefone, contas, metas) {
    this->cnpj = cnpj;
    this->razaoSocial = razaoSocial;
}

string PessoaJuridica::getCnpj() const {
    return this->cnpj;
}

string PessoaJuridica::getRazaoSocial() const {
    return this->razaoSocial;
}

void PessoaJuridica::setCnpj(string cnpj) {
    this->cnpj = cnpj;
}

void PessoaJuridica::setRazaoSocial(string razaoSocial) {
    this->razaoSocial = razaoSocial;
}

void PessoaJuridica::exibirDados() const {
    cout << "ID: " << getId() << "\n"
     << "Nome: " << getNome() << "\n"
     << "Email: " << getEmail() << "\n"
     << "Telefone: " << getTelefone() << "\n"
     << "CNPJ: " << cnpj << "\n"
     << "Razão Social: " << razaoSocial << "\n";
}
