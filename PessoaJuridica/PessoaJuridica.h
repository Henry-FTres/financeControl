#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H

#include "Pessoa.h"
#include <iostream>

using namespace std;

class PessoaJuridica : public Pessoa {
    private: 
        string cnpj;

    public:
        PessoaJuridica(
            int id,
            string nome,
            string email,
            string cnpj
        );

        string getCnpj() const;
        void setCnpj(string cnpj);

        void exibirDados() const override;
};

#endif
