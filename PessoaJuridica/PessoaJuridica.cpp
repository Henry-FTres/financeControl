#include "PessoaJuridica.h"
#include <iostream>

using namespace std;

PessoaJuridica::PessoaJuridica(
    int id,
    string nome,
    string email,
    string cnpj
) : Pessoa (id, nome, email) {this->cnpj = cnpj;}

string PessoaJuridica::getCnpj() const {return cnpj;}

void PessoaJuridica::setCnpj(string cnpj) {this->cnpj = cnpj;}

void PessoaJuridica::exibirDados() const {
    Pessoa::exibirDados();
    cout << "CNPJ: " << cnpj << "\n";
}