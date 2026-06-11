#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H

#include "Pessoa.h"
#include <string>

using namespace std;

class PessoaJuridica : public Pessoa {
    private: 
        std::string cnpj;
        std::string razaoSocial;

    public:
        PessoaJuridica() {};

        PessoaJuridica(
            int id,
            std::string nome,
            std::string email,
            std::string telefone,
            std::string cnpj,
            std::string razaoSocial,
            std::vector<Conta> contas = {}, 
            std::vector<Meta> metas = {}
        );

        //getters
        std::string getCnpj() const;
        std::string getRazaoSocial() const;

        //setters
        void setCnpj(std::string cnpj);
        void setRazaoSocial(std::string razaoSocial);

        void exibirDados() const override;
};

#endif

