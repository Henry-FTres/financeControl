#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
 
#include "Pessoa.h"
#include <string>
 
class PessoaFisica : public Pessoa {
    private:
        std::string cpf;
        std::string dataNascimento;
 
    public:
        PessoaFisica() {};

        PessoaFisica(
            int id,
            std::string nome,
            std::string email,
            std::string telefone,
            std::string cpf,
            std::string dataNascimento,
            std::vector<Conta> contas = {},
            std::vector<Meta> metas = {}
        );
        
        //getters
        std::string getCpf() const;
        string getDataNascimento() const;

        //setters
        void setCpf(std::string cpf);
        void setDataNascimento(std::string dataNascimento);
 
        void exibirDados() const override;
 
};
 
#endif