#include "PessoaJuridica.h"
#include <iostream>

using namespace std;

PessoaJuridica::PessoaJuridica(
    int id,
    string nome,
    string email,
    string telefone,
    string cnpj,
    string razaoSocial
) : Pessoa (id, nome, email, telefone) {
    this->cnpj = cnpj;
    this->razaoSocial = razaoSocial;
}

string PessoaJuridica::getCnpj() const {return this->cnpj;}

void PessoaJuridica::setCnpj(string cnpj) {this->cnpj = cnpj;}

void PessoaJuridica::exibirDados() const {
    Pessoa::exibirDados();
    cout << "CNPJ: " << cnpj << "\n";
}
