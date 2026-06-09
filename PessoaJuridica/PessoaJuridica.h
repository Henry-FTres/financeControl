#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H

#include "Pessoa.h"
#include <iostream>

using namespace std;

class PessoaJuridica : public Pessoa {
    private: 
        string cnpj;
        string razaoSocial;

    public:
        PessoaJuridica() {};

        PessoaJuridica(
            int id,
            string nome,
            string email,
            string telefone,
            string cnpj,
            string razaoSocial
        );

        string getCnpj() const;
        string getRazaoSocial() const;

        void setCnpj(string cnpj);
        void setRazaoSocial(string razaoSocial);

        void exibirDados() const override;
};

#endif

