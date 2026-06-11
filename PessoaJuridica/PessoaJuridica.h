#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H

#include "Pessoa.h"
#include <string>

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
            string razaoSocial,
            vector<Conta> contas = {}, 
            vector<Meta> metas = {}
        );

        //getters
        string getCnpj() const;
        string getRazaoSocial() const;

        //setters
        void setCnpj(string cnpj);
        void setRazaoSocial(string razaoSocial);

        void exibirDados() const override;
};

#endif

